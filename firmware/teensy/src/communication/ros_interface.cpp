#include "communication/ros_interface.h"

#include <micro_ros_platformio.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <rmw_microros/rmw_microros.h>

#include <std_msgs/msg/u_int32.h>

#include <tyrant_interfaces/msg/mode_request.h>
#include <tyrant_interfaces/msg/mode_status.h>


namespace
{
    // ========================================================
    // ROS CORE
    // ========================================================

    rcl_node_t node =
        rcl_get_zero_initialized_node();

    rcl_publisher_t heartbeat_publisher =
        rcl_get_zero_initialized_publisher();

    rcl_publisher_t response_publisher =
        rcl_get_zero_initialized_publisher();

    rcl_publisher_t mode_status_publisher =
        rcl_get_zero_initialized_publisher();

    rcl_subscription_t command_subscriber =
        rcl_get_zero_initialized_subscription();

    rcl_subscription_t mode_request_subscriber =
        rcl_get_zero_initialized_subscription();

    rcl_subscription_t host_heartbeat_subscriber =
        rcl_get_zero_initialized_subscription();

    rclc_support_t support {};

    rcl_allocator_t allocator;

    rclc_executor_t executor =
        rclc_executor_get_zero_initialized_executor();


    // ========================================================
    // INITIALIZATION FLAGS
    // ========================================================

    bool support_initialized = false;

    bool node_initialized = false;

    bool heartbeat_pub_initialized = false;
    bool response_pub_initialized = false;
    bool mode_status_pub_initialized = false;

    bool command_sub_initialized = false;
    bool mode_request_sub_initialized = false;
    bool host_heartbeat_sub_initialized = false;

    bool executor_initialized = false;

    bool mode_request_msg_initialized = false;
    bool mode_status_msg_initialized = false;

    bool entities_ready = false;


    // ========================================================
    // STANDARD MESSAGES
    // ========================================================

    std_msgs__msg__UInt32 heartbeat_msg;
    std_msgs__msg__UInt32 response_msg;
    std_msgs__msg__UInt32 command_msg;
    std_msgs__msg__UInt32 host_heartbeat_msg;


    // ========================================================
    // TYRANT MESSAGES
    // ========================================================

    tyrant_interfaces__msg__ModeRequest
        mode_request_msg;

    tyrant_interfaces__msg__ModeStatus
        mode_status_msg;


    // ========================================================
    // APPLICATION DATA
    // ========================================================

    bool new_command = false;
    uint32_t last_command = 0;

    bool new_mode_request = false;

    uint32_t requested_mode_id = 0;
    uint8_t requested_mode = 0;

    bool new_host_heartbeat = false;
    uint32_t host_heartbeat_value = 0;


    // ========================================================
    // RETURN VALUE HELPER
    // ========================================================

    void consumeRet(rcl_ret_t ret)
    {
        (void)ret;
    }


    // ========================================================
    // CALLBACKS
    // ========================================================

    void commandCallback(
        const void *msgin
    )
    {
        const auto *received =
            static_cast<
                const std_msgs__msg__UInt32 *
            >(msgin);

        last_command =
            received->data;

        new_command = true;
    }


    void modeRequestCallback(
        const void *msgin
    )
    {
        const auto *received =
            static_cast<
                const tyrant_interfaces__msg__ModeRequest *
            >(msgin);

        requested_mode_id =
            received->request_id;

        requested_mode =
            received->requested_mode;

        new_mode_request = true;
    }


    void hostHeartbeatCallback(
        const void *msgin
    )
    {
        const auto *received =
            static_cast<
                const std_msgs__msg__UInt32 *
            >(msgin);

        host_heartbeat_value =
            received->data;

        new_host_heartbeat = true;
    }


    void resetApplicationFlags()
    {
        new_command = false;
        last_command = 0;

        new_mode_request = false;
        requested_mode_id = 0;
        requested_mode = 0;

        new_host_heartbeat = false;
        host_heartbeat_value = 0;
    }
}


namespace TyrantROS
{
    // ========================================================
    // TRANSPORT
    // ========================================================

    void setupTransport()
    {
        Serial.begin(115200);

        delay(2000);

        set_microros_serial_transports(
            Serial
        );
    }


