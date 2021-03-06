/*
Ming Kong
Tandon Bridge Winter 2021
Homework 6
Question 2
*/

#include <iostream>

using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
// Prints an n-line triangle, filled with symbols characters, shifted m spaces from the left margin.

void printPineTree(int n, char symbol);
// Prints a sequence of n triangles of increasing sizes, filled with the symbol character.

int main() {
    int num_triangles;
    char tree_char;
    cout << "How many triangles do you want in your pine tree?: ";
    cin >> num_triangles;
    cout << "Please enter a single character to fill the tree: ";
    cin >> tree_char;
    printPineTree(num_triangles, tree_char);
    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
    int spaces = n - 1;
    int symbols = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (spaces + m); j++) {
            cout << " ";
        }

        for (int j = 0; j < symbols; j++) {
            cout << symbol;
        }

        for (int j = 0; j < spaces; j++) {
            cout << " ";
        }
        spaces--;
        symbols += 2;
        cout << endl;
    }
}

void printPineTree(int n, char symbol) {
    int margin = n - 1;
    for (int i = 1; i <= n; i++) {
        printShiftedTriangle(i + 1, margin, symbol);
        margin--;
    }
}
