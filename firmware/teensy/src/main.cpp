#include <Arduino.h>

#include "communication/ros_interface.h"
#include "communication/connection_manager.h"

#include "scheduler/scheduler.h"
#include "safety/safety_manager.h"


void setup()
{
    // ========================================================
    // SAFETY
    // ========================================================

    TyrantSafety::init();


    // ========================================================
    // SERIAL / MICRO-ROS TRANSPORT
    //
    // Only physical transport is configured here.
    // ROS entities are NOT created here.
    // ========================================================

    TyrantROS::setupTransport();


    // ========================================================
    // CONNECTION STATE MACHINE
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
    // MICRO-ROS CONNECTION LIFECYCLE
    //
    // WAITING → CONNECTED → LOST → RECONNECT
    // ========================================================

    TyrantConnection::update();


    // ========================================================
    // APPLICATION COMMUNICATION
    // ========================================================

    if (TyrantConnection::connected())
    {
        // Legacy bidirectional diagnostic.
        if (TyrantROS::hasNewCommand())
        {
            const uint32_t command =
                TyrantROS::getLastCommand();

            TyrantROS::publishResponse(command);
        }


        // Host application heartbeat.
        if (TyrantROS::hasNewHostHeartbeat())
        {
            (void)
                TyrantROS::getHostHeartbeatValue();

            TyrantSafety::notifyHostHeartbeat();
        }


        // Vehicle mode request.
        if (TyrantROS::hasModeRequest())
        {
            const uint8_t requested_mode =
                TyrantROS::getRequestedMode();

            (void)
                TyrantSafety::requestMode(
                    requested_mode
                );

            TyrantROS::publishModeStatus(
                TyrantSafety::getMode()
            );
        }
    }


    // ========================================================
    // TEENSY HEARTBEAT
    // ========================================================

    if (TyrantScheduler::heartbeatDue())
    {
        if (TyrantConnection::connected())
        {
            TyrantROS::publishHeartbeat();
        }
    }


    // ========================================================
    // SAFETY
    //
    // Runs even when ROS is disconnected.
    // This is important.
    // ========================================================

    if (TyrantScheduler::safetyDue())
    {
        TyrantSafety::update();

        if (TyrantConnection::connected())
        {
            TyrantROS::publishModeStatus(
                TyrantSafety::getMode()
            );
        }
    }


    // ========================================================
    // FUTURE CONTROL
    // ========================================================

    if (TyrantScheduler::controlDue())
    {
        if (TyrantSafety::propulsionAllowed())
        {
            // Future:
            //
            // Sensors
            //     ↓
            // EKF
            //     ↓
            // LMPC
            //     ↓
            // TAM / QP
            //     ↓
            // Thrusters
        }
    }


    delay(1);
}
