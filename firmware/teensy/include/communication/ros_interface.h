#pragma once

#include <Arduino.h>

namespace TyrantROS
{
    struct ModeRequestData
    {
        uint32_t request_id;
        uint8_t requested_mode;
    };

    bool init();

    void spin();

    void publishHeartbeat();

    void publishResponse(uint32_t value);

    void publishModeStatus(
        uint32_t request_id,
        uint8_t current_mode,
        uint8_t requested_mode,
        bool request_accepted,
        uint8_t reason,
        bool communication_healthy,
        bool propulsion_allowed
    );

    bool hasNewCommand();
    uint32_t getLastCommand();

    bool takeModeRequest(
        ModeRequestData &request
    );

    bool hasNewHostHeartbeat();
    uint32_t getHostHeartbeatValue();
}
