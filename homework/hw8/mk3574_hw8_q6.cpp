/*
Ming Kong
Tandon Bridge Winter 2021
Homework 8
Question 6
*/

#include <iostream>

using namespace std;

const char REPLACE = 'x';
const int ZERO_CHAR = 48;
const int NINE_CHAR = 57;

void hideCharacters(int begin, int end, string& line);
// Replaces the character in the range of indexes with a character

bool isNumber(char c);
// Checks if the character is a number

bool isWord(string word);
// Returns true if there are non digit characters in the word.

void parseLine(string& line);
// Goes through a string and detects numbers and replaces it with a different character

int main() {
    string input;
    cout << "Please enter a line of text: \n";
    getline(cin, input);

    parseLine(input);
    cout << input << endl;

    return 0;
}

void hideCharacters(int begin, int end, string& line) {
    for (int i = begin; i < end; i++) {
        line[i] = REPLACE;
    }
}

bool isNumber(char c) {
    return (c >= ZERO_CHAR && c <= NINE_CHAR);
}

bool isWord(string word) {
    for(char c: word) {
        if (!isNumber(c)) {
            return true;
        }
    }

    return false;
}

void parseLine(string& line) {
    bool word = true;
    int begin = 0, end = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == ' ') {
            if (!isWord(line.substr(begin, i - begin))) {
                hideCharacters(begin, i, line);
                begin = i + 1;
            } else {
                begin = i + 1;
            }
        }
    }
}