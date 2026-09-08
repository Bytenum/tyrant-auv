#include <Arduino.h>

#include "communication/ros_interface.h"
#include "scheduler/scheduler.h"
#include "safety/safety_manager.h"

namespace
{
    uint32_t last_request_id = 0;

    uint8_t last_requested_mode = 1;

    bool last_request_accepted = false;

    uint8_t last_reason = 0;
}


void setup()
{
    // ========================================================
    // SAFETY / VEHICLE STATE
    // ========================================================

    TyrantSafety::init();


    // ========================================================
    // MICRO-ROS
    // ========================================================

    const bool ros_ok =
        TyrantROS::init();

    if (!ros_ok)
    {
        while (true)
        {
            // Fail-safe:
            // operational firmware does not continue
            // if ROS initialization failed.

            delay(1000);
        }
    }


    // ========================================================
    // SCHEDULER
    // ========================================================

    TyrantScheduler::init();
}


void loop()
{
    // ========================================================
    // MICRO-ROS PROCESSING
    // ========================================================

    TyrantROS::spin();


    // ========================================================
    // LEGACY COMMUNICATION TEST
    // ========================================================

    if (TyrantROS::hasNewCommand())
    {
        const uint32_t command =
            TyrantROS::getLastCommand();

        TyrantROS::publishResponse(command);
    }


    // ========================================================
    // HOST HEARTBEAT
    // ========================================================

    if (TyrantROS::hasNewHostHeartbeat())
    {
        (void)
            TyrantROS::getHostHeartbeatValue();

        TyrantSafety::notifyHostHeartbeat();
    }


    // ========================================================
    // TYRANT MODE REQUEST
    // ========================================================

    TyrantROS::ModeRequestData request;

    if (TyrantROS::takeModeRequest(request))
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
            TyrantSafety::communicationHealthy(),
            TyrantSafety::propulsionAllowed()
        );
    }


    // ========================================================
    // TEENSY HEARTBEAT
    // ========================================================

    if (TyrantScheduler::heartbeatDue())
    {
        TyrantROS::publishHeartbeat();
    }


    // ========================================================
    // SAFETY TASK
    // ========================================================

    if (TyrantScheduler::safetyDue())
    {
        const bool forced_safe =
            TyrantSafety::update();

        if (forced_safe)
        {
            // request_id = 0 means this mode change
            // was generated internally by Teensy,
            // not by a host request.

            last_request_id = 0;

            last_requested_mode = 4; // SAFE

            last_request_accepted = false;

            last_reason = 6; // COMMUNICATION_TIMEOUT
        }

        TyrantROS::publishModeStatus(
            last_request_id,
            TyrantSafety::getMode(),
            last_requested_mode,
            last_request_accepted,
            last_reason,
            TyrantSafety::communicationHealthy(),
            TyrantSafety::propulsionAllowed()
        );
    }


    // ========================================================
    // FUTURE CONTROL TASK
    // ========================================================

    if (TyrantScheduler::controlDue())
    {
        if (TyrantSafety::propulsionAllowed())
        {
            // Future:
            //
            // Sensors
            //    ↓
            // EKF
            //    ↓
            // LMPC
            //    ↓
            // TAM / QP
            //    ↓
            // Thrusters
        }
    }


    delay(1);
}
