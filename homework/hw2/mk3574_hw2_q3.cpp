/*
Ming Kong

Question 3:
Suppose John and Bill worked for some time and we want to calculate the total time both of them worked. 
Write a program that reads number of days, hours, minutes each of them worked, and prints the total time both of them worked together as 
days, hours, minutes. 

Hint: Try to adapt the elementary method for addition of numbers to this use. Your program should interact with the user exactly as it shows in the following example:
Please enter the number of days John has worked: 2
Please enter the number of hours John has worked: 12
Please enter the number of minutes John has worked: 15

Please enter the number of days Bill has worked: 3
Please enter the number of hours Bill has worked: 15
Please enter the number of minutes Bill has worked: 20

The total time both of them worked together is: 6 days, 3 hours and 35minutes.
*/

#include <iostream>

using namespace std;

const int HOUR = 60;
const int DAY = 24;

int main() {
    int johnDays, johnHours, johnMinutes;
    int billDays, billHours, billMinutes;
    int totalDays, totalHours, totalMinutes;
    int carry;

    cout << "Please enter the number of days John has worked: ";
    cin >> johnDays;
    cout << "Please enter the number of hours John has worked: ";
    cin >> johnHours;
    cout << "Please enter the number of minutes John has worked: ";
    cin >> johnMinutes;
    cout << endl;

    cout << "Please enter the number of days Bill has worked: ";
    cin >> billDays;
    cout << "Please enter the number of hours Bill has worked: ";
    cin >> billHours;
    cout << "Please enter the number of minutes Bill has worked: ";
    cin >> billMinutes;
    cout << endl;

    totalMinutes = johnMinutes + billMinutes;
    carry = totalMinutes / HOUR;
    totalMinutes = totalMinutes % HOUR; 

    totalHours = johnHours + billHours + carry;
    carry = totalHours / DAY;
    totalHours = totalHours % DAY;

    totalDays = johnDays + billDays + carry;

    cout << "The total time both of them worked together is: " << totalDays <<
        " days, " << totalHours << " hours and " << totalMinutes << " minutes.\n";

    return 0;
}