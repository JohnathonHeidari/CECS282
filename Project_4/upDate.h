// Johnathon Heidari
// Class: (CECS 282-05)
// Project: (Prog 4 - Operator Overloadinge)
// Due Date: (05/14/20)

#ifndef PROGRAM_4_UPDATE_H
#define PROGRAM_4_UPDATE_H

#include <iostream>
#include <string>

class upDate {
private:
    // Instance variables
    int *dptr;
    static int counter;
public:
    // default constructor
    upDate();
    upDate(int, int, int);     // overriders method
    upDate(int);  // gregorian
    ~upDate();  // destruction


    void setDate(int M, int D, int Y);
    // accessor (getter)
    int getMonth();
    int getDay();
    int getYear();
    int julian();
    std::string getMonthName();
    // opertator
    upDate operator+ (int);
    upDate operator+=(int);
    friend upDate operator+(int,upDate);
    int operator-(const upDate&);
    upDate operator-(int);
    upDate operator-=(int);
    bool operator==(upDate);
    bool operator>(upDate);
    bool operator<(upDate);
    upDate(const upDate&);
    upDate operator=(upDate D);

    upDate operator++();
    upDate& operator++(int);
    upDate operator--();
    upDate operator--(int);



    friend std::ostream& operator<<(std::ostream &, const upDate&);


    static int GetDateCount();

};

#endif //PROGRAM_4_UPDATE_H
