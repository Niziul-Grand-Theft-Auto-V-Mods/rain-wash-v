//
// Copyright (C) 2015 crosire & kagikn & contributors
// License: https://github.com/scripthookvdotnet/scripthookvdotnet#license
//

#include "ui/feed-post/feed_post.h"

using namespace HUD;

namespace FEEDPOST
{
    void postTicker(string message,
                    bool isImportant,
                    bool cacheMessage)
    {
        BEGIN_TEXT_COMMAND_THEFEED_POST("CELL_EMAIL_BCON");
        ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(message.data());
        END_TEXT_COMMAND_THEFEED_POST_TICKER(isImportant, cacheMessage);
    }

    void postTickerForced(string message,
                          bool isImportant,
                          bool cacheMessage)
    {
        BEGIN_TEXT_COMMAND_THEFEED_POST("CELL_EMAIL_BCON");
        ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(message.data());
        END_TEXT_COMMAND_THEFEED_POST_TICKER_FORCED(isImportant, cacheMessage);
    }

    void postTickerWithTokens(string message,
                              bool isImportant,
                              bool cacheMessage)
    {
        BEGIN_TEXT_COMMAND_THEFEED_POST("CELL_EMAIL_BCON");
        ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(message.data());
        END_TEXT_COMMAND_THEFEED_POST_TICKER_WITH_TOKENS(isImportant, cacheMessage);
    }
    void postMessageWithDefaultIcon(string message,
                                    string topHeader,
                                    string bottomHeader,
                                    eFeedMessageType messageType,
                                    eFeedPostMessageIconType messageIconType,
                                    bool isImportant)
    {
        BEGIN_TEXT_COMMAND_THEFEED_POST("CELL_EMAIL_BCON");
        ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(message.data());
        END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT(icon_name[messageIconType],
                                                  icon_name[messageIconType],
                                                  topHeader.data(),
                                                  bottomHeader.data(),
                                                  messageType,
                                                  isImportant);
    }

    void postMessageWithCustomIcon(string message,
                                   string topHeader,
                                   string bottomHeader,
                                   string textureName,
                                   string textureDictionaryName,
                                   eFeedMessageType messageType,
                                   bool isImportant)
    {
        BEGIN_TEXT_COMMAND_THEFEED_POST("CELL_EMAIL_BCON");
        ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(message.data());
        END_TEXT_COMMAND_THEFEED_POST_MESSAGETEXT(textureDictionaryName.data(),
                                                  textureName.data(),
                                                  topHeader.data(),
                                                  bottomHeader.data(),
                                                  messageType,
                                                  isImportant);
    }
};