    bool pingAgent(
        uint32_t timeout_ms,
        uint8_t attempts
    )
    {
        return (
            rmw_uros_ping_agent(
                timeout_ms,
                attempts
            ) == RMW_RET_OK
        );
    }


    // ========================================================
    // CREATE ROS ENTITIES
    // ========================================================

    bool createEntities()
    {
        if (entities_ready)
        {
            return true;
        }


        allocator =
            rcl_get_default_allocator();


        // ----------------------------------------------------
        // Custom message memory
        // ----------------------------------------------------

        if (
            !tyrant_interfaces__msg__ModeRequest__init(
                &mode_request_msg
            )
        )
        {
            destroyEntities();
            return false;
        }

        mode_request_msg_initialized = true;


        if (
            !tyrant_interfaces__msg__ModeStatus__init(
                &mode_status_msg
            )
        )
        {
            destroyEntities();
            return false;
        }

        mode_status_msg_initialized = true;


        // ----------------------------------------------------
        // ROS support
        // ----------------------------------------------------

        if (
            rclc_support_init(
                &support,
                0,
                nullptr,
                &allocator
            ) != RCL_RET_OK
        )
        {
            destroyEntities();
            return false;
        }

        support_initialized = true;


        // ----------------------------------------------------
        // Node
        // ----------------------------------------------------

        if (
            rclc_node_init_default(
                &node,
                "tyrant_teensy",
                "",
                &support
            ) != RCL_RET_OK
        )
        {
            destroyEntities();
            return false;
        }

        node_initialized = true;


        // ----------------------------------------------------
        // Heartbeat publisher
        // ----------------------------------------------------

        if (
            rclc_publisher_init_default(
                &heartbeat_publisher,
                &node,
                ROSIDL_GET_MSG_TYPE_SUPPORT(
                    std_msgs,
                    msg,
                    UInt32
                ),
                "/tyrant/heartbeat"
            ) != RCL_RET_OK
        )
        {
            destroyEntities();
            return false;
        }

        heartbeat_pub_initialized = true;


        // ----------------------------------------------------
        // Legacy test response publisher
        // ----------------------------------------------------

        if (
            rclc_publisher_init_default(
                &response_publisher,
                &node,
                ROSIDL_GET_MSG_TYPE_SUPPORT(
                    std_msgs,
                    msg,
                    UInt32
                ),
                "/tyrant/test_response"
            ) != RCL_RET_OK
        )
        {
            destroyEntities();
            return false;
        }

        response_pub_initialized = true;


        // ----------------------------------------------------
        // CUSTOM MODE STATUS PUBLISHER
        // ----------------------------------------------------

        if (
            rclc_publisher_init_default(
                &mode_status_publisher,
                &node,
                ROSIDL_GET_MSG_TYPE_SUPPORT(
                    tyrant_interfaces,
                    msg,
                    ModeStatus
                ),
                "/tyrant/mode/status"
            ) != RCL_RET_OK
        )
        {
            destroyEntities();
            return false;
        }

        mode_status_pub_initialized = true;


        // ----------------------------------------------------
        // Legacy diagnostic subscriber
        // ----------------------------------------------------

        if (
            rclc_subscription_init_default(
                &command_subscriber,
                &node,
                ROSIDL_GET_MSG_TYPE_SUPPORT(
                    std_msgs,
                    msg,
                    UInt32
                ),
                "/tyrant/test_command"
            ) != RCL_RET_OK
        )
        {
            destroyEntities();
            return false;
        }

        command_sub_initialized = true;


        // ----------------------------------------------------
        // CUSTOM MODE REQUEST SUBSCRIBER
        // ----------------------------------------------------

        if (
            rclc_subscription_init_default(
                &mode_request_subscriber,
                &node,
                ROSIDL_GET_MSG_TYPE_SUPPORT(
                    tyrant_interfaces,
                    msg,
                    ModeRequest
                ),
                "/tyrant/mode/request"
            ) != RCL_RET_OK
        )
        {
            destroyEntities();
            return false;
        }

        mode_request_sub_initialized = true;


        // ----------------------------------------------------
        // Host heartbeat subscriber
        // ----------------------------------------------------

        if (
            rclc_subscription_init_default(
                &host_heartbeat_subscriber,
                &node,
                ROSIDL_GET_MSG_TYPE_SUPPORT(
                    std_msgs,
                    msg,
                    UInt32
                ),
                "/tyrant/host_heartbeat"
            ) != RCL_RET_OK
        )
        {
            destroyEntities();
            return false;
        }

        host_heartbeat_sub_initialized = true;


        // ----------------------------------------------------
        // Executor
        //
        // Three subscribers:
        // test command
        // ModeRequest
        // host heartbeat
        // ----------------------------------------------------

        executor =
            rclc_executor_get_zero_initialized_executor();

        if (
            rclc_executor_init(
                &executor,
                &support.context,
                3,
                &allocator
            ) != RCL_RET_OK
        )
        {
            destroyEntities();
            return false;
        }

        executor_initialized = true;


        if (
            rclc_executor_add_subscription(
                &executor,
                &command_subscriber,
                &command_msg,
                &commandCallback,
                ON_NEW_DATA
            ) != RCL_RET_OK
        )
        {
            destroyEntities();
            return false;
        }


        if (
            rclc_executor_add_subscription(
                &executor,
                &mode_request_subscriber,
                &mode_request_msg,
                &modeRequestCallback,
                ON_NEW_DATA
            ) != RCL_RET_OK
        )
        {
            destroyEntities();
            return false;
        }


        if (
            rclc_executor_add_subscription(
                &executor,
                &host_heartbeat_subscriber,
                &host_heartbeat_msg,
                &hostHeartbeatCallback,
                ON_NEW_DATA
            ) != RCL_RET_OK
        )
        {
            destroyEntities();
            return false;
        }


        heartbeat_msg.data = 0;
        response_msg.data = 0;

        resetApplicationFlags();

        entities_ready = true;

        return true;
    }


