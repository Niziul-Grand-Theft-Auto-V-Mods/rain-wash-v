#include "wash.hpp"

void wash_vehicle_dirt(int &vehicleId,
                       float &intensity)
{
  VEHICLE::SET_VEHICLE_DIRT_LEVEL(vehicleId,
                                  intensity);
}

void wash_vehicle_decal(int &vehicleId,
                        const float intensity)
{
  GRAPHICS::WASH_DECALS_FROM_VEHICLE(vehicleId,
                                     intensity);
}
