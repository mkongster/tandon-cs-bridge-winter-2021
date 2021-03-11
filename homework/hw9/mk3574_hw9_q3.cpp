/*
Ming Kong
Tandon Bridge Winter 2021
Homework 9
Question 3
*/

#include <iostream>

using namespace std;

int* getPosNums1(int* arr, int arr_size, int& out_pos_arr_size);

int* getPosNums2(int* arr, int arr_size, int* out_pos_arr_size_ptr);

void getPosNums3(int* arr, int arr_size, int*& out_pos_arr, int& out_pos_arr_size);

void getPosNums4(int* arr, int arr_size, int** out_pos_arr_ptr, int* out_pos_arr_size_ptr);

void printArray(int* arr, int arr_size);
// Helper function to print out arrays

int main() {
    int* test_arr = nullptr;
    int test_arr_size = 6;
    test_arr = new int[test_arr_size]{3, -1, -3, 0, 6, 4};
    printArray(test_arr, test_arr_size);

    int new_arr_size = 0;
    //int* new_arr_ptr = getPosNums1(test_arr, test_arr_size, new_arr_size);
    //int* new_arr_ptr = getPosNums2(test_arr, test_arr_size, &new_arr_size);
    //printArray(new_arr_ptr, new_arr_size);

    int* new_arr_ptr = nullptr;
    //getPosNums3(test_arr, test_arr_size, new_arr_ptr, new_arr_size);
    //printArray(new_arr_ptr, new_arr_size);
    // getPosNums4(test_arr, test_arr_size, &new_arr_ptr, &new_arr_size);
    // printArray(new_arr_ptr, new_arr_size);

    delete [] new_arr_ptr;

    return 0;
}

void printArray(int* arr, int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        cout << *(arr + i) << "\t";
    }
    cout << endl;
}

int* getPosNums1(int* arr, int arr_size, int& out_pos_arr_size) {
    int* new_arr = nullptr;
    new_arr = new int[arr_size];

    out_pos_arr_size = 0;
    for(int i = 0; i < arr_size; i++) {
        if ( *(arr + i) > 0 ) {
            new_arr[out_pos_arr_size] = *(arr + i);
            out_pos_arr_size++;
        }
    }

    delete [] arr;

    return new_arr;
}

int* getPosNums2(int* arr, int arr_size, int* out_pos_arr_size_ptr) {
    int* new_arr = nullptr;
    new_arr = new int[arr_size];


    *out_pos_arr_size_ptr = 0;
    for(int i = 0; i < arr_size; i++) {
        if ( *(arr + i) > 0 ) {
            new_arr[*out_pos_arr_size_ptr] = *(arr + i);
            *out_pos_arr_size_ptr = *out_pos_arr_size_ptr + 1;
        }
    }   
    
    delete [] arr;

    return new_arr;
}

void getPosNums3(int* arr, int arr_size, int*& out_pos_arr, int& out_pos_arr_size) {
    out_pos_arr = new int[arr_size];

    out_pos_arr_size = 0;
    for(int i = 0; i < arr_size; i++) {
        if ( *(arr + i) > 0 ) {
            out_pos_arr[out_pos_arr_size] = *(arr + i);
            out_pos_arr_size++;
        }
    }

    delete [] arr;
}

void getPosNums4(int* arr, int arr_size, int** out_pos_arr_ptr, int* out_pos_arr_size_ptr) {
    *out_pos_arr_ptr = new int[arr_size];

    *out_pos_arr_size_ptr = 0;
    for(int i = 0; i < arr_size; i++) {
        if ( *(arr + i) > 0 ) {
            *(*out_pos_arr_ptr + *out_pos_arr_size_ptr) = *(arr + i);
            *out_pos_arr_size_ptr = *out_pos_arr_size_ptr + 1;
        }
    }   
  
    delete [] arr;
}