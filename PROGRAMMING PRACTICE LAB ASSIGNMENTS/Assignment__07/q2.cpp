/*
Create an array of student objects where along with the support mentioned in 
Q.1, one can remove an object with specific roll, sort the collection in the 
descending order and show the same; two student collections can also be 
combined. Take the help of suitable STL class.
*/

#include "q1_2.h"


int main(){
    All_Students list1, list2; // TWO LISTS
    cout << "\nGive Students of first list-------\n";
    list1.Add_Student();
    list1.Add_Student();

    cout << "\n\nGive Students of second list-------\n";
    list2.Add_Student();
    list2.Add_Student();


   All_Students list_final; // FINAL LIST
   add_list(list1, list2, list_final);
   cout << "\nList after merging-----";
   list_final.print_all_students();
   list_final.Remove_Student();

   list_final.sort_desc_marks(); // SORT IN MARKS DESCENDING

   cout << "\n\nList after descending sorting of marks-----";
   list_final.print_all_students(); // PRINT THE SORTED LIST
   

}