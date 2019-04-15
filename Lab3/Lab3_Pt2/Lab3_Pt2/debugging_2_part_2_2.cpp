/*
 Student Name: Logan Christopher
 Student NetID: CLC1085
 Program Description: This program prints every other x character within a string.
*/

void printChars(int x);

#include <iostream>
using namespace std;

void printChars(int x, string y); // proto

int main() {
    // Declare vars that will be assigned amount of chars to print, and string
    int c;
    string s = "Hello World";
    
    cout << "Character printer. Every other character will be printed depending what value is given." << endl;
    cout << "Enter the number of characters you want to print: ";
    cin >> c;

    // Send the string and amount of chars as params to print function
    printChars(c, s);
}

void printChars(int x, string y) {
    // Temp x that will double in order to cycle through entire str
    int xVal = x;
    
    while (xVal <= y.length()) {
        // Index starts at 0, so subtract 1 to compensate
        int index = xVal - 1;
        cout << y[index];
        xVal += x;
    }
    cout << endl;
}
