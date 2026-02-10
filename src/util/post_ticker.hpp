#pragma once

#include "common.hpp"

void postTicker(const char* message,
                bool isImportant,
                bool cacheMessage);

void postTickerWithTokens(const char* message,
                          bool isImportant,
                          bool cacheMessage);
