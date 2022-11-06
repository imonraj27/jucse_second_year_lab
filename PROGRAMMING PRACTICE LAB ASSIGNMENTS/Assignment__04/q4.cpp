/*

Design a STRING class, which will have the initialization facility similar to array 
class. Provide support for 
 Assigning one object for another, 
 Two string can be concatenated using + operator, 
 Two strings can be compared using the relational operators.

*/


#include <iostream>
#include <string>
#include <string.h>
#define MAX_STRING_LEN 100

using namespace std;

class String { // string class

private:
    char *arr;
    int size;

public:
    String(int n=MAX_STRING_LEN)
    {
        size = n;
        arr = new char[n+1];
        for (int i = 0; i <= n; i++)
        {
            *(arr + i) = '\0';
        }
    }

    ~String(){
        delete[] arr;
    }

    int string_length(){
        int count=0;
        for (int i = 0; i < size; i++)
        {
            if(arr[i]=='\0'){
                break;
            }else{
                count++;
            }
        }
        return count;
    }

    String & operator + (String & a){ // overloaded + for concatenation
        int len1 = string_length();
        int len2 = a.string_length();
         int tot_len = len1+len2;
        String * b = new String(tot_len);
        int count;

        for (int i = 0; i < len1; i++)
        {
            (*b).arr[i] = arr[i];
        }


        
        for (int i = 0; i < len2; i++)
        {
            (*b).arr[len1+i] = a.arr[i];
        }
        
       

        return (*b);
    }

     bool operator < (String & a){ // overloaded < for stirng compare
         if(strcmp(arr, a.arr)<0){
             return true;
         }

         return false;
     }

     
     bool operator > (String & a){ // str cmp >
         if(strcmp(arr, a.arr)>0){
             return true;
         }

         return false;
     }

     
     bool operator <= (String & a){ // samely as above
         if(strcmp(arr, a.arr)<=0){
             return true;
         }

         return false;
     }

      bool operator >= (String & a){ // samely as above
         if(strcmp(arr, a.arr)>=0){
             return true;
         }

         return false;
     }

      bool operator == (String & a){ // check if equal overloaded ==
         if(strcmp(arr, a.arr)==0){
             return true;
         }

         return false;
     }


    String & operator = (String &right) // overloaded assignment
    { //IMPO

    int len1 = right.string_length();
        if (&right != this)
        {
           delete[] arr;
           arr = new char(len1+1);
        }

        
          for (int i = 0; i < len1; i++)
        {
            arr[i] = right.arr[i];
        }
        return *this;
    }

   
    // OVERLOADED INPUT OUTPUT
    friend ostream& operator << (ostream &, String &);
    friend istream& operator >> (istream &, String &);
 
};

ostream & operator << (ostream & op, String & a){
    op << a.arr;
    return op;
}



istream & operator >> (istream & ip, String & a){
    int len = a.size;
    ip.getline(a.arr, MAX_STRING_LEN);
    return ip;
}


void divider(string str){ // DECORATION PURPOSE
    cout << "\n-------------------------"<< str <<"-------------------------\n";
}

 int main(){

     String a, b;
     divider("Enter first string");
     cin >> a;
     divider("Enter second string");
     cin >> b;

     divider("First string is:");
     cout << a;
      divider("Second string is:");
     cout << b;

     String c = a+b; // CONCAT
      divider("First concat second string is: ");
     cout << c;
     String d = a; // ASSIGNMENT
      divider("assigning first string to another and prints: ");
     cout << d;

     if(a>b){ // STRING COMPARISON
         cout << "\nfirst string is greater" << endl;
     }else if(a<b){
         cout << "\nsecond string is greater" << endl;
     }else{
         cout << "\nequal string" << endl;
     }
  return 0;
   
 }   