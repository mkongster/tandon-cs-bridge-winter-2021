/*
Write a program that:
    Asks the user for their name.
    Asks the user to input their graduation year.
    Asks the user to input the current year.
Assume the student is in a four-year undergraduate program. 
Display the current status the student is in. 
Possible status include: not in college yet, freshman, sophomore, junior, senior, graduated. 

Note: If graduation year equals to current year, status is ‘Graduated’; 
if graduation year is four years after current year, status is ‘Freshman’, etc.

Your program should interact with the user exactly as it shows in the following example:
Please enter your name: Jessica
Please enter your graduation year: 2019
Please enter current year: 2015
Jessica, you are a Freshman
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