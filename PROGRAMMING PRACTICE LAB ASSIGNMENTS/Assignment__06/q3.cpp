/*
Implement a class template for 1D array. Elements may be any basic data type. 
Provision to find maximum element, sum of the elements must be there
*/



#include <bits/stdc++.h>
using namespace std;

template <class Type> // THE TEMPLATE DECLARATION
class Array // CAN STORE ANY BASIC DATA TYPE FOR ARITHMETIC OPERATIONS
{
    Type *arr;
    int Len;

public:
    Array(int len)
    {
        Len = len;
        arr = new Type[len];
    }
    Array()
    {
        arr = new Type[10];
    }

    void take_elements()
    {
        cout << "\nEnter array elements: ";
        for (int i = 0; i < Len; i++)
        {
            cin >> arr[i];
        }
    }

    Type sum_all() // SUM OF ALL VALUES OF THE ARRAY
    {
        Type sum = 0;
        for (int i = 0; i < Len; i++)
        {
            sum += arr[i];
        }
        return sum;
    }

    Type max_of_all() // MAX OF ALL ELEMENTS OF THE ARRAY
    {
        Type max = arr[0];
        for (int i = 1; i < Len; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        return max;
    }

    void dlt(){
        delete[] arr;
    }
};

int main()
{
    Array<float> list(4);
    cout << "\n----------------------float-----------------------------";
    list.take_elements();
    cout << "\nMAX: " << list.max_of_all();
    cout << "\nSUM: " << list.sum_all();

    Array<int> list2(4);
    cout << "\n----------------------integer-----------------------------";
    list.take_elements();
    cout << "\nMAX: " << list.max_of_all();
    cout << "\nSUM: " << list.sum_all();

    list.dlt();
    list2.dlt();
}