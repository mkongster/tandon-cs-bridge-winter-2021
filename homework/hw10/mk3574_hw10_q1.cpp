/*
Ming Kong
Tandon Bridge Winter 2021
Homework 10
Question 1
*/

#include <iostream>

using namespace std;

string* createWordsArray(string sentence, int& out_words_arr_size);
// Creates a dynamic arr of strings based on words in a sentence.

int main() {
    string s;
    string* arr;
    int arr_size;

    cout << "Please enter a sentence: " << endl;
    getline(cin, s);

    arr = createWordsArray(s, arr_size);

    for (int i = 0; i < arr_size; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}


string* createWordsArray(string sentence, int& out_words_arr_size) {
    string* words_array = new string[1];
    int capacity = 1;
    int size = 0;
    int index = 0;
    int occurence = sentence.find(" ");

    if (occurence == string::npos) {
        words_array[size] = sentence;
        out_words_arr_size = capacity;
        return words_array;
    }

    do {
        if (size == capacity) {
            string* temp = words_array;
            capacity *= 2;
            words_array = new string[capacity];
            for (int i = 0; i < size; i++) {
                words_array[i] = temp[i];
            }

            delete [] temp;
        }

        words_array[size] = sentence.substr(index, occurence - index);
        size++;
        index = occurence + 1;
        occurence = sentence.find(" ", index);
    } while (index != 0);
    
    out_words_arr_size = size;
    return words_array;
}