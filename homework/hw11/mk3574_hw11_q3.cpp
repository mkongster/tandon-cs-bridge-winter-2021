/*
Ming Kong
Tandon Bridge Winter 2021
Homework 11
Question 3
*/

#include <iostream>

using namespace std;

int minInArray1(int arr[], int arr_size);

int minInArray2(int arr[], int low, int high);

int main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;

    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout << res1 << " " << res2 << endl;

    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4);
    cout << res3 << " " << res4 << endl;
    return 0;
}

int minInArray1(int arr[], int arr_size) {
    if (arr_size == 1) {
        return arr[0];
    } else {
        if (arr[arr_size - 1] < arr[0]) {
            arr[0] = arr[arr_size - 1];
        }
        return minInArray1(arr, arr_size - 1);
    }
    return 0;
}

int minInArray2(int arr[], int low, int high) {
    if (low == high) {
        return arr[low];
    } else {
        if (arr[high - 1] < arr[low]) {
            arr[low] = arr[high - 1];
        }
        return minInArray2(arr, low, high - 1);
    }
}