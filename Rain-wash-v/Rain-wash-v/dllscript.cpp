#include "dllscript.h"
#include "wash/headers/wash.h"
#include "game/headers/game.h"

#ifdef _DEBUG

#include "ui/feed-post/feed_post.h"

#endif

using namespace GAME;
using namespace WASH;

#ifdef _DEBUG

using namespace FEEDPOST;

#endif

static void Update()
{
    auto static playerId
        = int{};

    auto static playerPedId
        = int{};

    auto static vehicleId
        = int{};

    auto static vehicleSpeed
        = float{};

    auto static rainLevel
        = float{};

    auto static dirtLevel
        = float{};

    auto static decalLevel
        = 1.0f;

    auto static isRaining
        = false;

    auto static isVehicleDirty
        = false;

    auto static isVehicleStopped
        = false;

    if (!GetIsGameRunning())
    {
        return;
    }

    playerPedId
        = GetPlayerPedId();

    if (!GetIsEntityNotInGame(playerPedId)
        &&
        !GetIsPlayerSittingInVehicle(playerPedId))
    {
        return;
    }
    
    playerId
        = GetPlayerId();

    vehicleId
        = GetVehicleId(playerId);

    isRaining
        = GetIsRaining();

    isVehicleDirty
        = GetIsVehicleDirty(vehicleId);

    if (!isRaining
        ||
        !isVehicleDirty)
    {
        return;
    }

    rainLevel
        = GetRainLevel();

    dirtLevel
        = GetDirtLevel(vehicleId);

    vehicleSpeed
        = GetVehicleSpeed(vehicleId);
    
    if (vehicleSpeed > 15.0f)
    {
        dirtLevel
            -= 1e-3f + (vehicleSpeed / 100.0f);
        
        WashVehicleDirt(vehicleId, dirtLevel
                                        = dirtLevel > 0.00f ? dirtLevel : 0.00f);
    }

    if (vehicleSpeed > 35.0f)
    {
        decalLevel
            -= 1e-3f + (vehicleSpeed / 100.0f);
        
        WashVehicleDecal(vehicleId, decalLevel
                                        = decalLevel > 0.99f ? decalLevel : 0.99f);
    }

#ifdef _DEBUG

    postTickerWithTokens(std
                            ::to_string(vehicleSpeed)
                                .append(" - ~r~vehicle_speed~w~"));
    postTickerWithTokens(std
                            ::to_string(decalLevel)
                                .append(" - ~r~decal_level~w~"));
    postTickerWithTokens(std
                            ::to_string(dirtLevel)
                                .append(" - ~r~dirt_level~w~"));
    postTickerWithTokens(std
                            ::to_string(rainLevel)
                                .append(" - ~r~rain_level~w~"));

#endif

    return;
}

void ScriptMain()
{
    while (true)
    {
        Update();

        WAIT(1000);
    }

    return;
}
