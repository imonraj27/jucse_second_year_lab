/*
12.	Design a STUDENT class to store roll, name, course, admission date and marks in 5 subjects. 
Provide methods corresponding to admission (marks are not available then), receiving 
marks and preparing mark sheet. Support must be there to show the number of students 
who have taken admission.
*/

#include <iostream>
#include <string>
#define MAX_STUDENTS 100
using namespace std;

class Student{ // THE STUDENT CLASS
    static int total_number_of_students;
    int roll;
    string name;
    string course;
    string admission_date;
    int marks[5];
    friend class student_list;
    public:
    void admit_student(){ // FUNCTION FOR ADMISSION OF STUDENT
        cout << "\nEnter the name of the student: ";
        cin.ignore();
        getline(cin, name);
        cout << "\nEnter the roll of " << name << ": ";
        cin >> roll;
        cout << "\nEnter the course of " << name << ": ";
        cin.ignore();
        getline(cin, course);
         cout << "\nEnter the admission date of " << name << ": ";
        cin.ignore();
        getline(cin, admission_date);
        total_number_of_students++;
        cout << "\n" << name << " is successfully admitted..with serial number " << total_number_of_students << endl;
    }

    void store_marks(){ // STORE MARKS OF ADMITTED STUDENT
        cout << "\nEnter marks of "<< name << " in five subjects: ";
        for (int i = 0; i < 5; i++)
        {
           cin >> marks[i];
        }

        cout << "\nMarks of " << name << " is successfully stored" << endl;
        
    }

    void show_marksheet(){ // SHOW MARKSHEET OF A STUDENT
        cout << "\n-----------------MARKSHEET--------------------------";
        cout << "\nName: " << name;
        cout << "\nRoll: " << roll;
        cout << "\nCourse: " << course;
        cout << "\nMarks: ";
        cout << marks[0] << " "; 
        cout << marks[1] << " "; 
        cout << marks[2] << " "; 
        cout << marks[3] << " "; 
        cout << marks[4] << " "; 
        cout << "\nAdmission date: " << admission_date;
        cout << "\n------------------------------------------------------\n";
    }
};

int Student::total_number_of_students = 0;

class student_list{ // CLASS TO MAINTAIN A STUDENT LIST
    Student list_s[MAX_STUDENTS]; // THE ARRAY TO STORE STUDENTS
    public: 
     void menu_driven_students(){ // MENU DRIVEN PROGRAM TO MAINTAIN STUDENTS
        int choice;
        int serl;
        do{
            cout << "\n1. Admit a student";
            cout << "\n2. Add a student marks";
            cout << "\n3. Prepare a student marksheet";
            cout << "\n4. Total Number of students";
            cout << "\n0. exit now()";
            cout << "\n\nENTER YOUR CHOICE: ";
            cin >> choice;

            
            if(!choice){
                break;
            }

            switch (choice)
            {
            case 1:
                if(Student::total_number_of_students == MAX_STUDENTS){
                    cout << "\nNo more space to add students";
                    break;
                }
                list_s[Student::total_number_of_students].admit_student();
                break;
             case 2:
                cout << "\nEnter the serial number of student: ";
                cin >> serl;
                if(serl>>Student::total_number_of_students){
                    cout << "\nInvalid serial number";
                    break;
                }
                list_s[serl-1].store_marks();
                break; 
             case 3:
                cout << "\nEnter the serial number of student: ";
                cin >> serl;
                if(serl>>Student::total_number_of_students){
                    cout << "\nInvalid serial number";
                    break;
                }
                list_s[serl-1].show_marksheet();
                break; 
             case 4:
                cout << "\nTotal Number of students: " << Student::total_number_of_students;
                break;           
            
            default:
                break;
            }
        }while(1);
    }
};

int main(){
    student_list s_list; // CREATING OBJECT
    s_list.menu_driven_students(); // CREATING A STUDENT LIST OBJECT AND CALLING THE MENU DRIVEN PROGRAM
    return 0;
}