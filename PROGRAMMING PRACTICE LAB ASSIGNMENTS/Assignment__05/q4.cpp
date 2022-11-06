/*
Each cricketer has name, date of birth and matches played. Cricketer may be a 
bowler or batsman. For a bowler, number of wickets taken, average economy is 
stored. For a batsman, total runs scored, average score is stored. A double 
wicket pair is formed taking a bowler and a batsman. An all-rounder is both a 
bowler and batsman. Support must be there to show the details of a cricketer, 
bowler, batsmen, all-rounder and the pair.
Design the classes and implement
*/



#include <bits/stdc++.h>
using namespace std;

class CRICKETER
{
public:
    string name;
    string dob;
    int matches_played;

    CRICKETER(string name = "NULL", string dob = "NULL", int matches_played = 0)
    {
        this->name = name;
        this->dob = dob;
        this->matches_played = matches_played;
    }
    CRICKETER(const CRICKETER &c)
    {
        this->name = c.name;
        this->dob = c.dob;
        this->matches_played = c.matches_played;
    }
    void showDataCRICKETER() // SHOW CRICEKTERS DATA
    {
        cout << "Name Of Cricketer: " << this->name << endl;
        cout << "DOB: " << this->dob << endl;
        cout << "Matches Played: " << this->matches_played << endl;
    }
};

class BOWLER : virtual public CRICKETER // DERIVING BOWLER CLASS 
{
public:
    int n_wickets;
    float economy;
    BOWLER(const CRICKETER &bow, int n_wickets = 0, float economy = 0) : CRICKETER(bow)
    {
        this->n_wickets = n_wickets;
        this->economy = economy;
    }
    BOWLER(const BOWLER &bow) : CRICKETER(bow)
    {
        this->n_wickets = bow.n_wickets;
        this->economy = bow.economy;
    }
    void showDataBOWLER() // SHOW BOWLER'S DATA
    {
        cout << "No Of Wickets Taken: " << this->n_wickets << endl;
        cout << "Economy: " << this->economy << endl;
    }
};

class BATSMAN : virtual public CRICKETER // DERIVING BATSMAN CLASS
{
public:
    int runs;
    float average_score;
    BATSMAN(const CRICKETER &bat, int runs = 0, float average_score = 0) : CRICKETER(bat)
    {
        this->runs = runs;
        this->average_score = average_score;
    }
    BATSMAN(const BATSMAN &bat) : CRICKETER(bat)
    {
        this->runs = bat.runs;
        this->average_score = bat.average_score;
    }
    void showDataBATSMAN() // SHOW BATSMAN DATA
    {
        cout << "Runs: " << this->runs << endl;
        cout << "Average Score: " << this->average_score << endl;
    }
};
class ALLROUNDER : public BOWLER, public BATSMAN // DERIVING ALL ROUNDER
{
public:
    ALLROUNDER(const BOWLER &bow, const BATSMAN &bat) : CRICKETER(bow), BOWLER(bow), BATSMAN(bat)
    {
      
    }
    void showData() // SHOW ALL ROUNDER
    {
        this->showDataCRICKETER();
        this->showDataBOWLER();
        this->showDataBATSMAN();
    }
};
class doubleWicket // DOUBLE WICKET PAIR CLASS
{
    BOWLER *bow;
    BATSMAN *bat;

public:
    doubleWicket(const BOWLER &bow, const BATSMAN &bat)
    {
        this->bow = new BOWLER(bow);
        this->bat = new BATSMAN(bat);
    }
    void showDataDBW() // SHOW DOUBLE WICKET DATA
    {
        bow->showDataCRICKETER();
        bow->showDataBOWLER();
        bat->showDataBATSMAN();
    }
};

void divider(){ // DECORATION
     cout << "===============================================" << endl;
}

int main()
{
    string cricketerName, dob;
    int matchs;
    cout << "\nEnter cricketer's name: ";
    getline(cin, cricketerName);
    cout << "\nEnter cricketer's DOB: ";
    getline(cin, dob);
    cout << "\nEnter cricketer's matches played: ";
    cin >> matchs;
    CRICKETER c(cricketerName, dob, matchs);
    BOWLER bow(c, 10, 5);
    BATSMAN bat(c, 100, 15);

    ALLROUNDER ar(bow, bat);
    doubleWicket dbw(bow, bat);
    cout << "ALL-ROUNDER:" << endl;
    ar.showData();
   divider();
    cout << "DOUBLE-WICKET:" << endl;
    dbw.showDataDBW();
    return 0;
}