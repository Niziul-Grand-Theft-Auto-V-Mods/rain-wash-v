#pragma once

#include <filesystem>

class Settings {
public:
  float get_rate_at_which_rain_will_clean_the_vehicle();
  
private:
  std::filesystem::path m_file = std::filesystem::current_path() / "RainWashV" / "settings.toml";
};

