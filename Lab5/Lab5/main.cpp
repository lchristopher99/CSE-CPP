/*
 Student Name: Logan Christopher
 Student NetID: CLC1085
 Program Description: This program takes input for a dictionary and outputs what was entered.
 */

#include <iostream>
using namespace std;

void userInput(string dictWord[], string dictDef[], int size);
void userOutput(string dictWord[], string dictDef[], int size);

int main() {
    int size;
    
    cout << "How many terms do you want the dictionary to hold? ";
    cin >> size;
    
    string dictWord[size];
    string dictDef[size];
    
    userInput(dictWord, dictDef, size);
    userOutput(dictWord, dictDef, size);
}

void userInput(string dictWord[], string dictDef[], int size) {
    string entry;
    cin.ignore();
    
    for (int i = 0; i < size; i++) {
        cout << "Enter Term " << (i + 1) << ": ";
        getline(cin, entry);
        
        dictWord[i] = entry;

        cout << "Enter the definition for '" << entry << "': ";
        getline(cin, entry);

        dictDef[i] = entry;

        cout << endl;
    }
}

void userOutput(string dictWord[], string dictDef[], int size) {
    cout << "You entered:" << endl;
    for (int i = 0; i < size; i++) {
        cout << (i + 1) << ". " << dictWord[i] << ": ";
        cout << dictDef[i] << endl;
    }
}
