#include <natives.h>
#include "game/headers/game.h"

using namespace PED;
using namespace DLC;
using namespace MISC;
using namespace PLAYER;
using namespace ENTITY;
using namespace VEHICLE;
using namespace GRAPHICS;

namespace GAME
{
    bool GetIsGameRunning()
    {
        return !GET_IS_LOADING_SCREEN_ACTIVE();
    }
    
    int GetPlayerId()
    {
        return PLAYER_ID();
    }

    int GetPlayerPedId()
    {
        return PLAYER_PED_ID();
    }

    bool GetIsEntityNotInGame(int& entityId)
    {
        return !DOES_ENTITY_EXIST(entityId);
    }

    bool GetIsPlayerSittingInVehicle(int& playerPedId)
    {
        return IS_PED_SITTING_IN_ANY_VEHICLE(playerPedId);
    }
    
    bool GetIsRaining()
    {
        return GetRainLevel() != 0.0f;
    }

    bool GetIsVehicleDirty(int& vehicleId)
    {
        return GetDirtLevel(vehicleId) > 0.0f;
    }

    bool GetIsVehicleStopped(int& vehicleId)
    {
        return IS_VEHICLE_STOPPED(vehicleId);
    }

    int GetVehicleId(int& playerId)
    {
        return GET_VEHICLE_PED_IS_IN(GET_PLAYER_PED(playerId), false);
    }

    float GetRainLevel()
    {
        return GET_RAIN_LEVEL();
    }

    float GetVehicleSpeed(int& vehicleId)
    {
        return GET_ENTITY_SPEED(vehicleId);
    }

    float GetDirtLevel(int& vehicleId)
    {
        return GET_VEHICLE_DIRT_LEVEL(vehicleId);
    }
};