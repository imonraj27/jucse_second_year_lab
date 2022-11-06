/* 
Design the class(es) for the following. Each account has account number and 
balance amount. A list of account is to be maintained where one can add and 
find account, display information of all accounts. While adding, account number 
must be unique. Withdraw object has account number (must exist) and amount 
(will not exceed balance amount of corresponding account). Withdraw object will 
update the balance of corresponding account in the list. Implement your design. 
Use friend function wherever required and again, modify your implementation to 
avoid friend function
 */




#include <iostream>

#define MAX_NUMBER_OF_ACCOUNT 100
using namespace std;


void divider(){
    cout << "\n----------------------------------------";
}



class Account{
    long long account_number;
    long long balance;
    public:
    Account(){
        account_number = 0;
        balance =0;
    }
    Account(long long a_n, long long b){
        account_number = a_n;
        balance = b;
    }
    long long get_account_number() const{
        return account_number;
    }
    void update_amount(long long r){
        if(r<0 && ((-1)*r>balance)){
            cout << "\nNot that much balance in account...." << endl; // Not enough balance for withdrawing
            return;
        }
        balance += r;
        cout << "\nWithdrawal done succesfully";
    }
    void show_details(){ // show an details account object
        cout << "\nACCOUNT NUMBER: "
             << account_number
             << "\nBALANCE: " << balance << endl;
    }
};

class Withdraw { // the withdraw class to maintain the withdrawals
    long long amount;
    public:
    Withdraw(Account & acc, long long amnt){
        amount = amnt;
        acc.update_amount((-1)*amnt); // -1 for withdrawing passing negative will deposit
    }
};


class account_list{ // account list class
    Account acc_list[MAX_NUMBER_OF_ACCOUNT];
    int serial_number;
    public:
    account_list(){
        serial_number = 0;
    }
    void add_account(){ // adding a new account to list
        if(serial_number == MAX_NUMBER_OF_ACCOUNT){
            cout << "\nNo more account can be created....";
            return;
        }
        int a_num;
        cout << "\nEnter the account number: ";
        cin >> a_num;
        for (int i = 0; i < serial_number; i++)
        {
            if(a_num == acc_list[i].get_account_number()){
                cout << "\nAccont number already exists....";
                return;
            }
           
        }
        int b;
        cout << "\nEnter the balance: ";
        cin >> b;

        acc_list[serial_number] = Account(a_num, b);
        serial_number++;
        
    }

    void withdraw_amount(){ // withdraw an amount
        long long amnt, acc_num;
        cout << "\nEnter the account number: ";
        cin >> acc_num;
        cout << "\nEnter the amount to withdraw: ";
        cin >> amnt;

         for (int i = 0; i < serial_number; i++)
        {
            if(acc_num == acc_list[i].get_account_number()){
               Withdraw w(acc_list[i], amnt);
               return;
            }
           
        }
        cout << "\nAccount number not found";
        
    }

    void find_account(){ // Find account by account number
         int a_num;
        cout << "\nEnter the account number: ";
        cin >> a_num;
        for (int i = 0; i < serial_number; i++)
        {
            if(a_num == acc_list[i].get_account_number()){
                acc_list[i].show_details();
                return;
            }
           
        }

        cout << "\nAccount number doesn't exists...";
    }

    void show_all_accounts(){ // Show all accounts list
        for(int i=0; i<serial_number; i++){
            divider();
            acc_list[i].show_details();
        }
    }
};

void maintain_accounts(){ // the function to control menu-driven operations
    int choice;
    account_list l;
    do{
        cout << "\n1. Add a new account\n2. Withdraw amount\n3. Show all accounts\n4. Find an account\n0. exit\n\nENTER YOUR CHOICE: ";
        cin >> choice;

        if(!choice){
            return;
        }

        switch (choice)
        {
        case 1:
            l.add_account();
            break;
        case 2:
            l.withdraw_amount();
            break;  
        case 3:
            l.show_all_accounts();
            break;
        case 4:
            l.find_account();
            break;            
        
        default:
            break;
        }
    }while(1);
}


int main(){
   maintain_accounts();
   return 0;
}