# Tyrant AUV

**Tyrant AUV** is a custom 8-thruster underwater vehicle platform designed for manual operation, limited autonomous missions, underwater sensing, and research in 6-DOF vehicle modeling and control.

The project integrates custom mechanical, electrical, embedded, communication, navigation, control, payload, and Ground Control Station (GCS) systems.

> **Status:** Early software development / architecture phase.

---

## System Overview

Tyrant uses a distributed computing architecture:

```text
                         CUSTOM GCS
                              │
                       Ethernet / Tether
                              │
                          Fathom-X
                              │
                              ▼
                       RASPBERRY PI
                  Gateway / Mission / Logs
                              │
                  ┌───────────┴───────────┐
                  │                       │
                  ▼                       ▼
             TEENSY 4.1               ESP32-S3
          Vehicle Controller      Payload Controller
                  │                       │
                  │                 pH / DO / Temp
                  │
          ┌───────┴────────┐
          │  6-DOF EKF     │
          │  6-DOF LMPC    │
          │  6x8 TAM / QP  │
          └───────┬────────┘
                  │
                  ▼
             8 THRUSTERS
```

### Computing Roles

**Teensy 4.1**

Real-time vehicle control authority responsible for:

* vehicle sensor acquisition
* 6-DOF state estimation
* 6-DOF LMPC
* thruster allocation
* thruster commands
* safety and failsafe
* watchdog
* high-rate control execution

**Raspberry Pi**

High-level companion computer responsible for:

* GCS communication
* communication gateway
* mission management
* command and reference routing
* telemetry
* payload routing
* parameter management
* system logging
* supervisory monitoring

**ESP32-S3**

Payload controller responsible for:

* pH sensing
* dissolved oxygen sensing
* temperature sensing
* payload sampling
* payload calibration
* payload health monitoring

---

## Control Architecture

The baseline vehicle control architecture is:

```text
Mission / Reference
        │
        ▼
  6-DOF State Reference
        │
        ▼
     6-DOF EKF
        │
        ▼
     6-DOF LMPC
        │
        ▼
 Desired Wrench
 [X Y Z K M N]
        │
        ▼
    6x8 TAM / QP
        │
        ▼
  8 Thruster Commands
```

The controller operates using the generalized vehicle wrench:

$$
\tau =
[X,\ Y,\ Z,\ K,\ M,\ N]^T
$$

Thruster allocation uses:

$$
\tau = BT
$$

where:

$$
B \in \mathbb{R}^{6 \times 8}
$$

and:

$$
T =
[T_1,T_2,\dots,T_8]^T
$$

The final Thruster Allocation Matrix (TAM) must be generated from the actual Tyrant mechanical geometry.

---

## Navigation Baseline

Tyrant does not assume high-accuracy absolute underwater positioning.

Baseline sensors:

* HWT905 IMU
* pressure/depth sensor

Baseline navigation does **not** assume:

* underwater GPS
* DVL
* USBL

Autonomous operation is therefore primarily based on:

* depth
* attitude
* heading
* velocity references
* timed motion
* local/relative motion
* mission actions

Absolute geographic waypoint navigation is not a baseline requirement.

---

## Repository Structure

```text
tyrant-auv/
│
├── docs/
│   ├── architecture/
│   └── protocol/
│
├── protocol/
│
├── firmware/
│   ├── teensy/
│   └── esp32/
│
├── companion/
│   └── raspberry-pi/
│
├── simulation/
│
├── gcs/
│
├── tools/
│
├── tests/
│
├── .gitignore
└── README.md
```

---

## Software Stack

Current baseline:

| Component    | Language | Role                             |
| ------------ | -------- | -------------------------------- |
| Teensy 4.1   | C++      | Real-time vehicle controller     |
| ESP32-S3     | C++      | Payload controller               |
| Raspberry Pi | Python   | Gateway, mission and logging     |
| Simulation   | Python   | Modeling and control development |
| GCS          | TBD      | Operator interface               |

Build systems and exact dependencies will be defined as the software architecture is developed.

---

## Development Strategy

Development is incremental and hardware-independent where practical.

Current software development sequence:

```text
Communication Architecture
          ↓
Communication Protocol
          ↓
Embedded Framework
          ↓
Raspberry Pi Backend
          ↓
Logging / Diagnostics
          ↓
6x8 TAM / QP
          ↓
6-DOF Dynamics
          ↓
6-DOF EKF
          ↓
6-DOF LMPC
          ↓
Mission System
          ↓
GCS
          ↓
Hardware Integration
```

Sensors and vehicle hardware may initially be replaced with simulated data so software development is not blocked by hardware availability.

---

## Current Development Focus

The current priority is establishing the software foundation:

* repository architecture
* communication architecture
* communication protocol
* Teensy firmware framework
* ESP32-S3 firmware framework
* Raspberry Pi backend
* simulated communication
* logging and diagnostics

Advanced control implementation will follow after the communication and software interfaces are stable.

---

## Research Scope

Tyrant also serves as an experimental platform for research involving:

```text
6-DOF Vehicle Dynamics
        ↓
CFD-Informed Initial Model
        ↓
Grey-Box System Identification
        ↓
Validated Vehicle Model
        ↓
6-DOF State Estimation
        ↓
6-DOF LMPC
        ↓
Constrained Thruster Allocation
        ↓
Real Vehicle Validation
```

CFD is treated as a physics-informed starting point rather than ground truth. Real vehicle experiments and system identification will be used for model refinement and validation.

---

## Project Status

🚧 **Under active development**

Mechanical and electrical development are progressing in parallel with the software stack.

The current repository should be considered an evolving engineering baseline until the core architecture is frozen.

---

## License

TBD.
