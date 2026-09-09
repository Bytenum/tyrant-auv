# Tyrant AUV — Phase 2C Communication Fault Injection VVT

## Purpose

Verify that the Teensy communication and safety architecture remains fail-safe
during ROS 2, micro-ROS Agent, and host application failures.

## Baseline

- ROS 2 Humble
- micro-ROS Humble
- Teensy 4.1
- Serial micro-ROS transport
- Vehicle modes:
  - BOOT = 0
  - IDLE = 1
  - MANUAL = 2
  - AUTO = 3
  - SAFE = 4
  - FAULT = 5
  - EMERGENCY = 6

## Topics

### Teensy -> ROS

- /tyrant/heartbeat
- /tyrant/mode/status
- /tyrant/system/health
- /tyrant/test_response

### ROS -> Teensy

- /tyrant/host_heartbeat
- /tyrant/mode/request
- /tyrant/test_command

---

## Test Matrix

| ID | Test | Expected Result | Result |
|---|---|---|---|
| 2C-FI-01 | Teensy boots while Agent OFF | WAITING_AGENT, no hang | |
| 2C-FI-02 | Agent starts after Teensy | Auto-connect without Teensy reset | |
| 2C-FI-03 | No host heartbeat | IDLE remains safe, propulsion false | |
| 2C-FI-04 | IDLE -> MANUAL with healthy heartbeat | Request accepted | |
| 2C-FI-05 | Host heartbeat stops in MANUAL | MANUAL -> SAFE | |
| 2C-FI-06 | Agent dies in MANUAL | MANUAL -> SAFE | |
| 2C-FI-07 | Agent returns | Auto-reconnect, remains SAFE | |
| 2C-FI-08 | SAFE -> MANUAL directly | Request rejected | |
| 2C-FI-09 | SAFE -> IDLE after health recovery | Request accepted | |
| 2C-FI-10 | IDLE -> AUTO | Rejected: AUTONOMY_NOT_READY | |
| 2C-FI-11 | Invalid mode = 99 | Rejected: INVALID_MODE | |
| 2C-FI-12 | Agent restart repeated 10 times | No crash, no manual Teensy reset | |

---

## Acceptance Criteria

Phase 2C fault injection passes when:

- Teensy never requires manual reset after Agent restart.
- Loss of communication never leaves propulsion authority active.
- MANUAL/AUTO transition to SAFE on communication loss.
- Reconnection does not restore MANUAL/AUTO authority automatically.
- Invalid mode requests are rejected.
- AUTO remains blocked until autonomy readiness exists.
- SystemHealth correctly reflects communication and propulsion state.
- Repeated Agent reconnect cycles do not crash the Teensy.
