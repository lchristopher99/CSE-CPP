/*
 Student Name: Logan Christopher
 Student NetID: clc1085
 Program Description: This program analyzes the time it takes for the radix algorithm to run.
 */

#include<iostream>
using namespace std;
using namespace std::chrono;

// proto
int findMaxNum(int arr[], int size);
void countSort(int arr[], int size, int exp);
void radixSort(int arr[], int size, string type);
void populate(int arr[], int size);
void printList(int arr[], int size);
long long calc_time();


int main()
{
    int size;
    cout << "How many elements do you want to populate the array with? ";
    cin >> size;
    cout << "--------------------------------------------------------------" << endl;
    
    
    int arr[size];
    
    // Ascending
    populate(arr, size);
    
    long long startTime = calc_time();
    radixSort(arr, size, "a");
    long long endTime = calc_time();
    
    cout << "Radix sort (ASCENDING) finished in " << endTime - startTime << " milliseconds." << endl;
    cout << endl;
    
    // printList(arr, size);
    
    // Descending
    populate(arr, size);
    
    startTime = calc_time();
    radixSort(arr, size, "r");
    endTime = calc_time();
    
    cout << "Radix sort (DESCENDING) finished in " << endTime - startTime << " milliseconds." << endl;
    cout << endl;
    
    // printList(arr, size);
    
    // Random
    populate(arr, size);
    
    startTime = calc_time();
    radixSort(arr, size, "a");
    endTime = calc_time();
    
    cout << "Radix sort (RANDOM) finished in " << endTime - startTime << " milliseconds." << endl;
    cout << endl;
    
    // printList(arr, size);
    
    populate(arr, size);
    
    startTime = calc_time();
    radixSort(arr, size, "a");
    endTime = calc_time();
    
    cout << "Radix sort (RANDOM) finished in " << endTime - startTime << " milliseconds." << endl;
    cout << endl;
    
    // printList(arr, size);
    
    populate(arr, size);
    
    startTime = calc_time();
    radixSort(arr, size, "a");
    endTime = calc_time();
    
    cout << "Radix sort (RANDOM) finished in " << endTime - startTime << " milliseconds." << endl;
    cout << endl;
    
    // printList(arr, size);
    
    return 0;
}

// loop through array and find largest number
int findMaxNum(int arr[], int size) {
    int mark = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > mark) {
            mark = arr[i];
        }
    }

    return mark;
}

void countSort(int arr[], int size, int index) {
    int output[size];
    int i, occurences[10] = {0};
    
    for (i = 0; i < size; i++) {
        occurences[(arr[i]/index)%10]++;
    }
    
    for (i = 1; i < 10; i++) {
        occurences[i] += occurences[i - 1];
    }
    
    for (i = size - 1; i >= 0; i--) {
        output[--occurences[arr[i]/index%10]]=arr[i];
    }
    
    for (i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

void countSortReversed(int arr[], int size, int index) {
    int output[size];
    int i, occurences[10] = {0};
    
    for (i = 0; i < size; i++) {
        occurences[9 - (arr[i]/index)%10]++;
    }
    
    for (i = 1; i < 10; i++) {
        occurences[i] += occurences[i - 1];
    }
    
    for (i = size - 1; i >= 0; i--) {
        output[--occurences[9-arr[i]/index%10]]=arr[i];
    }
    
    for (i = 0; i < size; i++) {
        arr[i] = output[i];
    }
}

//
void radixSort(int arr[], int size, string type) {
    int maxNum = findMaxNum(arr, size);

    if (type == "a") {
        for (int index = 1; maxNum/index > 0; index *= 10) {
            countSort(arr, size, index);
        }
    } else if (type == "r") {
        for (int index = 1; maxNum/index > 0; index *= 10) {
            countSortReversed(arr, size, index);
        }
    }
}

// populates list with random integers
void populate(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

// prints list
void printList(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

//Returns the time in milliseconds (as a 128 bit integer)
long long calc_time() {
    //Complicated and difficult to understand(at the moment) C++ code for getting the time in
    //milliseconds.
    microseconds ms = duration_cast<microseconds>(system_clock::now().time_since_epoch());
    
    //Transform the time into a big integer and return it.
    return ms.count();
}
