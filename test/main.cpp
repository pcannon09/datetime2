#include <iostream>

#include "../inc/dt.hpp"

int main()
{
    std::cout << "-= DateTime " << dt::version << " =-\n";
    std::cout << "* By Paul Cannon\n";

    dt::sysClock timeNow;

    while (1)
    {
        timeNow = dt::get();
        
        dt::set24h(false);

        std::cout << "Time: " << dt::hr(timeNow) << " ( " << dt::amOrPm(timeNow) << " ) : " << dt::min() << " : " << dt::sec(timeNow) << " . " << dt::ms(timeNow) << " . " << dt::us(timeNow) << "\n";

        dt::set24h(true);

        std::cout << "Time: " << dt::hr(timeNow) << " : " << dt::min() << " : " << dt::sec(timeNow) << " . " << dt::ms(timeNow) << " . " << dt::us(timeNow) << "\n";
        std::cout << "Date (DD / MM / YYYY): " << dt::day() << " / " << dt::month() << " / " << dt::year() << "; Timezone " << dt::timezone() << "\n";
        std::cout << "Date (More info)" << " Day of week: " << dt::wday() << " Day of year: " << dt::yday() << " DST: " << dt::isdst() << "\n";

        system("clear");
    }

    return 0;
}

