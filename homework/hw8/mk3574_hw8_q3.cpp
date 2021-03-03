/*
Ming Kong
Tandon Bridge Winter 2021
Homework 8
Question 3
*/

#include <iostream>

using namespace std;

void reverseArray(int arr[], int arr_size);
// Take an array of integers and its size, reorders to array to appear in reverse.

void swap(int index_one, int index_two, int arr[]);
// Swaps the elements of two locations in an array of integers.

void removeOdd(int arr[], int& arr_size);
// Alters an array so that only the numbers in it are the even ones, and updates the array size.

void splitParity(int arr[], int arr_size);
// Alters the order of numbers in an array so that all the odd numbers will appear first, and all even numbers appear last.

void printArray(int arr[], int arr_size);
// Helper function to print all integers in an array of a given size.

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1_size = 5;

    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2_size = 5;

    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3_size = 5;

    reverseArray(arr1, arr1_size);
    printArray(arr1, arr1_size);

    removeOdd(arr2, arr2_size);
    printArray(arr2, arr2_size);

    splitParity(arr3, arr3_size);
    printArray(arr3, arr3_size);

    return 0;
}

void reverseArray(int arr[], int arr_size) {
    int mid = arr_size / 2;
    for (int i = 0; i < mid; i++) {
        swap(i, arr_size - i - 1, arr);
    }
}

void swap(int index_one, int index_two, int arr[]) {
    int temp = arr[index_one];
    arr[index_one] = arr[index_two];
    arr[index_two] = temp;
}

void removeOdd(int arr[], int& arr_size) {
    int even_index = 0;
    for (int i = 0; i < arr_size; i++) {
        if (arr[i] % 2 == 0) {
            swap(i, even_index, arr);
            even_index++;
        }
    }

    arr_size -= arr_size - even_index;
}

void splitParity(int arr[], int arr_size) {
    int temp_size = arr_size;
    removeOdd(arr, arr_size);
    reverseArray(arr, temp_size);
}

void printArray(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}