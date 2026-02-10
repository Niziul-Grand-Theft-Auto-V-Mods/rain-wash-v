#pragma once

#include "common.hpp"

int get_player_id();

int get_player_ped_id();

int get_vehicle_id(int &playerId);

float get_rain_level();

float get_dirt_level(int &vehicleId);

float get_vehicle_speed(int &vehicleId);

bool get_is_game_running();

bool get_is_vehicle_stopped(int &vehicleId);

bool get_is_entity_not_in_game(int &entityId);

bool get_is_player_sitting_in_this_vehicle(int &playerPedId);

bool get_is_raining();

bool get_is_vehicle_dirty(int &vehicleId);

