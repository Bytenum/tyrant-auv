# HEARTBEAT

Message ID:

`0x0001`

Purpose:

Indicates that a Tyrant software node is alive and communicating.

## Expected Senders

* GCS
* Raspberry Pi
* Teensy 4.1
* ESP32-S3

## Payload

| Field     | Type   | Unit | Description              |
| --------- | ------ | ---- | ------------------------ |
| uptime_ms | uint32 | ms   | Time since node startup  |
| mode      | uint8  | enum | Current node/system mode |
| health    | uint8  | enum | Current health summary   |

## Notes

Heartbeat packets are used for communication-loss detection.

Each receiver shall track the last valid heartbeat received from relevant peers.

For safety-critical communication, timeout handling shall not depend solely on Raspberry Pi software.

The Teensy shall independently detect loss of required communication links.
