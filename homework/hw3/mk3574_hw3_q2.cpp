/*
Ming Kong
Tandon Bridge Winter 2021
Homework 3
Question 2
*/

#include <iostream>

using namespace std;

int main() {
    string name, status;
    int grad, current, value;

    cout << "Please enter your name: ";
    cin >> name;
    cout << "Please enter your graduation year: ";
    cin >> grad;
    cout << "Please enter current year: ";
    cin >> current;

    value = grad - current;

    if (value <= 0) {
        status = "Graduated";
    } else if (value > 4) {
        status = "not in college yet";
    } else {
        switch (value) {
            case 4: {
                status = "a Freshman";
                break;
            }
            case 3: {
                status = "a Sophomore";
                break;
            }
            case 2: {
                status = "a Junior";
                break;
            }
            case 1: {
                status = "a Senior";
                break;
            }
        }
    }

    cout << name << ", you are " << status << endl;

    return 0;
}