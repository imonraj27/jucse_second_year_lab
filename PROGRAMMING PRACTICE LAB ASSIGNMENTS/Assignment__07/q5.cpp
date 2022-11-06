/*
Store the roll and score of the students in a map in the sorted order of roll. One 
should be able to retrieve the score for a given roll. Take the help of suitable STL 
class
*/

#include <bits/stdc++.h>
using namespace std;

void divider(string a=""){
    cout << "\n========================" << a << "==============================";
}

class Student {
    int roll;
    int score;
    public:
    Student(){
        roll = -1;
        score = -1;
    }

    void take_student(int r){ // TAKE STUDENT DATA
        
        roll = r;
        cout << "\nEnter score of roll- " << roll << " : ";
        cin >> score;
        divider();
    }

    void print_student(){ // PRINT STUDENT DATA
        divider();
        cout << "\nRoll: " << roll;
        cout << "\nScore: " << score;
        divider();
    }
};

void insert_student(map<int, Student> &list){ // INSERT STUDENT INTO MAP STL
    divider();
    cout << "\nEnter the roll: ";
    int r;
    cin >> r;
    Student s;
    s.take_student(r);

    list.insert({r, s});
}


void show_student(map<int, Student> &list){ // SHOW STUDENT INTO MAP STL
    divider();
    cout << "\nEnter roll to find: ";
    int r;
    cin >> r;
    Student s = Student();
    if(list.count(r)>0){
        s = list.at(r);
        s.print_student();
    }else{ // IF ROLL DOESN'T EXIST ---
        cout << "\nINVALID ROLL!!";
    }
}

int main(){
    map<int, Student> list; // MAP WITH INTEGER ROLL AS KEY AND STUDENT OBJECT AS VALUE
    insert_student(list);
    insert_student(list);
    insert_student(list);
    insert_student(list);
    insert_student(list);

    cout << endl << endl;

    divider("FIND WITH ROLLS");

    show_student(list);
    show_student(list);
    show_student(list);
    show_student(list);
}