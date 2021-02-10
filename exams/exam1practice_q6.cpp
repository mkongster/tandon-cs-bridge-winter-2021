/*
Ming Kong
Tandon Bridge Winter 2021
Practice Exam 1
Question 6
*/

#include <iostream>

using namespace std;

int main() {
    int integer, starCount, spaces, totalLines;
    int lineCount = 0;
    bool middle = false;

    cout << "Please enter a positive integer: ";
    cin >> integer;

    int odd = integer % 2;

    if (odd) {
        starCount = 1;
        totalLines = integer;
    } else {
        starCount = 2;
        totalLines = integer - 1;
    }

    spaces = (integer - starCount) / 2;


    while (lineCount < totalLines) {
        for (int x = 0; x < spaces; x++) {
            cout << " ";
        }
        
        for (int y = 0; y < starCount; y++) {
            cout << "*";
        }

        for (int x = 0; x < spaces; x++) {
            cout << " ";
        }

        if (!middle) {
            spaces--;
            starCount += 2;
            cout << endl; 
        } else {
            spaces++;
            starCount -= 2;
            cout << endl;   
        }

        if (spaces == 0) {
            middle = true;
        }

        lineCount++;
    }



    return 0;
}