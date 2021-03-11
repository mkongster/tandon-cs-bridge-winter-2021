/*
Ming Kong
Tandon Bridge Winter 2021
Homework 9
Question 1
*/

#include <iostream>
#include <vector>

using namespace std;

const int ASCII_LOWER_TO_UPPER = int('a') - int('A');
const int ASCII_LOWER_A = int('a');

void countLetters(string& input, vector<int>& counts, int& word_count);
// Takes an input of string and counts the letters and words in the string.
// Accepts an input of string, a vector reference of size 26 (the alphabet), and an int reference to count words.

void displayCounts(vector<int>& counts, int& word_count);
// Displays the counts of words and letters in a readable format.

int main() {
    string input;
    cout << "Please enter a line of text: " << endl;
    getline(cin, input);

    vector<int> counts(26, 0);
    int word_count = 0;
    
    countLetters(input, counts, word_count);
    displayCounts(counts, word_count);

    return 0;
}

void countLetters(string& input, vector<int>& counts, int& word_count) {
    bool word = false;
    for (char c : input) {
        if ( (c == ' ' || c == '.' || c == ',') && word ) {
            word_count++;
            word = false;
        } else if (c >= 'A' && c <= 'Z') {
            counts[int(c) + ASCII_LOWER_TO_UPPER - ASCII_LOWER_A] = counts[int(c) + ASCII_LOWER_TO_UPPER - ASCII_LOWER_A] + 1;
            word = true;
        } else if (c >= 'a' && c <= 'z') {
            counts[int(c) - ASCII_LOWER_A] = counts[int(c) - ASCII_LOWER_A] + 1;
            word = true;
        }
    }

    if (word) {
        word_count++;
    }
}

void displayCounts(vector<int>& counts, int& word_count) {
    cout << word_count << "\t" << "words" << endl;
    for (int i = 0; i < counts.size(); i++) {
        if (counts[i] != 0) {
            cout << counts[i] << "\t" << char(ASCII_LOWER_A + i) << endl;
        }
    }
}
