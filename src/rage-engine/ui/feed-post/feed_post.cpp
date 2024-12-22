//
// Copyright (C) 2015 crosire & kagikn & contributors
// License: https://github.com/scripthookvdotnet/scripthookvdotnet#license
//

#include "../../../../inc/rage-engine/ui/feed-post/feed_post.h"

namespace feedpost
{
    void postTicker(string message,
                    bool isImportant,
                    bool cacheMessage)
    {
        HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("CELL_EMAIL_BCON");
        HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(message.data());
        HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(isImportant,
                                                  cacheMessage);
    }

    void postTickerForced(string message,
                          bool isImportant,
                          bool cacheMessage)
    {
        HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("CELL_EMAIL_BCON");
        HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(message.data());
        HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER_FORCED(isImportant,
                                                         cacheMessage);
    }

    void postTickerWithTokens(string message,
                              bool isImportant,
                              bool cacheMessage)
    {
        HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("CELL_EMAIL_BCON");
        HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(message.data());
        HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER_WITH_TOKENS(isImportant,
                                                              cacheMessage);
    }
    void postMessageWithDefaultIcon(string message,
                                    string topHeader,
                                    string bottomHeader,
                                    eFeedMessageType messageType,
                                    eFeedPostMessageIconType messageIconType,
                                    bool isImportant)
    {
        HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("CELL_EMAIL_BCON");
        HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(message.data());
        HUD::END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT(icon_name[messageIconType],
                                                       icon_name[messageIconType],
                                                       isImportant,
                                                       messageType,
                                                       topHeader.data(),
                                                       bottomHeader.data());
    }

    void postMessageWithCustomIcon(string message,
                                   string topHeader,
                                   string bottomHeader,
                                   string textureName,
                                   string textureDictionaryName,
                                   eFeedMessageType messageType,
                                   bool isImportant)
    {
        HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("CELL_EMAIL_BCON");
        HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(message.data());
        HUD::END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT(textureName.data(),
                                                       textureDictionaryName.data(),
                                                       isImportant,
                                                       messageType,
                                                       topHeader.data(),
                                                       bottomHeader.data());
    }
};
