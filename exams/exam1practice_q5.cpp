/*
Ming Kong
Tandon Bridge Winter 2021
Practice Exam 1
Question 5
*/

#include <iostream>

using namespace std;

int main() {
    int integer;
    int sum = 0;

    cout << "Please enter an integer: ";
    cin >> integer;
    int temp = integer;

    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    
    cout << "The sum of its digits for integer, "  << integer << " is: " << sum << endl;

    return 0;
}