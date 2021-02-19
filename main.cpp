#include <iostream>
#include "Date.hpp"
using namespace std;

int main(){
    Date date1;
    int month, day, year;

    cout << "The initialised date is (M-D-Y): " << date1.getMonth() << " " << date1.getDay() << " " << date1.getYear() <<endl;

    cout << "Please enter a date: (Month Day Year): ";
    cin >> month >> day >> year;

    date1.setMonth(month);
    date1.setDay(day);
    date1.setYear(year);
    cout << endl;

    cout << "Please enter a second date: (Month Day Year): ";
    cin >> month >> day >> year;

    Date date2(month, day, year);
    cout << "Printing the 2 days: " << endl;
    cout << "The date is (M-D-Y): " << endl;

    date1.printDate();
    cout << endl;
    cout << "The date is (M-D-Y): ";
    date2.printDate();
    cout << endl;

    if(date2.sameMonth(date1) == true)
        cout << "The months are the same";

    else 
        cout << "The months are different";



    return 0;
}