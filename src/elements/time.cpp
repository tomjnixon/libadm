#include "adm/elements/time.hpp"
#include <boost/format.hpp>
#include <iomanip>
#include <regex>
#include <sstream>

namespace adm {

  std::chrono::nanoseconds parseTimecode(const std::string& timecode) {
    // find pos of decimal point, and check there's only one
    size_t dp_pos = timecode.size();
    for (size_t i = 0; i < timecode.size(); i++) {
      if (timecode[i] == '.') {
        if (dp_pos != timecode.size()) {
          throw std::runtime_error("invalid timecode: " + timecode);
        }

        dp_pos = i;
      }
    }

    uint64_t total_ns = 0;

    // parse the part after the decimal point
    {
      uint64_t place_value = 100000000L;
      for (size_t i = dp_pos + 1; i < timecode.size(); i++) {
        char c = timecode[i];

        if ('0' <= c && c <= '9') {
          total_ns += place_value * (c - '0');
          place_value /= 10;
        } else {
          throw std::runtime_error("invalid timecode: " + timecode);
        }
      }
    }

    // parse the ':' seperated parts before the decimal point, working backwards
    {
      uint64_t part_value = 1000000000L;
      uint64_t place_value = part_value;
      uint64_t num_parts = 0;
      for (int i = dp_pos - 1; i >= 0; i--) {
        char c = timecode[i];

        if ('0' <= c && c <= '9') {
          total_ns += place_value * (c - '0');
          place_value *= 10;
        } else if (c == ':' && num_parts < 2) {
          part_value *= 60;
          place_value = part_value;
          num_parts++;
        } else {
          throw std::runtime_error("invalid timecode: " + timecode);
        }
      }
    }

    return std::chrono::nanoseconds(total_ns);
  }

  std::string formatTimecode(const std::chrono::nanoseconds& time) {
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0')
       << std::chrono::duration_cast<std::chrono::hours>(time).count();
    ss << ":";
    ss << std::setw(2) << std::setfill('0')
       << std::chrono::duration_cast<std::chrono::minutes>(time).count() % 60;
    ss << ":";
    ss << std::setw(2) << std::setfill('0')
       << std::chrono::duration_cast<std::chrono::seconds>(time).count() % 60;
    ss << ".";
    ss << std::setw(9) << std::setfill('0') << time.count() % 1000000000;
    return ss.str();
  }

}  // namespace adm
