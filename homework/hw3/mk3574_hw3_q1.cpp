/*
Ming Kong
Tandon Bridge Winter 2021
Homework 3
Question 1
*/

#include <iostream>

using namespace std;

int main() {
    double iOne, iTwo, taxRate, base, discount, total;
    char club;

    cout << "Enter price of first item: ";
    cin >> iOne;
    cout << "Enter price of second item: ";
    cin >> iTwo;
    cout << "Does customer have a club card? (Y/N): ";
    cin >> club;
    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> taxRate;

    base = iOne + iTwo;

    if (iOne >= iTwo) {
        discount = (0.5 * iTwo) + iOne;
    }
    else {
        discount = (0.5 * iOne) + iTwo;
    }

    if (club == 'y' || club == 'Y') {
        discount = 0.9 * discount;
    }

    total = discount * (1 + (taxRate / 100));

    cout << "Base price: " << base << endl;
    cout << "Price after discounts: " << discount << endl;
    cout << "Total price: " << total << endl;

    return 0;
}