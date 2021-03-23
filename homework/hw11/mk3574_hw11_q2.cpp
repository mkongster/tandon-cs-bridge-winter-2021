/*
Ming Kong
Tandon Bridge Winter 2021
Homework 11
Question 2
*/

#include <iostream>

using namespace std;

int sumOfSquares(int arr[], int arr_size);

bool isSorted(int arr[], int arr_size);

int main() {
    int arr_one[] = {2, -1, 3, 10};
    //cout << sumOfSquares(arr, 4) << endl;
    int arr_two[] = { 20, 23, 23, 45, 78, 88 };
    cout << isSorted(arr_two, 6) << endl;
    cout << isSorted(arr_one, 4) << endl;
    return 0;
}

int sumOfSquares(int arr[], int arr_size) {
    if (arr_size == 1) {
        return arr[0] * arr[0];
    } else {
        return sumOfSquares(arr, arr_size - 1) + (arr[arr_size - 1] * arr[arr_size - 1]) ;
    }
}

bool isSorted(int arr[], int arr_size) {
    if (arr_size == 2) {
        return (arr[0] < arr[1]);
    } else {
        if (arr[arr_size - 1] < arr[arr_size - 2]) {
            return false;
        }
        return isSorted(arr, arr_size - 1);
    }

    return true;
}