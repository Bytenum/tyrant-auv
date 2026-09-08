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

        // For current bring-up:
        // Teensy initialization is considered successful.
        //
        // Later this will depend on:
        // - sensors
        // - power health
        // - estimator
        // - thruster interface
        // - internal self-tests
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
            now - last_host_heartbeat_ms
            <= HOST_TIMEOUT_MS
        );
    }

    bool systemHealthy()
    {
        // For current Phase 2B, communication health
        // is our first real safety condition.
        //
        // More conditions will be added later.

        return communicationHealthy();
    }

    bool autonomyReady()
    {
        // AUTO is deliberately disabled for now.
        //
        // Later this will require:
        // - estimator valid
        // - reference valid
        // - sensors healthy
        // - controller healthy

        return false;
    }

    bool requestMode(uint8_t requested_mode)
    {
        if (requested_mode > 6)
        {
            return false;
        }

        const TyrantVehicle::Mode mode =
            static_cast<TyrantVehicle::Mode>(
                requested_mode
            );

        return TyrantVehicle::requestMode(
            mode,
            systemHealthy(),
            autonomyReady()
        );
    }

    void update()
    {
        const TyrantVehicle::Mode mode =
            TyrantVehicle::getMode();

        // Communication loss only forces SAFE
        // when propulsion-capable modes are active.
        //
        // IDLE is allowed to remain IDLE while waiting
        // for the host to connect.

        if (
            mode == TyrantVehicle::Mode::MANUAL ||
            mode == TyrantVehicle::Mode::AUTO
        )
        {
            if (!communicationHealthy())
            {
                TyrantVehicle::forceSafe();
            }
        }
    }

    uint8_t getMode()
    {
        return static_cast<uint8_t>(
            TyrantVehicle::getMode()
        );
    }

    bool propulsionAllowed()
    {
        const TyrantVehicle::Mode mode =
            TyrantVehicle::getMode();

        if (!systemHealthy())
        {
            return false;
        }

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
