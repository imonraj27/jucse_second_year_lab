/*
Design an ARRAY class with the following features:
a. Array object may be declared for a specific size and a value for initializing 
all the elements. If this it is to be assumed as a 0.
b. An array object may be declared and initialized with another object.
c. An array object may be declared and initialized with another array (not the 
object, standard array as in C language).
Let a and b are two objects:
i. a+b will add corresponding elements.
ii. a=b will do the assignment.
iii. a[I] will return the ith element of the object.
iv. a*5 or 5*a will multiply the element with 5.

*/





#include <iostream>
#define ARRSIZE(a) ((int)(sizeof(ar)/sizeof(ar[0])))


using namespace std;

class Array // array class
{
    private:
    int *arr;
    int size;

public:
    Array(int n)
    {
        size = n;
        arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            *(arr + i) = 0;
        }
    }

    ~Array(){
        delete[] arr;
    }

    int & operator [] (int i){ // overloading the subscript operator
        
         if(i > size-1){
            return arr[0];
        }
        return arr[i];
    }

    Array & operator + (const Array & a){ // overloaded + addition
        Array * b;
        if(a.size != size){
            b = new Array(1);
            return (*b);
        }

        b = new Array(size);

        for (int i = 0; i < size; i++)
            (*b)[i] = a.arr[i] + arr[i]; 

        return (*b);
    }

    Array & operator = (const Array &right) // overloaded asssignment operator
    { //IMPO
        if (&right != this)
        {
            if (size != right.size)
            {
                delete[] arr;
                size = right.size;
                arr = new int[size];
            }
        }
        for (int i = 0; i < size; i++)
            arr[i] = right.arr[i];
        return *this;
    }

    Array & from_array(int * ar, int n){ // copying from a built in C array to Array object
         if (size != n)
            {
                delete[] arr;
                size = n;
                arr = new int[size];
            }

            for (int i = 0; i < n; i++)
            {
                arr[i] = ar[i];
            }

             return *this;
            
    }

    Array & operator * (int t){ // multiplying all elements with a value
        Array * ar = new Array(size);
        for (int i = 0; i < size; i++)
        {
            (*ar)[i] = arr[i]*t;
        }

        return *ar;
        
    }


    // overloaded input and output operator
    friend ostream& operator << (ostream &, Array &); 
    friend istream& operator >> (istream &, Array &);
    friend Array& operator * (int, Array &);
 
};

ostream & operator << (ostream & op, Array & a){
    int len = a.size;
    for (int i = 0; i < len; i++)
    {
        op << a[i] << " ";
    }
    return op;
}



istream & operator >> (istream & ip, Array & a){
    int len = a.size;
    for (int i = 0; i < len; i++)
    {
        ip >> a[i];
    }
    return ip;
}

Array& operator * (int j, Array & a){
      int len = a.size;
       Array * ar = new Array(len);
    for (int i = 0; i < len; i++)
    {
        (*ar)[i] = j*a[i];
    }
    return *ar;
}


int main(){

    // creating array objects and doing various operations
    Array a(5);
   Array b(5);
    cout << "\nEnter first array: ";
   cin >> a;
   cout << "\nEnter second one: ";
   cin >> b;
   cout << "\nFirst array: " << a;
   cout << "\nSecond array: " << b;
   Array d = a*5;
    cout << "\nFirst array into 5 is: " << d;
   Array e = a+b;
   cout << "\nSum of two arrays: " << e;
    return 0;
}
