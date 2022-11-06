/* 4.	Write a function max (a, b) that will return the reference 
of larger value. Store the returned information to x where x is a i) 
variable of type a or b, ii) variable referring to type of a or b. 
In both the cases modify x. Check also the values of a and b. */


#include <iostream>

using namespace std;

int & max(int &x, int &y) { // FINDING MAX THORUGH PASSING BY REFERENCE
    if(x>y) {
        return x;
    } else {
        return y;
    }
}

int main() {
    cout << "Enter the two integers: ";
    int a, b;
    cin >> a >> b;

     cout << "\n-------------------First Part------------------------";
    int x = max(a, b); // x is of type integer
    cout << "\ninteger x is now " << x << " when it is int type";
    x++;
    cout << "\nx after modifying: " << x;
    cout << "\na and b are now: " << a << " " << b;

    cout << "\n-------------------Second Part------------------------";

    int &y = max(a,b); // y is of type integer reference
    cout << "\ny is now " << y << " when it is int & type";
    y++;
    cout << "\ninteger reference y after modifying: " << y;
     cout << "\na and b are now: " << a << " " << b;
}