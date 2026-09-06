# Tyrant ESP32 Payload Firmware

Firmware for the Tyrant AUV payload controller.

Target hardware:

**ESP32-S3**

Primary responsibilities:

* pH sensor acquisition
* dissolved oxygen sensor acquisition
* temperature acquisition
* payload calibration
* sampling state machine
* payload health monitoring
* payload data packaging
* communication with Raspberry Pi

The ESP32-S3 is not responsible for vehicle propulsion or real-time vehicle control.

## Planned Toolchain

* C++
* PlatformIO
* ESP32-S3

## Status

Payload firmware architecture under development.