#pragma once

#include "nativeCaller.h"

namespace DLC
{
    // https://nativedb.dotindustries.dev/natives/0x10D0A8F259E93EC9
    static BOOL GET_IS_LOADING_SCREEN_ACTIVE()
    {
        return invoke<BOOL>(0x10D0A8F259E93EC9);
    } // 0x10D0A8F259E93EC9 0x517B601B b323
};

namespace GRAPHICS
{
    // https://nativedb.dotindustries.dev/natives/0x323F647679A09103
    static float GET_DECAL_WASH_LEVEL(int decal)
    {
        return invoke<float>(0x323F647679A09103, decal);
    } // 0x323F647679A09103 0x054448EF b323

    // https://nativedb.dotindustries.dev/natives/0xE91F1B65F2B48D57
    static void REMOVE_DECALS_FROM_VEHICLE(int vehicle)
    {
        invoke<int>(0xE91F1B65F2B48D57, vehicle);
    } // 0xE91F1B65F2B48D57 0x831D06CA b323
}

namespace HUD
{
    // https://nativedb.dotindustries.dev/natives/0x8509B634FBE7DA11
    static void BEGIN_TEXT_COMMAND_DISPLAY_HELP(const char* inputType)
    {
        invoke<int>(0x8509B634FBE7DA11, inputType);
    } // 0x8509B634FBE7DA11 0xB245FC10 b323

    // https://nativedb.dotindustries.dev/natives/0x238FFE5C7B0498A6
    static void END_TEXT_COMMAND_DISPLAY_HELP(BOOL loop, BOOL beep, int duration)
    {
        invoke<int>(0x238FFE5C7B0498A6, 0, loop, beep, duration);
    } // 0x238FFE5C7B0498A6 0xB59B530D b323

    // https://nativedb.dotindustries.dev/natives/0x202709F4C58A0424
    static void BEGIN_TEXT_COMMAND_THEFEED_POST(const char* text)
    {
        invoke<int>(0x202709F4C58A0424, text);
    } // 0x202709F4C58A0424 0x574EE85C b323

    // https://nativedb.dotindustries.dev/natives/0x2ED7843F8F801023
    static int END_TEXT_COMMAND_THEFEED_POST_TICKER(BOOL is_important, BOOL cache_message)
    {
        return invoke<int>(0x2ED7843F8F801023, is_important, cache_message);
    } // 0x2ED7843F8F801023 0x08F7AF78 b323

    // https://nativedb.dotindustries.dev/natives/0x44FA03975424A0EE
    static int END_TEXT_COMMAND_THEFEED_POST_TICKER_FORCED(BOOL is_important, BOOL cache_message)
    {
        return invoke<int>(0x44FA03975424A0EE, is_important, cache_message);
    } // 0x44FA03975424A0EE 0x57B8D0D4 b323

    // https://nativedb.dotindustries.dev/natives/0x378E809BF61EC840
    static int END_TEXT_COMMAND_THEFEED_POST_TICKER_WITH_TOKENS(BOOL is_important, BOOL cache_message)
    {
        return invoke<int>(0x378E809BF61EC840, is_important, cache_message);
    } // 0x378E809BF61EC840 0x02BCAF9B b323

    // https://nativedb.dotindustries.dev/natives/0x1CCD9A37359072CF
    static int END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT(const char* picTxd, const char* picTxn, const char* sender, const char* subject, int iconType, BOOL flash)
    {
        return invoke<int>(0x1CCD9A37359072CF, picTxd, picTxn, flash, iconType, sender, subject);
    } // 0x1CCD9A37359072CF 0xE7E3C98B b323

    // https://nativedb.dotindustries.dev/natives/0x6C188BE134E074AA
    static void ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(const char* text)
    {
        invoke<int>(0x6C188BE134E074AA, text);
    } // 0x6C188BE134E074AA 0x27A244D8 b323
};

namespace ENTITY
{
    // https://nativedb.dotindustries.dev/natives/0xD5037BA82E12416F
    static float GET_ENTITY_SPEED(int entityId)
    {
        return invoke<float>(0xD5037BA82E12416F, entityId);
    } // 0xD5037BA82E12416F 0x9E1E4798 b323

    // https://nativedb.dotindustries.dev/natives/0x7239B21A38F536BA
    static BOOL DOES_ENTITY_EXIST(int entityId)
    {
        return invoke<BOOL>(0x7239B21A38F536BA, entityId);
    } // 0x7239B21A38F536BA 0x3AC90869 b323
}

namespace PLAYER
{
    // https://nativedb.dotindustries.dev/natives/0x4F8644AF03D0E0D6
    static int PLAYER_ID()
    {
        return invoke<int>(0x4F8644AF03D0E0D6);
    } // 0x4F8644AF03D0E0D6 0x8AEA886C b323

    // https://nativedb.dotindustries.dev/natives/0xD80958FC74E988A6
    static int PLAYER_PED_ID()
    {
        return invoke<int>(0xD80958FC74E988A6);
    } // 0xD80958FC74E988A6

    // https://nativedb.dotindustries.dev/natives/0x43A66C31C68491C0
    static int GET_PLAYER_PED(int player)
    {
        return invoke<int>(0x43A66C31C68491C0, player);
    } // 0x43A66C31C68491C0 0x6E31E993 b323
}

namespace PED
{
    // https://nativedb.dotindustries.dev/natives/0x826AA586EDB9FEF8
    static BOOL IS_PED_SITTING_IN_ANY_VEHICLE(int ped)
    {
        return invoke<BOOL>(0x826AA586EDB9FEF8, ped);
    } // 0x826AA586EDB9FEF8 0x0EA9CA03 b323
    
    // https://nativedb.dotindustries.dev/natives/0xA808AA1D79230FC2
    static BOOL IS_PED_SITTING_IN_VEHICLE(int ped, int vehicle)
    {
        return invoke<BOOL>(0xA808AA1D79230FC2, ped, vehicle);
    } // 0xA808AA1D79230FC2 0xDDDE26FA b323

    // https://nativedb.dotindustries.dev/natives/0x9A9112A0FE9A4713
    static int GET_VEHICLE_PED_IS_IN(int ped, BOOL lastVehicle = false)
    {
        return invoke<int>(0x9A9112A0FE9A4713, ped, lastVehicle);
    } // 0x9A9112A0FE9A4713 0xAFE92319 b323
}

namespace VEHICLE
{
    // https://nativedb.dotindustries.dev/natives/0x8F17BC8BA08DA62B
    static float GET_VEHICLE_DIRT_LEVEL(int vehicle)
    {
        return invoke<float>(0x8F17BC8BA08DA62B, vehicle);
    } // 0x8F17BC8BA08DA62B 0xFD15C065 b323
}

namespace MISC
{
    // https://nativedb.dotindustries.dev/natives/0x96695E368AD855F3
    static float GET_RAIN_LEVEL()
    {
        return invoke<float>(0x96695E368AD855F3);
    } // 0x96695E368AD855F3 0xC9F67F28 b323
};