/*
Ming Kong
Tandon Bridge Winter 2021
Homework 3
Question 5
*/

#include <iostream>

using namespace std;

const float LB_TO_KILOGRAMS = 0.453592;
const float INCH_TO_METERS = 0.0254;

int main() {
    double weight, height, bmi;
    string status;
    cout << "Please enter weight (in pounds): ";
    cin >> weight;
    cout << "Please enter height (in inches): ";
    cin >> height;

    weight = LB_TO_KILOGRAMS * weight;
    height = INCH_TO_METERS * height;

    bmi = weight / (height * height);
    if (bmi < 18.5) {
        status = "Underweight";
    } else if (bmi < 25) {
        status = "Normal";
    } else if (bmi < 30) {
        status = "Overweight";
    } else {
        status = "Obese";
    }

    cout << "The weight status is: " << status << endl;

    return 0;
}