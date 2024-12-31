#include "TimeInfo.hpp"

int TimeInfo_Year()
{
    time_t now = time(0);
    tm *NowTime = localtime(&now);
    int Year = 1900 + NowTime->tm_year;
    return Year;
}

int TimeInfo_Month()
{
    time_t now = time(0);
    tm *NowTime = localtime(&now);
    int Month = 1 + NowTime->tm_mon;
    return Month;
}

int TimeInfo_Day()
{
    time_t now = time(0);
    tm *NowTime = localtime(&now);
    int Day = NowTime->tm_mday;
    return Day;
}

string TimeInfo_All()
{
    time_t now = time(0);
    char *All =ctime(&now);
    return All;
}
