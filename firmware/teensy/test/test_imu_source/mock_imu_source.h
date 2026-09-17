#pragma once

#include "sensors/imu_source.h"


class MockImuSource : public TyrantSensors::ImuSource
{
public:

    void setProducing(
        bool producing
    )
    {
        producing_ = producing;
    }

    bool begin() override
    {
        initialized_ = true;
        producing_ = true;
        sample_available_ = false;

        sequence_ = 0;

        stats_ = {
            0,
            0,
            0
        };

        return true;
    }


    void update() override
    {
        if (!initialized_)
        {
            return;
        }

        if (!producing_)
        {
            return;
        }


        sequence_++;


        sample_.sequence =
            sequence_;

        sample_.timestamp_us =
            micros();


        sample_.accel_x = 0.0f;
        sample_.accel_y = 0.0f;
        sample_.accel_z = 9.80665f;


        sample_.gyro_x = 0.0f;
        sample_.gyro_y = 0.0f;
        sample_.gyro_z = 0.0f;


        sample_.valid = true;


        sample_available_ = true;

        stats_.samples_produced++;
    }


    bool takeSample(
        TyrantSensors::ImuSample &sample
    ) override
    {
        if (!sample_available_)
        {
            return false;
        }


        sample =
            sample_;


        sample_available_ =
            false;


        return true;
    }


    TyrantSensors::ImuSourceStats
    getStats() const override
    {
        return stats_;
    }


private:
    bool producing_ = false;
    bool initialized_ = false;

    bool sample_available_ = false;

    uint32_t sequence_ = 0;


    TyrantSensors::ImuSample sample_ {};


    TyrantSensors::ImuSourceStats stats_ {
        0,
        0,
        0
    };
};
