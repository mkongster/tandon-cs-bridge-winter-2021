/*
Ming Kong
Tandon Bridge Winter 2021
Homework 8
Question 5
*/

#include <iostream>

using namespace std;

void formattedNames(string first, string mid, string last);
// Prints out names in the following format: Last, First Middle Initial 

int main() {
    string first, mid, last = "";
    cout << "Please enter your first name, middle name and last name: ";
    cin >> first >> mid >> last;

    formattedNames(first, mid, last);

    return 0;
}

void formattedNames(string first, string mid, string last) {
    cout << last << ", " << first << " " << mid[0] << "." << endl;
}