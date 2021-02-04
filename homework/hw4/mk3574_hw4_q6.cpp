/*
Ming Kong
Tandon Bridge Winter 2021
Homework 4
Question 6
*/

#include <iostream>

using namespace std;

int main() {
    int input, digit, modDigit, num;
    int tens = 1;
    int oddCounter = 0;
    int evenCounter = 0;
    int counter;
    cout << "Please input a positive integer: ";
    cin >> input;

    for (int i = 0; i < input; i++) {
        num = i;
        while (num > 0) {
            digit = num % 10;
            num /= 10;
            modDigit = digit % 2;
            
            if (modDigit == 0) {
                evenCounter++;
            } else {
                oddCounter++;
            }
        }

        if (evenCounter > oddCounter) {
            cout << i << endl;
        }
        evenCounter = 0;
        oddCounter = 0;
    }

    return 0;
}
