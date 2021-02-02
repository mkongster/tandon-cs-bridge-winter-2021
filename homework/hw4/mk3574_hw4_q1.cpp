/*
Ming Kong
Tandon Bridge Winter 2021
Homework 4
Question 1
*/

#include <iostream>

using namespace std;

int main() {
    int input;
    int even = 2;

    cout << "Section a: \n";
    cout << "Please enter a positive integer: ";
    cin >> input;
    while (input > 0) {
        cout << even << endl;
        --input;
        even += 2;
    }

    cout << "Section b: \n";
    cout << "Please enter a positive integer: ";
    cin >> input;
    even = 2;
    for (int n = 0; n < input; n++) {
        cout << even << endl;
        even += 2;
    }

    return 0;
}