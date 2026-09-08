#include <Arduino.h>

#include "communication/ros_interface.h"
#include "scheduler/scheduler.h"
#include "safety/safety_manager.h"

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
        // Fail-safe:
        // firmware does not continue into operational logic
        // when ROS initialization fails.

        while (true)
        {
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
    // PROCESS MICRO-ROS
    // ========================================================

    TyrantROS::spin();


    // ========================================================
    // LEGACY BIDIRECTIONAL TEST
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
        // Read and clear the communication flag.
        //
        // The numerical heartbeat value is not currently
        // important. Arrival time is what matters.

        (void)TyrantROS::getHostHeartbeatValue();

        TyrantSafety::notifyHostHeartbeat();
    }


    // ========================================================
    // MODE REQUEST
    // ========================================================

    if (TyrantROS::hasModeRequest())
    {
        const uint8_t requested_mode =
            TyrantROS::getRequestedMode();

        TyrantSafety::requestMode(
            requested_mode
        );

        // Publish actual mode, regardless of whether request
        // was accepted or rejected.
        //
        // Therefore ROS always sees what Teensy actually chose.

        TyrantROS::publishModeStatus(
            TyrantSafety::getMode()
        );
    }


    // ========================================================
    // TEENSY HEARTBEAT — 1 Hz
    // ========================================================

    if (TyrantScheduler::heartbeatDue())
    {
        TyrantROS::publishHeartbeat();
    }


    // ========================================================
    // SAFETY TASK — 10 Hz
    // ========================================================

    if (TyrantScheduler::safetyDue())
    {
        TyrantSafety::update();

        TyrantROS::publishModeStatus(
            TyrantSafety::getMode()
        );
    }


    // ========================================================
    // CONTROL TASK — currently placeholder
    // ========================================================

    if (TyrantScheduler::controlDue())
    {
        if (TyrantSafety::propulsionAllowed())
        {
            // Future pipeline:
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
