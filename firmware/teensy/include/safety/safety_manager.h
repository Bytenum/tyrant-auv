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

    // Returns true when safety logic changes vehicle mode.
    bool update();

    void notifyHostHeartbeat();

    ModeRequestResult requestMode(
        uint8_t requested_mode
    );

    uint8_t getMode();

    bool communicationHealthy();
    bool systemHealthy();
    bool autonomyReady();

    bool propulsionAllowed();
}
