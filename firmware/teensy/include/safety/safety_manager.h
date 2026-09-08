#pragma once

#include <Arduino.h>

namespace TyrantSafety
{
    void init();

    void update();

    void setTransportConnected(bool connected);

    void notifyHostHeartbeat();

    bool requestMode(uint8_t requested_mode);

    uint8_t getMode();

    bool transportConnected();

    bool communicationHealthy();

    bool systemHealthy();

    bool autonomyReady();

    bool propulsionAllowed();
}
