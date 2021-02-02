/*
Ming Kong
Tandon Bridge Winter 2021
Homework 4
Question 2
*/

#include <iostream>

using namespace std;

const int ROMAN_I = 1;
const int ROMAN_V = 5;
const int ROMAN_X = 10;
const int ROMAN_L = 50;
const int ROMAN_C = 100;
const int ROMAN_D = 500;
const int ROMAN_M = 1000;

int main() {
    int input, holder, divide, remainder;
    string roman;

    cout << "Enter decimal number: ";
    cin >> input;
    holder = input;

    divide = input / ROMAN_M;
    input -= divide * ROMAN_M;
    while (divide) {
        roman += 'M';
        divide--;
    }

    divide = input / ROMAN_D;
    remainder = (input % ROMAN_D) / ROMAN_C;
    if (divide) {
        roman += "D";
        input -= ROMAN_D;
    }

    input -= remainder * ROMAN_C;
    while (remainder) {
        roman += 'C';
        remainder--;
    }

    divide = input / ROMAN_L;
    remainder = (input % ROMAN_L) / ROMAN_X;  
    if (divide) {
        roman += "L";
        input -= ROMAN_L;
    }

    input -= remainder * ROMAN_X;
    while (remainder) {
        roman += "X";
        remainder--;
    }

    divide = input / ROMAN_V;
    remainder = (input % ROMAN_V) / ROMAN_I;     

    if (divide) {
        roman += "V";
    }

    while (remainder) {
        roman += "I";
        remainder--;
    }

    cout << holder << " is " << roman << endl;

    return 0;
}