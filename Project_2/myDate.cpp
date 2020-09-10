// Author: Johnathon Heidari
// CECS 282-05 (Tu/Th)
// Program #2 due date: March 3, 2020

#include "myDate.h"
#include <iostream>
using namespace std;
int Greg2Julian(int month, int day, int year){
    // Simplify
    int m = month, d = day, y = year, JD;
    // converting gregorian to julian
    JD = d-32075+1461*(y+4800+(m-14)/12)/4+367*(m-2-(m-14)/12*12)
                                           /12-3*((y+4900+(m-14)/12)/100)/4;
    return JD;
}
void Julian2Greg(int JD, int &month, int &day, int &year){
    int L,N,I,J,K;
    L = JD + 68569;
    N = 4 * L / 146097;
    L = L - (146097 * N + 3) / 4;
    I = 4000 * (L + 1) / 1461001;
    L = L - 1461 * I / 4 + 31;
    J = 80 * L / 2447;
    K = L - 2447 * J / 80;
    L = J / 11;
    J = J + 2 - 12 * L;
    I = 100 * (N - 49) + I + L;
    // replace current variables
    month = J;
    day = K;
    year = I;
}

// constructor
myDate::myDate() {
    month = 5;
    day = 11;
    year = 1959;
}
// default
myDate::myDate(int M, int D, int Y){
    int tempday = D, tempmonth = M, tempyear = Y;
    int testingvalue = Greg2Julian(M,D,Y);
    Julian2Greg(testingvalue,M,D,Y);
    if(tempday != D ||tempmonth != M || tempyear != Y){
        month = 5;
        day = 11;
        year = 1959;
    }
    else{
        month = M;
        day = D;
        year = Y;
    }
}

// mutator ()''
void myDate::display() {
    // May 1, 1959
    string output;
    switch(month){
        case 1:
            output = "January ";
            break;
        case 2:
            output = "February ";
            break;
        case 3:
            output = "March ";
            break;
        case 4:
            output = "April ";
            break;
        case 5:
            output = "May ";
            break;
        case 6:
            output = "June ";
            break;
        case 7:
            output = "July ";
            break;
        case 8:
            output = "August ";
            break;
        case 9:
            output = "September ";
            break;
        case 10:
            output = "October ";
            break;
        case 11:
            output = "November ";
            break;
        case 12:
            output = "December ";
            break;
    }
    output += to_string(day) + ", " + to_string(year);
    cout<<output;
}

void myDate::increaseDate(int N) {
    // Grab the current Julian
    int currJD = Greg2Julian(getMonth(),getDay(),getYear());
    int newJD = currJD += N;
    // Insert the new gregorian with the Julian.
    Julian2Greg(newJD,month,day,year);

}

void myDate::decreaseDate(int N) {
    // Grab the current Julian
    int currJD = Greg2Julian(getMonth(),getDay(),getYear());
    int newJD = currJD -= N;
    // Insert the new gregorian with the Julian.
    Julian2Greg(newJD,month,day,year);
}

int myDate::daysBetween(myDate D) {
    int JD_1 = Greg2Julian(getMonth(),getDay(),getYear());
    int JD_2 = Greg2Julian(D.getMonth(),D.getDay(),D.getYear());
    // abs will insure that the future days will be a positive.
    return abs(JD_1 - JD_2);
}

int myDate::getMonth() {
    return month;
}

int myDate::getDay() {
    return day;
}

int myDate::getYear() {
    return year;
}

int myDate::dayOfYear() {
    int currJD = Greg2Julian(getMonth(),getDay(),getYear());
    int daysMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int currMonth = 1, total = 0;
    bool isfound = false;
    for(int i = 0; 12 > i; i++){
        if(currMonth == 2){
            if(((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)){
                isfound = true;

            }
        }
        if(currMonth == month){
            total += day;
            break;
        }
        else if(currMonth == 2 && isfound){
            total += 29;
        }
        else{
            total += daysMonth[i];
        }
        currMonth++;
    }
    return total;

}

string myDate::dayName() {
    string output;
    int m = month, d = day, y = year;
    int dayPattern[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    int dayValue = (y + y / 4 - y / 100 + y / 400 + dayPattern[m - 1] + d) % 7;

    switch(dayValue){
        case 0:
            output = "Sunday";
            break;
        case 1:
            output = "Monday";
            break;
        case 2:
            output = "Tuesday";
            break;
        case 3:
            output = "Wednesday";
            break;
        case 4:
            output = "Thursday";
            break;
        case 5:
            output = "Friday";
            break;
        case 6:
            output = "Saturday";
            break;
    }
    return output;
}
