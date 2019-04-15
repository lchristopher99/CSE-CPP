/*
 Student Name: Logan Christopher
 Student NetID: CLC1085
 Program Description: This program converts liters to quarts.
 */


#include <iostream>
using namespace std;

double circleArea(double radius);

int main() {
    // Declare two vars: radius and area
    double r, a;
    
    cout << "Circle area calculator" << endl;
    cout << "Enter the radius of the cirle area you want to compute: ";
    cin >> r;
    
    // Send the radius as a param to area function
    a = circleArea(r);
    
    cout << "The area of the circle is: " << a << endl;
}

double circleArea(double radius) {
    double area;
    // Compute area using params
    area = (radius * radius) * 3.14;
    
    return area;
}
