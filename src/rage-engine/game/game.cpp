#include "../../../inc/rage-engine/game/game.h"
#include "../../../inc/util/natives.h"

namespace game
{

int get_player_id()
{
    return PLAYER::PLAYER_ID();
}

int get_player_ped_id()
{
    return PLAYER::PLAYER_PED_ID();
}

int get_vehicle_id(int &playerId)
{
    return PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(playerId), false);
}

float get_rain_level()
{
    return MISC::GET_RAIN_LEVEL();
}

float get_dirt_level(int &vehicleId)
{
    return VEHICLE::GET_VEHICLE_DIRT_LEVEL(vehicleId);
}

float get_vehicle_speed(int &vehicleId)
{
    return ENTITY::GET_ENTITY_SPEED(vehicleId);
}

bool get_is_game_running()
{
    return !DLC::GET_IS_LOADING_SCREEN_ACTIVE();
}

bool get_is_vehicle_stopped(int &vehicleId)
{
    return VEHICLE::IS_VEHICLE_STOPPED(vehicleId);
}

bool get_is_entity_not_in_game(int &entityId)
{
    return !ENTITY::DOES_ENTITY_EXIST(entityId);
}

bool get_is_player_sitting_in_this_vehicle(int &playerPedId)
{
    return PED::IS_PED_SITTING_IN_ANY_VEHICLE(playerPedId);
}
} // namespace game
