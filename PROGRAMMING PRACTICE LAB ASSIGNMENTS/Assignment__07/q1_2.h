#include <bits/stdc++.h>
// HEADER FILE FOR QUESTION NUMBER 1 AND 2

using namespace std;

class Student
{
    int roll;
    string name;
    int score;

public:
    Student()
    {
        roll = -1;
        name = "none";
        score = 0;
    }
    void add_student() // ADD A STUDENT
    {
        cout << "\nEnter name: ";
        getline(cin, name);
        cout << "\nEnter roll: ";
        cin >> roll;
        cout << "\nEnter score: ";
        cin >> score;
        cin.ignore();
        cout << "\nStudent added successfully..";
    }
    void show_student() // SHOW A STUDENT DATA
    {
        cout << "\n----------------------------------------";
        cout << "\n"
             << left << setw(20) << name;
        cout << setw(10) << roll;
        cout << setw(10) << score;
    }

    int SCORE() const // RETURNS SCORE
    {
        return score;
    }

    int ROLL() const // RETURNS ROLL
    {
        return roll;
    }

    string NAME() /// RETURN NAME
    {
        return name;
    }

    Student &operator=(Student st) // OVERLOADED ASSIGNMENT OPERATOR
    {
        roll = st.ROLL();
        name = st.NAME();
        score = st.SCORE();

        return (*this);
    }
};

class All_Students
{
    vector<Student> all_students; // VECTOR STL

    void show_heading()
    {
        cout << "\n---------------------------------------";
        cout << "\n"
             << left << setw(20) << "NAME";
        cout << setw(10) << "ROLL";
        cout << setw(10) << "SCORE";
    }

    void show_footer()
    {
        cout << "\n----------------------------------------";
    }
    
    friend void add_list(All_Students &, All_Students &, All_Students &);

public:
    All_Students(){
        all_students.resize(0);
    }
    void Add_Student()
    {
        Student s;
        s.add_student();
        all_students.push_back(s);
    }

    void find_with_roll() // FIND A STUDENT WITH ROLL
    {
        int rol;
        cout << "\nEnter roll to find: ";
        cin >> rol;
        for (auto &it : all_students)
        {
            if (it.ROLL() == rol)
            {
                cout << "\nStudent with given roll is ----";
                it.show_student();
                return;
            }
        }

        cout << "\nSorry, given roll was not found!!!";
    }

    void Show_Student() // SHOW A STUDENT WITH SERIAL NO
    {
        int serial_no;
        cout << "\nEnter serial no to search student: ";
        cin >> serial_no;
        int size_of_list = all_students.size();
        if (serial_no > size_of_list)
        {
            cout << "\nInvalid access denied. Serial out of range!!";
            return;
        }
        all_students[serial_no - 1].show_student();
    }

    int total_number_of_students() // TOTAL NO OF STUDENTS
    {
        return all_students.size();
    }

    Student find_highest_score() // FIND STUDENT WITH HIGHEST SCORE
    {
        int max = -1;
        Student highest;
        for (auto &it : all_students)
        {
            if (it.SCORE() > max)
            {
                highest = it;
                max = it.SCORE();
            }
        }
        return highest;
    }

    void Remove_Student() // REMOVE A STUDENT WITH ROLL
    {
        cout << "\nEnter student's roll to remove: ";
        int rl;
        cin >> rl;
        for (auto it = all_students.begin(); it != all_students.end(); it++)
        {
            if (it->ROLL() == rl)
            {
                all_students.erase(it);
                cout << "\nSuccessfully deleted....";
                return;
            }
        }
        cout << "\nRoll Number not found!!";
    }

    void find_student_with_substring(string subs) // FIND STUDENTS WITH SUBSTRING IN NAME
    {
        Student st;
        size_t found;
        string temp;
        transform(subs.begin(), subs.end(), subs.begin(), ::tolower);
        for (auto &it : all_students)
        {
            temp = it.NAME();
            transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
            found = temp.find(subs);
            if (found != string::npos)
            {
                it.show_student();
            }
        }
    }

    // --------------------------SORT STUDENTS IN DESCENDING ORDER OF MARKS---------------------------//
    void sort_desc_marks()
    {
        int len = all_students.size();
        Student temp = Student();
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                if (all_students[i].SCORE() < all_students[j].SCORE())
                {
                    temp = all_students[i];
                    all_students[i] = all_students[j];
                    all_students[j] = temp;
                }
            }
        }
    }

    void print_all_students() // PRINT ALL STUDENTS
    {
        show_heading();
        for (auto &it : all_students)
        {
            it.show_student();
        }
        show_footer();
    }

    
};

void add_list(All_Students & first, All_Students & second, All_Students & final){ // MERGE TWO LIST
    int fs = first.total_number_of_students();
    int ss = second.total_number_of_students();
    int siz = fs+ss;
    final.all_students.resize(siz);

    for (int i = 0; i < fs; i++)
    {
        final.all_students[i] = first.all_students[i];
    }

    for (int i = 0; i < ss; i++)
    {
        final.all_students[fs+i] = second.all_students[i];
    }
    
}

