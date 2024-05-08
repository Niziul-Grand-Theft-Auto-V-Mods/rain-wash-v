//
// Copyright (C) 2015 crosire & kagikn & contributors
// License: https://github.com/scripthookvdotnet/scripthookvdotnet#license
//

#pragma once

#include <string>
#include <natives.h>
#include "enums/feed_message_type.h"
#include "enums/feed_post_message_icon_type.h"

using std::string;

namespace FEEDPOST
{
    
    /// <summary>
    /// Displays the ticker text string above the top left of the minimap.
    /// </summary>
    /// <param name="message">
    /// : The text body.
    /// </param>
    /// <param name="isImportant">
    /// : If set to <see langword="true"/>, the text will flash and may have a custom background color
    /// or vibrate the controller.
    /// </param>
    /// <param name="cacheMessage">
    /// : If set to <see langword="true"/>, the text will be cached in the pause menu.
    /// </param>
    void postTicker(string message,
                    bool isImportant,
                    bool cacheMessage = true);

    /// <summary>
    /// Displays the ticker text string above the top left of the minimap even if feed is paused.
    /// </summary>
    /// <param name="message">
    /// : The text body.
    /// </param>
    /// <param name="isImportant">
    /// : If set to <see langword="true"/>, the text will flash and may have a custom background color
    /// or vibrate the controller.
    /// </param>
    /// <param name="cacheMessage">
    /// : If set to <see langword="true"/>, the text will be cached in the pause menu.
    /// </param>
    void postTickerForced(string message,
                          bool isImportant,
                          bool cacheMessage = true);

    /// <summary>
    /// Displays the ticker text string above the top left of the minimap
    /// containing tokens (i.e. <c>~BLIP_INFO_ICON~</c>).
    /// </summary>
    /// <param name="message">
    /// : The text body.
    /// </param>
    /// <param name="isImportant">
    /// : If set to <see langword="true"/>, the text will flash and may have a custom background color
    /// or vibrate the controller.
    /// </param>
    /// <param name="cacheMessage">
    /// : If set to <see langword="true"/>, the text will be cached in the pause menu.
    /// </param>
    void postTickerWithTokens(string message,
                              bool isImportant = true,
                              bool cacheMessage = true);
    /// <summary>
    /// Displays the text message contact with default image and localised text message string in the top left of the HUD.
    /// </summary>
    /// <param name="message">
    /// : The message body.
    /// </param>
    /// <param name="topHeader">
    /// : The character name, that is to say the sender.
    /// </param>
    /// <param name="bottomHeader">
    /// : The subtitle (subject) of the text message.
    /// </param>
    /// <param name="messageType">
    /// : The text type.
    /// </param>
    /// <param name="messageIconType">
    /// : The message icon type.
    /// </param>
    /// <param name="isImportant">
    /// : If set to <see langword="true"/>, the message will flash and may have a custom background color
    /// or vibrate the controller.
    /// </param>
    void postMessageWithDefaultIcon(string message,
                                    string topHeader,
                                    string bottomHeader,
                                    eFeedMessageType messageType,
                                    eFeedPostMessageIconType messageIconType,
                                    bool isImportant = true);

    /// <summary>
    /// Displays the text message contact with custom image and localised text message string in the top left of the HUD.
    /// </summary>
    /// <param name="message">
    /// : The message body.
    /// </param>
    /// <param name="textureName">
    /// : The name of the texture for the contact image used in the text
    /// message.
    /// </param>
    /// <param name="textureDictionaryName">
    /// : The name of the texture dictionary for the contact image used in the text
    /// message.
    /// </param>
    /// <param name="topHeader">
    /// : The character name, that is to say the sender.
    /// </param>
    /// <param name="bottomHeader">
    /// : The subtitle (subject) of the text message.
    /// </param>
    /// <param name="messageType">
    /// : The icon type.
    /// </param>
    /// <param name="isImportant">
    /// : If set to <see langword="true"/>, the message will flash and may have a custom background color
    /// or vibrate the controller.
    /// </param>
    void postMessageWithCustomIcon(string message,
                                   string topHeader,
                                   string bottomHeader,
                                   string textureName,
                                   string textureDictionaryName,
                                   eFeedMessageType messageType,
                                   bool isImportant = true);
};