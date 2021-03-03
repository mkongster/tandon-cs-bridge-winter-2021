/*
Ming Kong
Tandon Bridge Winter 2021
Homework 8
Question 2
*/

#include <iostream>

using namespace std;

bool isPalindrome(string str);
// Determines if a string is a palindrome, the same forwards and backwards.
// Returns a true or false value.

int main () {
    string input;
    cout << "Please enter a word: ";
    cin >> input;

    if (isPalindrome(input)) {
        cout << input << " is a palindrome" << endl;
    } else {
        cout << input << " is not a palindrome" << endl;
    }

    return 0;
}

bool isPalindrome(string str) {
    int length = str.length();
    int mid = length / 2;
    for (int i = 0; i <= mid; i++) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}