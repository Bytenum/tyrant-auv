#include "vehicle/vehicle_mode.h"

namespace
{
    TyrantVehicle::Mode current_mode =
        TyrantVehicle::Mode::BOOT;
}

namespace TyrantVehicle
{
    void init()
    {
        current_mode = Mode::BOOT;
    }

    void completeBoot(bool initialization_ok)
    {
        if (initialization_ok)
        {
            current_mode = Mode::IDLE;
        }
        else
        {
            current_mode = Mode::FAULT;
        }
    }

    bool requestMode(
        Mode requested_mode,
        bool system_healthy,
        bool autonomy_ready
    )
    {
        // Already in requested mode.
        if (requested_mode == current_mode)
        {
            return true;
        }

        // BOOT, FAULT, and EMERGENCY are not normal
        // host-commandable modes.
        if (
            requested_mode == Mode::BOOT ||
            requested_mode == Mode::FAULT ||
            requested_mode == Mode::EMERGENCY
        )
        {
            return false;
        }

        // EMERGENCY and FAULT are latched for now.
        // Recovery logic will be designed separately.
        if (
            current_mode == Mode::EMERGENCY ||
            current_mode == Mode::FAULT
        )
        {
            return false;
        }

        // SAFE may always be requested.
        if (requested_mode == Mode::SAFE)
        {
            current_mode = Mode::SAFE;
            return true;
        }

        switch (current_mode)
        {
            case Mode::BOOT:
            {
                return false;
            }

            case Mode::IDLE:
            {
                if (
                    requested_mode == Mode::MANUAL &&
                    system_healthy
                )
                {
                    current_mode = Mode::MANUAL;
                    return true;
                }

                if (
                    requested_mode == Mode::AUTO &&
                    system_healthy &&
                    autonomy_ready
                )
                {
                    current_mode = Mode::AUTO;
                    return true;
                }

                return false;
            }

            case Mode::MANUAL:
            {
                if (requested_mode == Mode::IDLE)
                {
                    current_mode = Mode::IDLE;
                    return true;
                }

                return false;
            }

            case Mode::AUTO:
            {
                if (requested_mode == Mode::IDLE)
                {
                    current_mode = Mode::IDLE;
                    return true;
                }

                return false;
            }

            case Mode::SAFE:
            {
                if (
                    requested_mode == Mode::IDLE &&
                    system_healthy
                )
                {
                    current_mode = Mode::IDLE;
                    return true;
                }

                return false;
            }

            case Mode::FAULT:
            case Mode::EMERGENCY:
            default:
            {
                return false;
            }
        }
    }

    void forceSafe()
    {
        if (
            current_mode != Mode::FAULT &&
            current_mode != Mode::EMERGENCY
        )
        {
            current_mode = Mode::SAFE;
        }
    }

    void forceFault()
    {
        if (current_mode != Mode::EMERGENCY)
        {
            current_mode = Mode::FAULT;
        }
    }

    void forceEmergency()
    {
        current_mode = Mode::EMERGENCY;
    }

    Mode getMode()
    {
        return current_mode;
    }
}