    // ========================================================
    // DESTROY ROS ENTITIES
    // ========================================================

    void destroyEntities()
    {
        entities_ready = false;

        resetApplicationFlags();


        if (support_initialized)
        {
            rmw_context_t *rmw_context =
                rcl_context_get_rmw_context(
                    &support.context
                );

            if (rmw_context != nullptr)
            {
                (void)
                    rmw_uros_set_context_entity_destroy_session_timeout(
                        rmw_context,
                        0
                    );
            }
        }


        if (heartbeat_pub_initialized)
        {
            consumeRet(
                rcl_publisher_fini(
                    &heartbeat_publisher,
                    &node
                )
            );

            heartbeat_pub_initialized = false;

            heartbeat_publisher =
                rcl_get_zero_initialized_publisher();
        }


        if (response_pub_initialized)
        {
            consumeRet(
                rcl_publisher_fini(
                    &response_publisher,
                    &node
                )
            );

            response_pub_initialized = false;

            response_publisher =
                rcl_get_zero_initialized_publisher();
        }


        if (mode_status_pub_initialized)
        {
            consumeRet(
                rcl_publisher_fini(
                    &mode_status_publisher,
                    &node
                )
            );

            mode_status_pub_initialized = false;

            mode_status_publisher =
                rcl_get_zero_initialized_publisher();
        }


        if (command_sub_initialized)
        {
            consumeRet(
                rcl_subscription_fini(
                    &command_subscriber,
                    &node
                )
            );

            command_sub_initialized = false;

            command_subscriber =
                rcl_get_zero_initialized_subscription();
        }


        if (mode_request_sub_initialized)
        {
            consumeRet(
                rcl_subscription_fini(
                    &mode_request_subscriber,
                    &node
                )
            );

            mode_request_sub_initialized = false;

            mode_request_subscriber =
                rcl_get_zero_initialized_subscription();
        }


        if (host_heartbeat_sub_initialized)
        {
            consumeRet(
                rcl_subscription_fini(
                    &host_heartbeat_subscriber,
                    &node
                )
            );

            host_heartbeat_sub_initialized = false;

            host_heartbeat_subscriber =
                rcl_get_zero_initialized_subscription();
        }


        if (executor_initialized)
        {
            consumeRet(
                rclc_executor_fini(
                    &executor
                )
            );

            executor_initialized = false;

            executor =
                rclc_executor_get_zero_initialized_executor();
        }


        if (node_initialized)
        {
            consumeRet(
                rcl_node_fini(
                    &node
                )
            );

            node_initialized = false;

            node =
                rcl_get_zero_initialized_node();
        }


        if (support_initialized)
        {
            consumeRet(
                rclc_support_fini(
                    &support
                )
            );

            support_initialized = false;

            support = {};
        }


        // ----------------------------------------------------
        // Custom message memory
        // ----------------------------------------------------

        if (mode_status_msg_initialized)
        {
            tyrant_interfaces__msg__ModeStatus__fini(
                &mode_status_msg
            );

            mode_status_msg_initialized = false;
        }


        if (mode_request_msg_initialized)
        {
            tyrant_interfaces__msg__ModeRequest__fini(
                &mode_request_msg
            );

            mode_request_msg_initialized = false;
        }
    }


