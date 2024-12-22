namespace game
{
    int get_player_id();
    int get_player_ped_id();
    int get_vehicle_id(int&);
    float get_rain_level();
    float get_dirt_level(int&);
    float get_vehicle_speed(int&);

    inline bool get_is_raining()
    {
        return get_rain_level() != 0.0f;
    }

    bool get_is_game_running();

    inline bool get_is_vehicle_dirty(int &vehicleId)
    {
        return get_dirt_level(vehicleId) > 0.0f;
    }

    bool get_is_vehicle_stopped(int&);
    bool get_is_entity_not_in_game(int&);
    bool get_is_player_sitting_in_this_vehicle(int&);
}
