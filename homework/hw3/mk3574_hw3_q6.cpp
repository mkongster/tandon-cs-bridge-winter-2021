/*
Ming Kong
Tandon Bridge Winter 2021
Homework 3
Question 6
*/

#include <iostream>

using namespace std;

int main() {
    int hour, minute, length;
    float rate, cost;
    char holder;
    string weekday;

    cout << "Please input the day of the week: ";
    cin >> weekday;
    cout << "Please input the time the call started: ";
    cin >> hour >> holder >> minute;
    cout << "Please input the length of the call in minutes: ";
    cin >> length;

    if (weekday == "Sa" || weekday == "Su") {
        rate = 0.15;
    } else {
        if ((hour >= 8 && hour < 18) ) {
            rate = 0.4;
        } else {
            rate = 0.25;
        }
    }

    cost = rate * length;

    cout << "The cost of the call is: $" << cost << endl;

    return 0;
}