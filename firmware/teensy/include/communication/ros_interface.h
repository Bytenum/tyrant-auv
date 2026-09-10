#pragma once

#include <Arduino.h>

namespace TyrantROS
{
    struct ModeRequestData
    {
        uint32_t request_id;
        uint8_t requested_mode;
    };


    struct ErrorStats
    {
        uint32_t publish_failures;
        uint32_t executor_failures;
        uint32_t entity_create_failures;
        uint32_t entity_destroy_failures;
    };


    // ========================================================
    // CONNECTION LIFECYCLE
    // ========================================================

    void setupTransport();

    bool pingAgent(
        uint32_t timeout_ms,
        uint8_t attempts
    );

    bool createEntities();

    void destroyEntities();

    bool entitiesReady();

    void spin();


    // ========================================================
    // APPLICATION COMMUNICATION
    // ========================================================

    void publishHeartbeat();

    void publishResponse(
        uint32_t value
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

    void publishSystemHealth(
        bool communication_healthy,
        bool autonomy_ready,
        bool propulsion_allowed,
        uint8_t current_mode,
        uint32_t host_heartbeat_age_ms
    );

    void publishCommunicationDiagnostics(
        uint8_t connection_state,
        uint32_t connection_count,
        uint32_t disconnect_count,
        uint32_t reconnect_count,
        uint32_t publish_failures,
        uint32_t executor_failures,
        uint32_t entity_create_failures,
        uint32_t entity_destroy_failures
    );


    // ========================================================
    // DIAGNOSTICS
    // ========================================================

    ErrorStats getErrorStats();


    // ========================================================
    // LEGACY DIAGNOSTIC
    // ========================================================

    bool hasNewCommand();

    uint32_t getLastCommand();


    // ========================================================
    // MODE REQUEST
    // ========================================================

    bool takeModeRequest(
        ModeRequestData &request
    );


    // ========================================================
    // HOST HEARTBEAT
    // ========================================================

    bool hasNewHostHeartbeat();

    uint32_t getHostHeartbeatValue();
}