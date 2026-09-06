#include <Arduino.h>
#include <micro_ros_platformio.h>

#include <rcl/rcl.h>
#include <rclc/rclc.h>

#include <std_msgs/msg/u_int32.h>

rcl_publisher_t publisher;
rcl_node_t node;
rclc_support_t support;
rcl_allocator_t allocator;

std_msgs__msg__UInt32 heartbeat_msg;

unsigned long last_publish_ms = 0;

void setup()
{
    Serial.begin(115200);

    delay(2000);

    set_microros_serial_transports(Serial);

    allocator = rcl_get_default_allocator();

    rclc_support_init(
        &support,
        0,
        nullptr,
        &allocator
    );

    rclc_node_init_default(
        &node,
        "tyrant_teensy",
        "",
        &support
    );

    rclc_publisher_init_default(
        &publisher,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, UInt32),
        "/tyrant/heartbeat"
    );

    heartbeat_msg.data = 0;
}

void loop()
{
    const unsigned long now = millis();

    if (now - last_publish_ms >= 1000)
    {
        heartbeat_msg.data++;

        rcl_publish(
            &publisher,
            &heartbeat_msg,
            nullptr
        );

        last_publish_ms = now;
    }

    delay(10);
}
