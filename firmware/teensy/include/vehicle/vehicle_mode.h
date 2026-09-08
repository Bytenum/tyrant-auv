#pragma once

#include <Arduino.h>

namespace TyrantVehicle
{
    enum class Mode : uint8_t
    {
        BOOT = 0,
        IDLE = 1,
        MANUAL = 2,
        AUTO = 3,
        SAFE = 4,
        FAULT = 5,
        EMERGENCY = 6
    };

    void init();

    void completeBoot(bool initialization_ok);

    bool requestMode(
        Mode requested_mode,
        bool system_healthy,
        bool autonomy_ready
    );

    void forceSafe();

    void forceFault();

    void forceEmergency();

    Mode getMode();
}
