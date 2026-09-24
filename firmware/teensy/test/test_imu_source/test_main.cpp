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
        TyrantSensors::getImuSnapshot(
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

    TyrantSensors::ImuSample
        stale_sample {};


    TEST_ASSERT_FALSE(
        TyrantSensors::takeImuSample(
            stale_sample
        )
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
    TEST_ASSERT_EQUAL_UINT32(
        0,
        TyrantSensors::
            getImuSamplesDropped()
    );
}

void test_imu_snapshot_is_non_destructive()
{
    TyrantSensors::setImuSource(
        mock_imu
    );

    TyrantSensors::init();

    TyrantSensors::update();


    TyrantSensors::ImuSample
        first_snapshot {};

    TyrantSensors::ImuSample
        second_snapshot {};


    TEST_ASSERT_TRUE(
        TyrantSensors::getImuSnapshot(
            first_snapshot
        )
    );


    TEST_ASSERT_TRUE(
        TyrantSensors::getImuSnapshot(
            second_snapshot
        )
    );


    TEST_ASSERT_EQUAL_UINT32(
        first_snapshot.sequence,
        second_snapshot.sequence
    );
}

void test_imu_take_is_destructive_but_snapshot_remains()
{
    TyrantSensors::setImuSource(
        mock_imu
    );

    TyrantSensors::init();

    TyrantSensors::update();


    TyrantSensors::ImuSample
        estimator_sample {};

    TyrantSensors::ImuSample
        snapshot {};


    TEST_ASSERT_TRUE(
        TyrantSensors::takeImuSample(
            estimator_sample
        )
    );


    TEST_ASSERT_FALSE(
        TyrantSensors::takeImuSample(
            estimator_sample
        )
    );


    TEST_ASSERT_TRUE(
        TyrantSensors::getImuSnapshot(
            snapshot
        )
    );


    TEST_ASSERT_EQUAL_UINT32(
        estimator_sample.sequence,
        snapshot.sequence
    );
}

void test_nan_imu_rejected_from_estimator_stream()
{
    TyrantSensors::setImuSource(
        mock_imu
    );

    TyrantSensors::init();


    mock_imu.setAccelX(
        NAN
    );


    TyrantSensors::update();


    const auto health =
        TyrantSensors::getImuHealth();


    TEST_ASSERT_FALSE(
        health.valid
    );


    TyrantSensors::ImuSample
        snapshot {};


    TEST_ASSERT_TRUE(
        TyrantSensors::getImuSnapshot(
            snapshot
        )
    );


    TEST_ASSERT_FALSE(
        snapshot.valid
    );


    TyrantSensors::ImuSample
        estimator_sample {};


    TEST_ASSERT_FALSE(
        TyrantSensors::takeImuSample(
            estimator_sample
        )
    );
}
void test_imu_contains_9_axis_data()
{
    TyrantSensors::setImuSource(
        mock_imu
    );

    TyrantSensors::init();

    TyrantSensors::update();


    TyrantSensors::ImuSample
        sample {};


    TEST_ASSERT_TRUE(
        TyrantSensors::getImuSnapshot(
            sample
        )
    );


    TEST_ASSERT_TRUE(
        sample.valid
    );


    TEST_ASSERT_TRUE(
        sample.mag_valid
    );


    TEST_ASSERT_TRUE(
        sample.mag_updated
    );


    TEST_ASSERT_EQUAL_INT16(
        100,
        sample.mag_x_lsb
    );

    TEST_ASSERT_EQUAL_INT16(
        -200,
        sample.mag_y_lsb
    );

    TEST_ASSERT_EQUAL_INT16(
        300,
        sample.mag_z_lsb
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

    RUN_TEST(
        test_imu_snapshot_is_non_destructive
    );


    RUN_TEST(
        test_imu_take_is_destructive_but_snapshot_remains
    );
    RUN_TEST(
        test_nan_imu_rejected_from_estimator_stream
    );
    RUN_TEST(
        test_imu_contains_9_axis_data
    );
        UNITY_END();
    }


void loop()
{
}
