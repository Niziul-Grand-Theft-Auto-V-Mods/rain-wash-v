#include "script.hpp"
#include "util/game.hpp"
#include "util/settings.hpp"
#include "util/wash.hpp"
#include "util/post_ticker.hpp"
#include <stdio.h>

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
      = get_is_vehicle_dirty(vehicle_id);

    if (!is_vehicle_dirty)
    {
      continue;
    }

    /*auto decal_level*/
    /*= 1.0f;*/

    auto rain_level
      = get_rain_level();

    auto dirt_level
      = get_dirt_level(vehicle_id);

    auto vehicle_speed
      = get_vehicle_speed(vehicle_id);

    auto is_vehicle_stopped
      = get_is_vehicle_stopped(vehicle_id);

    if (is_vehicle_stopped)
    {
      wash_vehicle_dirt(vehicle_id,
                        dirt_level
                        = max(0.0f, dirt_level -= rain_level / 100.0f));
    }
    else
    {
        wash_vehicle_dirt(vehicle_id,
                          dirt_level
                          = max(0.0f, dirt_level -= (rain_level / 100.0f) + (vehicle_speed / 100.0f)));

        if (vehicle_speed > 5.0f)
        {
          wash_vehicle_decal(vehicle_id, 0.015f);
        }
      }
    }
};

void script_main()
{
  auto b_welcome
    = false;

  while (true)
  {
    auto player
      = PLAYER::PLAYER_ID();
    auto player_ped
      = PLAYER::PLAYER_PED_ID();

    if (DLC::GET_IS_LOADING_SCREEN_ACTIVE()
        ||
        !ENTITY::DOES_ENTITY_EXIST(player_ped)
        ||
        !PLAYER::IS_PLAYER_CONTROL_ON(player))
    {
      WAIT(0);
      continue;
    }

    if (PED::IS_PED_INJURED(player_ped)
        ||
        PLAYER::IS_PLAYER_BEING_ARRESTED(player, TRUE))
    {
      WAIT(0);
      continue;
    }

    if (!b_welcome)
    {
      postTickerWithTokens("rain wash v - by ~b~niziul~w~", true, true);
      b_welcome = true;
    }

    if (MISC::HAS_PC_CHEAT_WITH_HASH_BEEN_ACTIVATED("rwvcs"_J))
    {
      char info[64];

      sprintf_s(info, "rwvs: rate - \'~b~%f~w~\'", Settings().get_rate_at_which_rain_will_clean_the_vehicle());

      postTickerWithTokens(info, true, true);
    }

    WAIT(0);
  }

  return;
}
