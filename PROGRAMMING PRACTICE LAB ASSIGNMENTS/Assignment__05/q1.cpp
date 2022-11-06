/*
There are number of students. For every student roll (unique), name is to be 
stored. For each subject, subject code and name is to be stored. A student can 
opt for number of subjects. System should be able to maintain student list, 
subject list and will be able to answer: i) which student has selected which 
subjects and ii) for a subjects who are the students.
Design the classes and implement. For list consider memory data structure.
*/


#include <iostream>
#include <string>

using namespace std;

bool student_exist = false;

void div(){ // DECORATION 
    cout << "\n---------------------";
}

class Student {
    long roll;
    string name;
    public: 
    Student(long r, string n){
        roll = r;
        name = n;
    }

     Student(){
        roll = -1;
        name = "NULL";
    }

    long roll_no() const{
        return roll;
    }
    
    void set_student(){ // STORE STUDENT DATA
        cout << "\nEnter student's roll(unique): ";
        cin >> roll;
        cout << "\nEnter student's name: ";
        cin.ignore();
        getline(cin, name);
    }
 
    void get_student(){ // SHOW STUDENT DATA
        cout << "\nName: " << name;
        cout << "\nRoll: " << roll;
    }
};

class Subject { // SUBJECT CLASS WITH GET AND SET OPERATIONS
    int subject_code;
    string subject_name;
    public: 
    void set_subject(){
        cout << "\nEnter subject code: ";
        cin >> subject_code;
        cout << "\nEnter subject name: ";
        cin >> subject_name;
    }

    int sub_code() const{
        return subject_code;
    }

    void get_subject(){
         cout << "\nSubject Name: " << subject_name;
        cout << "\nSubject Code: " << subject_code;
    }
};

class Student_node { // STUDENT NODE FOR IMPLEMENTING LINKED LIST
    Student s;
    Student_node * next;
    public: 
    Student_node(){
        next = NULL;
    }

    Student_node(long r, string name){
        next = NULL;
        s = Student(r,name);
    }

    void take_student(){
        s.set_student();
    }

    void print_stud(){
        s.get_student();
    }

    bool atend_st_node(){
        return (next==NULL);
    }

    bool if_roll(long r){
        return (r==s.roll_no());
    }

    void insert_after(Student_node * target){
        if(target == NULL){
            cout << "\nError !!";
            return;
        }

        Student_node * temp = (this)->next;
        (this)->next = target;
        target->next = temp;
    }

    void delete_after(){
        Student_node * temp = (this)->next;
        (this)->next = temp->next;
        delete[] temp;
    }

    Student_node * advance(){
        return (this)->next;
    }
};

class Subject_node { // SUBJECT NODE FOR IMPLEMENTING LINKED LIST
    Subject sub;
    Subject_node * next;
    Student_node * sHead;

    public: 
    Subject_node(){
        next = NULL;
        sHead = NULL;
    }

    void take_subject(){
        sub.set_subject();
    }

    void print_sub(){
        sub.get_subject();
    }

    bool if_sub_code(int code){
        return (code==sub.sub_code());
    }

    bool atend_sub_node(){
        return (next==NULL);
    }

    void insert_after_subject(Subject_node * target){
         if(target == NULL){
            cout << "\nError !!";
            return;
        }

        Subject_node * temp = (this)->next;
        (this)->next = target;
        target->next = temp;
    }

    void insert_sub_student(Student_node * ps){
        if(ps==NULL){
            cout << "\nError!!";
            return;
        }

        if(sHead==NULL){
            sHead = ps;
            return;
        }

        Student_node * cur = sHead;

        while(!(cur->atend_st_node())){
            cur = cur->advance();
        }

        cur->insert_after(ps);
    }

    Subject_node * advance(){
        return (this)->next;
    }

    void students_under_subject(){ // SHOW STUDENTS UNDER SUBJECT
        if(sHead==NULL){
            cout << "\nNo Students....";
            return;
        }

        Student_node * cur = sHead;

        while(cur){
            cur->print_stud();
            div();
            cur = cur->advance();
        }
    }

