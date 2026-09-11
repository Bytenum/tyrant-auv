#include "sensors/sensor_manager.h"


namespace
{
    TyrantSensors::ImuSample latest_imu {};

    TyrantSensors::PressureSample latest_pressure {};


    TyrantSensors::SensorHealth imu_health {
        TyrantSensors::SensorState::NOT_INITIALIZED,
        0,
        0,
        0,
        false
    };


    TyrantSensors::SensorHealth pressure_health {
        TyrantSensors::SensorState::NOT_INITIALIZED,
        0,
        0,
        0,
        false
    };


    bool imu_sample_available = false;

    bool pressure_sample_available = false;
}


namespace TyrantSensors
{
    void init()
    {
        latest_imu = {};

        latest_pressure = {};


        imu_health = {
            SensorState::NOT_INITIALIZED,
            0,
            0,
            0,
            false
        };


        pressure_health = {
            SensorState::NOT_INITIALIZED,
            0,
            0,
            0,
            false
        };


        imu_sample_available = false;

        pressure_sample_available = false;


        // Hardware drivers will be initialized here
        // during Phase 3.2 and 3.3.
    }


    void update()
    {
        // ====================================================
        // FUTURE PHASE 3.2
        //
        // IMU driver polling / sample acquisition
        // ====================================================


        // ====================================================
        // FUTURE PHASE 3.3
        //
        // Pressure sensor polling / acquisition
        // ====================================================


        // IMPORTANT:
        //
        // Do NOT fabricate valid sensor data here.
        //
        // Until a real driver has provided a valid sample,
        // sensor health must remain NOT_INITIALIZED / invalid.
    }


    bool getLatestImu(
        ImuSample &sample
    )
    {
        if (!imu_sample_available)
        {
            return false;
        }

        if (!latest_imu.valid)
        {
            return false;
        }

        sample = latest_imu;

        return true;
    }


    bool getLatestPressure(
        PressureSample &sample
    )
    {
        if (!pressure_sample_available)
        {
            return false;
        }

        if (!latest_pressure.valid)
        {
            return false;
        }

        sample = latest_pressure;

        return true;
    }


    SensorHealth getImuHealth()
    {
        return imu_health;
    }


    SensorHealth getPressureHealth()
    {
        return pressure_health;
    }


    bool imuHealthy()
    {
        return (
            imu_health.state ==
                SensorState::READY &&
            imu_health.valid
        );
    }


    bool pressureHealthy()
    {
        return (
            pressure_health.state ==
                SensorState::READY &&
            pressure_health.valid
        );
    }


    bool requiredSensorsHealthy()
    {
        return (
            imuHealthy() &&
            pressureHealthy()
        );
    }
}

