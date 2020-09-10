// Author: Johnathon Heidari
// CECS 282-05 (Tu/Th)
// Program #3 due date: March 26, 2020

#include <iostream>
#include "myDate.h"
using namespace std;
#include<iomanip>

struct Student{
    char name[20], grade;
    int SID;
    string hometown;
    myDate Bday;
};

int mainMenu();
myDate randomDate();
void create10Students(Student *pStudent[10], int i);
void sortedByName(Student *pStudent[10], int i);
void displaySort(Student *pStudent[10], int i);
void sortedByStudentId(Student *pStudent[10], int i);
void sortedByGrade(Student *pStudent[10], int i);
void sortedByBirthday(Student *pStudent[10], int i);
void sortedByHomeTown(Student *pStudent[10], int i);
int mainMenu();
void Julian2GregS(int JD, int &month, int &day, int &year);
void swap(Student **x, Student **y);

int main() {
    int M=0,D=0,Y=0;
    Julian2GregS(0,M,D,Y);
    cout<<M<<"  "<<D<<"  "<<Y<<"  "<<endl;
    srand(time(0));
    // Pointer to pointer
    Student **studentList;
    // Declares array of pointers
    studentList = new Student*[10];
    // Initializes all index of Student structure pointers
    for (int i = 0; 10 > i; i++){
        studentList[i] = new Student;
    }
    // Ask the user for input
    create10Students(studentList, 10);
    int option = 0;
    while (option != 6) {
        option = mainMenu();
        switch (option) {
            case 1:
                sortedByName(studentList, 10);
                displaySort(studentList,10);
                continue;
            case 2:
                sortedByStudentId(studentList, 10);
                displaySort(studentList,10);
                continue;
            case 3:
                sortedByGrade(studentList, 10);
                displaySort(studentList,10);
                continue;
            case 4:
                sortedByBirthday(studentList, 10);
                displaySort(studentList,10);
                continue;
            case 5:
                sortedByHomeTown(studentList, 10);
                displaySort(studentList,10);
                continue;
            case 6:
                cout << "Thanks for playing the program.";
        }
        return 0;
    }
}

void sortedByHomeTown(Student *pStudent[10], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (((*(pStudent + j))->hometown.compare((*(pStudent + i))->hometown)) < 0) {
                swap(pStudent + i, pStudent + j);
            }
        }
    }
}

void sortedByBirthday(Student *pStudent[10], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            int bday1 = Greg2Julian((*(pStudent+j))->Bday.getMonth(), (*(pStudent+j))->Bday.getDay(), (*(pStudent+j))->Bday.getYear());
            int bday2 = Greg2Julian((*(pStudent+(i)))->Bday.getMonth(), (*(pStudent+(i)))->Bday.getDay(), (*(pStudent+(i)))->Bday.getYear());
            if(bday1 < bday2){
                swap(pStudent+j, pStudent+(i));
            }
        }
    }
}

void sortedByGrade(Student *pStudent[10], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if ((*(pStudent + j))->grade < (*(pStudent + i))->grade) {
                swap(pStudent + i, pStudent + j);
            }
        }
    }
}

void sortedByStudentId(Student *pStudent[10], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if ((*(pStudent + j))->SID < (*(pStudent + i))->SID) {
                swap(pStudent + i, pStudent + j);
            }
        }
    }
}

void displaySort(Student *pStudent[10], int n) {
    cout<<setw(20) << left << "Name" <<setw(20) << left << "Student ID" <<setw(20) << left << "Grade" <<setw(20) << left << "Birthday" <<setw(20) << left << "Hometown" << endl;
    for (int i = 0; n > i; i++){
        cout<<setw(20) << left << pStudent[i]->name;
        cout<<setw(20) << left << pStudent[i]->SID;
        cout<<setw(20) << left << pStudent[i]->grade;
        cout<<setw(20) << left;
        (pStudent[i]->Bday).display();
        cout<<setw(20) << left;
        cout<<setw(20) << left << pStudent[i]->hometown;
        cout<<endl;
    }
    cout<<endl;
}

void sortedByName(Student *pStudent[10], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp((*(pStudent + j))->name, (*(pStudent + i))->name) < 0) {
                swap(pStudent + i, pStudent + j);
            }
        }
    }
}

void create10Students(Student *pStudent[10], int n) {
    string names[10] = {"Kobe Bryant", "Travis Scott", "Robin Williams", "Lil Uzi Vert", "Post Malone", "Donald Trump",
                        "Trippe Red", "Will Smith", "Lebron James", "Michael Jackson"};
    string homes[10] = {"Philadelphia", "Houston", "Chicago", "Philadelphia", "Syracuse", "New York", "Canton",
                        "Philadelphia", "Akron", "San Francisco"};
    string userInput;

    for (int i = 0; n > i; i++) {
        userInput = "";
        cout << "Please enter a name for student " << (i + 1) << ": ";
        cin >> userInput;
        if (userInput == "default") {
            break;
        }
        names[i] = userInput;
        userInput = "";
        cout << "Please enter a hometown for student " << (i + 1) << ": ";
        cin >> userInput;
        homes[i] = userInput;
        cout << endl;
    }
    char grade[5] = {'A', 'B', 'C', 'D', 'F'};
    for(int i=0; i<n; i++) {
        //NAME
        for (int i = 0; i < 10; i++) {
            strcpy(pStudent[i]->name, names[i].c_str());
        }
        // SID
        pStudent[i]->SID = rand() % (9999 - 1000 + 1) + 1000;
        // Grade
        pStudent[i]->grade = grade[(rand() % 5)];
        // Birthday
        pStudent[i]->Bday = randomDate();
        // Hometown
        for (int i = 0; i < 10; i++) {
            pStudent[i]->hometown = homes[i];
        }
    }
}


    myDate randomDate() {
        int m = 0, d = 0, y = 0;
        int start = Greg2Julian(1, 1, 1999);
        int finish = Greg2Julian(12, 31, 2004);
        int randJD = rand() % (finish - start + 1) + start;
        Julian2Greg(randJD, m, d, y);
        myDate date(m, d, y);
        return date;
    }

void swap(Student **x, Student **y){
    Student temp = **x;
    **x = **y;
    **y = temp;
}


    int mainMenu() {
        int answer;
        cout << "1) Display list sorted by Name" << endl;
        cout << "2) Display list sorted by Student ID" << endl;
        cout << "3) Display list sorted by Grade" << endl;
        cout << "4) Display list sorted by Birthday" << endl;
        cout << "5) Display list sorted by HomeTown" << endl;
        cout << "6) Exit\n" << endl;
        cout << "Choose menu option (1-6): " << endl;
        cin >> answer;
        while (answer < 1 || answer > 6) {
            cout << "Invaild answer please select again" << endl;
            cin >> answer;
        }
        return answer;
    }

void Julian2GregS(int JD, int &month, int &day, int &year){
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