/*
 Student Name: Logan Christopher
 Student NetID: CLC1085
 Program Description: This program converst seconds to a readable time format.
 */

#include <iostream>
#include <string>
#include "time_class.h"
using namespace std;


int main()
{
    // Case 1
    // ---------------------------------------------------------------------------------------------- //
    cout << "Case 1" << endl;
    
    Time obj1;
    
    cout << "145:59:12 + 25:00:57" << endl;
    obj1.set_time_by_seconds(525552); // Total: 525552 // 145 hours 59 min 12 sec
    
    obj1.increase_time_by_seconds(90057); // Total: 90057 // 25 hour 0 min 57 sec
    
    string time = obj1.get_time();
    cout << "Result: " << time << endl << endl; // Total: 615609 // 171 hours 0 min 9 sec
    
    // Case 2
    // ---------------------------------------------------------------------------------------------- //
    cout << "Case 2" << endl;
    
    Time obj2;
    
    cout << "60:12:22 - 12:56:02" << endl;
    obj2.set_time_by_seconds(216742); // Total: 216742 // 60 hours 12 min 22 sec

    obj2.decrease_time_by_seconds(46562); // Total: 46562 // 12 hour 56 min 2 sec
    
    time = obj2.get_time();
    cout << "Result: " << time << endl << endl; // Total: 263304 // 47 hours 16 min 20 sec
    
    // Case 3
    // ---------------------------------------------------------------------------------------------- //
    cout << "Case 3" << endl;
    
    Time obj3;
    
    cout << "02:11:54 - 03:00:10" << endl;
    obj3.set_time_by_seconds(7914); // Total: 7914 // 2 hours 11 min 54 sec
    
    obj3.decrease_time_by_seconds(10810); // Total: 10810 // 3 hour 0 min 10 sec
    
    time = obj3.get_time();
    cout << "Result: " << time << endl << endl; // Total: 0 // 0 hours 0 min 0 sec
}

