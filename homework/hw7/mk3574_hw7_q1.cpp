/*
Ming Kong
Tandon Bridge Winter 2021
Homework 7
Question 1
*/

#include <iostream>

using namespace std;

const string JAN = "Janurary";
const string FEB = "Feburary";
const string MAR = "March";
const string APR = "April";
const string MAY = "May";
const string JUN = "June";
const string JUL = "July";
const string AUG = "August";
const string SEP = "September";
const string OCT = "October";
const string NOV = "November";
const string DEC = "December";
const int JAN_DAYS = 31;
const int FEB_DAYS = 28;
const int MAR_DAYS = 31;
const int APR_DAYS = 30;
const int MAY_DAYS = 31;
const int JUN_DAYS = 30;
const int JUL_DAYS = 31;
const int AUG_DAYS = 31;
const int SEP_DAYS = 30;
const int OCT_DAYS = 31;
const int NOV_DAYS = 30;
const int DEC_DAYS = 31;

int printMonthCalender(int num_of_days, int starting_day);
// Prints a formatted calender
// Returns a number 1-7 the represents the day in the week of the last day in that month.

bool isLeapYear(int year);
// Checks if the year is a leap year.
// Returns true or false.

void printYearCalender(int year, int starting_day);
// Prints a year calender specified by the year and the starting day of the week.

int main() {
    int year, day;

    cout << "Please enter a year: ";
    cin >> year;

    cout << "Please enter the starting day of the year as a number (1-7, Mon - Sun): ";
    cin >> day;

    printYearCalender(year, day);

    return 0;
}

int printMonthCalender(int num_of_days, int starting_day) {
    int day_counter = 0;

    cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;

    for (int i = 1; i < starting_day; i++) {
        cout << " \t";
        day_counter++;
    }

    for (int i = 1; i <= num_of_days; i++) {
        cout << i;
        day_counter++;
        if (day_counter == 7) {
            cout << endl;
            day_counter = 0;
        } else {
            cout << "\t";
        }
    }
    cout << endl << endl;

    return day_counter;
}

bool isLeapYear(int year) {
    int four = year % 4;
    int hundred = year % 100;
    int four_hundred = year % 400;

    if (!four && hundred) {
        return true;
    }

    if (!hundred && !four_hundred) {
        return true;
    }

    return false;
}

void printYearCalender(int year, int starting_day) {
    int day;

    cout << JAN << " " << year << endl;
    day = printMonthCalender(JAN_DAYS, starting_day);

    cout << FEB << " " << year << endl;
    if (isLeapYear(year)) {
        day = printMonthCalender(FEB_DAYS + 1, day + 1);
    } else {
        day = printMonthCalender(FEB_DAYS, day + 1);
    }

    cout << MAR << " " << year << endl;
    day = printMonthCalender(MAR_DAYS, day + 1);

    cout << APR << " " << year << endl;
    day = printMonthCalender(APR_DAYS, day + 1);

    cout << MAY << " " << year << endl;
    day = printMonthCalender(MAY_DAYS, day + 1);
    
    cout << JUN << " " << year << endl;
    day = printMonthCalender(JUN_DAYS, day + 1);

    cout << JUL << " " << year << endl;
    day = printMonthCalender(JUL_DAYS, day + 1);

    cout << AUG << " " << year << endl;
    day = printMonthCalender(AUG_DAYS, day + 1);

    cout << SEP << " " << year << endl;
    day = printMonthCalender(SEP_DAYS, day + 1);

    cout << OCT << " " << year << endl;
    day = printMonthCalender(OCT_DAYS, day + 1);

    cout << NOV << " " << year << endl;
    day = printMonthCalender(NOV_DAYS, day + 1);

    cout << DEC << " " << year << endl;
    day = printMonthCalender(DEC_DAYS, day + 1);
}