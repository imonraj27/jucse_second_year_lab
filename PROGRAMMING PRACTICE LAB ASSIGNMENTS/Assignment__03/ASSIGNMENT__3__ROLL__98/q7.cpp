/*	Define functions f(int, int) and f (char, int).
 Call the functions with arguments of type (int, char),
  (char,char) and (float, float). */

  
#include <iostream>

using namespace std;


void f(int a, int b) {
    cout << "\nThis is f(int, int)";
    cout << "\nYour parameters: " << a << " " << b;
}

//BOTH FUNCTION ARE SAME NAME OR FUNCTION OVERLOADING

// void f(char a, int b) {
//     cout << "\nThis is f(char, int)";
//     cout << "\nYour parameters: " << a << " " << b;
// }




int main() {

    int x = 5;
    char c1= 'A';
    char c2= 'B';
    float y = 54.25;
    float z = 9.55;

    f(x,c1);
    f(c1,c2);
    f(y,z);


    /* here occurs problem due to function overloading*/   

   return 0;
}