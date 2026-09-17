#pragma once

#include <Arduino.h>

#include "sensors/pressure_source.h"


class MockPressureSource :
    public TyrantSensors::PressureSource
{
public:
    void setProducing(bool producing)
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


        stats_.read_attempts++;


        if (!producing_)
        {
            return;
        }


        sequence_++;

        sample_.sequence =
            sequence_;

        sample_.timestamp_us =
            micros();

        sample_.pressure_pa =
            101325.0f;

        sample_.temperature_c =
            25.0f;

        sample_.valid =
            true;


        sample_available_ =
            true;


        stats_.read_successes++;

        stats_.samples_produced++;
    }


    bool takeSample(
        TyrantSensors::PressureSample &sample
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


    TyrantSensors::PressureSourceStats
    getStats() const override
    {
        return stats_;
    }


private:
    bool initialized_ = false;

    bool producing_ = true;

    bool sample_available_ = false;


    uint32_t sequence_ = 0;


    TyrantSensors::PressureSample sample_ {};


    TyrantSensors::PressureSourceStats stats_ {
        0,
        0,
        0
    };
};
