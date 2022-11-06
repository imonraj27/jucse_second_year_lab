/* 8.	Define a structure student with roll and score as attributes and with 
two member functions to take input and to show the data. Use the member functions
 to take data for a structure variable and to show. Write global function
  i) to modify score and ii) to show the data again. */

#include <iostream>

using namespace std;

struct Student { // THE STRUCT STUDENT WITH MEMBER FUNCTIONS
    int roll;
    int score;

    void take_student_data(){ // TO TAKE THE STUDENT DATA
        cout << "\nEnter the student roll number: ";
        cin >> roll;
        cout << "\nEnter the score of roll " << roll << " : ";
        cin >> score;
    }

    void show_student_data(){ // TO SHOW THE STUDNT DATA
        cout << "\nRoll: " << roll << "\tScore: " << score;
    }
};

void modify_score(Student * ps){ // GLOBAL FUNCTION TO MODIFY SCORE
    cout << "\nWhat is the modified score: ";
    cin >> (*ps).score;
}

void show_student_data(Student s){ // GLOBAL FUNCTION TO SHOW STUDENT DATA
    cout << "Roll: " << s.roll << "\tScore: " << s.score << endl;
}

int main() {
    Student s;
    cout << "\n--------------------TAKING STUDENT DATA-------------------------\n";
    s.take_student_data();
      cout << "\n--------------------SHOWING STUDENT DATA-------------------------\n";
    s.show_student_data();
      cout << "\n--------------------MODIFYING STUDENT DATA-------------------------\n";
    modify_score(&s);
      cout << "\n--------------------SHOWING UPDATED STUDENT DATA-------------------------\n";
    show_student_data(s);
    return 0;
}