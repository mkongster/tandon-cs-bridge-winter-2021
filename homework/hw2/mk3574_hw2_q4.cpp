/*
Ming Kong

Question 4: Write a program that reads from the user two positive integers, and prints the result of
when we add, subtract multiply, divide, div and mod them.

Your program should interact with the user exactly as it shows in the following example:
Please enter two positive integers, separated by a space:
14 4
14 + 4 = 18
14 – 4 = 10
14 * 4 = 56
14 / 4 = 3.5
14 div 4 = 3
14 mod 4 = 2
*/

#include <iostream>

using namespace std;

int main() {
    int numOne, numTwo;
    int sum, diff, multiply, div, mod;
    double division;

    cout << "Please enter two positive integers, separated by a space:\n";
    cin >> numOne >> numTwo;

    sum = numOne + numTwo;
    diff = numOne - numTwo;
    multiply = numOne * numTwo;
    division = numOne / float(numTwo);
    div = numOne / numTwo;
    mod = numOne % numTwo;

    cout << numOne << " + " << numTwo << " = " << sum << endl;
    cout << numOne << " - " << numTwo << " = " << diff << endl;
    cout << numOne << " * " << numTwo << " = " << multiply << endl;
    cout << numOne << " / " << numTwo << " = " << division << endl;
    cout << numOne << " div " << numTwo << " = " << div << endl;
    cout << numOne << " mod " << numTwo << " = " << mod << endl;


    return 0;
}