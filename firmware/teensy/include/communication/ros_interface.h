#pragma once

#include <Arduino.h>


namespace TyrantROS
{
    // ========================================================
    // CUSTOM APPLICATION DATA
    // ========================================================

    struct ModeRequestData
    {
        uint32_t request_id;
        uint8_t requested_mode;
    };


    // ========================================================
    // MICRO-ROS TRANSPORT / CONNECTION LIFECYCLE
    // ========================================================

    // Configure physical serial transport.
    // Called once during Teensy boot.
    void setupTransport();


    // Check whether micro-ROS Agent is reachable.
    bool pingAgent(
        uint32_t timeout_ms,
        uint8_t attempts
    );


    // Create node, publishers, subscribers and executor.
    bool createEntities();


    // Destroy all ROS entities.
    // Used by automatic reconnect lifecycle.
    void destroyEntities();


    // True when ROS entities are fully initialized.
    bool entitiesReady();


    // Process incoming subscriptions.
    void spin();


    // ========================================================
    // TEENSY HEARTBEAT
    // ========================================================

    void publishHeartbeat();


    // ========================================================
    // LEGACY COMMUNICATION DIAGNOSTIC
    // ========================================================

    void publishResponse(
        uint32_t value
    );


    bool hasNewCommand();


    uint32_t getLastCommand();


    // ========================================================
    // TYRANT MODE COMMUNICATION
    // ========================================================

    bool takeModeRequest(
        ModeRequestData &request
    );


    void publishModeStatus(
        uint32_t request_id,
        uint8_t current_mode,
        uint8_t requested_mode,
        bool request_accepted,
        uint8_t reason,
        bool communication_healthy,
        bool propulsion_allowed
    );


    // ========================================================
    // HOST HEARTBEAT
    // ========================================================

    bool hasNewHostHeartbeat();


    uint32_t getHostHeartbeatValue();


    // ========================================================
    // SYSTEM HEALTH TELEMETRY
    // ========================================================

    void publishSystemHealth(
        bool communication_healthy,
        bool autonomy_ready,
        bool propulsion_allowed,
        uint8_t current_mode,
        uint32_t host_heartbeat_age_ms
    );
}