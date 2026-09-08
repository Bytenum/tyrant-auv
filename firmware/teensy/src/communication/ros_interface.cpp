#include "communication/ros_interface.h"

#include <micro_ros_platformio.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>

#include <std_msgs/msg/u_int32.h>
#include <std_msgs/msg/u_int8.h>

namespace
{
    // ========================================================
    // ROS CORE
    // ========================================================

    rcl_node_t node;

    rclc_support_t support;
    rcl_allocator_t allocator;
    rclc_executor_t executor;


    // ========================================================
    // PUBLISHERS
    // ========================================================

    rcl_publisher_t heartbeat_publisher;
    rcl_publisher_t response_publisher;
    rcl_publisher_t mode_status_publisher;


    // ========================================================
    // SUBSCRIBERS
    // ========================================================

    rcl_subscription_t command_subscriber;
    rcl_subscription_t mode_request_subscriber;
    rcl_subscription_t host_heartbeat_subscriber;


    // ========================================================
    // MESSAGE STORAGE
    // ========================================================

    std_msgs__msg__UInt32 heartbeat_msg;
    std_msgs__msg__UInt32 response_msg;
    std_msgs__msg__UInt32 command_msg;
    std_msgs__msg__UInt32 host_heartbeat_msg;

    std_msgs__msg__UInt8 mode_request_msg;
    std_msgs__msg__UInt8 mode_status_msg;


    // ========================================================
    // INTERNAL FLAGS
    // ========================================================

    bool new_command = false;
    uint32_t last_command = 0;

    bool new_mode_request = false;
    uint8_t requested_mode = 0;

    bool new_host_heartbeat = false;
    uint32_t host_heartbeat_value = 0;


    // ========================================================
    // CALLBACKS
    // ========================================================

    void commandCallback(const void *msgin)
    {
        const auto *received_msg =
            static_cast<const std_msgs__msg__UInt32 *>(
                msgin
            );

        last_command = received_msg->data;
        new_command = true;
    }

    void modeRequestCallback(const void *msgin)
    {
        const auto *received_msg =
            static_cast<const std_msgs__msg__UInt8 *>(
                msgin
            );

        requested_mode = received_msg->data;
        new_mode_request = true;
    }

    void hostHeartbeatCallback(const void *msgin)
    {
        const auto *received_msg =
            static_cast<const std_msgs__msg__UInt32 *>(
                msgin
            );

        host_heartbeat_value = received_msg->data;
        new_host_heartbeat = true;
    }
}


namespace TyrantROS
{
    bool init()
    {
        Serial.begin(115200);

        delay(2000);

        set_microros_serial_transports(Serial);

        allocator = rcl_get_default_allocator();


        // ====================================================
        // SUPPORT
        // ====================================================

        if (
            rclc_support_init(
                &support,
                0,
                nullptr,
                &allocator
            ) != RCL_RET_OK
        )
        {
            return false;
        }


        // ====================================================
        // NODE
        // ====================================================

        if (
            rclc_node_init_default(
                &node,
                "tyrant_teensy",
                "",
                &support
            ) != RCL_RET_OK
        )
        {
            return false;
        }


        // ====================================================
        // HEARTBEAT PUBLISHER
        // ====================================================

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
            return false;
        }


        // ====================================================
        // TEST RESPONSE PUBLISHER
        // ====================================================

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
            return false;
        }


        // ====================================================
        // MODE STATUS PUBLISHER
        // ====================================================

        if (
            rclc_publisher_init_default(
                &mode_status_publisher,
                &node,
                ROSIDL_GET_MSG_TYPE_SUPPORT(
                    std_msgs,
                    msg,
                    UInt8
                ),
                "/tyrant/mode/status"
            ) != RCL_RET_OK
        )
        {
            return false;
        }


        // ====================================================
        // TEST COMMAND SUBSCRIBER
        // ====================================================

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
            return false;
        }


        // ====================================================
        // MODE REQUEST SUBSCRIBER
        // ====================================================

        if (
            rclc_subscription_init_default(
                &mode_request_subscriber,
                &node,
                ROSIDL_GET_MSG_TYPE_SUPPORT(
                    std_msgs,
                    msg,
                    UInt8
                ),
                "/tyrant/mode/request"
            ) != RCL_RET_OK
        )
        {
            return false;
        }


        // ====================================================
        // HOST HEARTBEAT SUBSCRIBER
        // ====================================================

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
            return false;
        }


        // ====================================================
        // EXECUTOR
        //
        // Three subscriber handles:
        //
        // 1. test command
        // 2. mode request
        // 3. host heartbeat
        // ====================================================

        if (
            rclc_executor_init(
                &executor,
                &support.context,
                3,
                &allocator
            ) != RCL_RET_OK
        )
        {
            return false;
        }


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
            return false;
        }


        heartbeat_msg.data = 0;
        response_msg.data = 0;
        mode_status_msg.data = 0;

        return true;
    }


    void spin()
    {
        rclc_executor_spin_some(
            &executor,
            RCL_MS_TO_NS(5)
        );
    }


    void publishHeartbeat()
    {
        heartbeat_msg.data++;

        const rcl_ret_t ret =
            rcl_publish(
                &heartbeat_publisher,
                &heartbeat_msg,
                nullptr
            );

        (void)ret;
    }


    void publishResponse(uint32_t value)
    {
        response_msg.data = value;

        const rcl_ret_t ret =
            rcl_publish(
                &response_publisher,
                &response_msg,
                nullptr
            );

        (void)ret;
    }


    void publishModeStatus(uint8_t mode)
    {
        mode_status_msg.data = mode;

        const rcl_ret_t ret =
            rcl_publish(
                &mode_status_publisher,
                &mode_status_msg,
                nullptr
            );

        (void)ret;
    }


    bool hasNewCommand()
    {
        return new_command;
    }


    uint32_t getLastCommand()
    {
        new_command = false;

        return last_command;
    }


    bool hasModeRequest()
    {
        return new_mode_request;
    }


    uint8_t getRequestedMode()
    {
        new_mode_request = false;

        return requested_mode;
    }


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