    bool entitiesReady()
    {
        return entities_ready;
    }


    // ========================================================
    // SPIN
    // ========================================================

    void spin()
    {
        if (!entities_ready)
        {
            return;
        }

        const rcl_ret_t ret =
            rclc_executor_spin_some(
                &executor,
                RCL_MS_TO_NS(5)
            );

        (void)ret;
    }


    // ========================================================
    // HEARTBEAT
    // ========================================================

    void publishHeartbeat()
    {
        if (!entities_ready)
        {
            return;
        }

        heartbeat_msg.data++;

        const rcl_ret_t ret =
            rcl_publish(
                &heartbeat_publisher,
                &heartbeat_msg,
                nullptr
            );

        (void)ret;
    }


    // ========================================================
    // LEGACY TEST RESPONSE
    // ========================================================

    void publishResponse(
        uint32_t value
    )
    {
        if (!entities_ready)
        {
            return;
        }

        response_msg.data = value;

        const rcl_ret_t ret =
            rcl_publish(
                &response_publisher,
                &response_msg,
                nullptr
            );

        (void)ret;
    }


    // ========================================================
    // CUSTOM MODE STATUS
    // ========================================================

    void publishModeStatus(
        uint32_t request_id,
        uint8_t current_mode,
        uint8_t requested_mode,
        bool request_accepted,
        uint8_t reason,
        bool communication_healthy,
        bool propulsion_allowed
    )
    {
        if (!entities_ready)
        {
            return;
        }


        // No ROS time synchronization yet.
        mode_status_msg.header.stamp.sec = 0;

        mode_status_msg.header.stamp.nanosec = 0;


        mode_status_msg.request_id =
            request_id;

        mode_status_msg.current_mode =
            current_mode;

        mode_status_msg.requested_mode =
            requested_mode;

        mode_status_msg.request_accepted =
            request_accepted;

        mode_status_msg.reason =
            reason;

        mode_status_msg.communication_healthy =
            communication_healthy;

        mode_status_msg.propulsion_allowed =
            propulsion_allowed;


        const rcl_ret_t ret =
            rcl_publish(
                &mode_status_publisher,
                &mode_status_msg,
                nullptr
            );

        (void)ret;
    }


    // ========================================================
    // LEGACY DIAGNOSTIC
    // ========================================================

    bool hasNewCommand()
    {
        return new_command;
    }


    uint32_t getLastCommand()
    {
        new_command = false;

        return last_command;
    }


    // ========================================================
    // CUSTOM MODE REQUEST
    // ========================================================

    bool takeModeRequest(
        ModeRequestData &request
    )
    {
        if (!new_mode_request)
        {
            return false;
        }

        request.request_id =
            requested_mode_id;

        request.requested_mode =
            requested_mode;

        new_mode_request = false;

        return true;
    }


    // ========================================================
    // HOST HEARTBEAT
    // ========================================================

    bool hasNewHostHeartbeat()
    {
        return new_host_heartbeat;
    }


    uint32_t getHostHeartbeatValue()
    {
        new_host_heartbeat = false;

        return host_heartbeat_value;
    }
}
