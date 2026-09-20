#include <Arduino.h>
#include <unity.h>

#include "../test_pressure_source/mock_pressure_source.h"

#include "sensors/sensor_manager.h"


constexpr float SURFACE_PRESSURE_PA =
    100000.0f;

constexpr float WATER_DENSITY =
    1025.0f;

constexpr float GRAVITY_MPS2 =
    9.80665f;


MockPressureSource mock_pressure;


float pressureForDepth(
    float depth_m
)
{
    return
        SURFACE_PRESSURE_PA +
        (
            WATER_DENSITY *
            GRAVITY_MPS2 *
            depth_m
        );
}


void preparePressureAtSurface()
{
    TyrantSensors::setPressureSource(
        mock_pressure
    );

    TyrantSensors::init();

    mock_pressure.setProducing(
        true
    );

    mock_pressure.setPressurePa(
        SURFACE_PRESSURE_PA
    );

    TyrantSensors::update();
}


void test_pressure_ready_but_depth_not_zeroed()
{
    preparePressureAtSurface();


    const auto pressure_health =
        TyrantSensors::getPressureHealth();


    TEST_ASSERT_EQUAL_UINT8(
        static_cast<uint8_t>(
            TyrantSensors::SensorState::READY
        ),
        static_cast<uint8_t>(
            pressure_health.state
        )
    );


    TEST_ASSERT_TRUE(
        pressure_health.valid
    );


    TEST_ASSERT_FALSE(
        TyrantSensors::
            depthSurfaceReferenceValid()
    );


    TyrantSensors::DepthMeasurement
        depth {};


    TEST_ASSERT_TRUE(
        TyrantSensors::getLatestDepth(
            depth
        )
    );


    TEST_ASSERT_FALSE(
        depth.valid
    );
}


void test_set_surface_reference_gives_zero_depth()
{
    preparePressureAtSurface();


    TEST_ASSERT_TRUE(
        TyrantSensors::
            setDepthSurfaceReference()
    );


    TEST_ASSERT_TRUE(
        TyrantSensors::
            depthSurfaceReferenceValid()
    );


    TyrantSensors::DepthMeasurement
        depth {};


    TEST_ASSERT_TRUE(
        TyrantSensors::getLatestDepth(
            depth
        )
    );


    TEST_ASSERT_TRUE(
        depth.valid
    );


    TEST_ASSERT_FLOAT_WITHIN(
        0.001f,
        0.0f,
        depth.depth_m
    );
}


void test_one_meter_depth()
{
    preparePressureAtSurface();


    TEST_ASSERT_TRUE(
        TyrantSensors::
            setDepthSurfaceReference()
    );


    // Consume depth=0 measurement produced
    // when the surface reference was set.
    TyrantSensors::DepthMeasurement
        zero_depth {};

    TyrantSensors::getLatestDepth(
        zero_depth
    );


    mock_pressure.setPressurePa(
        pressureForDepth(
            1.0f
        )
    );


    TyrantSensors::update();


    TyrantSensors::DepthMeasurement
        depth {};


    TEST_ASSERT_TRUE(
        TyrantSensors::getLatestDepth(
            depth
        )
    );


    TEST_ASSERT_TRUE(
        depth.valid
    );


    TEST_ASSERT_FLOAT_WITHIN(
        0.01f,
        1.0f,
        depth.depth_m
    );
}


void test_clear_reference_invalidates_depth()
{
    preparePressureAtSurface();


    TEST_ASSERT_TRUE(
        TyrantSensors::
            setDepthSurfaceReference()
    );


    TyrantSensors::
        clearDepthSurfaceReference();


    TEST_ASSERT_FALSE(
        TyrantSensors::
            depthSurfaceReferenceValid()
    );


    TyrantSensors::DepthMeasurement
        depth {};


    TEST_ASSERT_TRUE(
        TyrantSensors::getLatestDepth(
            depth
        )
    );


    TEST_ASSERT_FALSE(
        depth.valid
    );
}


void test_pressure_stale_invalidates_depth()
{
    preparePressureAtSurface();


    TEST_ASSERT_TRUE(
        TyrantSensors::
            setDepthSurfaceReference()
    );


    TyrantSensors::DepthMeasurement
        initial_depth {};

    TyrantSensors::getLatestDepth(
        initial_depth
    );


    mock_pressure.setProducing(
        false
    );


    delay(1100);


    TyrantSensors::update();


    const auto pressure_health =
        TyrantSensors::getPressureHealth();


    TEST_ASSERT_EQUAL_UINT8(
        static_cast<uint8_t>(
            TyrantSensors::SensorState::STALE
        ),
        static_cast<uint8_t>(
            pressure_health.state
        )
    );


    TyrantSensors::DepthMeasurement
        depth {};


    TEST_ASSERT_TRUE(
        TyrantSensors::getLatestDepth(
            depth
        )
    );


    TEST_ASSERT_FALSE(
        depth.valid
    );
}


void setup()
{
    delay(2000);


    UNITY_BEGIN();


    RUN_TEST(
        test_pressure_ready_but_depth_not_zeroed
    );


    RUN_TEST(
        test_set_surface_reference_gives_zero_depth
    );


    RUN_TEST(
        test_one_meter_depth
    );


    RUN_TEST(
        test_clear_reference_invalidates_depth
    );


    RUN_TEST(
        test_pressure_stale_invalidates_depth
    );


    UNITY_END();
}


void loop()
{
}
