/*
 Student Name: Logan Christopher
 Student NetID: clc1085
 Program Description: This program analyzes the time it takes for certain algorithms to run.
 */

#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

void populate(int arr[], int size);
void printlist(int arr[], int size);
void swap(int &x, int &y);
long long calc_time();
int partition(int arr[], int start, int finish);

// algorithm protos
void selectionSort(int arr[], int size, string type);
void quickSort(int arr[], int start, int finish);


int main() {
    int size;
    cout << "How many elements do you want to populate the array with? ";
    cin >> size;
    cout << "-----------------------------------------------------------------------------------------------" << endl;

    
    int arr[size];
    
    // sorted in ASCENDING order, then SELECTION sorted and timed //

    populate(arr, size);
    // printlist(arr, size);
    
    selectionSort(arr, size, "a");

    long long startTime = calc_time();
    selectionSort(arr, size, "a");
    // printlist(arr, size);
    long long endTime = calc_time();
    
    cout << "Selection sort (SORTED) finished in " << endTime - startTime << " milliseconds." << endl;
    cout << endl;

    // sorted in REVERSE order, then SELECTION sorted and timed //

    populate(arr, size);
    // printlist(arr, size);
    
    selectionSort(arr, size, "r");
    
    startTime = calc_time();
    selectionSort(arr, size, "a");
    // printlist(arr, size);
    endTime = calc_time();
    
    cout << "Selection sort (REVERSED) finished in " << endTime - startTime << " milliseconds." << endl;
    cout << endl;
    
    // sorted in RANDOM order, then SELECTION sorted and timed //
    int x = 0;
    while (x < 3) {
        populate(arr, size);
        // printlist(arr, size);
        
        startTime = calc_time();
        selectionSort(arr, size, "a");
        // printlist(arr, size);
        endTime = calc_time();
        
        cout << "Selection sort (RANDOM) finished in " << endTime - startTime << " milliseconds. Iteration: " << x + 1 << endl;
        cout << endl;

        x += 1;
    }

    cout << "-----------------------------------------------------------------------------------------------" << endl;
    
    // sorted in ASCENDING order, then QUICK sorted and timed //
    
    populate(arr, size);
    // printlist(arr, size);
    
    quickSort(arr, 0, size - 1);

    startTime = calc_time();
    quickSort(arr, 0, size - 1);
    // printlist(arr, size);
    endTime = calc_time();

    cout << "Quick sort (SORTED) finished in " << endTime - startTime << " milliseconds." << endl;
    cout << endl;
    
    // sorted in REVERSE order, then QUICK sorted and timed //

    populate(arr, size);
    // printlist(arr, size);
    
    selectionSort(arr, size, "r");

    startTime = calc_time();
    quickSort(arr, 0, size - 1);
    // printlist(arr, size);
    endTime = calc_time();
    
    cout << "Quick sort (REVERSED) finished in " << endTime - startTime << " milliseconds." << endl;
    cout << endl;

    // sorted in RANDOM order, then QUICK sorted and timed //
    x = 0;
    while (x < 3) {
        populate(arr, size);
        // printlist(arr, size);
        
        startTime = calc_time();
        quickSort(arr, 0, size - 1);
        // printlist(arr, size);
        endTime = calc_time();
        
        cout << "Quick sort (RANDOM) finished in " << endTime - startTime << " milliseconds. Iteration: " << x + 1 << endl;
        cout << endl;
        
        x += 1;
    }
}

void populate(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void printlist(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

//Returns the time in milliseconds (as a 128 bit integer)
long long calc_time()
{
    //Complicated and difficult to understand(at the moment) C++ code for getting the time in
    //milliseconds.
    microseconds ms = duration_cast<microseconds>(system_clock::now().time_since_epoch());
    
    //Transform the time into a big integer and return it.
    return ms.count();
}

int partition(int arr[], int start, int finish) {
    int p_index = (start + finish) / 2;
    int pivot_value = arr[p_index];
    
    swap(arr[p_index], arr[finish]);
    
    int new_location = start - 1;
    
    for (int i = start; i < finish; i++) {
        if (arr[i] <= pivot_value) {
            new_location++;
            swap(arr[new_location], arr[i]);
        }
    }
    
    swap(arr[new_location + 1], arr[finish]);
    return new_location + 1;
}

// algorithms
void selectionSort(int arr[], int size, string type) {
    if (type == "a") {
        for (int i = 0; i < size; i++) {
            int mark = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[mark] > arr[j]) {
                    mark = j;
                }
            }
            swap(arr[i], arr[mark]);
        }
    } else if (type == "r") {
        for (int i = 0; i < size; i++) {
            int mark = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[mark] < arr[j]) {
                    mark = j;
                }
            }
            swap(arr[i], arr[mark]);
        }
    }
}

void quickSort(int arr[], int start, int finish) {
    if (start < finish)
    {
        int p_index = partition(arr, start, finish);
        quickSort(arr, start, p_index - 1);
        quickSort(arr, p_index + 1, finish);
    }
}
