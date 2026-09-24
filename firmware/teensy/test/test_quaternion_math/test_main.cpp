#include <Arduino.h>
#include <unity.h>

#include <math.h>

#include "estimation/quaternion_math.h"


void test_identity_quaternion()
{
    const auto q =
        TyrantEstimation::
            quaternionIdentity();


    TEST_ASSERT_FLOAT_WITHIN(
        0.0001f,
        1.0f,
        q.w
    );

    TEST_ASSERT_FLOAT_WITHIN(
        0.0001f,
        0.0f,
        q.x
    );

    TEST_ASSERT_FLOAT_WITHIN(
        0.0001f,
        0.0f,
        q.y
    );

    TEST_ASSERT_FLOAT_WITHIN(
        0.0001f,
        0.0f,
        q.z
    );
}


void test_normalize_quaternion()
{
    TyrantEstimation::Quaternion q {
        2.0f,
        0.0f,
        0.0f,
        0.0f
    };


    TEST_ASSERT_TRUE(
        TyrantEstimation::
            normalizeQuaternion(q)
    );


    TEST_ASSERT_FLOAT_WITHIN(
        0.0001f,
        1.0f,
        TyrantEstimation::
            quaternionNorm(q)
    );
}


void test_identity_rotation()
{
    const auto q =
        TyrantEstimation::
            quaternionIdentity();


    const TyrantEstimation::Vector3 body {
        1.0f,
        2.0f,
        3.0f
    };


    const auto nav =
        TyrantEstimation::
            rotateBodyToNavigation(
                q,
                body
            );


    TEST_ASSERT_FLOAT_WITHIN(
        0.0001f,
        1.0f,
        nav.x
    );

    TEST_ASSERT_FLOAT_WITHIN(
        0.0001f,
        2.0f,
        nav.y
    );

    TEST_ASSERT_FLOAT_WITHIN(
        0.0001f,
        3.0f,
        nav.z
    );
}


void test_positive_yaw_rotates_x_toward_y()
{
    const float pi =
        3.14159265358979323846f;


    const TyrantEstimation::Vector3
        omega_b {
            0.0f,
            0.0f,
            pi / 2.0f
        };


    const auto delta =
        TyrantEstimation::
            deltaQuaternionFromBodyRate(
                omega_b,
                1.0f
            );


    const TyrantEstimation::Vector3
        body_x {
            1.0f,
            0.0f,
            0.0f
        };


    const auto nav =
        TyrantEstimation::
            rotateBodyToNavigation(
                delta,
                body_x
            );


    TEST_ASSERT_FLOAT_WITHIN(
        0.001f,
        0.0f,
        nav.x
    );

    TEST_ASSERT_FLOAT_WITHIN(
        0.001f,
        1.0f,
        nav.y
    );

    TEST_ASSERT_FLOAT_WITHIN(
        0.001f,
        0.0f,
        nav.z
    );


    TEST_ASSERT_FLOAT_WITHIN(
        0.0001f,
        1.0f,
        TyrantEstimation::
            quaternionNorm(delta)
    );
}


void setup()
{
    delay(2000);

    UNITY_BEGIN();

    RUN_TEST(
        test_identity_quaternion
    );

    RUN_TEST(
        test_normalize_quaternion
    );

    RUN_TEST(
        test_identity_rotation
    );

    RUN_TEST(
        test_positive_yaw_rotates_x_toward_y
    );

    UNITY_END();
}


void loop()
{
}