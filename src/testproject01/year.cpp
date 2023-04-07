#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <algorithm>

struct WeekDays
{
    std::string one = "sunday";
    std::string two = "monday";
    std::string three = "tuesday";
    std::string four = "wednesday";
    std::string five = "thursday";
    std::string six = "friday";
    std::string seven = "saturday";
};

void insertVectorDay(const int& day,std::vector<std::string>& days,WeekDays& weekday)
{
    int counter = day;
    for(int i= 0;i<365;i++)
    {
        if(counter>7)
        counter = 1;        
        switch(counter)
        {
            case 1:
            {
                days.push_back(weekday.one);
                break;
            }
            case 2:
            {
                days.push_back(weekday.two);
                break;
            }
            case 3:
            {
                days.push_back(weekday.three);
                break;
            }
            case 4:
            {
                days.push_back(weekday.four);
                break;
            }
            case 5:
            {
                days.push_back(weekday.five);
                break;
            }
            case 6:
            {
                days.push_back(weekday.six);
                break;
            }
            case 7:
            {
                days.push_back(weekday.seven);
                break;
            }
            default:
            {
                std::abort;
                break;
            }
        }
        counter++;
    }
}

int main()
{
    int day,counter=0;
    WeekDays weekday;
    std::vector<std::string> days;
    days.reserve(366);
    std::cout << "Enter the number of the week to star the year: ";
    std::cin >> day;
    insertVectorDay(day,days,weekday);
    for(auto one:days){
        std::cout << one << std::endl;
        if(one=="sunday")
        counter++;
    }
    std::sort(days.begin(),days.end());

    std::cout << counter;
}