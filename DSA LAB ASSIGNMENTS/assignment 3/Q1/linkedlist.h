/* ----- CREATED AND TESTED BY IMON RAJ , JADAVPUR UNIVERSITY , BATCH 2020-2024 COMPUTER
SCINECE AND ENGINEERING DEPARTMENT , THIS HEADER FILE HAS THE BASIC ADT OPERATION 
FUNCTIONS OF A LINKED LIST DATA STRUCTURE. SPECIAL THANKS TO OUR MENTOR AND TEACHER 
IN THIS PARTICULAR COURSE MR PROF CHANDAN MAZUMDAR ----- */

#include <stdio.h>
#include <stdlib.h>

#ifndef linkedlist

// defining the Node of a linked list using structure
typedef struct node
{
    int data;
    struct node *next;
} Node;



// create a new Node with integer data
Node * createnode(int data) {
    Node * newnode = (Node *)malloc(sizeof(Node));
    if (newnode == NULL) {
        return NULL;
    } 

    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}



// initializing a new list
Node * init_l()
{
    return NULL;
}


// check if the list is empty
int empty_l(Node *head)
{
    return (head == NULL);
}



// check if the pointer is in the last of list
int atend_l(Node *cur)
{
    if (cur == NULL)
    {
        return 0;
    }
    else
    {
        return (cur->next == NULL);
    }
}


// delete first element of the list
Node * delete_front(Node **phead) {
    if (*phead == NULL){
        return NULL;
    }

    Node * temp = *phead;
    *phead = (*phead)->next;
    temp->next = NULL;
    return(temp);
}


// delete an element after a particular node
Node * delete_after(Node *prev){
    if(prev == NULL || prev->next == NULL){
        return NULL;
    } 

    Node * temp = prev->next;
    prev->next = temp->next;

    temp->next = NULL;
    return temp;

}



// insert a new node at the begining of the list
void insert_front(Node *target, Node **phead) {
    if (target == NULL){
        return;
    }


    target->next = *phead;
    *phead = target;
}


// insert a new node after a specific node 
void insert_after(Node *target, Node *prev) {
    if (target == NULL || prev == NULL){
        return;
    }

    target->next = prev->next;
    prev->next = target;
}


// print the complete list
void print_l(Node * head) {
    if (head == NULL) {
        printf("\nList is empty");
        return;
    }

    Node * cur = head;

    while (cur != NULL)
    {
        printf("%d-->", cur->data);
        cur = cur->next;
    }
    
}


// delete the complete list
void delete_l(Node ** phead) {
    if((*phead) == NULL){
        return;
    }

    Node * temp = NULL;

    while(!empty_l(*phead)) {
       temp = delete_front(phead);
       free(temp);
       temp = NULL;
    }
}

#define linkedlist
#endif