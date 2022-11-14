#ifndef DATE_H
#define DATE_H
#include <iostream>
using namespace std;
class Date 
{
private:
 int day;
 int month;
 int year; 

public:
    //argument constructor
     Date(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
    //default
     Date() {
        day=0;
        month=0;
        year=0;
    }
     int getDay() {
        return day;
    }
     void setDay(int d) {
        day = d;
    }
     int getMonth() {
        return month;
    }
     void setMonth(int m) {
        month = m;
    }
     int getYear() {
        return year;
    }
     void setYear(int y) {
        year = y;
    }
    
     void display()
    {
        cout<<day<<"  "<<month<<"  "<<year ;
    }

 

};
#endif