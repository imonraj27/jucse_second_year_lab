/*
14.	Design  the class(es) for the following scenario:
•	An item list contains item code, name, rate, and quantity for several items.
•	Whenever a new item is added in the list uniqueness of item code is to be checked. 
•	Time to time rate of the items may change. 
•	Whenever an item is issued or received existence of the item is checked and quantity is updated. 
•	In case of issue, availability of quantity is also to be checked.
•	User may also like to know price/quantity available for an item.

*/


#include <iostream>
#include <string>
#define MAX_NUMBER_OF_ITEMS 100

using namespace std;

class Item { // ITEM CLASS
    int item_code;
    string item_name;
    int item_rate;
    int item_quantity;
    public:
    Item(){
        item_code = -1;
        item_name = "NULL";
        item_rate = 0;
        item_quantity = 0;
    }
    Item(int c, string n, int r, int q){
        item_code = c;
        item_name = n;
        item_rate = r;
        item_quantity = q;
    }
    void add_quantity(){ // INCREASE ITEM QUANTITY
        item_quantity++;
    }

    int get_id(){ // RETURNS ITEM CODE
        return item_code;
    }

    void print_item_details(){ // PRINTS A ITEM'S DETAILS
        cout << "\nITEM CODE: " << item_code;
        cout << "\nITEM NAME: " << item_name;
        cout << "\nITEM RATE: " << item_rate;
        cout << "\nITEM QUANTITY: " << item_quantity << endl;
    }

    bool is_out_of_stock(){ //  CHECK IF ITEM OUT OF STOCK
        return (item_quantity==0);
    }

    void issue_quantity(){ // DECREASE ITEM QUANTITY
        item_quantity--;
    }

    void change_rate(int new_rate){ // CHANGE ITEM RATE
        item_rate = new_rate;
        cout << "\nThe Rate of the item has been updated..." << endl;
        cout << "\nTHE ITEM DETAILS IS NOW..";
        print_item_details();
    }
};

class all_items { // CLASS TO MAINTAIN ALL ITEMS
    int item_unique_id;
    Item i_list[MAX_NUMBER_OF_ITEMS]; // ARRAY OF ITEMS

    void add_item(){ // TO ADD AN ITEM
        int id,rate;
        bool found = false;
        string name;
        cout << "\nEnter the code of the item to be added: ";
        cin >> id;
        for (int i = 0; i < item_unique_id; i++) // INCREASES QUNATITY IF FOUND
        {
            if(i_list[i].get_id()==id){
                found = true;
                cout << "\nThis item is already there.. Increasing the quantity .. \n";
                i_list[i].add_quantity();
                i_list[i].print_item_details();
               return;
            }
        }

        if(!found){ // ADDS A NEW ITEM IF NOT ALREADY EXISTS
            if(item_unique_id == MAX_NUMBER_OF_ITEMS){
                cout << "\nFull of items.....";
                return;
            }
            cout << "\nEnter the name of item: ";
            cin >> name;
            cout << "\nEnter the rate of the item: ";
            cin >> rate;
        }
        
        i_list[item_unique_id] = Item(id, name, rate, 1);
        cout << "\nA new item is added\nHere are details--";
        i_list[item_unique_id].print_item_details();
        item_unique_id++;
    }
    void issue_item(){ // ISSUE AN ITEM
        int id;
        cout << "\nEnter the item code to issue: ";
        cin >> id;
         bool found = false;
        for (int i = 0; i < item_unique_id; i++)
        {
            if(i_list[i].get_id()==id){
               
                found = true;
                if(i_list[i].is_out_of_stock()){
                    cout << "\nThe item is out of stock...";
                }else{
                    i_list[i].issue_quantity();
                    cout << "\nThe following item is issued..";
                     i_list[i].print_item_details();
                }
               return;
            }
        }

        if(!found){
            cout << "\nThe item is not found......";
        }
    }

    void change_rate_of_item(){// CHAGE THE RATE OF AN ITEM WITH ITS CODE
        int r, id;
        cout << "\nEnter the item code to change rate: ";
        cin >> id;
        bool found = false;
        for (int i = 0; i < item_unique_id; i++)
        {
            if(i_list[i].get_id()==id){
               
                found = true;
                cout << "\nEnter the new rate: ";
                cin >> r;
                i_list[i].change_rate(r);
               return;
            }
        }

        if(!found){
            cout << "\nThe item code is invalid..." << endl;
        }
    }
    public:
    all_items(){
        item_unique_id = 0;
    }
    void maintain_items(){ // FUNCTION TO MAINTAIN ITEMS OPERATIONS
        int choice;
        do
        {
            cout << "\n1. Add Item\n2. Issue Item\n3. Change Rate\n0. Exit\n\nENTER YOUR CHOICE: ";
            cin >> choice;
            if(!choice){
                break;
            }

            switch (choice)
            {
            case 1:
                add_item();
                break;
            case 2:
                issue_item();
                break;    
            case 3:
                change_rate_of_item();
            default:
                break;
            }
        } while (1);
        
    }
};

int main(){
    all_items l;
    l.maintain_items();
}