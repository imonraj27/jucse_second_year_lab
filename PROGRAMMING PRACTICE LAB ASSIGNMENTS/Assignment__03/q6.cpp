/* 6.	Write a function void f(int) that prints “inside f(int)”.
 Call the function with actual argument of type: i) int, ii) char, 
 iii) float and iv) double. Add one more function f(float) that 
 prints “inside f(float)”.  Repeat the calls again and observe the outcomes. */


#include <iostream>

using namespace std;

void f(int a) {
    cout << "\ninside f(int)";
}

// void f(float a) {
//     cout << "\ninside f(float)";
// }



int main() {
    int k = 2;
    char c = 'a';
    float t = 32.02;
    double s = 3.87;

    f(k);
    f(c);
    f(t);
    f(s);
 
   /*When Both the functions are there there is overloading, and 
   doesn't compile shows ambiguous situation*/

   return 0;
}