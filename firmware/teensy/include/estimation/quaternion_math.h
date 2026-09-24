#pragma once

#include "estimation/estimator_types.h"


namespace TyrantEstimation
{

Quaternion quaternionIdentity();


float quaternionNorm(
    const Quaternion &q
);


bool normalizeQuaternion(
    Quaternion &q
);


Quaternion multiplyQuaternion(
    const Quaternion &a,
    const Quaternion &b
);


Vector3 rotateBodyToNavigation(
    const Quaternion &q_nb,
    const Vector3 &vector_b
);


Quaternion deltaQuaternionFromBodyRate(
    const Vector3 &omega_b,
    float dt_s
);

}