    bool if_taken(long r){ // CHECK IF A STUDENT TAKEN A SUBJECT
         if(sHead==NULL){
           return false;
        }

        Student_node * cur = sHead;

        while(cur){
           if(cur->if_roll(r)){
               if(!student_exist){
                    student_exist = true;
                    cur->print_stud();
                    cout << "\nHAS TAKEN--";
               }
              
               return true;
           }
            cur = cur->advance();
        }

        return false;
    }

    void delete_sub_sts(){
        if(sHead==NULL){
            return;
        }

     Student_node * cur = NULL;


         while(sHead){
             cur = sHead->advance();
             delete[] sHead;
            sHead = cur;
        }

    }
};

class STUDENT_SUBJECT_SYSTEM { // A SPECIAL TYPE OF LINKED STRUCTURE MAINTAINENCE
    Subject_node * sub_head;
    public:
    STUDENT_SUBJECT_SYSTEM(){
        sub_head = NULL;
    }

    void insert_new_subject(){ // INSERT A NEW SUBJECT
        Subject_node * temp = new Subject_node();
        temp->take_subject();

        if(!sub_head){
            sub_head = temp;
            return;
        }

        Subject_node * cur = sub_head;


        while(!(cur->atend_sub_node())){
            cur = cur->advance();
        }

        cur->insert_after_subject(temp);

    }

    void insert_new_student(){ // INSERT A NEW STUDENT WITH SUBJECT CHOICE
        Student_node * st; 
        long roll;
        string name;
         cout << "\nEnter student's roll(unique): ";
        cin >> roll;
        cout << "\nEnter student's name: ";
        cin.ignore();
        getline(cin, name);

        
        Subject_node * cur = sub_head;
        char c;

        while(cur){
            cout << "\nDo you want to take--";
            cur->print_sub();
            cout << "\n\ny/n : ";
            cin >> c;
            if(c=='y'){
                st = new Student_node(roll, name);
                 cur->insert_sub_student(st);
            }
           
            cur = cur->advance();
        }
    }

    void students_under_subject(){ // SHOW STUDENTS UNDER A SUBJECT 
        int code;
        cout << "\nEnter subject code to see students: ";
        cin >> code;
        bool found = false;

         Subject_node * cur = sub_head;

        while(cur){
           if(cur->if_sub_code(code)){
               
               cur->students_under_subject();
               found=true;
               break;
           }
            cur = cur->advance();
        }

        if(!found){
            cout << "\nNo such subject code!!!";
        }
    }

    void subjects_by_student(){ // SHOW SUBJECTS TAKEN BY A STUDENT
        long roll;
        cout << "\nEnter the roll to see the subjects: ";
        cin >> roll;

        Subject_node * cur = sub_head;

        while(cur){
           if(cur->if_taken(roll)){
               cur->print_sub();
           }
            cur = cur->advance();
        }

        student_exist = false;
    }

    void delete_everything(){
        Subject_node * cur = NULL;

        while(sub_head){
            sub_head->delete_sub_sts();
            cur = sub_head->advance();
            delete[] sub_head;
            sub_head = cur;
        }
    }
};

int main(){
    STUDENT_SUBJECT_SYSTEM maintain_sub_stud;
    int choice;

    do{ // THE MENU DRIVEN OPERATIONS
        cout << "\n1. Take a subject\n2. Admit a student\n3. Search students for a subject\n4. Show subjects of a student\n0. Exit\n\nENTER YOUR CHOICE: ";
        cin >> choice;

        if(!choice){
            maintain_sub_stud.delete_everything();
            break;
        }

        switch(choice){
            case 1:
            maintain_sub_stud.insert_new_subject();
            break;
            case 2:
            maintain_sub_stud.insert_new_student();
            break;
            case 3: 
            maintain_sub_stud.students_under_subject();
            break;
            case 4:
            maintain_sub_stud.subjects_by_student();
            break;
            default: 
            cout << "\nPlease enter valid option!!";
            break;
        }
    }while(true);
}