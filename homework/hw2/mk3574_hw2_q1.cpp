/*
Ming Kong

Question 1:
Write a program that asks the user to enter a number of quarters, dimes, nickels and pennies 
and then outputs the monetary value of the coins in the format of dollars and remaining cents. 

Your program should interact with the user exactly as it shows in the following example:
Please enter number of coins:
# of quarters: 13
# of dimes: 4
# of nickels: 11
# of pennies: 17
The total is 4 dollars and 37 cents
*/

#include <iostream>

using namespace std;

const float QUARTER = 0.25;
const float DIME = 0.1;
const float NICKEL = 0.05;
const float PENNY = 0.01;

int main() {
    int quarters, dimes, nickels, pennies, dollars, cents;
    double total;

    cout << "Please enter number of coins:\n";
    cout << "# of quarters: ";
    cin >> quarters;
    cout << "# of dimes: ";
    cin >> dimes;
    cout << "# of nickels: ";
    cin >> nickels;
    cout << "# of pennies: ";
    cin >> pennies;

    total = quarters * QUARTER + dimes * DIME + nickels * NICKEL + pennies * PENNY;
    dollars = total;
    cents = (total - dollars) * 100;
    cout << "The total is " << dollars << " dollars and " << cents << " cents\n";

    return 0;
}