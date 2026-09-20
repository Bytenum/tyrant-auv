#include "sensors/depth_estimator.h"


namespace TyrantSensors
{
    DepthEstimator::DepthEstimator(
        float water_density_kg_m3
    )
    {
        setWaterDensity(
            water_density_kg_m3
        );
    }


    bool DepthEstimator::setSurfacePressure(
        float pressure_pa
    )
    {
        if (pressure_pa <= 0.0f)
        {
            return false;
        }


        surface_pressure_pa_ =
            pressure_pa;


        surface_reference_valid_ =
            true;


        return true;
    }


    void DepthEstimator::clearSurfaceReference()
    {
        surface_pressure_pa_ =
            0.0f;


        surface_reference_valid_ =
            false;
    }


    bool DepthEstimator::surfaceReferenceValid() const
    {
        return surface_reference_valid_;
    }


    float DepthEstimator::getSurfacePressure() const
    {
        return surface_pressure_pa_;
    }


    bool DepthEstimator::setWaterDensity(
        float water_density_kg_m3
    )
    {
        if (water_density_kg_m3 <= 0.0f)
        {
            return false;
        }


        water_density_kg_m3_ =
            water_density_kg_m3;


        return true;
    }


    float DepthEstimator::getWaterDensity() const
    {
        return water_density_kg_m3_;
    }


    bool DepthEstimator::estimateDepth(
        const PressureSample &sample,
        float &depth_m
    ) const
    {
        if (!surface_reference_valid_)
        {
            return false;
        }


        if (!sample.valid)
        {
            return false;
        }


        const float delta_pressure_pa =
            sample.pressure_pa -
            surface_pressure_pa_;


        depth_m =
            delta_pressure_pa /
            (
                water_density_kg_m3_ *
                GRAVITY_MPS2
            );


        return true;
    }

    bool DepthEstimator::estimateMeasurement(
        const PressureSample &sample,
        DepthMeasurement &measurement
    ) const
    {
        measurement.sequence =
            sample.sequence;

        measurement.timestamp_us =
            sample.timestamp_us;

        measurement.depth_m =
            0.0f;

        measurement.valid =
            false;


        float depth_m = 0.0f;


        if (
            !estimateDepth(
                sample,
                depth_m
            )
        )
        {
            return false;
        }


        measurement.depth_m =
            depth_m;

        measurement.valid =
            true;


        return true;
    }
}
