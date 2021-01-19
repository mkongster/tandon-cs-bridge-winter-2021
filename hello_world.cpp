#include <iostream>

using namespace std;

int main()
{
    int ascii;
    char character;
    cout << "Please enter a character: ";
    cin >> character;
    ascii = character;
    cout << "The character, " << character << " has an ascii value of: ";
    cout << ascii << endl;
    
    return 0;
}
