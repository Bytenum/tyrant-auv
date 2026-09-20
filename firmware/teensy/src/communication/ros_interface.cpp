#include "communication/ros_interface.h"

#include <micro_ros_platformio.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <rmw_microros/rmw_microros.h>

#include <std_msgs/msg/u_int32.h>

#include <tyrant_interfaces/msg/mode_request.h>
#include <tyrant_interfaces/msg/mode_status.h>
#include <tyrant_interfaces/msg/system_health.h>
#include <tyrant_interfaces/msg/imu_telemetry.h>
#include <tyrant_interfaces/msg/pressure_telemetry.h>
#include <tyrant_interfaces/msg/depth_reference_request.h>
#include <tyrant_interfaces/msg/depth_reference_status.h>
#include <tyrant_interfaces/msg/communication_diagnostics.h>



// ============================================================
// PRIVATE INTERNAL STORAGE
// ============================================================

namespace
{
    // ========================================================
    // ROS CORE OBJECTS
    // ========================================================

    rcl_node_t node =
        rcl_get_zero_initialized_node();


    rclc_support_t support {};

    rcl_allocator_t allocator;


    rclc_executor_t executor =
        rclc_executor_get_zero_initialized_executor();


    // ========================================================
    // PUBLISHERS
    // ========================================================

    rcl_publisher_t heartbeat_publisher =
        rcl_get_zero_initialized_publisher();


    #ifdef TYRANT_ENABLE_DIAGNOSTICS
    rcl_publisher_t response_publisher =
        rcl_get_zero_initialized_publisher();
    #endif


    rcl_publisher_t mode_status_publisher =
        rcl_get_zero_initialized_publisher();


    rcl_publisher_t system_health_publisher =
        rcl_get_zero_initialized_publisher();
    
    rcl_publisher_t imu_telemetry_publisher =
        rcl_get_zero_initialized_publisher();
    
    rcl_publisher_t pressure_telemetry_publisher =
        rcl_get_zero_initialized_publisher();
    rcl_publisher_t depth_reference_status_publisher =
        rcl_get_zero_initialized_publisher();
    rcl_publisher_t communication_diagnostics_publisher =
        rcl_get_zero_initialized_publisher();


    // ========================================================
    // SUBSCRIBERS
    // ========================================================

    #ifdef TYRANT_ENABLE_DIAGNOSTICS
    rcl_subscription_t command_subscriber =
        rcl_get_zero_initialized_subscription();
    #endif

    rcl_subscription_t mode_request_subscriber =
        rcl_get_zero_initialized_subscription();


    rcl_subscription_t host_heartbeat_subscriber =
        rcl_get_zero_initialized_subscription();
    
    rcl_subscription_t depth_reference_request_subscriber =
        rcl_get_zero_initialized_subscription();

    // ========================================================
    // EXECUTOR CONFIGURATION
    // ========================================================

    // ========================================================
    // EXECUTOR CONFIGURATION
    // ========================================================

    #ifdef TYRANT_ENABLE_DIAGNOSTICS
        constexpr size_t EXECUTOR_HANDLE_COUNT = 3;
    #else
        constexpr size_t EXECUTOR_HANDLE_COUNT = 2;
    #endif

    // ========================================================
    // ENTITY INITIALIZATION FLAGS
    //
    // Dipakai supaya destroyEntities() aman walaupun
    // createEntities() hanya berhasil sebagian.
    // ========================================================

    bool support_initialized = false;

    bool node_initialized = false;


    bool heartbeat_pub_initialized = false;
    bool mode_status_pub_initialized = false;
    bool system_health_pub_initialized = false;
    bool communication_diagnostics_pub_initialized = false;
    bool imu_telemetry_pub_initialized = false;
    bool depth_reference_status_pub_initialized = false;
    bool pressure_telemetry_pub_initialized = false;
    
    
    bool mode_request_sub_initialized = false;
    bool host_heartbeat_sub_initialized = false;
    bool depth_reference_request_sub_initialized = false;
    bool executor_initialized = false;


    bool mode_request_msg_initialized = false;
    bool mode_status_msg_initialized = false;
    bool system_health_msg_initialized = false;
    bool communication_diagnostics_msg_initialized = false;
    bool imu_telemetry_msg_initialized = false;
    bool pressure_telemetry_msg_initialized = false;
    bool depth_reference_status_msg_initialized = false;
    bool depth_reference_request_msg_initialized = false;

    bool entities_ready = false;

    // ========================================================
    // diagnostic only flags
    // ========================================================
    #ifdef TYRANT_ENABLE_DIAGNOSTICS
    bool response_pub_initialized = false;
    bool command_sub_initialized = false;
    #endif
    // ========================================================
    // end of diagnostic only flags
    // ========================================================

    // ========================================================
    // STANDARD ROS MESSAGE STORAGE
    // ========================================================

