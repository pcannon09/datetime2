#pragma once

#include <chrono>
#include <string>

namespace dt 
{
    extern std::string version;

    typedef std::chrono::time_point<std::chrono::system_clock> sysClock;

    /// @brief Update current time
    /// @return sysClock 
    sysClock get();

    /// @brief Sets time mode (12h or 24)
    /// @param sysClock
    /// @return bool
    bool set24h(bool x);

    /// @brief Gets if it's Am or Pm
    /// @param sysClock
    /// @return std::string 
    std::string amOrPm(sysClock timeNow);

    /// @brief Get second from the last update
    /// @param timeNow
    /// @return int
    int sec(sysClock timeNow);

    /// @brief Get second from the last update
    /// @param timeNow
    /// @return int
    int second(sysClock timeNow);

    /// @brief Get the hour from the last update
    /// @param timeNow
    /// @return int
    int hour(sysClock timeNow);

    /// @brief Get the hour from the last update
    /// @param timeNow
    /// @return int
    int hr(sysClock timeNow);

    /// @brief Get minute from the last update
    /// @return int
    int minute();

    /// @brief Get minute from the last update
    /// @return int
    int min();

    /// @brief Get millisecond from the last update
    /// @param timeNow
    /// @return int
    int ms(sysClock timeNow);

    /// @brief Get millisecond ffrom the last update
    /// @param timeNow
    /// @return int
    int milliseconds(sysClock timeNow);

    /// @brief Get microseconds from the last update
    /// @param timeNow
    /// @return int
    int us(sysClock timeNow);

    /// @brief Get microseconds from the last update
    /// @param timeNow
    /// @return int
    int microseconds(sysClock timeNow);

    /// @brief Get the current year
    /// @return int
    int year();

    /// @brief Get the day of the week
    /// @return int
    int wday();
    
    /// @brief Get current day of the month
    /// @return int
    int day();

    /// @brief Get current month
    /// @return int
    int month();

    /// @brief Get day of the year
    /// @return int
    int yday();
    
    /// @brief DST
    /// @return int
    int isdst();
    
    /// @brief Gets the current time zone 
    /// @return std::string 
    std::string timezone();
}
