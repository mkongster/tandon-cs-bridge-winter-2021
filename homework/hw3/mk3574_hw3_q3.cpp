/*
Ming Kong
Tandon Bridge Winter 2021
Homework 3
Question 3
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double a, b, c, sqrtTerm;
    double solutionPlus, solutionMinus;
    string status;

    cout << "Please enter value of a: ";
    cin >> a;
    cout << "Please enter value of b: ";
    cin >> b;
    cout << "Please enter value of c: ";
    cin >> c;

    if (a == 0 && b == 0 && c == 0) {
        cout << "This equation has an infinite number of solutions." << endl;
    } else if (a == 0) {
        cout << "This equation has no solution." << endl;
    } else {
        sqrtTerm = (b * b) - (4 * a * c);
        if (sqrtTerm < 0) {
            cout << "This equation has no real solution." << endl;
        } else if (sqrtTerm == 0) {
            double solution = -b / (2 * a);
            cout << "This equation has a single real solution x=" << solution << endl;
        } else {
            solutionPlus = (-b + sqrt(sqrtTerm)) / (2 * a);
            solutionMinus = (-b - sqrt(sqrtTerm)) / (2 * a);
            cout << "This equation has two real solutions x=" << solutionPlus << ", x=" << solutionMinus << endl;
        }
    }
    return 0;
}