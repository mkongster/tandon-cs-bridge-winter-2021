/*
Ming Kong
Tandon Bridge Winter 2021
Homework 6
Question 3
*/

#include <iostream>

using namespace std;

double eApprox(int n);
// Approximates 'e', calulated by the sum of the first n + 1 addends.

int main() {
    cout.precision(30);

    for (int i = 1; i <= 15; i++) {
        cout << "i = " << i << "\t" << eApprox(i) << endl;
    }
    return 0;
}

double eApprox(int n) {
    double e = 1;
    int factorial_divisor = 1;

    for (int i = 1; i <= n; i++) {
        factorial_divisor *= i;
        e += (static_cast<double>(1) / factorial_divisor);       
    }

    return e;
}
