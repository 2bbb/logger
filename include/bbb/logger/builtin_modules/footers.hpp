#pragma once

#include <string>
#include <iomanip>
#include <utility>

#include "../log_level.hpp"
#include "../modules/footer.hpp"
#include "../detail/time_utils.hpp"

namespace bbb {
    struct time_footer : footer {
        std::string foot(std::string tag, log_level level) const {
            return " (at " + time_utils::get_current_date_string() + ")";
        }
        void set_footer_time_format(const std::string &format) {
            this->format = format;
        }
    private:
        std::string format{"%Y/%m/%d %T"};
    };

    struct elapsed_time_footer : footer {
        std::string foot(std::string tag, log_level level) const {
            return " (elapsed " + std::to_string(time_utils::get_elapsed_time()) + ")";
        }
    };
};