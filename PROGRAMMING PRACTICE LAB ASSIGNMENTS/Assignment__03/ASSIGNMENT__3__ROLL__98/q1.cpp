/*  1.	Write a Macro to find the maximum of two numbers. Call the macro with
 i) two integers as the arguments and ii) two char * as the arguments. Observe the outcomes.   */


#include <iostream>
#define MAX(a,b) ((a>b) ? a: b) //Defining the macro here

using namespace std;

int main() {
    int x=10, y=15, z; // Integers declaration
    z = MAX(x,y); // Using the macro here
    cout << "Using integers: " << z << "\n";

    // ----------Using the macro with char * variable----------------

    char p='a', q='c';
    char * pp = &p;
    char * pq = &q;

    char * pr = MAX(pp,pq); // Using the macro 
    cout << "Two char * are: " << (int)pp << " " << (int)pq << "   Max Using char pointers: " << (int)pr; // It prints unknown result some unknown characters
    return 0;
}

