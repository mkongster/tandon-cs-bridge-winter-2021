/*
Ming Kong
Tandon Bridge Winter 2021
Homework 3
Question 4
*/

#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {
    double real, decimal;
    int choice, rounded;

    cout << "Please enter a Real number: \n";
    cin >> real;
    cout << "Choose your rounding method: \n";
    cout << "1. Floor round \n";
    cout << "2. Ceiling round \n";
    cout << "3. Round to the nearest whole number \n";\
    cin >> choice;

    switch (choice) {
        case 1: {
            rounded = int(real);
            break;
        }
        case 2: {
            if ((int)real == real) {
                rounded = real;
            } else {
                rounded = int(real) + 1; 
            }
            break;
        }
        case 3: {
            decimal = real - int(real);
            if (decimal >= 0.5) {
                rounded = int(real) + 1;
            } else {
                rounded = int(real);
            }
            break;
        }
    }

    cout << rounded << endl;

    return 0;
}