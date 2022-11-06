/*
Modify the STRING class so that assigning/initializing a string by another will not 
copy it physically but will keep a reference count, which will be incremented. 
Reference value 0 means the space can be released

*/


#include <iostream>
#include <string>
#include <string.h>
#define MAX_STRING_LEN 100

using namespace std;


// ------SAME AS ABOVE QUESTION EXCEPT THE ASSIGNMENT--------------------//
class String {

private:
    char *arr;
    int size;
    int *ref_count;

public:
    String(int n=MAX_STRING_LEN)
    {
        size = n;
        ref_count = new int;
        (*ref_count)=1;
        arr = new char[n+1];
        for (int i = 0; i <= n; i++)
        {
            *(arr + i) = '\0';
        }
    }

    ~String(){
        delete[] arr;
    }

    int count_of_reference(){
        return *ref_count;
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

    String & operator + (String & a){
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

     bool operator < (String & a){
         if(strcmp(arr, a.arr)<0){
             return true;
         }

         return false;
     }

     
     bool operator > (String & a){
         if(strcmp(arr, a.arr)>0){
             return true;
         }

         return false;
     }

     
     bool operator <= (String & a){
         if(strcmp(arr, a.arr)<=0){
             return true;
         }

         return false;
     }

      bool operator >= (String & a){
         if(strcmp(arr, a.arr)>=0){
             return true;
         }

         return false;
     }

      bool operator == (String & a){
         if(strcmp(arr, a.arr)==0){
             return true;
         }

         return false;
     }


    void operator = (String &right) // JUST INCREASING THE REFERENCE COUNT
    { 

        (*(right.ref_count))++;
        this->size = right.size;
        this->ref_count = right.ref_count;
        this->arr = right.arr;
        
    }

    void Delete_String(){ // DOWN THE REFERENCE COUNT AND IF 0 THEN FREE MEMORY
        (*ref_count)--;
        if(*ref_count==0){
            delete[] arr;
        }
    }
   
    //===========OVERLOADED INPUT OUTPUT OPERATORS================//
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


void divider(string str){
    cout << "\n-------------------------"<< str <<"-------------------------\n";
}

 int main(){

     String a, b, c, d, e;
     cin >> a;

     // ALL THE ASSIGNMENT ACTUALLY INCREASE REFERENCE 
     // COUNT AND REFRES TO THE SAME STRING WITHOUT CREATING NEW STRING
     b = a;
     c = b;
     d = c;
     e = d;
     divider("printing string");
     cout << b << endl;
     cout << "\nThe reference count is now: " << a.count_of_reference() << endl;
     divider("delete two");
     // DELETING AND CHECKING THE REFERENCE COUNT
     b.Delete_String();
     c.Delete_String();
    cout << a << endl;
      cout << "\nThe reference count is now: " << a.count_of_reference() << endl;
      divider("delete two more");
      d.Delete_String();
      e.Delete_String();
    
      cout << a << endl;
      cout << "\nThe reference count is now: " << a.count_of_reference() << endl;
       divider("delete one more");
        a.Delete_String();
         cout << a << endl;
      cout << "\nThe reference count is now: " << a.count_of_reference() << endl;
  return 0;
   
 }   