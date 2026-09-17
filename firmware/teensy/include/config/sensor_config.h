#pragma once

#include <Arduino.h>


namespace TyrantSensorConfig
{
    // ========================================================
    // HWT905 UART
    //
    // IMPORTANT:
    // Values below must match the real Main Board wiring
    // and HWT905 configuration.
    // ========================================================

    constexpr uint32_t HWT905_BAUD =
        9600;


    // ========================================================
    // SENSOR FRESHNESS
    //
    // Provisional bring-up value.
    // We will tune this after confirming the actual
    // HWT905 output rate.
    // ========================================================

    constexpr uint64_t IMU_STALE_TIMEOUT_US =
        500000ULL;
    
    constexpr uint32_t PRESSURE_STALE_TIMEOUT_US =
    1000000;
}
