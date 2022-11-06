/* 11.	Create an APPLICANT class with application id (auto generated as last id +1), name and 
score. Support must be there to receive applicant data, show applicant details and to find out 
number of applicants. */

#include <iostream>
#include <string>
#define NUMBER_OF_APPLICANTS 50
using namespace std;



class Applicant { // APPLICANT CLASS
    static int auto_id; // INT VARIABLE TO GENERATE AUTO ID
    int id;
    string name;
    int score;
    friend class All_Applicants;

    public:
    void get_applicant_details(){ // GETTER FUNCTION TO SHOW APPLICANT DETAILS
        cout << "\n\n---------------------------------------------\n";
        cout << "ID: " << id <<endl;
        cout << "Name: " << name <<endl;
        cout << "Score: " << score <<endl;
        cout << "---------------------------------------------\n";
    }

    void set_applicant_details(){ // STORING APPLICATION DETAILS
        cout << "\n\n----------------NEW APPLICANT DATA ENTRY-----------------------------\n";
        cout << "Enter the name: " << endl;
        cin.ignore();
        getline(cin, name);
        cout << "Enter the score: ";
        cin >> score;

        auto_id++;
        id = auto_id;
    }

    static int number_of_applicants(){ // STATIC FUNCTION TO SHOW TOTAL NUMBER OF APPLICANTS
        return auto_id;
    }

};

class All_Applicants{ // CLASS FOR ALL APPLICANTS
     
     Applicant * a_list = new Applicant[NUMBER_OF_APPLICANTS];
     friend class Applicant;

     public:
     void menu_driven_applicants_operation(){ // THE MENU DRIVEN PROGRAM
         int choice, id_val;
         do
         {
             cout << "1. Add Applicant\n2. Get Applicant data\n3. Number of applicants\n0. EXIT...\n\nEnter your choice: ";
             cin >> choice;
             if(!choice)
                return;

             switch (choice)
             {
             case 1:
                    if(Applicant::auto_id==NUMBER_OF_APPLICANTS){
                        cout << "\nNo more applicant can be added\n";
                        break;
                    }
                 a_list[Applicant::auto_id].set_applicant_details();
                 break;
              case 2:
                cout << "Enter the id to get data: ";
                cin >> id_val;
                 a_list[id_val-1].get_applicant_details();
                 break;
              case 3:
                 cout << "\n-------------------------------------------\nNumber of applicants: " << Applicant::auto_id << endl;
                  cout << "---------------------------------------------\n";
                 break;    
             default:
                 break;
             }   
         } while (1);
         
     }

     void delete_applicants(){
         delete[] a_list;
     }
};




int Applicant::auto_id = 0;




int main() {
   All_Applicants new_applicants; // CREATING A NEW ALL_APPLICANT OBJECT
    new_applicants.menu_driven_applicants_operation();
    new_applicants.delete_applicants();
    return 0;
}