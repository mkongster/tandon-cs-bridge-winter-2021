/*
Ming Kong
Tandon Bridge Winter 2021
Homework 6
Question 1
*/

#include <iostream>

using namespace std;

int fib(int n);
// Returns the n-th fibonacci number

int main() {
    int input;
    cout << "Please enter a positive integer: ";
    cin >> input;
    cout << fib(input);

    return 0;
}

int fib(int n) {
    int fib = 1, a = 1, b = 1;

    if (n < 2) {
        return n;
    }

    for (int i = 2; i < n; i++) {
        fib = a + b;
        a = b;
        b = fib;
    }

    return fib;
}
