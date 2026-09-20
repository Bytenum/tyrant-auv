#include "sensors/sensor_manager.h"

#include <Arduino.h>

#include "config/sensor_config.h"

#include "sensors/depth_estimator.h"

namespace
{
    TyrantSensors::DepthEstimator
        depth_estimator;


    TyrantSensors::DepthMeasurement
        latest_depth {};


    bool depth_measurement_available =
        false;

    TyrantSensors::ImuSource *imu_source =
        nullptr;

    TyrantSensors::PressureSource *pressure_source =
        nullptr;


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


    bool imu_sample_available =
        false;

    bool pressure_sample_available =
        false;
}


namespace TyrantSensors
{
    bool setDepthSurfaceReference()
    {
        if (
            pressure_health.state !=
                SensorState::READY
        )
        {
            return false;
        }


        if (
            !pressure_health.valid ||
            !latest_pressure.valid
        )
        {
            return false;
        }


        if (
            !depth_estimator.setSurfacePressure(
                latest_pressure.pressure_pa
            )
        )
        {
            return false;
        }


        DepthMeasurement measurement {};


        depth_estimator.estimateMeasurement(
            latest_pressure,
            measurement
        );


        latest_depth =
            measurement;


        depth_measurement_available =
            true;


        return true;
    }


    void clearDepthSurfaceReference()
    {
        depth_estimator.clearSurfaceReference();


        latest_depth.depth_m =
            0.0f;

        latest_depth.valid =
            false;


        depth_measurement_available =
            true;
    }


    bool depthSurfaceReferenceValid()
    {
        return depth_estimator
            .surfaceReferenceValid();
    }


    bool getLatestDepth(
        DepthMeasurement &measurement
    )
    {
        if (!depth_measurement_available)
        {
            return false;
        }


        measurement =
            latest_depth;


        depth_measurement_available =
            false;


        return true;
    }

    void setImuSource(
        ImuSource &source
    )
    {
        imu_source =
            &source;
    }


    void setPressureSource(
        PressureSource &source
    )
    {
        pressure_source =
            &source;
    }


    void init()
    {
        /*
         * Reset cached samples.
         */
        latest_imu =
            ImuSample {};

        latest_pressure =
            PressureSample {};


        imu_sample_available =
            false;

        pressure_sample_available =
            false;
        latest_depth = {};

        depth_measurement_available =
            false;

        depth_estimator.clearSurfaceReference();

        /*
         * Reset health state.
         */
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


        /*
         * Initialize IMU source.
         */
        if (imu_source == nullptr)
        {
            imu_health.state =
                SensorState::ERROR;

            imu_health.error_count++;

            imu_health.valid =
                false;
        }
        else
        {
            imu_health.state =
                SensorState::INITIALIZING;

            if (!imu_source->begin())
            {
                imu_health.state =
                    SensorState::ERROR;

                imu_health.error_count++;

                imu_health.valid =
                    false;
            }
        }


        /*
         * Initialize pressure source.
         */
        if (pressure_source == nullptr)
        {
            pressure_health.state =
                SensorState::ERROR;

            pressure_health.error_count++;

            pressure_health.valid =
                false;
        }
        else
        {
            pressure_health.state =
                SensorState::INITIALIZING;

            if (!pressure_source->begin())
            {
                pressure_health.state =
                    SensorState::ERROR;

                pressure_health.error_count++;

                pressure_health.valid =
                    false;
            }
        }
    }


    void update()
    {
        /*
         * =========================
         * IMU
         * =========================
         */
        if (imu_source != nullptr)
        {
            imu_source->update();


            ImuSample new_imu_sample {};


            if (
                imu_source->takeSample(
                    new_imu_sample
                )
            )
            {
                latest_imu =
                    new_imu_sample;

                imu_sample_available =
                    true;


                imu_health.state =
                    SensorState::READY;

                imu_health.sample_count++;

                imu_health.last_update_us =
                    new_imu_sample.timestamp_us;

                imu_health.valid =
                    new_imu_sample.valid;
            }
        }


        /*
         * IMU stale detection.
         *
         * micros() is a 32-bit counter.
         * Unsigned subtraction keeps this
         * wrap-safe.
         */
        if (
            imu_health.state ==
                SensorState::READY
        )
        {
            const uint32_t now_us =
                micros();

            const uint32_t last_update_us =
                static_cast<uint32_t>(
                    imu_health.last_update_us
                );

            const uint32_t age_us =
                now_us -
                last_update_us;


            if (
                age_us >
                TyrantSensorConfig::
                    IMU_STALE_TIMEOUT_US
            )
            {
                imu_health.state =
                    SensorState::STALE;

                imu_health.valid =
                    false;
            }
        }


        /*
         * =========================
         * PRESSURE
         * =========================
         */
        if (pressure_source != nullptr)
        {
            pressure_source->update();


            PressureSample new_pressure_sample {};


            if (
                pressure_source->takeSample(
                    new_pressure_sample
                )
            )
            {
                latest_pressure =
                    new_pressure_sample;

                pressure_sample_available =
                    true;


                pressure_health.state =
                    SensorState::READY;

                pressure_health.sample_count++;

                pressure_health.last_update_us =
                    new_pressure_sample.timestamp_us;

                pressure_health.valid =
                    new_pressure_sample.valid;

                DepthMeasurement new_depth {};
                depth_estimator.estimateMeasurement(
                    new_pressure_sample,
                    new_depth
                );


                latest_depth =
                    new_depth;


                depth_measurement_available =
                    true;
            }
        }


        /*
         * Pressure stale detection.
         */
        if (
            pressure_health.state ==
                SensorState::READY
        )
        {
            const uint32_t now_us =
                micros();

            const uint32_t last_update_us =
                static_cast<uint32_t>(
                    pressure_health.last_update_us
                );

            const uint32_t age_us =
                now_us -
                last_update_us;


            if (
                age_us >
                TyrantSensorConfig::
                    PRESSURE_STALE_TIMEOUT_US
            )
            {
                pressure_health.state =
                    SensorState::STALE;
                pressure_health.valid =
                    false;
                latest_depth.valid =
                    false;
                depth_measurement_available =
                    true;
            }
        }
    }


    bool getLatestImu(
        ImuSample &sample
    )
    {
        if (!imu_sample_available)
        {
            return false;
        }


        sample =
            latest_imu;

        imu_sample_available =
            false;


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


        sample =
            latest_pressure;

        pressure_sample_available =
            false;


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


    uint32_t getImuBytesReceived()
    {
        if (imu_source == nullptr)
        {
            return 0;
        }


        return
            imu_source
                ->getStats()
                .bytes_received;
    }


    uint32_t getImuRegisterUpdates()
    {
        if (imu_source == nullptr)
        {
            return 0;
        }


        return
            imu_source
                ->getStats()
                .register_updates;
    }


    uint32_t getImuSamplesProduced()
    {
        if (imu_source == nullptr)
        {
            return 0;
        }


        return
            imu_source
                ->getStats()
                .samples_produced;
    }

    uint32_t getPressureReadAttempts()
    {
        if (pressure_source == nullptr)
        {
            return 0;
        }

        return pressure_source
            ->getStats()
            .read_attempts;
    }


    uint32_t getPressureReadSuccesses()
    {
        if (pressure_source == nullptr)
        {
            return 0;
        }

        return pressure_source
            ->getStats()
            .read_successes;
    }


    uint32_t getPressureSamplesProduced()
    {
        if (pressure_source == nullptr)
        {
            return 0;
        }

        return pressure_source
            ->getStats()
            .samples_produced;
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