    std_msgs__msg__UInt32 heartbeat_msg;
    std_msgs__msg__UInt32 host_heartbeat_msg;
    // ========================================================
    // diagnostic only msg storage
    // ========================================================
    #ifdef TYRANT_ENABLE_DIAGNOSTICS
    std_msgs__msg__UInt32 response_msg;
    std_msgs__msg__UInt32 command_msg;
    #endif
    // ========================================================
    // end of diagnostic only msg storage
    // ========================================================

    // ========================================================
    // TYRANT CUSTOM MESSAGE STORAGE
    // ========================================================

    tyrant_interfaces__msg__ModeRequest
        mode_request_msg;


    tyrant_interfaces__msg__ModeStatus
        mode_status_msg;


    tyrant_interfaces__msg__SystemHealth
        system_health_msg;
    
    tyrant_interfaces__msg__ImuTelemetry
        imu_telemetry_msg;
    
    tyrant_interfaces__msg__PressureTelemetry
        pressure_msg;

    tyrant_interfaces__msg__DepthReferenceRequest
        depth_reference_request_msg;

    tyrant_interfaces__msg__DepthReferenceStatus
        depth_reference_status_msg;

    tyrant_interfaces__msg__CommunicationDiagnostics
        communication_diagnostics_msg;


    // ========================================================
    // APPLICATION DATA / FLAGS
    // ========================================================

   #ifdef TYRANT_ENABLE_DIAGNOSTICS
    bool new_command = false;
    uint32_t last_command = 0;
    #endif


    bool new_mode_request = false;
    uint32_t requested_mode_id = 0;
    uint8_t requested_mode = 0;


    bool new_host_heartbeat = false;
    uint32_t host_heartbeat_value = 0;

    uint32_t publish_failures = 0;
    uint32_t executor_failures = 0;
    uint32_t entity_create_failures = 0;
    uint32_t entity_destroy_failures = 0;

    bool new_depth_reference_request = false;
    uint32_t depth_reference_request_id =0;
    uint8_t depth_reference_command =0;
    // ========================================================
    // HELPER
    //
    // Untuk mengonsumsi return value dari fungsi rcl_*_fini
    // sehingga compiler tidak memberi warning unused-result.
    // ========================================================

    void consumeRet(rcl_ret_t ret)
    {
        (void)ret;
    }

    void recordPublishResult(rcl_ret_t ret)
    {
        if (ret != RCL_RET_OK)
        {
            publish_failures++;
        }
    }


    void recordExecutorResult(rcl_ret_t ret)
    {
        if (
            ret != RCL_RET_OK &&
            ret != RCL_RET_TIMEOUT
        )
        {
            executor_failures++;
        }
    }


    bool recordCreateResult(rcl_ret_t ret)
    {
        if (ret == RCL_RET_OK)
        {
            return true;
        }

        entity_create_failures++;

        return false;
    }


    void recordDestroyResult(rcl_ret_t ret)
    {
        if (ret != RCL_RET_OK)
        {
            entity_destroy_failures++;
        }
    }

    // ========================================================
    // CALLBACK: LEGACY TEST COMMAND (diagnostic only)
    // ========================================================

    #ifdef TYRANT_ENABLE_DIAGNOSTICS
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
    #endif


    // ========================================================
    // CALLBACK: CUSTOM MODE REQUEST
    // ========================================================

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


    // ========================================================
    // CALLBACK: HOST HEARTBEAT
    // ========================================================

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

    // ========================================================
    // CALLBACK: DEPTH REFERENCE REQUEST
    // ========================================================
    void depthReferenceRequestCallback(
        const void *msgin
    )
    {
        const auto *received =
            static_cast<
                const tyrant_interfaces__msg__DepthReferenceRequest *
            >(msgin);


        depth_reference_request_id =
            received->request_id;

        depth_reference_command =
            received->command;

        new_depth_reference_request =
            true;
    }
    // ========================================================
    // RESET APPLICATION FLAGS
    // ========================================================

    void resetApplicationFlags()
    {
        #ifdef TYRANT_ENABLE_DIAGNOSTICS
        new_command = false;
        last_command = 0;
        #endif


        new_mode_request = false;
        requested_mode_id = 0;
        requested_mode = 0;
        new_host_heartbeat = false;
        host_heartbeat_value = 0;
        new_depth_reference_request = false;
        depth_reference_request_id = 0;
        depth_reference_command = 0;
    }
}


// ============================================================
// PUBLIC TYRANT ROS API
// ============================================================

namespace TyrantROS
{
    // ========================================================
    // SETUP PHYSICAL MICRO-ROS TRANSPORT
    //
    // Dipanggil sekali saat Teensy boot.
    //
    // ROS entities TIDAK dibuat di sini.
    // ConnectionManager yang menentukan kapan entity dibuat.
    // ========================================================

