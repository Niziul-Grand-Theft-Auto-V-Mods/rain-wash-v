#include "wash/headers/wash.h"

namespace WASH
{
    void WashVehicleDirt(int& vehicleId, float& intensity)
    {
        invoke<int>(0x79D3B596FE44EE8B, vehicleId, intensity);
    }

    void WashVehicleDecal(int& vehicleId, float& intensity)
    {
        invoke<int>(0x5B712761429DBC14, vehicleId, intensity);
    }
};