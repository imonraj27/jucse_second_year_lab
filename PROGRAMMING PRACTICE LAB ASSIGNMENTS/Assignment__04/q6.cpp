/*

For each student roll, name and phone number are to be maintained. For each 
subject store subject code, name. A student may choose number of subjects 
from a list of subjects. A subject may be chosen by number of students. Given a 
roll number system must able to display the subjects chosen by the student and 
also be able to display the students corresponding to a subject code. Design the 
classes and implement the system......

*/

#include <iostream>
#include <string>
#define MAX_STUDENT_NUMBER 50
using namespace std;

class Student
{ // STUDENT CLASS
    int roll;
    string name;
    string phn;
    friend class All_Students;

public:
    void set_student()
    { // STORE STUDENT'S DATA
        cout << "\nEnter student's name: ";
        cin.ignore();
        getline(cin, name);
        cout << "\nEnter roll: ";
        cin >> roll;
        cout << "\nEnter ph no.: ";
        cin.ignore();
        getline(cin, phn);
    }

    void print_student()
    { // SHOW STUDENT DATA
        cout << "\n-----------------------------\n";
        cout << "NAME: " << name << endl;
        cout << "ROLL: " << roll << endl;
        cout << "PHN NO: " << phn << endl;
        cout << "\n-----------------------------\n";
    }
};

class Subject
{ // SUBJECT CLASS
    int subject_code;
    string subject_name;
    friend class All_Subjects;

public:
    int taken_by[MAX_STUDENT_NUMBER];
    int taken_by_count;
    Subject()
    {
        subject_code = -1;
        subject_name = "none";
        taken_by_count = -1;
    }
    Subject(int sc, string sname)
    {
        subject_code = sc;
        subject_name = sname;
        taken_by_count = 0;
    }

    void student_add_to_subject(int serial_no)
    { // ADD A STUDENT TO A SUB
        if (taken_by_count == MAX_STUDENT_NUMBER)
        {
            cout << "\nError students exceeded";
            return;
        }
        taken_by[taken_by_count] = serial_no;
        taken_by_count++;
    }

    void print_subject()
    { // PRINTS A SUBJECT
        cout << subject_name << " " << subject_code;
    }

    int if_taken(int serial_no)
    { // CHECK IF SL NO TAKEN SUBJECT
        for (int i = 0; i < taken_by_count; i++)
        {
            if (taken_by[i] == serial_no)
            {
                return 1;
            }
        }
        return 0;
    }
};

class All_Subjects
{ // ALL SUBJECTS CLASS

    int count_index;

public:
    Subject arr[5];
    All_Subjects()
    {
        count_index = 0;
    }

    void add_subject()
    { // ADD A SUBJECT TO SUBJECT LIST
        int code;
        string sname;
        if (count_index == 5)
        {
            cout << "\nNo more subject can be added";
            return;
        }
        cout << "\nEnter subject name: ";
        cin >> sname;
        cout << "\nEnter subject code";
        cin >> code;
        arr[count_index] = Subject(code, sname);
        count_index++;
    }

    void print_all_subs()
    { // PRINT ALL SUBS
        cout << "\n---------ALL SUBJECTS AVAILABLE--------------" << endl;
        for (int i = 0; i < count_index; i++)
        {
            cout << i + 1;
            arr[i].print_subject();
            cout << endl;
        }
    }

    void add_student_to_subject(int serial_no)
    { // ADD A STUDENT TO A SUBJECT
        print_all_subs();

        cout << "\nChoose any three subject serial only: ";
        int temp;

        for (int i = 0; i < 3; i++)
        {
            cin >> temp;
            arr[temp - 1].student_add_to_subject(serial_no);
        }
    }

    int subject_serial_from_code(int scode)
    { // RETURNS SUBJECT SERIAL FROM CODE
        for (int i = 0; i < count_index; i++)
        {
            if (arr[i].subject_code == scode)
            {
                return i;
            }
        }
        return -1;
    }

    void subjects_by_student(int serial_no)
    { // SUBJECTS TAKEN BY A STUDENT
        for (int i = 0; i < count_index; i++)
        {
            if (arr[i].if_taken(serial_no))
            {
                cout << "\n";
                arr[i].print_subject();
                cout << endl;
            }
        }
    }
};

class All_Students
{ // ALL STUDENTS CLASS
    Student slist[MAX_STUDENT_NUMBER];
    int count_student;
    friend class All_Subjects;

public:
    All_Students()
    {
        count_student = 0;
    }
    void add_student(All_Subjects &subs)
    {
        if (count_student == MAX_STUDENT_NUMBER)
        {
            cout << "\nNo more students can be added";
            return;
        }

        slist[count_student].set_student();
        subs.add_student_to_subject(count_student);
        count_student++;
    }
    void print_with_serial(int sl)
    { // PRINT A STUDENT GIVEN HIS/HER SERIAL NO
        slist[sl].print_student();
    }

    void Students_Under_Subject(All_Subjects &subs)
    {
        all_students_under_subject(*this, subs);
    }

    int serial_from_roll(int r)
    { // RETURN SERIAL WHEN ROLL IS GIVEN
        for (int i = 0; i < count_student; i++)
        {
            if (slist[i].roll == r)
            {
                return i;
            }
        }

        return -1;
    }

    void subjects_by_student(All_Subjects &subs)
    {
        int roll;
        cout << "\nEnter the roll: ";
        cin >> roll;

        int srl = serial_from_roll(roll);
        if (srl == -1)
        {
            cout << "\nRoll doesn't exist";
            return;
        }
        subs.subjects_by_student(srl);
    }

    friend void all_students_under_subject(All_Students &, All_Subjects &);
};

void show_student_under_sub(All_Students &pplist, Subject &subs)
{
    for (int i = 0; i < subs.taken_by_count; i++)
    {
        pplist.print_with_serial(subs.taken_by[i]);
    }
}

void all_students_under_subject(All_Students &ppl, All_Subjects &subs)
{
    subs.print_all_subs();
    int scode;
    cout << "\nChoose code to find: ";
    cin >> scode;
    int target_serial = subs.subject_serial_from_code(scode);

    if (target_serial == -1)
    {
        cout << "\nSubject doesn't exist";
        return;
    }

    show_student_under_sub(ppl, subs.arr[target_serial]);
}

int main()
{
    //DOING ALL THE OPERATIONS
    All_Subjects subs;
    subs.add_subject();
    subs.add_subject();
    subs.add_subject();
    subs.add_subject();
    subs.add_subject();
    subs.add_subject();

    All_Students sls;
    sls.add_student(subs);
    sls.add_student(subs);
    sls.add_student(subs);
    sls.add_student(subs);

    sls.Students_Under_Subject(subs);

    sls.subjects_by_student(subs);
}