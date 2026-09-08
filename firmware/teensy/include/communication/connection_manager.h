#pragma once

#include <Arduino.h>

namespace TyrantConnection
{
    enum class State : uint8_t
    {
        WAITING_AGENT = 0,
        AGENT_AVAILABLE,
        CONNECTED,
        DISCONNECTED
    };

    void init();

    void update();

    bool connected();

    State getState();
}
