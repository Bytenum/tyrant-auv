# Tyrant Raspberry Pi Companion Software

Companion software for the Tyrant AUV Raspberry Pi.

The Raspberry Pi acts as the high-level system gateway and mission supervisor.

Primary responsibilities:

* communication gateway
* GCS connectivity
* mission management
* command routing
* reference routing
* telemetry forwarding
* payload routing
* parameter management
* system monitoring
* data logging

The Raspberry Pi is not the real-time flight controller.

Physical propulsion commands remain under Teensy safety authority.

## Planned Stack

* Python
* pyproject.toml-based package
* Linux / Raspberry Pi OS

## Status

Companion software architecture under development.
