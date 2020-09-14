// Johnathon Heidari
// Class: (CECS 282-05)
// Project: (Prog 4 - Operator Overloadinge)
// Due Date: (05/14/20)

#include "upDate.h"
#include <iostream>
using namespace std;
int upDate::counter = 0;
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

upDate::upDate() {
    counter += 1;
    dptr = new int[3];
    dptr[0] = 5;
    dptr[1] = 11;
    dptr[2] = 1959;
}

upDate::upDate(int M, int D, int Y) {
    counter += 1;
    dptr = new int[3];
    int tempday = D, tempmonth = M, tempyear = Y;
    int testingValue = Greg2Julian(M,D,Y);
    Julian2Greg(testingValue,M,D,Y);
    if(tempday != D ||tempmonth != M || tempyear != Y){
        dptr[0] = 5;
        dptr[1] = 11;
        dptr[2] = 1959;
    }
    else{
        dptr[0] = M;
        dptr[1] = D;
        dptr[2] = Y;
    }
}
upDate::upDate(int J){
    dptr = new int[3];
    dptr[0] = 5;
    dptr[1] = 11;
    dptr[2] = 1959;
    Julian2Greg( J,dptr[0],dptr[1],dptr[2]);
    counter += 1;
}
upDate::upDate(const upDate &D) {
    counter += 1;
    dptr = new int[3];
    dptr[0] = D.dptr[0];
    dptr[1] = D.dptr[1];
    dptr[2] = D.dptr[2];
}

upDate::~upDate() {
    counter -= 1;
    delete [] dptr;
}
void upDate::setDate(int M, int D, int Y) {
    dptr[0] = M;
    dptr[1] = D;
    dptr[2] = Y;
}

int upDate::getMonth() {
    return dptr[0];
}

int upDate::getDay() {
    return dptr[1];
}

int upDate::getYear() {
    return dptr[2];
}

string upDate::getMonthName() {
    string output;
    switch(dptr[0]){
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
    return output;
}
// addition
upDate upDate::operator+(int x) {
    int M = dptr[0],D = dptr[1],Y = dptr[2];
    int JD = Greg2Julian(M,D,Y);
    JD += x;
    Julian2Greg(JD,M,D,Y);
    upDate temp(M,D,Y);
    return temp;
}

upDate operator+(int x, upDate otherDate) {
    int JD = Greg2Julian(otherDate.dptr[0],otherDate.dptr[1],otherDate.dptr[2]);
    JD += x;
    Julian2Greg(JD,otherDate.dptr[0],otherDate.dptr[1],otherDate.dptr[2]);
    upDate temp(otherDate.dptr[0],otherDate.dptr[1],otherDate.dptr[2]);
    return temp;
}

upDate upDate::operator+=(int x) {
    int JD = Greg2Julian(dptr[0],dptr[1],dptr[2]);
    JD += x;
    Julian2Greg(JD,dptr[0],dptr[1],dptr[2]);
    upDate temp(dptr[0],dptr[1],dptr[2]);
    return temp;
}

upDate upDate::operator-(int x) {
    //needs work
    int M = dptr[0],D = dptr[1],Y = dptr[2];
    int JD = Greg2Julian(M,D,Y);
    JD -= x;
    Julian2Greg(JD,M,D,Y);
    upDate temp(M,D,Y);
    return temp;
}
// INT X = D2 - D3
int upDate::operator-(const upDate& otherDate) {
    int JD = Greg2Julian(dptr[0],dptr[1],dptr[2]);
    int JD2 = Greg2Julian(otherDate.dptr[0],otherDate.dptr[1],otherDate.dptr[2]);
    JD = (JD - JD2);
    return JD;
}
upDate upDate::operator-=(int x) {
    int JD = Greg2Julian(dptr[0],dptr[1],dptr[2]);
    JD -= x;
    Julian2Greg(JD,dptr[0],dptr[1],dptr[2]);
    upDate temp(dptr[0],dptr[1],dptr[2]);
    return temp;
}

// comparison
bool upDate::operator==(upDate otherDate) {
    return dptr[0] == otherDate.dptr[0] && dptr[1] == otherDate.dptr[1] && dptr[3] == otherDate.dptr[3];
}
bool upDate::operator>(upDate otherDate) {
    return dptr[0] > otherDate.dptr[0] && dptr[1] > otherDate.dptr[1] && dptr[3] > otherDate.dptr[3];
}
bool upDate::operator<(upDate otherDate) {
    return dptr[0] < otherDate.dptr[0] && dptr[1] < otherDate.dptr[1] && dptr[3] < otherDate.dptr[3];
}

upDate upDate::operator=(upDate D) {
    dptr[0] = D.dptr[0];
    dptr[1] = D.dptr[1];
    dptr[2] = D.dptr[2];
    return (upDate(dptr[0],dptr[1],dptr[2]));
}

std::ostream &operator<<(std::ostream & out, const upDate& otherDate) {
    return out <<otherDate.dptr[0] << "/" << otherDate.dptr[1] << "/" << otherDate.dptr[2];

}

upDate upDate::operator++() {
    int JD = Greg2Julian(dptr[0],dptr[1],dptr[2]);
    JD += 1;
    Julian2Greg(JD,dptr[0],dptr[1],dptr[2]);
    upDate temp(dptr[0],dptr[1],dptr[2]);
    return temp;
}

upDate upDate::operator--() {
    int JD = Greg2Julian(dptr[0],dptr[1],dptr[2]);
    JD -= 1;
    Julian2Greg(JD,dptr[0],dptr[1],dptr[2]);
    upDate temp(dptr[0],dptr[1],dptr[2]);
    return temp;
}
upDate &upDate::operator++(int x) {
    int JD = Greg2Julian(dptr[0],dptr[1],dptr[2]);
    JD += 1;
    Julian2Greg(JD,dptr[0],dptr[1],dptr[2]);
    upDate temp(dptr[0],dptr[1],dptr[2]);
    return temp;
}

upDate upDate::operator--(int x) {
    int JD = Greg2Julian(dptr[0],dptr[1],dptr[2]);
    JD -= 1;
    Julian2Greg(JD,dptr[0],dptr[1],dptr[2]);
    upDate temp(dptr[0],dptr[1],dptr[2]);
    return temp;
}

int upDate::GetDateCount() {
    return counter;
}

int upDate::julian() {
    return Greg2Julian(dptr[0],dptr[1],dptr[2]);
}








