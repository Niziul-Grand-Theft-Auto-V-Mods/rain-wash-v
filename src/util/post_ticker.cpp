#include "post_ticker.hpp"

void postTicker(const char* message,
                bool isImportant,
                bool cacheMessage)
{
  HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("CELL_EMAIL_BCON");
  HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(message);
  HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER_FORCED(isImportant,
                                                   cacheMessage);
}

void postTickerWithTokens(const char* message,
                          bool isImportant,
                          bool cacheMessage)
{
  HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("CELL_EMAIL_BCON");
  HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(message);
  HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER_WITH_TOKENS(isImportant,
                                                        cacheMessage);
}
