#pragma once

namespace GAME
{
    bool GetIsGameRunning();

    int GetPlayerId();

    int GetPlayerPedId();

    bool GetIsEntityNotInGame(int&);

    bool GetIsPlayerSittingInVehicle(int&);

    bool GetIsRaining();

    bool GetIsVehicleDirty(int&);

    bool GetIsVehicleStopped(int&);

    int GetVehicleId(int&);

    float GetRainLevel();
    
    float GetVehicleSpeed(int&);

    float GetDirtLevel(int&);
};