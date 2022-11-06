/*

Design a COMPLEX class, which will behave like normal integer with
 respect to 
  addition,
   subtraction,
    accepting the value and 
    Displaying the value.

*/


#include <iostream>

using namespace std;

class Complex { // complex class
    float real;
    float imag;
    public:
    Complex(){
        real = 0;
        imag = 0;
    }

    Complex(float r, float i){
        real = r;
        imag = i;
    }

    Complex operator + (Complex cn){ // overloaded binary +
        return Complex(real+cn.real, imag+cn.imag);
    }

     Complex operator - (Complex cn){ // overloaded binary -
        return Complex(real-cn.real, imag-cn.imag);
    }

    Complex operator * (Complex cn){ // overloaded multiplication
        int r = real*(cn.real) - imag*(cn.imag);
        int i = imag*(cn.real) + real*(cn.imag);
        return Complex(r, i);
    }
    friend ostream & operator << (ostream &, Complex &); // overloaded output
    friend istream & operator >> (istream &, Complex &); // overloaded input

   
};

 ostream & operator << (ostream & op, Complex & cm){
        op << cm.real;
        op << ((cm.imag<0)?"":"+") << cm.imag << "i";
        return op;
    }

  istream & operator >> (istream & ip, Complex & cm){
      ip >> cm.real >> cm.imag;
      return ip;
  }


void divider(){ // for just decoration purpose
    cout << "\n--------------------------------------------------\n";
}

 int main(){
   Complex c1, c2, c3, c4, c5; // all complex numbers to do various stuffs
   divider();
   cout << "Enter first complex number: ";
   cin >> c1;
   divider();
   cout << "Enter second complex number: ";
   cin >> c2;
   divider();
   c3 = c1+c2; //add
   c4 = c1-c2; //subtract
   c5 = c1*c2; //multiply
   cout << "SUM: " << c3;
   divider();
   cout << "SUBTRACTION: " << c4;
   divider();
   cout << "PRODUCT: " << c5;
   
 }   