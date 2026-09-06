# Tyrant Teensy Firmware

Firmware for the Tyrant AUV real-time vehicle controller.

Target hardware:

**Teensy 4.1**

Primary responsibilities:

* vehicle sensor acquisition
* deterministic control scheduling
* 6-DOF state estimation
* 6-DOF LMPC
* thruster allocation
* thruster command generation
* mode authority
* safety management
* watchdog
* fault handling
* high-rate logging

The Teensy is the final authority for commands that affect vehicle propulsion.

## Planned Toolchain

* C++
* PlatformIO
* Teensy 4.1

## Status

Firmware architecture under development.
