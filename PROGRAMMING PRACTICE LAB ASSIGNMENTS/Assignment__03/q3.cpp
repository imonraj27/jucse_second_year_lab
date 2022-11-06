/* 3.	Write a function swap (a, b) to interchange 
the values of two variables. Do not use pointers. */

#include <iostream>

using namespace std;

void swap(int &p, int &q) { // We are passing arguments by reference
    int t = p; // t is temporary variable
    p = q;
    q = t;
}

int main() {
    int a, b;
    cout << "\nEnter the two integers to swap: "; // Taking int values
    cin >> a >> b;
    swap(a, b);
    cout << "\nValues after swapping are: " << a << " " << b << "\n"; // Printing after swapping
    return 0;
}