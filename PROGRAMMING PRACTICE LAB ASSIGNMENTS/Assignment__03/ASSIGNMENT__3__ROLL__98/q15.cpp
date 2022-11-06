/* 

15.	Design a BALANCE class with account number, balance
 and date of last update. Consider a TRANSACTION class with account
  number, date of transaction, amount and transaction type (W for withdrawal 
  and D for deposit). If it is a withdrawal check whether the amount 
  is available or not. Transaction object will make necessary update 
  in the BALANCE class.
 */

#include <iostream>
#include <string>
using namespace std;

class Balance // THE BALANCE CLASS
{
    int account_number;
    int balance;
    string date_last_update;
    friend class Transaction;

public:
    Balance(int a_num = 0, int b = 0, string d_last = "not_avalilable") // CONSTRUCTOR
    {
        account_number = a_num;
        balance = b;
        date_last_update = d_last;
    }

    void create_account() // CREATES ACCOUNT WITH INITIAL AMOUNT
    {
        cout << "\nEnter account number: ";
        cin >> account_number;
        cout << "\nEnter balance: ";
        cin >> balance;
        cout << "\nEnter last update date: ";
        cin.ignore();
        getline(cin, date_last_update);
    }

    void update_balance(int ext) // UPDATE THE BALANCE
    {
        if ((-1) * ext > balance)
        {
            cout << "\nNot enough amount in account to withdraw...";
        }
        else
        {
            balance += ext;
        }
    }

    void update_last_date(string d) // UPDATE THE DATE
    {
        date_last_update = d;
    }

    void show_everything() // PRINTS ALL DETAILS OF AN BALANCE ACCOUNT
    {
        cout << "\n----------------------ACCOUNT DETAILS----------------------";
        cout << "\nACCOUNT NUMBER: " << account_number;
        cout << "\nACCOUNT BALANCE: " << balance;
        cout << "\nLAST UPDATE: " << date_last_update;
        cout << "\n-----------------------------------------------------------";
    }
};

class Transaction // THE CLASS FOR TRANSACTION
{
    int acc_number;
    string date_of_transaction;
    int transaction_amount;
    char trans_type;

public:
    Transaction(Balance &acc, string d_tran = "empty", int amnt = 0, char t_type = 'W') // CONSTRUCTOR
    {
        acc_number = acc.account_number;
        date_of_transaction = d_tran;
        transaction_amount = amnt;
        trans_type = t_type;

        if (t_type == 'W')
        {
            acc.update_balance((-1) * amnt);
            acc.update_last_date(d_tran);
        }
        else if (t_type == 'D')
        {
            acc.update_balance(amnt);
            acc.update_last_date(d_tran);
        }
        else
        {
            cout << "\nInvalid type of transaction....";
        }
    }
};
 
void maintain_transaction(Balance &acc) // FUNCTION TO MAINTAIN DIFFERENT OPERATIONS
{
    int choice, amnt;
    string date;
    Transaction t(acc);
    do
    {
        cout << "\n1. Withdraw amount\n2. Deposit amount\n3. Show acc details\n0. exit\n\nENTER YOUR CHOICE: ";
        cin >> choice;
        if (!choice)
        {
            break;
        }

        switch (choice)
        {
        case 1:
            cout << "\nEnter the amount to withdraw: ";
            cin >> amnt;
            cout << "\nEnter today's date: ";
            cin.ignore();
            getline(cin, date);
            t = Transaction(acc, date, amnt, 'W');
           cout << "\nTransaction successful...";
            break;
        case 2:
            cout << "\nEnter the amount to deposit: ";
            cin >> amnt;
            cout << "\nEnter today's date: ";
            cin.ignore();
            getline(cin, date);
            t = Transaction(acc, date, amnt, 'D');
            cout << "\nTransaction successful...";
            break;

        case 3: 
            acc.show_everything();  
            break; 
        default:
            break;
        }
    } while (1);
}

int main(){
    Balance acc;
    acc.create_account();
    maintain_transaction(acc);
    return 0;
}