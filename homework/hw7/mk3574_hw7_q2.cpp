/*
Ming Kong
Tandon Bridge Winter 2021
Homework 7
Question 2
*/

#include <iostream>
#include <cmath>

using namespace std;

int out_sum_divs, out_count_divs;

void analyzeDividors(int num, int& out_count_divs, int& out_sum_divs);
// Analyzes a number to find the count and sum of its proper divisors.

bool isPerfect(int num);
// Determines if a number is a perfect number.

int main() {
    int num, sum_divisors_one, sum_divisors_two, temp;
    
    cout << "Please enter a positive integer greater than or equal to 2: ";
    cin >> num;
    
    for (int i = 2; i <= num; i++) {
        if (isPerfect(i)) {
            cout << i << " is a perfect number.\n";
        } else {
            temp = out_sum_divs;
            analyzeDividors(temp, out_count_divs, out_sum_divs);
            if (i == out_sum_divs && temp < out_sum_divs) {
                cout << out_sum_divs << " and " << temp << " are amicable numbers.\n";
            }
        }
    }

    return 0;
}

void analyzeDividors(int num, int& out_count_divs, int& out_sum_divs) {
    out_sum_divs = 0;
    out_count_divs = 0;

    for (int i = 1; (i * i) < num; i++) {
        if (num % i == 0) {
            out_count_divs++;
            out_sum_divs += i;
        }
    }

    for (int i = sqrt(num); i > 1; i--) {
        if (num % i == 0) {
            out_count_divs++;
            out_sum_divs += num / i;
        }
    }
}

bool isPerfect(int num) {
    analyzeDividors(num, out_count_divs, out_sum_divs);

    if (num == out_sum_divs) {
        return true;
    }

    return false;
}