    void setupTransport()
    {
        Serial.begin(115200);


        // Beri waktu USB serial settle.
        delay(2000);


        set_microros_serial_transports(
            Serial
        );
    }


    // ========================================================
    // PING MICRO-ROS AGENT
    // ========================================================

    bool pingAgent(
        uint32_t timeout_ms,
        uint8_t attempts
    )
    {
        return (
            rmw_uros_ping_agent(
                timeout_ms,
                attempts
            )
            ==
            RMW_RET_OK
        );
    }


    // ========================================================
    // CREATE ALL ROS ENTITIES
    //
    // Dipanggil ConnectionManager setelah Agent ditemukan.
    // ========================================================

    bool createEntities()
    {
        // Jangan create dua kali.
        if (entities_ready)
        {
            return true;
        }


        allocator =
            rcl_get_default_allocator();


        // ====================================================
        // INITIALIZE CUSTOM MESSAGE MEMORY
        // ====================================================

        if (
            !tyrant_interfaces__msg__ModeRequest__init(
                &mode_request_msg
            )
        )
        {
            destroyEntities();

            return false;
        }


        mode_request_msg_initialized =
            true;


        if (
            !tyrant_interfaces__msg__ModeStatus__init(
                &mode_status_msg
            )
        )
        {
            destroyEntities();

            return false;
        }


        mode_status_msg_initialized =
            true;


        if (
            !tyrant_interfaces__msg__SystemHealth__init(
                &system_health_msg
            )
        )
        {
            destroyEntities();

            return false;
        }
        system_health_msg_initialized =
            true;
        if (
            !tyrant_interfaces__msg__ImuTelemetry__init(
                &imu_telemetry_msg
            )
        )
        {
            entity_create_failures++;

            destroyEntities();

            return false;
        }

        imu_telemetry_msg_initialized =
            true;

        if (
            !tyrant_interfaces__msg__PressureTelemetry__init(
                &pressure_msg
            )
        )
        {
            entity_create_failures++;

            destroyEntities();

            return false;
        }

        pressure_telemetry_msg_initialized =
            true;
        if (
            !tyrant_interfaces__msg__CommunicationDiagnostics__init(
                &communication_diagnostics_msg
            )
        )
        {
            entity_create_failures++;

            destroyEntities();

            return false;
        }
        communication_diagnostics_msg_initialized = true;
        if (
            !tyrant_interfaces__msg__DepthReferenceRequest__init(
                &depth_reference_request_msg
            )
        )
        {
            entity_create_failures++;

            destroyEntities();

            return false;
        }

        depth_reference_request_msg_initialized =
            true;


        if (
            !tyrant_interfaces__msg__DepthReferenceStatus__init(
                &depth_reference_status_msg
            )
        )
        {
            entity_create_failures++;

            destroyEntities();

            return false;
        }

        depth_reference_status_msg_initialized =
            true;


        // ====================================================
        // RCLC SUPPORT
        // ====================================================

        if (
            !recordCreateResult(
                rclc_support_init(
                    &support,
                    0,
                    nullptr,
                    &allocator
                )
            )
            
        )
        {
            destroyEntities();

            return false;
        }


        support_initialized =
            true;


        // ====================================================
        // NODE
        // ====================================================

        if (
            !recordCreateResult(
                rclc_node_init_default(
                    &node,
                    "tyrant_teensy",
                    "",
                    &support
                )
            )
            
            
        )
        {
            destroyEntities();

            return false;
        }


        node_initialized =
            true;


        // ====================================================
        // PUBLISHER:
        // /tyrant/heartbeat
        //
        // Type:
        // std_msgs/msg/UInt32
        // ====================================================

        if (
            
            !recordCreateResult(
                rclc_publisher_init_default(
                    &heartbeat_publisher,
                    &node,
                    ROSIDL_GET_MSG_TYPE_SUPPORT(
                    std_msgs,
                    msg,
                    UInt32
                ),
                "/tyrant/heartbeat"
                )
            )
            
        )
        {
            destroyEntities();

            return false;
        }


        heartbeat_pub_initialized =
            true;


        // ====================================================
        // PUBLISHER:
        // /tyrant/test_response
        //
        // Legacy communication diagnostic.
        // ====================================================

        #ifdef TYRANT_ENABLE_DIAGNOSTICS
        if (
            !recordCreateResult(
                rclc_publisher_init_default(
                    &response_publisher,
                    &node,
                    ROSIDL_GET_MSG_TYPE_SUPPORT(
                        std_msgs,
                        msg,
                        UInt32
                    ),
                    "/tyrant/test_response"
                )
            )
        )
        {
            destroyEntities();
            return false;
        }
        response_pub_initialized = true;
        #endif

        // ====================================================
        // PUBLISHER:
        // /tyrant/mode/status
        //
        // Custom Tyrant message.
        // ====================================================

        if (
            !recordCreateResult(
                rclc_publisher_init_default(
                    &mode_status_publisher,
                    &node,
                    ROSIDL_GET_MSG_TYPE_SUPPORT(
                        tyrant_interfaces,
                        msg,
                        ModeStatus
                    ),
                    "/tyrant/mode/status"
                )
            )
        )
        {
            destroyEntities();

            return false;
        }


        mode_status_pub_initialized =
            true;


        // ====================================================
        // PUBLISHER:
        // /tyrant/system/health
        //
        // Custom Tyrant health telemetry.
        // ====================================================

        if (
            !recordCreateResult(
                rclc_publisher_init_default(
                    &system_health_publisher,
                    &node,
                    ROSIDL_GET_MSG_TYPE_SUPPORT(
                        tyrant_interfaces,
                        msg,
                        SystemHealth
                    ),
                    "/tyrant/system/health"
                )
            )
            
        )
        {
            destroyEntities();

            return false;
        }
        system_health_pub_initialized =
            true;

        if (
            !recordCreateResult(
                rclc_publisher_init_default(
                    &imu_telemetry_publisher,
                    &node,
                    ROSIDL_GET_MSG_TYPE_SUPPORT(
                        tyrant_interfaces,
                        msg,
                        ImuTelemetry
                    ),
                    "/tyrant/sensors/imu"
                )
            )
        )
        {
            destroyEntities();

            return false;
        }

        imu_telemetry_pub_initialized =
            true;
        // ====================================================
        // PUBLISHER:
        // /tyrant/communication/diagnostics
        //
        // Custom Tyrant communication diagnostics.
        // ====================================================
        if (
            !recordCreateResult(
                rclc_publisher_init_default(
                    &pressure_telemetry_publisher,
                    &node,
                    ROSIDL_GET_MSG_TYPE_SUPPORT(
                        tyrant_interfaces,
                        msg,
                        PressureTelemetry
                    ),
                    "/tyrant/sensors/pressure"
                )
            )
        )
        {
            destroyEntities();

            return false;
        }
            pressure_telemetry_pub_initialized =
            true;
        if (
            !recordCreateResult(
                rclc_publisher_init_default(
                    &depth_reference_status_publisher,
                    &node,
                    ROSIDL_GET_MSG_TYPE_SUPPORT(
                        tyrant_interfaces,
                        msg,
                        DepthReferenceStatus
                    ),
                    "/tyrant/depth/reference/status"
                )
            )
        )
        {
            destroyEntities();

            return false;
        }

        depth_reference_status_pub_initialized =
            true;

        if (
            !recordCreateResult(
                rclc_publisher_init_default(
                    &communication_diagnostics_publisher,
                    &node,
                    ROSIDL_GET_MSG_TYPE_SUPPORT(
                        tyrant_interfaces,
                        msg,
                        CommunicationDiagnostics
                    ),
                    "/tyrant/communication/diagnostics"
                )
            )
        )
        {
            destroyEntities();

            return false;
        }
        


        communication_diagnostics_pub_initialized = true;

        // ====================================================
        // SUBSCRIBER:
        // /tyrant/test_command
        //
        // Legacy communication diagnostic.
        // ====================================================

       #ifdef TYRANT_ENABLE_DIAGNOSTICS
        if (
            !recordCreateResult(
                rclc_subscription_init_default(
                    &command_subscriber,
                    &node,
                    ROSIDL_GET_MSG_TYPE_SUPPORT(
                        std_msgs,
                        msg,
                        UInt32
                    ),
                    "/tyrant/test_command"
                )
            )
        )
        {
            destroyEntities();
            return false;
        }
        command_sub_initialized = true;
        #endif

        // ====================================================
        // SUBSCRIBER:
        // /tyrant/mode/request
        //
        // Custom Tyrant ModeRequest.
        // ====================================================

        if (
            !recordCreateResult(
                rclc_subscription_init_default(
                    &mode_request_subscriber,
                    &node,
                    ROSIDL_GET_MSG_TYPE_SUPPORT(
                        tyrant_interfaces,
                        msg,
                        ModeRequest
                    ),
                    "/tyrant/mode/request"
                )
            )
            
        )
        {
            destroyEntities();

            return false;
        }


        mode_request_sub_initialized =
            true;


        // ====================================================
        // SUBSCRIBER:
        // /tyrant/host_heartbeat
        // ====================================================

        if (
            !recordCreateResult(
                rclc_subscription_init_default(
                    &host_heartbeat_subscriber,
                    &node,
                    ROSIDL_GET_MSG_TYPE_SUPPORT(
                        std_msgs,
                        msg,
                        UInt32
                    ),
                    "/tyrant/host_heartbeat"
                )
            )
            
        )
        {
            destroyEntities();

            return false;
        }


        host_heartbeat_sub_initialized =
            true;
        if (
            !recordCreateResult(
                rclc_subscription_init_default(
                    &depth_reference_request_subscriber,
                    &node,
                    ROSIDL_GET_MSG_TYPE_SUPPORT(
                        tyrant_interfaces,
                        msg,
                        DepthReferenceRequest
                    ),
                    "/tyrant/depth/reference/request"
                )
            )
        )
        {
            destroyEntities();

            return false;
        }

        depth_reference_request_sub_initialized =
            true;

        // ====================================================
        // EXECUTOR
        //
        // Hanya subscriber yang memakai executor handle.
        //
        // Subscriber kita:
        //
        // 1. test_command
        // 2. ModeRequest
        // 3. host_heartbeat
        //
        // Maka handle count tetap = 3.
        // ====================================================

        executor =
            rclc_executor_get_zero_initialized_executor();


        if (
            !recordCreateResult(rclc_executor_init(
                &executor,
                &support.context,
                EXECUTOR_HANDLE_COUNT,
                &allocator
            )
            )
        )
        {
            destroyEntities();

            return false;
        }


        executor_initialized =
            true;


        // ====================================================
        // ADD TEST COMMAND SUBSCRIBER
        // ====================================================
        #ifdef TYRANT_ENABLE_DIAGNOSTICS
        if (
            !recordCreateResult(
                rclc_executor_add_subscription(
                    &executor,
                    &command_subscriber,
                    &command_msg,
                    &commandCallback,
                    ON_NEW_DATA
            )
            )
        )
        {
            destroyEntities();

            return false;
        }
        #endif 

        // ====================================================
        // ADD MODE REQUEST SUBSCRIBER
        // ====================================================

        if (
            !recordCreateResult(
                rclc_executor_add_subscription(
                    &executor,
                    &mode_request_subscriber,
                    &mode_request_msg,
                    &modeRequestCallback,
                    ON_NEW_DATA
                )
            )
        )
        {
            destroyEntities();

            return false;
        }


        // ====================================================
        // ADD HOST HEARTBEAT SUBSCRIBER
        // ====================================================

        if (
            !recordCreateResult(
                rclc_executor_add_subscription(
                    &executor,
                    &host_heartbeat_subscriber,
                    &host_heartbeat_msg,
                    &hostHeartbeatCallback,
                    ON_NEW_DATA
                )
            )
        )
        {
            destroyEntities();

            return false;
        }

        if (
            !recordCreateResult(
                rclc_executor_add_subscription(
                    &executor,
                    &depth_reference_request_subscriber,
                    &depth_reference_request_msg,
                    &depthReferenceRequestCallback,
                    ON_NEW_DATA
                )
            )
        )
        {
            destroyEntities();

            return false;
        }


        // ====================================================
        // INITIAL MESSAGE VALUES
        // ====================================================

        heartbeat_msg.data =
            0;

        #ifdef TYRANT_ENABLE_DIAGNOSTICS
        response_msg.data =
            0;
        #endif

        resetApplicationFlags();


        entities_ready =
            true;


        return true;


    }


