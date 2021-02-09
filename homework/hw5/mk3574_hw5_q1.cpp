/*
Ming Kong
Tandon Bridge Winter 2021
Homework 5
Question 1
*/

#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Please enter a positive integer: ";
    cin >> n;

    for (int y = 1; y <= n; y++) {
        for (int x = 1; x <= n; x++) {
            cout << x * y << "\t";
        }
        cout << endl;
    }
    return 0;
}