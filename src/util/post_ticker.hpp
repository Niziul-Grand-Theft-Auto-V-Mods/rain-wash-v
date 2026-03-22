#pragma once

#include "common.hpp"
#include <string_view>

void postTicker(const std::string_view message,
                bool isImportant,
                bool cacheMessage);

void postTickerWithTokens(const std::string_view message,
                          bool isImportant,
                          bool cacheMessage);
