# VEHICLE_STATE

Message ID:

`0x0301`

Purpose:

Reports the current estimated vehicle state.

## Typical Route

```text
Teensy -> Raspberry Pi -> GCS
```

## Payload

| Field            | Type    | Unit  | Description                                  |
| ---------------- | ------- | ----- | -------------------------------------------- |
| x                | float32 | m     | Relative position X                          |
| y                | float32 | m     | Relative position Y                          |
| z                | float32 | m     | Relative position Z / depth-frame coordinate |
| roll             | float32 | rad   | Roll angle                                   |
| pitch            | float32 | rad   | Pitch angle                                  |
| yaw              | float32 | rad   | Yaw angle                                    |
| u                | float32 | m/s   | Body-frame surge velocity                    |
| v                | float32 | m/s   | Body-frame sway velocity                     |
| w                | float32 | m/s   | Body-frame heave velocity                    |
| p                | float32 | rad/s | Roll rate                                    |
| q                | float32 | rad/s | Pitch rate                                   |
| r                | float32 | rad/s | Yaw rate                                     |
| estimator_status | uint8   | enum  | Estimator health/status                      |

## Important Navigation Constraint

The Tyrant AUV baseline does not assume GPS, DVL, or USBL underwater.

Therefore, `x`, `y`, and `z` shall not automatically be interpreted as globally referenced absolute position.

The coordinate frame and origin shall be explicitly defined by the estimator implementation.
