#pragma once

#include <Arduino.h>

namespace TyrantScheduler
{
    void init();

    bool heartbeatDue();

    bool safetyDue();

    bool controlDue();
}
