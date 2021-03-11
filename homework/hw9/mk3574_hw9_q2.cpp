/*
Ming Kong
Tandon Bridge Winter 2021
Homework 9
Question 2
*/

#include <iostream>
#include <vector>

using namespace std;

const int ASCII_LOWER_TO_UPPER = int('a') - int('A');
const int ASCII_LOWER_A = int('a');

void countLetters(string& input, vector<int>& counts);
// Takes an input of string and counts the letters (case insensitive).
// Accepts an input of string, a vector reference of size 26 (the alphabet).

bool isAnagram(string& one, string& two);
// Checks if two strings are anagrams.
// Return true if anagram, else false.

int main() {
    string one, two;
    cout << "Please enter two strings to see if they are anagrams of each other. " << endl;
    cout << "Please enter the first string: " << endl;
    getline(cin, one);
    cout << "Please enter the second string: " << endl;
    getline(cin, two);

    bool anagram = isAnagram(one, two);

    if (anagram) {
        cout << "The two strings are anagrams!" << endl;
    } else {
        cout << "The two strings are not anagrams." << endl;
    }

    return 0;
}

void countLetters(string& input, vector<int>& counts) {
    for (char c : input) {
        if (c >= 'A' && c <= 'Z') {
            counts[int(c) + ASCII_LOWER_TO_UPPER - ASCII_LOWER_A] = counts[int(c) + ASCII_LOWER_TO_UPPER - ASCII_LOWER_A] + 1;
        } else if (c >= 'a' && c <= 'z') {
            counts[int(c) - ASCII_LOWER_A] = counts[int(c) - ASCII_LOWER_A] + 1;
        }
    }
}

bool isAnagram(string& one, string& two) {
    vector<int> count_one(26, 0);
    vector<int> count_two(26, 0);

    countLetters(one, count_one);
    countLetters(two, count_two);

    for (int i = 0; i < count_one.size(); i++) {
        if (count_one[i] != count_two[i]) {
            return false;
        }
    }

    return true;
}