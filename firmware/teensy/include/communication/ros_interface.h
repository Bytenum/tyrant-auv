#pragma once

#include <Arduino.h>

namespace TyrantROS
{
    // ========================================================
    // DATA TYPES
    // ========================================================

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
    // PRODUCTION COMMUNICATION
    // ========================================================

    void publishHeartbeat();


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

    void publishImuTelemetry(
        uint8_t sensor_state,
        uint32_t sequence,
        uint64_t timestamp_us,

        float accel_x,
        float accel_y,
        float accel_z,

        float gyro_x,
        float gyro_y,
        float gyro_z,

        bool valid,

        uint32_t bytes_received,
        uint32_t register_updates,
        uint32_t samples_produced,
        uint32_t error_count
    );

    void publishPressureTelemetry(
        uint8_t sensor_state,
        uint32_t sequence,
        uint64_t timestamp_us,

        float pressure_pa,
        float temperature_c,

        bool valid,

        uint32_t read_attempts,
        uint32_t read_successes,
        uint32_t samples_produced,
        uint32_t error_count
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
    // COMMUNICATION DIAGNOSTICS
    // ========================================================

    ErrorStats getErrorStats();


    // ========================================================
    // OPTIONAL BRING-UP DIAGNOSTICS
    //
    // Only available when:
    // TYRANT_ENABLE_DIAGNOSTICS is defined.
    //
    // Topics:
    // /tyrant/test_command
    // /tyrant/test_response
    // ========================================================

#ifdef TYRANT_ENABLE_DIAGNOSTICS

    void publishResponse(
        uint32_t value
    );

    bool hasNewCommand();

    uint32_t getLastCommand();

#endif


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