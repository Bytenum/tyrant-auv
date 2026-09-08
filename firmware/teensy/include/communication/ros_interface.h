#pragma once

#include <Arduino.h>

namespace TyrantROS
{
    struct ModeRequestData
    {
        uint32_t request_id;
        uint8_t requested_mode;
    };


    // ========================================================
    // CONNECTION LIFECYCLE
    // ========================================================

    void setupTransport();

    bool pingAgent(
        uint32_t timeout_ms,
        uint8_t attempts
    );

    bool createEntities();

    void destroyEntities();

    bool entitiesReady();

    void spin();


    // ========================================================
    // APPLICATION COMMUNICATION
    // ========================================================

    void publishHeartbeat();

    void publishResponse(
        uint32_t value
    );

    void publishModeStatus(
        uint32_t request_id,
        uint8_t current_mode,
        uint8_t requested_mode,
        bool request_accepted,
        uint8_t reason,
        bool communication_healthy,
        bool propulsion_allowed
    );


    // Legacy diagnostic
    bool hasNewCommand();

    uint32_t getLastCommand();


    // Production mode request
    bool takeModeRequest(
        ModeRequestData &request
    );


    // Host health
    bool hasNewHostHeartbeat();

    uint32_t getHostHeartbeatValue();
}
