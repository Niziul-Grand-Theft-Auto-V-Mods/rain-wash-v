#include "post_ticker.hpp"
#include <string_view>

void postTicker(const std::string_view message,
                bool isImportant,
                bool cacheMessage)
{
  HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("CELL_EMAIL_BCON");
  HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(message.data());
  HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER_FORCED(isImportant,
                                                   cacheMessage);
}

void postTickerWithTokens(const std::string_view message,
                          bool isImportant,
                          bool cacheMessage)
{
  HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("CELL_EMAIL_BCON");
  HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(message.data());
  HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER_WITH_TOKENS(isImportant,
                                                        cacheMessage);
}
