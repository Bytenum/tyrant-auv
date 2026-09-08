#pragma once

#include <Arduino.h>

namespace TyrantSafety
{
    struct ModeRequestResult
    {
        bool accepted;
        uint8_t reason;
    };

    void init();

    void update();

    void setTransportConnected(bool connected);

    void notifyHostHeartbeat();

    ModeRequestResult requestMode(
        uint8_t requested_mode
    );

    uint8_t getMode();

    bool transportConnected();

    bool communicationHealthy();

    bool systemHealthy();

    bool autonomyReady();

    bool propulsionAllowed();

    // Internal mode changes such as:
    // communication loss -> SAFE
    bool takeInternalModeEvent(
        uint8_t &reason
    );
}
