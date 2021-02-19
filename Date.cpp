#include <iostream>
#include "Date.hpp"
using namespace std;

    Date::Date(){
        month = 1;
        day = 1;
        year = 1;
    }
    Date::Date(int m, int d, int y){
        if(m < 13)
            month = m;
        if (d < 32)
            day = d;
        if (y > 0)
            year = y;
    }
    int Date::getMonth(){
        return month;
    }
    int Date::getDay(){
        return day;
    }
    int Date::getYear(){
        return year;
    }

    void Date::setMonth(int m){
        month = m;
    }
    void Date::setDay(int d){
        day = d;
    }
    void Date::setYear(int y){
        year = y;
    }

    void Date::printDate(){
        cout << "The date is (Month Day Year: " << getMonth() << " " << getDay() << " " << getYear() << endl; 
    }

    bool Date::sameMonth(Date mon){
        if (mon.month == month)
            return true;
        else 
            return false;
    }