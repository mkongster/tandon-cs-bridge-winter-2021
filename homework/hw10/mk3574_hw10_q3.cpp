/*
Ming Kong
Tandon Bridge Winter 2021
Homework 10
Question 3
*/

#include <iostream>
#include <vector>

using namespace std;

void main1();
// Not allowed to use vector

void main2();
// Allowed to use vector

void append_to_int_arr(int* &arr, int& size, int& capacity, int value);
// Dynamically appends value to an int array, doubles on resize.

int* populate_int_arr(int& size);
// Populates a dynamic array of user input integers returns the pointer to the int array and sets the size reference variable.

void search_int_arr(int* arr, int size);
// Asks the user for an integer to search within the integer array.


int main() {
    //main1();
    main2();
    return 0;
}

void main1() {
    int size;
    int* arr = populate_int_arr(size);
    search_int_arr(arr, size);
}

void append_to_int_arr(int* &arr, int& size, int& capacity, int value) {
    if (size == capacity) {
        int* temp = arr;
        capacity *= 2;

        for (int i = 0; i < size; i++) {
            arr[i] = temp[i];
        }

        delete [] temp;
    }
    arr[size] = value;
    size++;

}

int* populate_int_arr(int& size) {
    size = 0;
    int capacity = 1;
    int* arr = new int[capacity];

    int num;
    cout << "Please enter a sequence of positive integers, each in a separate line" << endl;
    cout << "End your input by typing -1." << endl;
    cin >> num;
    while(num != -1) {
        append_to_int_arr(arr, size, capacity, num);
        cin >> num;
    }

    return arr;
}

void search_int_arr(int* arr, int size) {
    int search;
    cout << "Please enter a number you want to search." << endl;
    cin >> search;

    int capacity = 1;
    int index_size = 0;
    int* indexes = new int[capacity];

    for (int i = 0; i < size; i++) {
        if (arr[i] == search) {
            append_to_int_arr(indexes, index_size, capacity, i + 1);
        }
    }

    if (index_size < 1) {
        cout << "Could not find your integer: " << search << endl;
    } else {
        cout << search << " shows in lines ";
        for (int i = 0; i < index_size - 1; i++) {
            cout << indexes[i] << ", ";
        }
        cout << indexes[index_size - 1] << '.' << endl;
    };
}

void main2() {
    vector<int> int_vec;

    cout << "Please enter a sequence of positive integers, each in a separate line" << endl;
    cout << "End your input by typing -1." << endl;    
    int num;
    cin >> num;
    while (num != -1) {
        int_vec.push_back(num);
        cin >> num;
    }

    int search;
    cout << "Please enter a number you want to search." << endl;
    cin >> search;
    vector<int> indexes;

    for (int i = 0; i < int_vec.size(); i++) {
        if (int_vec[i] == search) {
            indexes.push_back(i + 1);
        }
    }

    if (indexes.size() < 1) {
        cout << "Could not find your integer: " << search << endl;
    } else {
        cout << search << " shows in lines ";
        for (int i = 0; i < indexes.size() - 1; i++) {
            cout << indexes[i] << ", ";
        }
        cout << indexes[indexes.size() - 1] << '.' << endl;
    }

}