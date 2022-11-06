/* 2.	Write a function to find the product of two numbers. 
 Call it number of times. Make the functions inline.
  [check the time of execution and size of object code] */

#include <iostream>
#include <ctime>
#include <chrono>
 
using namespace std;

inline __attribute((always_inline)) int mult(int a, int b) {
    return a*b;
}

int mult2(int a, int b) {
    return a*b;
}

int main() {

    int k = 5, j = 7, product;

   //clock_t time_required;

    //time_required = clock(); // CLOCK STARTS

    auto begin = std::chrono::high_resolution_clock::now();


    for (int i = 0; i < 10000000; i++)
    {
       product = mult(j, k);
    }  
           

   // time_required = clock() - time_required; // TIME FOR NORMAL FUNCTION

   auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);

    cout << "The time required is: " << elapsed.count() * 1e-9 << " seconds" << endl;   

    // time_required = clock();

    begin = std::chrono::high_resolution_clock::now();


    for (int i = 0; i < 10000000; i++)
    {
       product = mult2(j, k);
    }  
           

   // time_required = clock() - time_required; // TIME FOR INLINE FUNCTION

      end = std::chrono::high_resolution_clock::now();
    elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);


    cout << "The time required is: " << elapsed.count() * 1e-9 << " seconds" << endl;    
            
    return 0;
}