/*
Ming Kong
Tandon Bridge Winter 2021
Homework 10
Question 2
*/

#include <iostream>

using namespace std;

int* findMissing(int arr[], int n, int& res_arr_size);

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << '\t';
    }
    cout << endl;
}

int main() {
    int test[] = {3, 1, 3, 0, 6, 4};
    int new_size;
    
    cout << "Before: ";
    printArray(test, 6);
    int* new_arr = findMissing(test, 6, new_size);

    cout << "After: \t";
    printArray(new_arr, new_size);

    return 0;
}

int* findMissing(int arr[], int n, int& res_arr_size) {
    int* temp = new int[n]{0};
    int* new_arr = new int[n];

    int missing = 0;
    for (int i = 0; i <= n; i++) {
        temp[arr[i]] = -1; 
    }

    for (int i = 0; i <= n; i++) {
        if (temp[i] != -1) {
            new_arr[missing] = i;
            missing++;
        }
    }

    res_arr_size = missing;
    delete [] temp;

    return new_arr;
}