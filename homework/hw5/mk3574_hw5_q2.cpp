/*
Ming Kong
Tandon Bridge Winter 2021
Homework 5
Question 2
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int const MAX_GUESSES = 5;

int main() {
    srand(time(0));
    int answer = (rand() % 100) + 1;
    int high = 100;
    int low = 1;
    int numGuesses = 0;
    int guess;

    cout << "I thought of a number between 1 and 100! Try to guess it.\n";
    do {
        cout << "Range: [" << low << ", " << high << "], Number of guesses left: " << MAX_GUESSES - numGuesses << endl;
        cout << "Your guess: ";
        cin >> guess;
        numGuesses++;

        if (guess == answer) {
            cout << "Congrats! You guessed my number in " << numGuesses << " guesses.\n";
            return 0;
        } else if (MAX_GUESSES != numGuesses) {
            if (guess > answer) {
                cout << "Wrong! My number is smaller.\n\n";
                high = guess - 1;
            } else {
                cout << "Wrong! My number is bigger.\n\n";
                low = guess + 1;
            }
        }

    } while (numGuesses < MAX_GUESSES);

    cout << "Out of guesses! My number is " << answer << endl;

    return 0;
}