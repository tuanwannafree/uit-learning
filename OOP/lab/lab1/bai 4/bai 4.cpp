// bai 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Date.h"
using namespace std;

bool leapYear(int year) {
    if (year % 4 == 0 || year % 400 == 0 ) {
        return true;
    }
    return false;
}

void Date::input() {
    cout << "Nhap ngay ";
    cin >> day;
    if (day > 31) {
        cout << "Nhap lai" << endl;
        input();
    }
    cout << "Nhap thang ";
    cin >> month;
    if (((month == 4 || month == 6 || month == 9 || month == 11) && day >= 31) || month > 12 || (month == 2 && day > 29) ) {
        cout << "Nhap lai" << endl;
        input();
    }
    cout << "Nhap nam ";
    cin >> year;

    if ( ((!leapYear(year)) && month == 2 && day > 28) || (leapYear(year)  && month == 2 && day > 29) ) {
        cout << "Nhap lai" << endl;
        input();
    }
}

void Date::tomorrow() {
    day++;
    if (month == 2) {
        if (leapYear(year)) {
            if (day == 30) {
                day = 1;
                month = 3;
            }
        }
        else if (day == 29) {
            day = 1;
            month = 3;
        }

    }
    else {
        if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
            if (day == 32) {
                day = 1;
                month++;
                if (month > 12) {
                    month = 1;
                    year++;
                }
            }
        }
        else {
            if (day == 31) {
                day = 1;
                month++;
                if (month > 12) {
                    month = 1;
                    year++;
                }
            }
        }
    }
}

void Date::display() {
    cout << day << " / " << month << " / " << year;
}


int main()
{
    Date a;
    a.input();
    a.tomorrow();
    a.display();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
