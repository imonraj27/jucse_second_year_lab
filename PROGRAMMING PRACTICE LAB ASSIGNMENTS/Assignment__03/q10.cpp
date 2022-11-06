/* 10.	Create a STACK class with operation for initialization, push and pop. 
Support for checking underflow and overflow condition are also to be provided. */


#include <iostream>
#define LENGTH_OF_STACK 10

using namespace std;



class Stack { // CLASS FOR STACK
    int * arr;
    int top;

    public:
    Stack() { // CONSTRUCTOR
        arr = new int[LENGTH_OF_STACK]; // ALLOCATING MEMORY 
        top = -1;
    }

    void push(int value){
        if(top==LENGTH_OF_STACK-1) {
            cout << "Stack Overflow !!!!" << endl;
            return;
        }
        top++;
        arr[top] = value;
    }

    void pop() {
        if(top==-1){
            cout << "Stack Underflow !!!!" << endl;
            return;
        }
        cout << "Value after pop: " << arr[top];
        top--;
    }

    int Topval() {
         if(top==-1){
            return -9999;
        }
        return arr[top];
    }

    void delete_stack(){
        delete[] arr;
    }
};

int main() {
    Stack new_stack;
    int choice, value;

    do {
        cout << "\n\n1. Push a value to the stack\n2. Pop the value from stack\n0. exit....\n\nENTER YOUR CHOICE: ";
        cin >> choice;

        if (!choice) {
            new_stack.delete_stack();
            break;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter the integer to push: ";
            cin >> value;
            new_stack.push(value);
            break;
        case 2: 
            new_stack.pop();
            break;    
        
        default:
            break;
        }
    } while(1);
    return 0;
}