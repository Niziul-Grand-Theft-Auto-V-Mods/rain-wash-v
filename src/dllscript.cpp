#include "../inc/dllscript.h"
#include "../inc/features/wash/wash.h"
#include "../inc/rage-engine/game/game.h"
#include "../inc/rage-engine/ui/feed-post/feed_post.h"

#include <algorithm>
#include <cstdio>
#include <fstream>
#include <ios>
#include <iostream>
#include <stdio.h>
#include <string>

std::string get_dll_path()
{
    static std::string ExePathA_filePathStr;
    if (ExePathA_filePathStr.empty())
    {
        char filePath[FILENAME_MAX];
        GetModuleFileNameA(nullptr, filePath, FILENAME_MAX);
        ExePathA_filePathStr = filePath;
        ExePathA_filePathStr = ExePathA_filePathStr.substr(0, ExePathA_filePathStr.rfind('\\'));
    }
    return ExePathA_filePathStr + "\\";
}
void save_all_near_vehicles_in_the_log(Vehicle *&pool_vehicles,
                                       int &pool_count)
{
    auto log = std::ofstream{get_dll_path() += "Rain-wash-v.log", std::ios_base::app};

    for (auto i = 0; i < pool_count; i++)
    {
        char vehicle_info[256];

        auto vehicle_id
            = *(pool_vehicles + i);

        auto dirt_level
            = game::get_dirt_level(vehicle_id);

        auto distance_from_the_player
            = SYSTEM::VDIST(ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false),
                            ENTITY::GET_ENTITY_COORDS(vehicle_id, false));

        sprintf_s(vehicle_info,
                  "vehicle_id: \'%i\'; addr: \'%p\' vehicle_dirt_level: \'%f\'; vehicle_distance_from_the_player: \'%f\'\n",
                   i,
                   pool_vehicles + i,
                   dirt_level,
                   distance_from_the_player);

        log << vehicle_info;
    }

    log << "\n";

    log.close();
}

void sort_all_vehicles_by_distance(Vehicle *&vehicles,
                                   int &size)
{
    if (size < 2)
    {
        return;
    }

    std::sort(vehicles,
              vehicles + size,
              [](const Vehicle &a,
                 const Vehicle &b)
    {
        auto player_coords
              = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false);

        return
              SYSTEM::VDIST(player_coords,
                            ENTITY::GET_ENTITY_COORDS(a, false))
              <
              SYSTEM::VDIST(player_coords,
                            ENTITY::GET_ENTITY_COORDS(b, false));
    });
}
void wash_all_near_vehicles(const Vehicle *vehicles,
                            const int &count)
{
    for (auto i = 0; i < count; i++)
    {
        auto vehicle_id
            = *(vehicles + i);

        if (!ENTITY::DOES_ENTITY_EXIST(vehicle_id))
        {
            continue;
        }

        if (SYSTEM::VDIST(ENTITY::GET_ENTITY_COORDS(vehicle_id, false),
                          ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false)) > 20.0f)
        {
            continue;
        }

        auto is_vehicle_dirty
            = game::get_is_vehicle_dirty(vehicle_id);

        if (!is_vehicle_dirty)
        {
            continue;
        }

        auto decal_level
            = 1.0f;

        auto rain_level
            = game::get_rain_level();

        auto dirt_level
            = game::get_dirt_level(vehicle_id);

        auto vehicle_speed
            = game::get_vehicle_speed(vehicle_id);

        auto is_vehicle_stopped
            = game::get_is_vehicle_stopped(vehicle_id);

        if (is_vehicle_stopped)
        {
            wash::wash_vehicle_dirt(vehicle_id,
                                    dirt_level
                                        = max(0, dirt_level -= rain_level / 100.0f));
            wash::wash_vehicle_decal(vehicle_id,
                                     decal_level
                                        = max(0, decal_level = -rain_level / 100.0f));
        }
        else
        {
            wash::wash_vehicle_dirt(vehicle_id,
                                    dirt_level
                                        = max(0, dirt_level -= (rain_level / 100.0f) + (vehicle_speed / 100.0f)));
            wash::wash_vehicle_decal(vehicle_id,
                                     decal_level
                                        = max(0, decal_level -= (rain_level / 100.0f) + (vehicle_speed / 100.0f)));
        }
    }
};

void script_main()
{
    while (true)
    {
        if (!game::get_is_game_running()
            ||
            !game::get_is_raining())
        {
            WAIT(1000);

            continue;
        }

        auto pool_size
            = 32;

        auto pool_count
            = 0;

        auto pool_vehicles
            = new Vehicle[pool_size];

        pool_count
            = worldGetAllVehicles(pool_vehicles,
                                  pool_size);

        /*feedpost::postTicker(string("poo_count: ").append(std::to_string(pool_count)), true);*/

        sort_all_vehicles_by_distance(pool_vehicles,
                                      pool_count);

        /*save_all_near_vehicles_in_the_log(pool_vehicles,*/
        /*                                  pool_count);*/

        while (ENTITY::DOES_ENTITY_EXIST(*(pool_vehicles + 0)))
        {
            wash_all_near_vehicles(pool_vehicles,
                                   pool_count);

            sort_all_vehicles_by_distance(pool_vehicles,
                                          pool_count);

            if (!game::get_is_raining())
            {
                break;
            }

            if (pool_count > 1)
            {
                auto count_of_entity_that_does_exist
                    = 0;

                for (auto i = pool_count - 1; i > 0; i--)
                {
                    count_of_entity_that_does_exist
                        += !ENTITY::DOES_ENTITY_EXIST(*(pool_vehicles + i));
                }

                /*feedpost::postTicker(string("count_of_entity_that_does_exist: ").append(std::to_string(count_of_entity_that_does_exist)), true);*/

                if (count_of_entity_that_does_exist == pool_count - 1)
                {
                    break;
                }
            }

            WAIT(1000);
        }

        delete[] pool_vehicles;

        WAIT(1000);
    }

    return;
}

BOOL APIENTRY DllMain(HMODULE h_module,
                      DWORD ul_reason_for_call,
                      LPVOID lp_reserved)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
        {
            scriptRegister(h_module, script_main);
        }
        break;
        case DLL_PROCESS_DETACH:
        {
            scriptUnregister(h_module);
        }
        break;
    }
    return TRUE;
}
