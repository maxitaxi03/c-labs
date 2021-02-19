#ifndef HEADER
#define HEADER

class Date{
    int month, day, year;

public:
    Date();
    Date(int m, int d, int y);

    int getMonth();
    int getDay();
    int getYear();

    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);

    void printDate();
    bool sameMonth(Date mon);


    
};







#endif