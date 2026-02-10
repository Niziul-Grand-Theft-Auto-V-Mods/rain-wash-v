#include "settings.hpp"
#include "post_ticker.hpp"
#include "../../inc/toml/toml.hpp"

float Settings::get_rate_at_which_rain_will_clean_the_vehicle()
{
  const auto parse_result = toml::try_parse(m_file, toml::spec::v(1, 1, 0));

  if (parse_result.is_ok())
  {
    postTickerWithTokens("parse_result.~b~is_ok~w~", true, true);

    return parse_result.unwrap().at("rwv").at("rate").as_floating();
  }
  else {
    postTickerWithTokens("parse_result.~r~is_err~w~", true, true);
  }

  return 0.000069f;
}
