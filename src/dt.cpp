#include <chrono>
#include <ctime>
#include <string>

namespace dt 
{
    std::string version = "2.0";

    bool modeIs24h = true;

    std::time_t xtm;

    typedef std::chrono::time_point<std::chrono::system_clock> sysClock;

    sysClock get()
    {
        sysClock x = std::chrono::system_clock::now();

        xtm = std::chrono::system_clock::to_time_t(x);

        return x;
    }

    bool set24h(bool x)
    {
        modeIs24h = x;

        return x;
    }

    std::string amOrPm(sysClock timeNow)
    {
        auto x = std::chrono::duration_cast<std::chrono::hours>(timeNow.time_since_epoch());

        if (static_cast<int>(x.count() % 24) >= 12)
        {
            return "Pm";
        }

        return "Am";
    }

    int sec(sysClock timeNow)
    {
        auto x = std::chrono::duration_cast<std::chrono::seconds>(timeNow.time_since_epoch());

        return static_cast<int>(x.count() % 60);
    }

    int second(sysClock timeNow)
    {
        return sec(timeNow);
    }

    int hour(sysClock timeNow)
    {
        std::tm *timeNowX = std::localtime(&xtm);

        if (amOrPm(timeNow) == "Pm" && modeIs24h)
        {
            return timeNowX->tm_hour - 12;
        }

        return timeNowX->tm_hour;
    }

    int min()
    {
        std::tm *timeNowX = std::localtime(&xtm);

        return timeNowX->tm_min;
    }

    int minute()
    {
        return min();
    }

    int hr(sysClock timeNow)
    {
        return hour(timeNow);
    }
    
    int ms(sysClock timeNow)
    {
        auto x = std::chrono::duration_cast<std::chrono::milliseconds>(timeNow.time_since_epoch());

        return static_cast<int>(x.count() % 100);
    }

    int milliseconds(sysClock timeNow)
    {
        return ms(timeNow);
    }

    int us(sysClock timeNow)
    {
        auto x = std::chrono::duration_cast<std::chrono::microseconds>(timeNow.time_since_epoch());

        return static_cast<int>(x.count() % 1000);
    }

    int microseconds(sysClock timeNow)
    {
        return us(timeNow);
    }

    int year()
    {
        std::tm *timeNowX = std::localtime(&xtm);

        return timeNowX->tm_year + 1900;
    }

    int wday()
    {
        std::tm *timeNowX = std::localtime(&xtm);

        return timeNowX->tm_wday;
    }

    int day()
    {
        std::tm *timeNowX = std::localtime(&xtm);

        return timeNowX->tm_mday;
    }

    int month()
    {
        std::tm *timeNowX = std::localtime(&xtm);

        return timeNowX->tm_mon + 1;
    }

    int yday()
    {
        std::tm *timeNowX = std::localtime(&xtm);

        return timeNowX->tm_yday + 1;
    }

    int isdst()
    {
        // A value of 0 indicates that daylight saving time (DST) is not in effect.
        // A value greater than 0 indicates that DST is in effect.
        // A value less than 0 means that the information is not available.

        std::tm *timeNowX = std::localtime(&xtm);

        return timeNowX->tm_isdst;
    }

    std::string timezone()
    {
        std::tm *timeNowX = std::localtime(&xtm);

        return timeNowX->tm_zone;
    }
}
