#include <Arduino.h>
#include <unity.h>

#include "mock_imu_source.h"

#include "sensors/sensor_manager.h"


MockImuSource mock_imu;

void test_no_imu_source_enters_error()
{
    TyrantSensors::init();

    const auto health =
        TyrantSensors::getImuHealth();

    TEST_ASSERT_EQUAL_UINT8(
        static_cast<uint8_t>(
            TyrantSensors::SensorState::ERROR
        ),
        static_cast<uint8_t>(
            health.state
        )
    );

    TEST_ASSERT_FALSE(
        health.valid
    );

    TEST_ASSERT_GREATER_THAN_UINT32(
        0,
        health.error_count
    );
}

void test_mock_imu_becomes_ready()
{
    TyrantSensors::setImuSource(
        mock_imu
    );

    TyrantSensors::init();

    TyrantSensors::update();


    const auto health =
        TyrantSensors::getImuHealth();


    TEST_ASSERT_EQUAL_UINT8(
        static_cast<uint8_t>(
            TyrantSensors::SensorState::READY
        ),
        static_cast<uint8_t>(
            health.state
        )
    );


    TEST_ASSERT_TRUE(
        health.valid
    );
}


void test_mock_imu_sample()
{
    TyrantSensors::ImuSample sample {};


    TEST_ASSERT_TRUE(
        TyrantSensors::getLatestImu(
            sample
        )
    );


    TEST_ASSERT_TRUE(
        sample.valid
    );


    TEST_ASSERT_FLOAT_WITHIN(
        0.001f,
        0.0f,
        sample.accel_x
    );


    TEST_ASSERT_FLOAT_WITHIN(
        0.001f,
        0.0f,
        sample.accel_y
    );


    TEST_ASSERT_FLOAT_WITHIN(
        0.001f,
        9.80665f,
        sample.accel_z
    );


    TEST_ASSERT_FLOAT_WITHIN(
        0.001f,
        0.0f,
        sample.gyro_x
    );


    TEST_ASSERT_FLOAT_WITHIN(
        0.001f,
        0.0f,
        sample.gyro_y
    );


    TEST_ASSERT_FLOAT_WITHIN(
        0.001f,
        0.0f,
        sample.gyro_z
    );
}

void test_imu_becomes_stale()
{
    mock_imu.setProducing(
        true
    );

    TyrantSensors::update();

    auto health =
        TyrantSensors::getImuHealth();

    TEST_ASSERT_EQUAL_UINT8(
        static_cast<uint8_t>(
            TyrantSensors::SensorState::READY
        ),
        static_cast<uint8_t>(
            health.state
        )
    );


    mock_imu.setProducing(
        false
    );


    delay(600);


    TyrantSensors::update();


    health =
        TyrantSensors::getImuHealth();


    TEST_ASSERT_EQUAL_UINT8(
        static_cast<uint8_t>(
            TyrantSensors::SensorState::STALE
        ),
        static_cast<uint8_t>(
            health.state
        )
    );


    TEST_ASSERT_FALSE(
        health.valid
    );
}


void test_mock_stats()
{
    TyrantSensors::setImuSource(
        mock_imu
    );

    TyrantSensors::init();
    TyrantSensors::update();

    mock_imu.setProducing(true);
    TyrantSensors::update();
    
    const uint32_t samples =
        TyrantSensors::
            getImuSamplesProduced();


    TEST_ASSERT_GREATER_THAN_UINT32(
        0,
        samples
    );


    TEST_ASSERT_EQUAL_UINT32(
        0,
        TyrantSensors::
            getImuBytesReceived()
    );


    TEST_ASSERT_EQUAL_UINT32(
        0,
        TyrantSensors::
            getImuRegisterUpdates()
    );
}


void setup()
{
    delay(2000);


    UNITY_BEGIN();

    RUN_TEST(
    test_no_imu_source_enters_error
    );

    RUN_TEST(
        test_mock_imu_becomes_ready
    );


    RUN_TEST(
        test_mock_imu_sample
    );


    RUN_TEST(
        test_mock_stats
    );

    RUN_TEST(
        test_imu_becomes_stale
    );


    UNITY_END();
}


void loop()
{
}
