/* 13.	Create a class for linked list.
 Consider a separate class NODE for basic node activities 
 and use it in class for linked list. */

#include <iostream>
using namespace std;

class Node{ // THE NODE CLASS 
    int data;
    Node * next;
    friend class Linkedlist;
    public:
    Node(int d){ // CONSTRUCTOR ITSELF CARRIES OUT NODE CREATION OPERATION
        data = d;
        next = NULL;
    }
};

class Linkedlist{ // THE CLASS FOR LINKED LIST
    Node * head;
    public:
    Linkedlist(){
        head = NULL;
    }

    void insert_front(int data){ // INSERT DATA AT THE FRONT
        if(head==NULL){
            head = new Node(data);
            head->next = NULL;
            return;
        }

        Node * newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insert_end(int data){ // INSERT DATA AT THE END
        if(head==NULL){
             head = new Node(data);
            head->next = NULL;
            return;
        }

        Node * ptr = head, * newNode = new Node(data);
        while(ptr->next != NULL){
            ptr = ptr->next;
        }

        ptr->next = newNode;
    }

    void delete_front(){ // DELETE THE DATA AT FRONT
        if(head==NULL){
            cout << "\nEmpty List!!";
            return;
        }

        Node * ptr = head->next;
         delete[] head;
         head = ptr;    

    }

    void delete_end(){ // DELTE DATA AT THE END OF LIST
        if(head==NULL){
            return;
        }

        if(head->next == NULL){
            delete[] head;
            head = NULL;
            return;
        }

        Node * ptr = NULL, * ptr2 = head;
        while(ptr2->next != NULL){
            ptr = ptr2;
            ptr2 = ptr2->next;
        }

        if(ptr->next){
             ptr->next = NULL;
        }
       
        delete[] ptr2;
        ptr2 = NULL;
    }

    void print_list(){ // PRINT THE LIST COMPLETELY
        if(head==NULL){
            cout << "\nList is empty";
            return;
        }
        Node * ptr = head;
        while(ptr!=NULL){
            cout << ptr->data << "-->";
            ptr = ptr->next;
        }
    }

    void Linked_list_operations(){ // FUNCTION TO MAINTAIN ALL LINKED LIST OPERATIONS
        int choice, data;
        do
        {
           cout << "\n\n1. Print List\n2. Insert At Front\n3. Insert At End\n4. Delete At Front\n5. Delete at End\n0. Exit\n\nENTER YOUR CHOICE: ";
           cin >> choice;
           if(choice==0){
               break;
           } 

           switch(choice){
               case 1:
               print_list();
               break;

               case 2:
               cout << "\nEnter value to insert at front: ";
               cin >> data;
               insert_front(data);
               break;

                case 3:
               cout << "\nEnter value to insert at end: ";
               cin >> data;
               insert_end(data);
               break;

               case 4: 
               delete_front();
               break;

               case 5:
               delete_end();
               break;
           }
        } while (1);
        
    }
};

int main(){
    Linkedlist l;
    l.Linked_list_operations();
    return 0;
}