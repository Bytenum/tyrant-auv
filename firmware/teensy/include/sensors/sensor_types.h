#pragma once

#include <Arduino.h>


namespace TyrantSensors
{
    // ========================================================
    // SENSOR STATE
    // ========================================================

    enum class SensorState : uint8_t
    {
        NOT_INITIALIZED = 0,
        INITIALIZING    = 1,
        READY           = 2,
        STALE           = 3,
        ERROR           = 4
    };


    // ========================================================
    // IMU SAMPLE
    //
    // Body-frame raw/conditioned measurements.
    //
    // Units:
    // acceleration : m/s^2
    // angular rate : rad/s
    // timestamp    : microseconds since MCU boot
    // ========================================================

    struct ImuSample
    {
        uint32_t sequence;

        uint64_t timestamp_us;

        float accel_x;
        float accel_y;
        float accel_z;

        float gyro_x;
        float gyro_y;
        float gyro_z;

        bool valid;
    };


    // ========================================================
    // PRESSURE SAMPLE
    //
    // Driver-level pressure measurement.
    //
    // Depth itself should be calculated using a known
    // reference pressure / fluid-density model rather than
    // hidden inside a low-level hardware driver.
    // ========================================================

    struct PressureSample
    {
        uint32_t sequence;

        uint64_t timestamp_us;

        float pressure_pa;

        float temperature_c;

        bool valid;
    };


    // ========================================================
    // GENERIC SENSOR HEALTH
    // ========================================================

    struct SensorHealth
    {
        SensorState state;

        uint32_t sample_count;

        uint32_t error_count;

        uint64_t last_update_us;

        bool valid;
    };
}
