/*
Students come to mark sheet collection desk and are served in first come first 
served basis. Implement the scenario. Take the help of suitable STL class.
*/

#include <bits/stdc++.h>
#define NUMB_STUD 4
using namespace std;

class Student {
    string name;
    int roll;
    int marks[2];
    public:
    Student(string n, int r, int m1, int m2){
        name = n;
        roll = r;
        marks[0] = m1;
        marks[1] = m2;
    }
    Student(){
        name = "__";
        roll = -1;
        marks[0] = -1;
        marks[1] = -1;
    }
    int ROLL(){
        return roll;
    }
    void print_data(){ // PRINT A STUDENT MARKSHEET
        cout << "\n\n-----------------MARKSHEET-----------------------";
        cout << "\nNAME: " << name;
        cout << "\nROLL: " << roll;
        cout << "\nMARKS: " << marks[0] << " " << marks[1];
        cout << "\n---------------------------------------------------";
    }
};

class All_students {
    Student arr[NUMB_STUD];
    public:
    void prepare_all_sheets(){ // TAKE ALL MARKSHEET DATA
        string name;
        int r, m1, m2;

        for (int i = 0; i < NUMB_STUD; i++)
        {
            cout << "\n\n---------------" << i+1 << "th------------------------";
            cout << "\nEnter name : ";
            if(i!=0){
                cin.ignore();
            }
            getline(cin, name);
            cout << "\nEnter roll: ";
            cin >> r;
            cout << "\nEnter two marks: ";
            cin >> m1 >> m2;
            arr[i] = Student(name, r, m1, m2);
        }
        
    }

    void marksheet(int rol){ // SHOW MARKSHEET WITH ROLL
        for(int i=0; i<NUMB_STUD; i++){
            if(arr[i].ROLL()==rol){
                arr[i].print_data();
                return;
            }
        }

        cout << "\nInvalid roll!!";
    }
};

void marksheet_collection_desk(){ // FUNCTION FOR MARKSHEET COLLECTIONS
    All_students list;
    list.prepare_all_sheets();
    deque<int> StQ; // FIFO PRINCIPLE IMPLEMENTATION

    int choice, rr;

    do{ // MENU DRIVEN 
        cout << "\n1. ENQUEUE A STUDENT(add behind line)"
            << "\n2. DEQUEUE A STUDENT(provide marksheet and let go)"
            << "\n3. SHUT COLLECTION DESK DOWN"
            << "\n\nENTER CHOICE: ";
            cin >> choice;

            if(choice==3){
                break;
            }

            switch(choice){
                case 1:
                cout << "\nTell your roll to stand in queue: ";
                cin >> rr;
                StQ.push_front(rr);
                cout << "\n\n";
                break;
                case 2: 
                rr = StQ.back();
                StQ.pop_back();
                list.marksheet(rr);
                break;
                default:
                break;

            }
    }while(true);
}


int main(){
    marksheet_collection_desk();
    return 0;
}