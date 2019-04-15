/*
 Student Name: Logan Christopher
 Student NetID: CLC1085
 Program Description: This program comapres two arrays and returns whether or not they match.
 */


#include <iostream>
using namespace std;

// proto
int compareArr(int sizeArr1, int sizeArr2, int arr1[], int arr2[], int match);
void printMatch(int match);

int main() {
    // declare a boolean match variable that will be used to determine if there is match
    int match = 0;
    
    // declare constants for array sizes
    const int ARR_SIZE1 = 5;
    const int ARR_SIZE2 = 6;
    
    // declare arrays and elements within
    int arr1[ARR_SIZE1] = {10, 20, 30, 40, 50};
    int arr2[ARR_SIZE1] = {10, 20, 30, 40, 50};
    int arr3[ARR_SIZE2] = {10, 20, 30, 40, 50, 60};
    int arr4[ARR_SIZE1] = {50, 40, 30, 20, 10};
    
    // Get size of all arrays
    int sizeArr1 = sizeof(arr1) / sizeof(arr1[0]);
    int sizeArr2 = sizeof(arr2) / sizeof(arr2[0]);
    int sizeArr3 = sizeof(arr3) / sizeof(arr3[0]);
    int sizeArr4 = sizeof(arr4) / sizeof(arr4[0]);

    // compare size of arrays
    printMatch(compareArr(sizeArr1, sizeArr2, arr1, arr2, match));
    printMatch(compareArr(sizeArr2, sizeArr3, arr2, arr3, match));
    printMatch(compareArr(sizeArr3, sizeArr4, arr3, arr4, match));
}

int compareArr(int sizeArr1, int sizeArr2, int arr1[], int arr2[], int match) {
    // compare length
    if (sizeArr1 == sizeArr2) {
        // loop through each element within matching length arrays and if all elements match, according to respective index, ...
        for (int i = 0; i < sizeArr1; i++) {
            if (arr1[i] == arr2[i]) {
                // ... then both arrays are equal
                match = true;
            } else {
                // ... if not, then return a false value and break loop
                return false;
            }
        }
        
        if (match) {
            return true;
        }
        
    } else {
        return false;
    }
    
    return 0;
}

// if bool value 'match' is true, print 'match'
void printMatch(int func) {
    if (func) {
        cout << "Arrays Match." << endl;
    } else {
        cout << "Arrays Do Not Match." << endl;
    }
}
