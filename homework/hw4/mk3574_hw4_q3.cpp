/*
Ming Kong
Tandon Bridge Winter 2021
Homework 4
Question 3
*/

#include <iostream>

using namespace std;

int const CHAR_ZERO = 48;
int const CHAR_ONE = 49;

int main() {
    int decimal, remainder;
    char digit;
    string binary;

    cout << "Enter decimal number: \n";
    cin >> decimal;

    while (decimal) {
        remainder = decimal % 2;
        
        if (remainder == 0) {
            digit = char(CHAR_ZERO);
        } else {
            digit = char(CHAR_ONE);
        }
        
        decimal /= 2;
        binary = digit + binary;
    }

    cout << "The binary representation of " << decimal << " is " << binary;

    return 0;
}