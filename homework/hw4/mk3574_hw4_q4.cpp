/*
Ming Kong
Tandon Bridge Winter 2021
Homework 4
Question 4
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    int digit;
    float length;
    int sum = 0;
    double geoMean;

    cout << setprecision(5);

    cout << "Section a: \n";
    cout << "Please enter the length of the sequence: ";
    cin >> length;

    cout << "Please enter your sequence: \n";
    for (int i = 0; i < length; i++) {
        cin >> digit;
        sum += digit;
    }

    geoMean = pow(sum, (1/length));
    cout << "The geometric mean is: " << geoMean << endl;


    cout << "Section b: \n";
    sum = 0;
    length = 0;

    cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1: \n";
    cin >> digit;
    while (digit > -1) {
        sum += digit;
        length++;    
        cin >> digit;
    }

    geoMean = pow(sum, (1/length));
    cout << "The geometric mean is: " << geoMean << endl;

    return 0;
}