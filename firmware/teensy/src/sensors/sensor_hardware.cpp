#include "sensors/sensor_hardware.h"

#include <Arduino.h>

#include "config/sensor_config.h"
#include "sensors/sensor_manager.h"
#include "sensors/drivers/hwt905_driver.h"


namespace
{
    TyrantSensors::Hwt905Driver hwt905(
        Serial6,
        TyrantSensorConfig::HWT905_BAUD
    );
}


namespace TyrantSensors
{
    void bindProductionSensors()
    {
        setImuSource(
            hwt905
        );
    }
}