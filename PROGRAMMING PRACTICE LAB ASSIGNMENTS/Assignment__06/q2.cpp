/*

Consider a class Student with roll, name and score as attributes. Support to take 
and display data is also there. One wants to works with array of Student 
objects. May collect data for array elements, display those. In case index goes 
out of bounds, exception is to be raised with suitable message
*/

#include <bits/stdc++.h>
using namespace std;

class STUDENT
{ // STUDENT CLASS WITH BASIC READ WRITE OPERATIONS
    int roll;
    int score;
    string name;

public:
    void take_data()
    {
        cout << "\nEnter Name: ";
        getline(cin, name);
        cout << "\nEnter roll: ";
        cin >> roll;
        cout << "\nEnter Score: ";
        cin >> score;
        cin.ignore();
    }

    void print_data()
    {
        cout << "\nName: " << name
             << "\nRoll: " << roll
             << "\nScore: " << score;
    }
};

class STUDENT_LIST
{ // CLASS TO MAINTAIN A STUDENT LIST OF A MAX LENGTH
    int Len, index;
    STUDENT *sArr;

public:
    class Error
    { // THE ERROR EXCEPTION CLASS
    };

    STUDENT_LIST(int l)
    {
        Len = l;
        sArr = new STUDENT[Len];
        index = 0;
    }

    void add_student()
    {
        if (index < Len)
        {
            sArr[index].take_data();
            index++;
        }
        else
        {
            throw Error(); // THORW ERROR WHENEVER OUT OF RANGE INDEX
        }
    }

    void show_student()
    {
        int i;
        cout << "\nEnter index: ";
        cin >> i;

        if (i >= 0 && i < Len && i <= index)
        {
            sArr[i].print_data();
        }
        else
        {
            throw Error(); // THORW ERROR WHENEVER OUT OF RANGE INDEX
        }
    }

    void dlt_ev()
    {
        delete[] sArr;
    }
};

int main()
{
    STUDENT_LIST list(4);
    try
    { // TRY CATCH BLOCK TO HANDLE EXCEPTIONS
        list.add_student();
        list.add_student();
        list.add_student();
        list.add_student();
        list.add_student();
    }
    catch (STUDENT_LIST::Error)
    {
        cout << "\nSome error occured!!";
    }

    list.dlt_ev();

    list = STUDENT_LIST(4);

    try
    { // TRY CATCH BLOCK TO HANDLE EXCEPTIONS
        list.add_student();
        list.add_student();
        list.show_student();
        list.show_student();
    }
    catch (STUDENT_LIST::Error)
    {
        cout << "\nSome error occured!!";
    }

    list.dlt_ev();
}