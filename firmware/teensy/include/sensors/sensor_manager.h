#pragma once

#include <Arduino.h>

#include "sensors/sensor_types.h"


namespace TyrantSensors
{
    // ========================================================
    // LIFECYCLE
    // ========================================================

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

    SensorHealth getPressureHealth();


    // ========================================================
    // READINESS
    // ========================================================

    bool imuHealthy();

    bool pressureHealthy();

    bool requiredSensorsHealthy();
}
