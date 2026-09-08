#pragma once

#include <Arduino.h>

namespace TyrantSafety
{
    void init();

    void update();

    void notifyHostHeartbeat();

    bool requestMode(uint8_t requested_mode);

    uint8_t getMode();

    bool communicationHealthy();

    bool systemHealthy();

    bool autonomyReady();

    bool propulsionAllowed();
}
