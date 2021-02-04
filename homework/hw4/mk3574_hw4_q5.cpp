/*
Ming Kong
Tandon Bridge Winter 2021
Homework 4
Question 5
*/

#include <iostream>

using namespace std;

int main() {
    int lines;
    int numAsterisks;
    int numSpaces = 0;

    cout << "Please input a positive integer: ";
    cin >> lines;
    numAsterisks = 2 * lines - 1;

    for (int x = 0; x < lines; x++) {
        for (int y = 0; y < numSpaces; y++) {
            cout << " ";
        }
        for (int z = 0; z < numAsterisks; z++) {
            cout << "*";
        }
        for (int y = 0; y < numSpaces; y++) {
            cout << " ";
        }
        numAsterisks -= 2;
        numSpaces++;
        cout << endl;
    }

    numAsterisks = 1;
    numSpaces = lines - 1;
    for (int x = 0; x < lines; x++) {
        for (int y = 0; y < numSpaces; y++) {
            cout << " ";
        }
        for (int z = 0; z < numAsterisks; z++) {
            cout << "*";
        }
        for (int y = 0; y < numSpaces; y++) {
            cout << " ";
        }
        cout << endl;

        numAsterisks += 2;
        numSpaces--;
    }

    return 0;
}