    // ========================================================
    // DESTROY ALL ROS ENTITIES
    //
    // Dipanggil ketika Agent hilang.
    //
    // Setelah ini ConnectionManager dapat menunggu Agent baru
    // dan memanggil createEntities() lagi TANPA reset Teensy.
    // ========================================================

    void destroyEntities()
    {
        entities_ready =
            false;


        resetApplicationFlags();


        // ====================================================
        // JANGAN MENUNGGU REMOTE DESTROY JIKA AGENT SUDAH MATI
        // ====================================================

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


        // ====================================================
        // EXECUTOR
        //
        // Fini executor lebih dulu karena dia memegang
        // handle terhadap subscriber.
        // ====================================================

        if (executor_initialized)
        {
            consumeRet(
                rclc_executor_fini(
                    &executor
                )
            );


            executor_initialized =
                false;


            executor =
                rclc_executor_get_zero_initialized_executor();
        }


        // ====================================================
        // SUBSCRIBERS
        // ====================================================
        #ifdef TYRANT_ENABLE_DIAGNOSTICS
        if (command_sub_initialized)
        {
            consumeRet(
                rcl_subscription_fini(
                    &command_subscriber,
                    &node
                )
            );


            command_sub_initialized =
                false;


            command_subscriber =
                rcl_get_zero_initialized_subscription();
        }
        #endif

        if (mode_request_sub_initialized)
        {
            consumeRet(
                rcl_subscription_fini(
                    &mode_request_subscriber,
                    &node
                )
            );


            mode_request_sub_initialized =
                false;


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


            host_heartbeat_sub_initialized =
                false;


            host_heartbeat_subscriber =
                rcl_get_zero_initialized_subscription();
        }

        if (depth_reference_request_sub_initialized)
        {
            recordDestroyResult(
                rcl_subscription_fini(
                    &depth_reference_request_subscriber,
                    &node
                )
            );

            depth_reference_request_sub_initialized =
                false;

            depth_reference_request_subscriber =
                rcl_get_zero_initialized_subscription();
        }


        // ====================================================
        // PUBLISHERS
        // ====================================================

        if (heartbeat_pub_initialized)
        {
            consumeRet(
                rcl_publisher_fini(
                    &heartbeat_publisher,
                    &node
                )
            );


            heartbeat_pub_initialized =
                false;


            heartbeat_publisher =
                rcl_get_zero_initialized_publisher();
        }

        #ifdef TYRANT_ENABLE_DIAGNOSTICS
        if (response_pub_initialized)
        {
            consumeRet(
                rcl_publisher_fini(
                    &response_publisher,
                    &node
                )
            );


            response_pub_initialized =
                false;


            response_publisher =
                rcl_get_zero_initialized_publisher();
        }
        #endif

        if (mode_status_pub_initialized)
        {
            consumeRet(
                rcl_publisher_fini(
                    &mode_status_publisher,
                    &node
                )
            );


            mode_status_pub_initialized =
                false;


            mode_status_publisher =
                rcl_get_zero_initialized_publisher();
        }


        if (system_health_pub_initialized)
        {
            consumeRet(
                rcl_publisher_fini(
                    &system_health_publisher,
                    &node
                )
            );


            system_health_pub_initialized =
                false;


            system_health_publisher =
                rcl_get_zero_initialized_publisher();
        }

        if (
            imu_telemetry_pub_initialized
        )
        {
            recordDestroyResult(
                rcl_publisher_fini(
                    &imu_telemetry_publisher,
                    &node
                )
            );

            imu_telemetry_pub_initialized =
                false;

            imu_telemetry_publisher =
                rcl_get_zero_initialized_publisher();
        }
        if (
            pressure_telemetry_pub_initialized
        )
        {
            recordDestroyResult(
                rcl_publisher_fini(
                    &pressure_telemetry_publisher,
                    &node
                )
            );

            pressure_telemetry_pub_initialized =
                false;

            pressure_telemetry_publisher =
                rcl_get_zero_initialized_publisher();
        }

        if (depth_reference_status_pub_initialized)
        {
            recordDestroyResult(
                rcl_publisher_fini(
                    &depth_reference_status_publisher,
                    &node
                )
            );

            depth_reference_status_pub_initialized =
                false;

            depth_reference_status_publisher =
                rcl_get_zero_initialized_publisher();
        }

        if (communication_diagnostics_pub_initialized)
        {
            recordDestroyResult(
                rcl_publisher_fini(
                    &communication_diagnostics_publisher,
                    &node
                )
            );

            communication_diagnostics_pub_initialized =
                false;

            communication_diagnostics_publisher =
                rcl_get_zero_initialized_publisher();
        }


        // ====================================================
        // NODE
        // ====================================================

        if (node_initialized)
        {
            consumeRet(
                rcl_node_fini(
                    &node
                )
            );


            node_initialized =
                false;


            node =
                rcl_get_zero_initialized_node();
        }


        // ====================================================
        // SUPPORT / CONTEXT
        // ====================================================

        if (support_initialized)
        {
            consumeRet(
                rclc_support_fini(
                    &support
                )
            );


            support_initialized =
                false;


            support = {};
        }


        // ====================================================
        // CUSTOM MESSAGE MEMORY CLEANUP 
        // ====================================================

        if (system_health_msg_initialized)
        {
            tyrant_interfaces__msg__SystemHealth__fini(
                &system_health_msg
            );


            system_health_msg_initialized =
                false;
        }


        if (mode_status_msg_initialized)
        {
            tyrant_interfaces__msg__ModeStatus__fini(
                &mode_status_msg
            );


            mode_status_msg_initialized =
                false;
        }


        if (mode_request_msg_initialized)
        {
            tyrant_interfaces__msg__ModeRequest__fini(
                &mode_request_msg
            );


            mode_request_msg_initialized =
                false;
        }
        
        if (
            imu_telemetry_msg_initialized
        )
        {
            tyrant_interfaces__msg__ImuTelemetry__fini(
                &imu_telemetry_msg
            );

            imu_telemetry_msg_initialized =
                false;
        }

        if (
            pressure_telemetry_msg_initialized
        )
        {
            tyrant_interfaces__msg__PressureTelemetry__fini(
                &pressure_msg
            );

            pressure_telemetry_msg_initialized =
                false;
        }

        if (communication_diagnostics_msg_initialized)
        {
            tyrant_interfaces__msg__CommunicationDiagnostics__fini(
                &communication_diagnostics_msg
            );

            communication_diagnostics_msg_initialized =
                false;
        }
        if (depth_reference_request_msg_initialized)
        {
            tyrant_interfaces__msg__DepthReferenceRequest__fini(
                &depth_reference_request_msg
            );

            depth_reference_request_msg_initialized =
                false;
        }


        if (depth_reference_status_msg_initialized)
        {
            tyrant_interfaces__msg__DepthReferenceStatus__fini(
                &depth_reference_status_msg
            );

            depth_reference_status_msg_initialized =
                false;
        }


    }


