#pragma once


namespace TyrantEstimation
{

struct Vector3
{
    float x;
    float y;
    float z;
};


struct Quaternion
{
    // Hamilton quaternion, scalar first.
    //
    // q_nb rotates a vector from BODY FRD
    // into the local NAVIGATION frame.

    float w;
    float x;
    float y;
    float z;
};


struct NominalState
{
    // Position in local navigation frame [m].
    //
    // +X = local magnetic-reference forward axis
    // +Y = right/east-like
    // +Z = down

    Vector3 position_n;


    // Linear velocity in navigation frame [m/s].

    Vector3 velocity_n;


    // Body -> navigation attitude quaternion.

    Quaternion q_nb;


    // Accelerometer bias expressed in body FRD [m/s^2].

    Vector3 accel_bias_b;


    // Gyroscope bias expressed in body FRD [rad/s].

    Vector3 gyro_bias_b;
};

}