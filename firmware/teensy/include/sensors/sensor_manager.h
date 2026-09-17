#pragma once

#include <Arduino.h>

#include "sensors/sensor_types.h"
#include "sensors/imu_source.h"
#include "sensors/pressure_source.h"

namespace TyrantSensors
{
    // ========================================================
    // LIFECYCLE
    // ========================================================
    void setImuSource(
        ImuSource &source
    );

    void setPressureSource(
        PressureSource &source
    );

    void init();

    void update();


    // ========================================================
    // SAMPLE ACCESS
    // ========================================================

    bool getLatestImu(
        ImuSample &sample
    );

    bool getLatestPressure(
        PressureSample &sample
    );


    // ========================================================
    // HEALTH ACCESS
    // ========================================================

    SensorHealth getImuHealth();
    uint32_t getImuBytesReceived();
    uint32_t getImuRegisterUpdates();
    uint32_t getImuSamplesProduced();

    SensorHealth getPressureHealth();
    uint32_t getPressureReadAttempts();
    uint32_t getPressureReadSuccesses();
    uint32_t getPressureSamplesProduced();

    // ========================================================
    // READINESS
    // ========================================================

    bool imuHealthy();

    bool pressureHealthy();

    bool requiredSensorsHealthy();
}
