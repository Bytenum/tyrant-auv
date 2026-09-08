#include "safety/safety_manager.h"
#include "vehicle/vehicle_mode.h"

namespace
{
    bool host_heartbeat_received = false;

    unsigned long last_host_heartbeat_ms = 0;

    constexpr unsigned long HOST_TIMEOUT_MS = 500;
}

namespace TyrantSafety
{
    void init()
    {
        host_heartbeat_received = false;
        last_host_heartbeat_ms = 0;

        TyrantVehicle::init();

        // Bring-up initialization is currently considered OK.
        TyrantVehicle::completeBoot(true);
    }

    void notifyHostHeartbeat()
    {
        host_heartbeat_received = true;
        last_host_heartbeat_ms = millis();
    }

    bool communicationHealthy()
    {
        if (!host_heartbeat_received)
        {
            return false;
        }

        const unsigned long now = millis();

        return (
            now - last_host_heartbeat_ms <=
            HOST_TIMEOUT_MS
        );
    }

    bool systemHealthy()
    {
        // Current first real safety condition.
        return communicationHealthy();
    }

    bool autonomyReady()
    {
        // Deliberately false until sensors,
        // estimator and reference validation exist.
        return false;
    }

    ModeRequestResult requestMode(
        uint8_t requested_mode
    )
    {
        if (requested_mode > 6)
        {
            return {
                false,
                static_cast<uint8_t>(
                    TyrantVehicle::Reason::INVALID_MODE
                )
            };
        }

        const auto result =
            TyrantVehicle::requestMode(
                static_cast<TyrantVehicle::Mode>(
                    requested_mode
                ),
                systemHealthy(),
                autonomyReady()
            );

        return {
            result.accepted,
            static_cast<uint8_t>(
                result.reason
            )
        };
    }

    bool update()
    {
        const auto mode =
            TyrantVehicle::getMode();

        if (
            mode == TyrantVehicle::Mode::MANUAL ||
            mode == TyrantVehicle::Mode::AUTO
        )
        {
            if (!communicationHealthy())
            {
                TyrantVehicle::forceSafe();

                return true;
            }
        }

        return false;
    }

    uint8_t getMode()
    {
        return static_cast<uint8_t>(
            TyrantVehicle::getMode()
        );
    }

    bool propulsionAllowed()
    {
        if (!systemHealthy())
        {
            return false;
        }

        const auto mode =
            TyrantVehicle::getMode();

        if (mode == TyrantVehicle::Mode::MANUAL)
        {
            return true;
        }

        if (
            mode == TyrantVehicle::Mode::AUTO &&
            autonomyReady()
        )
        {
            return true;
        }

        return false;
    }
}
