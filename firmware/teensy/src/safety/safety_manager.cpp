#include "safety/safety_manager.h"
#include "vehicle/vehicle_mode.h"

namespace
{
    bool transport_connected = false;

    bool host_heartbeat_received = false;

    unsigned long last_host_heartbeat_ms = 0;

    constexpr unsigned long HOST_TIMEOUT_MS = 500;
}


namespace TyrantSafety
{
    void init()
    {
        transport_connected = false;

        host_heartbeat_received = false;
        last_host_heartbeat_ms = 0;

        TyrantVehicle::init();

        // Current bring-up self-test is considered successful.
        TyrantVehicle::completeBoot(true);
    }


    void setTransportConnected(bool connected)
    {
        transport_connected = connected;

        if (!connected)
        {
            // Never allow an old heartbeat timestamp to become
            // valid again after a reconnect.
            host_heartbeat_received = false;
            last_host_heartbeat_ms = 0;

            const TyrantVehicle::Mode mode =
                TyrantVehicle::getMode();

            // Immediate safety reaction to middleware loss.
            if (
                mode == TyrantVehicle::Mode::MANUAL ||
                mode == TyrantVehicle::Mode::AUTO
            )
            {
                TyrantVehicle::forceSafe();
            }
        }
    }


    bool transportConnected()
    {
        return transport_connected;
    }


    void notifyHostHeartbeat()
    {
        // A heartbeat is only meaningful if the middleware
        // connection currently exists.
        if (!transport_connected)
        {
            return;
        }

        host_heartbeat_received = true;
        last_host_heartbeat_ms = millis();
    }


    bool communicationHealthy()
    {
        if (!transport_connected)
        {
            return false;
        }

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
        return communicationHealthy();
    }


    bool autonomyReady()
    {
        // Still deliberately disabled.
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

    const auto result =
        TyrantVehicle::requestMode(
            mode,
            systemHealthy(),
            autonomyReady()
        );

    return result.accepted;
}


    void update()
    {
        const TyrantVehicle::Mode mode =
            TyrantVehicle::getMode();

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
        if (!systemHealthy())
        {
            return false;
        }

        const TyrantVehicle::Mode mode =
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
