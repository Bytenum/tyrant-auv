#pragma once

#include <Arduino.h>

namespace TyrantROS
{
    bool init();

    void spin();

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
