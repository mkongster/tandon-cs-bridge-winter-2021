/*
Ming Kong
Tandon Bridge Winter 2021
Homework 8
Question 1
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

const int CHAR_ZERO = 48;
const int MAX_ARRAY = 20;

int minInArray(int arr[], int arr_size);
// Finds the minimum integer in an array.

int parseStringToNumArray(string& input, int arr[]);
// Parses a string of numbers separated by space to an array.
// Returns the length of the array populated.

int main() {
    // int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    // cout << minInArray(arr, 10) << endl;

    int arr[MAX_ARRAY];
    int array_length;
    string input;

    cout << "Please enter 20 integers separated by a space: \n";
    getline(cin, input);

    array_length = parseStringToNumArray(input, arr);

    int min = minInArray(arr, array_length);

    cout << "The minimum value is " << min << ", and it is located in the following indices: ";
    for (int i = 0; i < array_length; i++) {
        if (arr[i] == min) {
            cout << i << " ";
        }
    }

    cout << endl;

    
    return 0;

}

int minInArray(int arr[], int arr_size) {
    int min = INT32_MAX;

    for (int i = 0; i < arr_size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

int parseStringToNumArray(string& input, int arr[]) {
    int array_counter = 0, index = 0;
    int str_length = input.length();
    int temp = 0;

    while (index < str_length) {
        if (input[index] != ' ') {
            temp *= 10;
            temp += int(input[index]) - CHAR_ZERO;
        } else {
            arr[array_counter] = temp;
            array_counter++;
            temp = 0;
        }
        index++;
    }
    arr[array_counter] = temp;
    array_counter++;

    return array_counter;
}