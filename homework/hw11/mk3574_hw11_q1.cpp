/*
Ming Kong
Tandon Bridge Winter 2021
Homework 11
Question 1
*/

#include <iostream>

using namespace std;

void printTriangle(int n);
// Triangle is the strongest shape

void printOppositeTriangles(int n);
// Supreme triangles

void printRuler(int n);
// Prints the ruler

int main() {
    //printTriangle(4);
    //printOppositeTriangles(4);
    printRuler(4);
    return 0;
}

void printTriangle(int n) {
    if (n == 1) {
        cout << "*\n";
    } else {
        printTriangle(n-1);

        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;

    }
}

void printOppositeTriangles(int n) {
    if (n == 1) {
        cout << "*\n";
        cout << "*\n";
    } else {
        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;

        printOppositeTriangles(n-1);

        for (int i = 0; i < n; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

void printRuler(int n) {
    if (n == 1) {
        cout << "-\n";
    } else {
        printRuler(n-1);
        for (int i = 0; i < n; i++) {
            cout << "-";
        }
        cout << endl;
        printRuler(n-1);
    }
}