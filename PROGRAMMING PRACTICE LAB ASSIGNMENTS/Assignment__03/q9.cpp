/*
9.	Design a class TIME which stores hour, minute and second. 
The class should have the methods to support the following:
•	User may give the time value in 24-hour format.
•	User may give the time value in AM/PM format
•	Display the time in 24-hour format.
•	Display the time in AM/PM format.
•	User may like to add minute with a time value.

*/


#include <iostream>
#include <string>
using namespace std;

class Time // CREATING A TIME CLASS
{
    short hour;
    short minute;
    short second;

public:
    Time(short H = 0, short M = 0, short S = 0, string St = "na") // CONSTRUCTOR FUNCTION
    {
        if (H > 24 || M > 59 || S > 59)
        {
            cout << "\nError in Time value..\n";
            hour = 0;
            minute = 0;
            second = 0;
        }
        else if (St != "na")
        {
            if (H > 12)
            {
                cout << "\nHour value given is undefined in am/pm format..\n";
                hour = 0;
                minute = 0;
                second = 0;
            }
            else if (St == "pm")
            {

                hour = 12 + H;
                minute = M;
                second = S;
                 if(H == 12) {
                    hour = 12;
                }
            }
            else if (St == "am")
            {
                hour = H;
                minute = M;
                second = S;
                  if(H == 12) {
                    hour = 0;
                }
            }
            else
            {
                cout << "\nError in format mention of am/pm\n";
                hour = 0;
                minute = 0;
                second = 0;
            }
        }else{
             hour = H;
                minute = M;
                second = S;
        }
    }

    void Display_In_24format() { // FUNCTION TO DISPLAY TIME IN 24 HOURS FORMAT
        cout << "Time: " << hour << " :" << minute << " :" << second << endl;
    }

    void Display_In_ampm() { // FUNCTION TO DISPLAY TIME IN AM PM FORMAT
        if(hour > 12) {
            cout << "Time: " << hour-12 << " :" << minute << " :" <<  second << " PM" << endl;
        } else if(hour == 12){
             cout << "Time: " << hour << " :" << minute << " :" <<  second << " PM" << endl;
        } else if(hour == 0){
             cout << "Time: " << 12 << " :" << minute << " :" <<  second << " AM" << endl;
        } else {
             cout << "Time: " << hour << " :" << minute << " :" <<  second << " AM" << endl;
        }
    }

    void add_minute(int extra_minute) { // FUNCTION TO ADD MINUTES TO A TIME VALUE
        int temp, addM, addH;
        if((temp=extra_minute+minute) >= 60){
            addM = temp%60;
            addH = temp/60; 
            hour = static_cast<short>((hour+addH)%24);
        minute = static_cast<short>(addM);
        } else {
            minute + static_cast<short>(minute + extra_minute);
        }
        
    }
};

int main() {
    Time time(0,0,0);
    int choice, hour, minute, second;
    string St;
    do {
        cout << "\n1. Add/Update the time value in 24 format\n2. Add/Update the time value in am/pm format\n3. Display in 24 hour format\n4. Display in am/pm format\n5. Add Minute\n0. EXIT____\n\nEnter your choice: ";
        cin >> choice;
        if(!choice){
            break;
        }

        switch (choice) // THE MENU DRIVEN PROGRAM
        {
        case 1:
             cout << "\nEnter the value of Hour: ";
            cin >> hour;
             cout << "\nEnter the value of Minute: ";
            cin >> minute;
             cout << "\nEnter the value of Second: ";
            cin >> second;
            time = Time(hour, minute, second);
            break;
        case 2:
              cout << "\nEnter the value of Hour: ";
            cin >> hour;
             cout << "\nEnter the value of Minute: ";
            cin >> minute;
             cout << "\nEnter the value of Second: ";
            cin >> second;
            cout << "\nEnter the am/pm value: ";
            cin >> St;
            time = Time(hour,minute,second,St);
            break;
        case 3:
            time.Display_In_24format();
            break;
        case 4: 
            time.Display_In_ampm();
            break;  
        case 5:
            cout << "\nEnter the minutes value to add: ";
            cin >> minute;
            time.add_minute(minute);      
        default:
            break;
        }
    }while(1);
    return 0;
}