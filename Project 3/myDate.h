// Author: Johnathon Heidari
// CECS 282-05 (Tu/Th)
// Program #2 due date: March 3, 2020

#ifndef PROJ_2_MYDATE_H
#define PROJ_2_MYDATE_H


#include <string>


int Greg2Julian(int month, int day, int year);
void Julian2Greg(int JD, int &month, int &day, int &year);
class myDate {
private:
    // Instance variables
    int month, day, year;
    // default constructor
public:
    myDate();
    // overload "constructor"
    myDate(int, int, int);
    // display  (May 11, 1959)
    void display();
    // increment days ( + && -)
    void increaseDate(int);
    void decreaseDate(int);
    // return number of days it been...
    int daysBetween(myDate);
    // accessor (getter)
    int getMonth();
    int getDay();
    int getYear();
    // return number of d
    int dayOfYear();
    std::string dayName();
};


#endif //PROJ_2_MYDATE_H
