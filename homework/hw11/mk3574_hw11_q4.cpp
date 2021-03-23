/*
Ming Kong
Tandon Bridge Winter 2021
Homework 11
Question 4
*/

#include <iostream>

using namespace std;

int jumpIt(int arr[], int pos, int size);

int main() {
    int arr[] = {0, 3, 80, 6, 57, 10};
    cout << jumpIt(arr, 0, 6) << endl;
    return 0;
}

int jumpIt(int arr[], int pos, int size) {
    if (pos >= size - 1) {
        return arr[size - 1];
    } else {
        int path_two = jumpIt(arr, pos + 2, size) + arr[pos];
        int path_one = jumpIt(arr, pos + 1, size) + arr[pos];
        if (path_one < path_two) {
            return path_one;
        } else {
            return path_two;
        }
    }
}