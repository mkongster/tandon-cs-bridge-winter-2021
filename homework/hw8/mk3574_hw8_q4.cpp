/*
Ming Kong
Tandon Bridge Winter 2021
Homework 8
Question 4
*/

#include <iostream>
#include <random>
#include <ctime>
#include <string>

using namespace std;

const string PIN = "54321";
const int ASCII_ZERO = 48;

string convertPin();
// Prints out a new mapping of the PIN digits to randomized to either 1, 2 or 3
// Returns a string of the new PIN using the randomized mapping

int main() {
    string input, converted;
    cout << "Please enter your PIN according to the following mapping: \n";
    cout << "PIN:\t0 1 2 3 4 5 6 7 8 9\n";
    converted = convertPin();
    cin >> input;

    if (converted == input) {
        cout << "Your PIN is correct\n";
    } else {
        cout << "Your PIN is not correct\n";
    }

    return 0;
}

string convertPin() {
    srand(time(0));
    string new_pin = "";
    int converted[10];
    cout << "NUM:\t";
    for (int i = 0; i < 10; i++) {
        converted[i] = rand() % 3 + 1;
        cout << converted[i] << " ";
    } 

    for (int i = 0; i < 5; i++) {
        int num = PIN[i] - ASCII_ZERO;
        new_pin.append(to_string(converted[num]));
    }

    cout << endl;

    return new_pin;
}