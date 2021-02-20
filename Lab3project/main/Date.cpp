#include <iostream>
#include<cassert>
#include "Date.h"
using namespace std;

Date::Date() {
    month = 1;
    day = 1;
    year = 1;
}
Date::Date(int m, int d, int y) {
        month = m;
        day = d;
        year = y;
}
int Date::getMonth() {
    return month;
}
int Date::getDay() {
    return day;
}
int Date::getYear() {
    return year;
}

void Date::setMonth(int m) {
    assert(m > 0 && m < 13);
    month = m;
}
void Date::setDay(int d) {
    assert(d > 0 && d < 32);
    day = d;
}
void Date::setYear(int y) {
    year = y;
}

void Date::printDate() {
    cout << "The date is (Month Day Year: " << getMonth() << " " << getDay() << " " << getYear() << ")"<< endl;
}

bool Date::sameMonth(Date mon) {
    if (mon.month == month)
        return true;
    else
        return false;
}