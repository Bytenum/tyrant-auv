#include "estimation/quaternion_math.h"

#include <math.h>


namespace
{

constexpr float MIN_QUATERNION_NORM =
    1.0e-6f;

constexpr float SMALL_ANGLE_THRESHOLD =
    1.0e-6f;

}


namespace TyrantEstimation
{

Quaternion quaternionIdentity()
{
    return {
        1.0f,
        0.0f,
        0.0f,
        0.0f
    };
}


float quaternionNorm(
    const Quaternion &q
)
{
    return sqrtf(
        q.w * q.w +
        q.x * q.x +
        q.y * q.y +
        q.z * q.z
    );
}


bool normalizeQuaternion(
    Quaternion &q
)
{
    const float norm =
        quaternionNorm(q);


    if (
        !isfinite(norm) ||
        norm < MIN_QUATERNION_NORM
    )
    {
        return false;
    }


    const float inverse_norm =
        1.0f / norm;


    q.w *= inverse_norm;
    q.x *= inverse_norm;
    q.y *= inverse_norm;
    q.z *= inverse_norm;


    return true;
}


Quaternion multiplyQuaternion(
    const Quaternion &a,
    const Quaternion &b
)
{
    return {
        a.w * b.w -
        a.x * b.x -
        a.y * b.y -
        a.z * b.z,

        a.w * b.x +
        a.x * b.w +
        a.y * b.z -
        a.z * b.y,

        a.w * b.y -
        a.x * b.z +
        a.y * b.w +
        a.z * b.x,

        a.w * b.z +
        a.x * b.y -
        a.y * b.x +
        a.z * b.w
    };
}


Vector3 rotateBodyToNavigation(
    const Quaternion &q_nb,
    const Vector3 &vector_b
)
{
    // Rotation matrix corresponding to a Hamilton,
    // scalar-first quaternion.
    //
    // q_nb maps BODY -> NAVIGATION.

    const float ww = q_nb.w * q_nb.w;
    const float xx = q_nb.x * q_nb.x;
    const float yy = q_nb.y * q_nb.y;
    const float zz = q_nb.z * q_nb.z;

    const float wx = q_nb.w * q_nb.x;
    const float wy = q_nb.w * q_nb.y;
    const float wz = q_nb.w * q_nb.z;

    const float xy = q_nb.x * q_nb.y;
    const float xz = q_nb.x * q_nb.z;
    const float yz = q_nb.y * q_nb.z;


    Vector3 vector_n {};


    vector_n.x =
        (ww + xx - yy - zz) * vector_b.x +
        2.0f * (xy - wz) * vector_b.y +
        2.0f * (xz + wy) * vector_b.z;

    vector_n.y =
        2.0f * (xy + wz) * vector_b.x +
        (ww - xx + yy - zz) * vector_b.y +
        2.0f * (yz - wx) * vector_b.z;

    vector_n.z =
        2.0f * (xz - wy) * vector_b.x +
        2.0f * (yz + wx) * vector_b.y +
        (ww - xx - yy + zz) * vector_b.z;


    return vector_n;
}


Quaternion deltaQuaternionFromBodyRate(
    const Vector3 &omega_b,
    float dt_s
)
{
    const float omega_norm =
        sqrtf(
            omega_b.x * omega_b.x +
            omega_b.y * omega_b.y +
            omega_b.z * omega_b.z
        );


    const float angle =
        omega_norm * dt_s;


    Quaternion delta {};


    if (
        omega_norm < SMALL_ANGLE_THRESHOLD
    )
    {
        // Small-angle approximation:
        //
        // dq ≈ [1, 0.5 * omega * dt]

        delta = {
            1.0f,

            0.5f * omega_b.x * dt_s,
            0.5f * omega_b.y * dt_s,
            0.5f * omega_b.z * dt_s
        };


        normalizeQuaternion(delta);

        return delta;
    }


    const float half_angle =
        0.5f * angle;

    const float scale =
        sinf(half_angle) /
        omega_norm;


    delta = {
        cosf(half_angle),

        omega_b.x * scale,
        omega_b.y * scale,
        omega_b.z * scale
    };


    normalizeQuaternion(delta);

    return delta;
}

}