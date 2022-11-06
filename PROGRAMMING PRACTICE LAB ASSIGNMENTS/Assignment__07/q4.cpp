/*
Maintain a container of students where they are kept in the descending order of 
their scores. Take the help of suitable STL class.
*/

#include <bits/stdc++.h>
using namespace std;

class Student
{
    string name;
    int score;

public:
    Student(string n, int sc)
    {
        name = n;
        score = sc;
    }
    Student()
    {
        name = "___";
        score = 0;
    }

    int Score() const
    {
        return score;
    }

    void print_student() // PRINT STUDENT DATA
    {
        cout << "\n____________________"
             << "\nName: " << name
             << "\nScore: " << score
             << "\n____________________";
    }
};

bool operator<(const Student &a, const Student &b)
{
    return (a.Score() < b.Score());
}

// bool operator>(Student &a, Student &b)
// {
//     return (a.Score() > b.Score());
// }

int main()
{
    priority_queue<Student> list; // PRIORITY QUEUE TO POP STUDENT WRT SCORE
    string name;
    int score, i;
    Student s;
    cout << "\nHow many stuents: ";
    cin >> i;
    cin.ignore();

    for (int j = 0; j < i; j++) // INSERTING STUDENT IN ANY ORDER OF SCORE
    {
        cout << "\nEnter name: ";
        getline(cin, name);
        cout << "\nEnter score: ";
        cin >> score;
        cin.ignore();
        s = Student(name, score);
        list.push(s);
    }

    for (int j = 0; j < i; j++) // POPPING WILL BE PRIORITISED WRT SCORE
    {
        s = list.top();
        list.pop();
        s.print_student();
    }
}