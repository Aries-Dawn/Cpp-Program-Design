#include <iostream>
#include <string>
#include <string.h>

enum Week { Saturday,Sunday,Monday,Tuesday,Wednesday,Thursday,Friday };
enum Weather {Rain,Sunny};

struct DayInfo
{
    enum Week Day;
    enum Weather Weather;
    
};

bool canTravel( DayInfo day){
    if (day.Day == Week::Saturday || day.Day == Week::Sunday)
    {
        if (day.Weather == Weather::Sunny)
        {
            return true;
        }
    }
    return false;
}

int main(){
    DayInfo now;
    std::cout<<"Input the day : Saturday-0,Sunday-1,Monday-2,Tuesday-3,Wednesday-4,Thursday-5,Friday-6"<<std::endl;
    std::cin>>(int&)now.Day;
    // now.Day = Week::Friday;
    // std::cout<<now.Day<<std::endl;
    std::cout<<"Input the Weather : Rain-0,Sunny-1"<<std::endl;
    std::cin>>(int&)now.Weather;
    // now.Weather = Weather::Sunny;
    std::cout<<std::boolalpha<<canTravel(now)<<std::endl;
}