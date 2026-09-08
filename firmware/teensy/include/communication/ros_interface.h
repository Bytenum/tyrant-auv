#pragma once

#include <Arduino.h>

namespace TyrantROS
{
    // Configure physical micro-ROS transport once.
    void setupTransport();

    // Agent/session lifecycle.
    bool pingAgent(
        uint32_t timeout_ms,
        uint8_t attempts
    );

    bool createEntities();

    void destroyEntities();

    bool entitiesReady();

    // Process incoming messages.
    void spin();


    // --------------------------------------------------------
    // Existing application API
    // --------------------------------------------------------

    void publishHeartbeat();

    void publishResponse(uint32_t value);

    void publishModeStatus(uint8_t mode);

    bool hasNewCommand();

    uint32_t getLastCommand();

    bool hasModeRequest();

    uint8_t getRequestedMode();

    bool hasNewHostHeartbeat();

    uint32_t getHostHeartbeatValue();
}
