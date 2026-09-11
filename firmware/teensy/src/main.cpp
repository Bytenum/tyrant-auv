#include <Arduino.h>

#include "communication/ros_interface.h"
#include "communication/connection_manager.h"

#include "scheduler/scheduler.h"
#include "safety/safety_manager.h"


namespace
{
    uint32_t last_request_id = 0;

    uint8_t last_requested_mode = 1; // IDLE

    bool last_request_accepted = false;

    uint8_t last_reason = 0; // NONE
}


void setup()
{
    // ========================================================
    // SAFETY / VEHICLE STATE
    // ========================================================

    TyrantSafety::init();


    // ========================================================
    // PHYSICAL MICRO-ROS TRANSPORT
    // ========================================================

    TyrantROS::setupTransport();


    // ========================================================
    // CONNECTION MANAGER
    // ========================================================

    TyrantConnection::init();


    // ========================================================
    // SCHEDULER
    // ========================================================

    TyrantScheduler::init();
}


void loop()
{
    // ========================================================
    // CONNECTION LIFECYCLE
    // ========================================================

    TyrantConnection::update();


    // ========================================================
    // APPLICATION COMMUNICATION
    // ========================================================

    if (TyrantConnection::connected())
    {
        // ----------------------------------------------------
        // Legacy diagnostic command
        // ----------------------------------------------------
        #ifdef TYRANT_ENABLE_DIAGNOSTICS
        if (TyrantROS::hasNewCommand())
        {
            const uint32_t command =
                TyrantROS::getLastCommand();

            TyrantROS::publishResponse(
                command
            );
        }
        #endif

        // ----------------------------------------------------
        // Host heartbeat
        // ----------------------------------------------------

        if (
            TyrantROS::hasNewHostHeartbeat()
        )
        {
            (void)
                TyrantROS::
                    getHostHeartbeatValue();

            TyrantSafety::
                notifyHostHeartbeat();
        }


        // ----------------------------------------------------
        // CUSTOM MODE REQUEST
        // ----------------------------------------------------

        TyrantROS::ModeRequestData request;

        if (
            TyrantROS::takeModeRequest(
                request
            )
        )
        {
            last_request_id =
                request.request_id;

            last_requested_mode =
                request.requested_mode;


            const auto result =
                TyrantSafety::requestMode(
                    request.requested_mode
                );


            last_request_accepted =
                result.accepted;

            last_reason =
                result.reason;


            TyrantROS::publishModeStatus(
                last_request_id,
                TyrantSafety::getMode(),
                last_requested_mode,
                last_request_accepted,
                last_reason,
                TyrantSafety::
                    communicationHealthy(),
                TyrantSafety::
                    propulsionAllowed()
            );
        }


        // ----------------------------------------------------
        // INTERNAL SAFETY EVENT
        //
        // Example:
        // Agent loss or host heartbeat timeout.
        // ----------------------------------------------------

        uint8_t internal_reason = 0;

        if (
            TyrantSafety::
                takeInternalModeEvent(
                    internal_reason
                )
        )
        {
            last_request_id = 0;

            last_requested_mode = 4; // SAFE

            last_request_accepted = false;

            last_reason =
                internal_reason;


            TyrantROS::publishModeStatus(
                last_request_id,
                TyrantSafety::getMode(),
                last_requested_mode,
                last_request_accepted,
                last_reason,
                TyrantSafety::
                    communicationHealthy(),
                TyrantSafety::
                    propulsionAllowed()
            );
        }
    }


    // ========================================================
    // TEENSY HEARTBEAT + diagnostic
    // ========================================================

    if (
        TyrantScheduler::heartbeatDue()
    )
    {
if (
        TyrantConnection::connected()
    )
    {
        TyrantROS::publishHeartbeat();


        const auto connection_stats =
            TyrantConnection::getStats();

        const auto error_stats =
            TyrantROS::getErrorStats();


        TyrantROS::publishCommunicationDiagnostics(
            static_cast<uint8_t>(
                TyrantConnection::getState()
            ),
            connection_stats.connection_count,
            connection_stats.disconnect_count,
            connection_stats.reconnect_count,
            error_stats.publish_failures,
            error_stats.executor_failures,
            error_stats.entity_create_failures,
            error_stats.entity_destroy_failures
        );
    }
    }
    // ========================================================
    // SYSTEM HEALTH TELEMETRY — 5 Hz
    // ========================================================

    if (
        TyrantScheduler::healthDue()
    )
    {
        if (
            TyrantConnection::connected()
        )
        {
            TyrantROS::publishSystemHealth(
                TyrantSafety::communicationHealthy(),
                TyrantSafety::autonomyReady(),
                TyrantSafety::propulsionAllowed(),
                TyrantSafety::getMode(),
                TyrantSafety::hostHeartbeatAgeMs()
            );
        }
    }

    // ========================================================
    // SAFETY TASK
    //
    // Must run even when ROS is disconnected.
    // ========================================================

    if (
        TyrantScheduler::safetyDue()
    )
    {
        TyrantSafety::update();


        if (
            TyrantConnection::connected()
        )
        {
            // Catch a safety event generated by update().
            uint8_t internal_reason = 0;

            if (
                TyrantSafety::
                    takeInternalModeEvent(
                        internal_reason
                    )
            )
            {
                last_request_id = 0;

                last_requested_mode = 4;

                last_request_accepted = false;

                last_reason =
                    internal_reason;
            }


            TyrantROS::publishModeStatus(
                last_request_id,
                TyrantSafety::getMode(),
                last_requested_mode,
                last_request_accepted,
                last_reason,
                TyrantSafety::
                    communicationHealthy(),
                TyrantSafety::
                    propulsionAllowed()
            );
        }
    }


    // ========================================================
    // FUTURE CONTROL
    // ========================================================

    if (
        TyrantScheduler::controlDue()
    )
    {
        if (
            TyrantSafety::
                propulsionAllowed()
        )
        {
            // Future:
            //
            // Sensors
            //    ↓
            // EKF
            //    ↓
            // LMPC
            //    ↓
            // TAM/QP
            //    ↓
            // Thrusters
        }
    }


    delay(1);
}
