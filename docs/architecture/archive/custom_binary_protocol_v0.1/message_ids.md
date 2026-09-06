# Tyrant Protocol Message IDs

Protocol Version: **0.1**

## System

|     ID | Message   |
| -----: | --------- |
| 0x0001 | HEARTBEAT |
| 0x0002 | PING      |
| 0x0003 | PONG      |

## Mode and Safety

|     ID | Message      |
| -----: | ------------ |
| 0x0101 | MODE_COMMAND |
| 0x0102 | MODE_STATUS  |

## Commands and References

|     ID | Message           |
| -----: | ----------------- |
| 0x0201 | MANUAL_COMMAND    |
| 0x0202 | VEHICLE_REFERENCE |

## Vehicle State

|     ID | Message       |
| -----: | ------------- |
| 0x0301 | VEHICLE_STATE |

## Sensors

|     ID | Message    |
| -----: | ---------- |
| 0x0401 | IMU_DATA   |
| 0x0402 | DEPTH_DATA |

## Control and Thrusters

|     ID | Message          |
| -----: | ---------------- |
| 0x0501 | CONTROL_WRENCH   |
| 0x0502 | THRUSTER_COMMAND |

## Mission

Reserved range:

`0x0600–0x06FF`

## Payload

|     ID | Message      |
| -----: | ------------ |
| 0x0701 | PAYLOAD_DATA |

## Parameters

Reserved range:

`0x0800–0x08FF`

## Fault and Health

|     ID | Message       |
| -----: | ------------- |
| 0x0901 | HEALTH_STATUS |
| 0x0902 | FAULT_REPORT  |

## Notes

Message IDs are currently provisional and may change while protocol version 0.1 is under development.
