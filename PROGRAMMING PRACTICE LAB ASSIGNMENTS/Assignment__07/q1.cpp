/*
Create an array of student objects (containing roll, name, name and score) 
whose size may vary dynamically once objects are added or removed, randomly 
elements may be accessed, one can find number of objects in the list, one can 
find the student with highest score, find the students with a substring in their 
name and also without a substring in the name. Take the help of suitable STL 
classes
*/

#include "q1_2.h"


int main(){
    All_Students list; // STUDENT LIST OBJECT AND ALL OPERATIONS
    list.Add_Student();
    list.Add_Student();
    list.Add_Student();
    list.Add_Student();
    
    list.find_with_roll();
    list.Show_Student();
    cout << "\nTotal number of students: " << list.total_number_of_students();
    cout <<  "\nThe highest student----\n";
    (list.find_highest_score()).show_student();

    string sub;
    cout << "\nEnter the substring to search students: ";
    cin.ignore();
    getline(cin, sub);
    list.find_student_with_substring(sub);

}