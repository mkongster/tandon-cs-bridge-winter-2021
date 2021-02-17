/*
Ming Kong
Tandon Bridge Winter 2021
Homework 6
Question 4
*/

#include <iostream>
#include <cmath>

using namespace std;

void printDivisors(int num);
// Given a positive integer num, it prints all of nums' divisors in ascending order, separated by space.

int main() {
    int input;

    cout << "Please enter a positive integer >= 2: ";
    cin >> input;

    printDivisors(input);
    return 0;
}

void printDivisors(int num) {
    for (int i = 1; (i * i) < num; i++) {
        if (num % i == 0) {
            cout << i;
            cout << " ";
        }
    }

    for (int i = sqrt(num); i >= 1; i--) {
        if (num % i == 0) {
            cout << num / i;
            cout << " ";
        }
    }

}