    // ========================================================
    // ENTITY STATE
    // ========================================================

    bool entitiesReady()
    {
        return entities_ready;
    }


    // ========================================================
    // PROCESS INCOMING ROS DATA
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


        recordExecutorResult(ret);
    }


    // ========================================================
    // PUBLISH TEENSY HEARTBEAT
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


        recordPublishResult(ret);
    }


    // ========================================================
    // LEGACY TEST RESPONSE
    // ========================================================
    #ifdef TYRANT_ENABLE_DIAGNOSTICS
    void publishResponse(
        uint32_t value
    )
    {
        if (!entities_ready)
        {
            return;
        }


        response_msg.data =
            value;


        const rcl_ret_t ret =
            rcl_publish(
                &response_publisher,
                &response_msg,
                nullptr
            );


        recordPublishResult(ret);
    }
    #endif

    // ========================================================
    // PUBLISH CUSTOM MODE STATUS
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


        // ----------------------------------------------------
        // Timestamp
        //
        // Masih 0 karena ROS time synchronization
        // belum kita implementasikan.
        // ----------------------------------------------------

        mode_status_msg.header.stamp.sec =
            0;


        mode_status_msg.header.stamp.nanosec =
            0;


        // frame_id dibiarkan empty string.


        // ----------------------------------------------------
        // Request correlation
        // ----------------------------------------------------

        mode_status_msg.request_id =
            request_id;


        // ----------------------------------------------------
        // Vehicle mode
        // ----------------------------------------------------

        mode_status_msg.current_mode =
            current_mode;


        mode_status_msg.requested_mode =
            requested_mode;


        // ----------------------------------------------------
        // Request result
        // ----------------------------------------------------

        mode_status_msg.request_accepted =
            request_accepted;


        mode_status_msg.reason =
            reason;


        // ----------------------------------------------------
        // Safety information
        // ----------------------------------------------------

        mode_status_msg.communication_healthy =
            communication_healthy;


        mode_status_msg.propulsion_allowed =
            propulsion_allowed;


        // ----------------------------------------------------
        // Publish
        // ----------------------------------------------------

        const rcl_ret_t ret =
            rcl_publish(
                &mode_status_publisher,
                &mode_status_msg,
                nullptr
            );


        recordPublishResult(ret);
    }


    // ========================================================
    // PUBLISH SYSTEM HEALTH
    // ========================================================

    void publishSystemHealth(
        bool communication_healthy,
        bool autonomy_ready,
        bool propulsion_allowed,
        uint8_t current_mode,
        uint32_t host_heartbeat_age_ms
    )
    {
        if (!entities_ready)
        {
            return;
        }


        system_health_msg.communication_healthy =
            communication_healthy;


        system_health_msg.autonomy_ready =
            autonomy_ready;


        system_health_msg.propulsion_allowed =
            propulsion_allowed;


        system_health_msg.current_mode =
            current_mode;


        system_health_msg.host_heartbeat_age_ms =
            host_heartbeat_age_ms;


        const rcl_ret_t ret =
            rcl_publish(
                &system_health_publisher,
                &system_health_msg,
                nullptr
            );


        recordPublishResult(ret);
    }
    
    // ========================================================
    // PUBLISH IMU TELEMETRY
    // ========================================================   
    
    void publishImuTelemetry(
        uint8_t sensor_state,
        uint32_t sequence,
        uint64_t timestamp_us,

        float accel_x,
        float accel_y,
        float accel_z,

        float gyro_x,
        float gyro_y,
        float gyro_z,

        bool valid,

        uint32_t bytes_received,
        uint32_t register_updates,
        uint32_t samples_produced,
        uint32_t error_count
    )
    {
        if (!entities_ready)
        {
            return;
        }


        imu_telemetry_msg.sensor_state =
            sensor_state;

        imu_telemetry_msg.sequence =
            sequence;

        imu_telemetry_msg.timestamp_us =
            timestamp_us;


        imu_telemetry_msg.accel_x =
            accel_x;

        imu_telemetry_msg.accel_y =
            accel_y;

        imu_telemetry_msg.accel_z =
            accel_z;


        imu_telemetry_msg.gyro_x =
            gyro_x;

        imu_telemetry_msg.gyro_y =
            gyro_y;

        imu_telemetry_msg.gyro_z =
            gyro_z;


        imu_telemetry_msg.valid =
            valid;


        imu_telemetry_msg.bytes_received =
            bytes_received;

        imu_telemetry_msg.register_updates =
            register_updates;

        imu_telemetry_msg.samples_produced =
            samples_produced;

        imu_telemetry_msg.error_count =
            error_count;


        const rcl_ret_t ret =
            rcl_publish(
                &imu_telemetry_publisher,
                &imu_telemetry_msg,
                nullptr
            );


        recordPublishResult(ret);
}
    // ========================================================
    // PUBLISH PRESSURE TELEMETRY
    // ========================================================

    void publishPressureTelemetry(
        uint8_t sensor_state,
        uint32_t sequence,
        uint64_t timestamp_us,

        float pressure_pa,
        float temperature_c,

        bool valid,

        uint32_t read_attempts,
        uint32_t read_successes,
        uint32_t samples_produced,
        uint32_t error_count
    )
    {
        if (!entities_ready)
        {
            return;
        }


        pressure_msg.sensor_state =
            sensor_state;

        pressure_msg.sequence =
            sequence;

        pressure_msg.timestamp_us =
            timestamp_us;


        pressure_msg.pressure_pa =
            pressure_pa;

        pressure_msg.temperature_c =
            temperature_c;


        pressure_msg.valid =
            valid;


        pressure_msg.read_attempts =
            read_attempts;

        pressure_msg.read_successes =
            read_successes;

        pressure_msg.samples_produced =
            samples_produced;

        pressure_msg.error_count =
            error_count;


        const rcl_ret_t ret =
            rcl_publish(
                &pressure_telemetry_publisher,
                &pressure_msg,
                nullptr
            );


        recordPublishResult(ret);
    }
    // ========================================================
    // PUBLISH DEPTH REFERENCE STATUS
    // ========================================================
    void publishDepthReferenceStatus(
        uint32_t request_id,
        uint8_t command,
        bool accepted,
        uint8_t reason,
        bool reference_valid,
        float surface_pressure_pa
    )
    {
        if (!entities_ready)
        {
            return;
        }


        depth_reference_status_msg.request_id =
            request_id;


        depth_reference_status_msg.command =
            command;


        depth_reference_status_msg.accepted =
            accepted;


        depth_reference_status_msg.reason =
            reason;


        depth_reference_status_msg.reference_valid =
            reference_valid;


        depth_reference_status_msg.surface_pressure_pa =
            surface_pressure_pa;


        const rcl_ret_t ret =
            rcl_publish(
                &depth_reference_status_publisher,
                &depth_reference_status_msg,
                nullptr
            );


        recordPublishResult(ret);
    }
    // ========================================================
    // PUBLISH Communication Diagnostics
    // ========================================================
    void publishCommunicationDiagnostics(
        uint8_t connection_state,
        uint32_t connection_count,
        uint32_t disconnect_count,
        uint32_t reconnect_count,
        uint32_t publish_failure_count,
        uint32_t executor_failure_count,
        uint32_t entity_create_failure_count,
        uint32_t entity_destroy_failure_count
    )
    {
        if (!entities_ready)
        {
            return;
        }

        communication_diagnostics_msg.connection_state =
            connection_state;

        communication_diagnostics_msg.connection_count =
            connection_count;

        communication_diagnostics_msg.disconnect_count =
            disconnect_count;

        communication_diagnostics_msg.reconnect_count =
            reconnect_count;

        communication_diagnostics_msg.publish_failures =
            publish_failure_count;

        communication_diagnostics_msg.executor_failures =
            executor_failure_count;

        communication_diagnostics_msg.entity_create_failures =
            entity_create_failure_count;

        communication_diagnostics_msg.entity_destroy_failures =
            entity_destroy_failure_count;


        const rcl_ret_t ret =
            rcl_publish(
                &communication_diagnostics_publisher,
                &communication_diagnostics_msg,
                nullptr
            );

        recordPublishResult(ret);
    }

    //==================================//Implementation//===============================================//

    // ========================================================
    // COMMUNICATION ERROR STATISTICS
    // ========================================================

    ErrorStats getErrorStats()
    {
        return {
            publish_failures,
            executor_failures,
            entity_create_failures,
            entity_destroy_failures
        };
    }
 
    // ========================================================
    // LEGACY TEST COMMAND
    // ========================================================
    #ifdef TYRANT_ENABLE_DIAGNOSTICS
    bool hasNewCommand()
    {
        return new_command;
    }

    uint32_t getLastCommand()
    {
        new_command =
            false;


        return last_command;
    }
    #endif

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


        new_mode_request =
            false;


        return true;
    }
    // ========================================================
    // CUSTOM DEPTH REFERENCE REQUEST
    // ========================================================
    bool takeDepthReferenceRequest(
        DepthReferenceRequestData &request
    )
    {
        if (!new_depth_reference_request)
        {
            return false;
        }


        request.request_id =
            depth_reference_request_id;


        request.command =
            depth_reference_command;


        new_depth_reference_request =
            false;


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
        new_host_heartbeat =
            false;


        return host_heartbeat_value;
    }
}
