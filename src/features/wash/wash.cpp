#pragma once

#include "../../../inc/util/natives.h"
#include "../../../inc/features/wash/wash.h"

void wash::wash_vehicle_dirt(int &vehicleId, float &intensity)
{
    VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicleId, intensity);
}

void wash::wash_vehicle_decal(int &vehicleId, float &intensity)
{
    GRAPHICS::WASH_DECALS_FROM_VEHICLE(vehicleId, intensity);
}
