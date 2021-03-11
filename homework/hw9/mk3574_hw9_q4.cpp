/*
Ming Kong
Tandon Bridge Winter 2021
Homework 9
Question 4
*/

#include <iostream>

using namespace std;

void printArray(int arr[], int arr_size);

void swap(int index_one, int index_two, int arr[]);

void oddsKeepEvensFlip(int arr[], int arr_size);

int main() {
    int arr_size = 6;
    int arr[arr_size] = {5, 2, 11, 7, 6, 4};

    printArray(arr, arr_size);
    oddsKeepEvensFlip(arr, arr_size);
    printArray(arr, arr_size);

    int arr_size_two = 10;
    int arr_two[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    printArray(arr_two, arr_size_two);
    oddsKeepEvensFlip(arr_two, arr_size_two);
    printArray(arr_two, arr_size_two);

    return 0;
}

void printArray(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void oddsKeepEvensFlip(int arr[], int arr_size) {
    int even_index = arr_size - 1;
    int odd_index = 0;
    int copy_arr[arr_size];
    for (int i = 0; i < arr_size; i++) {
        copy_arr[i] = arr[i];
    }

    for (int i = 0; i < arr_size; i++) {
        if (copy_arr[i] % 2) {
            arr[odd_index] = copy_arr[i];
            odd_index++;
        } else {
            arr[even_index] = copy_arr[i];
            even_index--;
        }
    }

}
