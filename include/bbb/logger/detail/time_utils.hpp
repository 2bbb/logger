#pragma once

#include <chrono>
#include <ctime>
#include <string>
#include <sstream>

namespace bbb {
    namespace time_utils {
        static std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
        
        static const std::chrono::system_clock::time_point &start_time() {
            return start;
        }

        static std::chrono::system_clock::time_point now() {
            return std::chrono::system_clock::now();
        }

        template <typename type = double>
        static type get_elapsed_time() {
            return static_cast<std::chrono::duration<type>>(now() - start_time()).count();
        }

        template <typename clock_type>
        std::string get_date_string(std::chrono::time_point<clock_type> t) {
            auto as_time_t = std::chrono::system_clock::to_time_t(t);
            struct tm tm;
            char some_buffer[64];
            if(::localtime_r(&as_time_t, &tm)) {
                std::stringstream ss;
                ss << std::put_time(&tm, "%Y/%m/%d %T");
                return ss.str();
            }
            throw std::runtime_error("Failed to get current date as string");
        }

        inline static std::string get_current_date_string() {
            return get_date_string(now());
        }

    };
};