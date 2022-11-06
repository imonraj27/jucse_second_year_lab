/* ----- CREATED AND TESTED BY IMON RAJ , JADAVPUR UNIVERSITY , BATCH 2020-2024 COMPUTER
SCINECE AND ENGINEERING DEPARTMENT , THIS HEADER FILE HAS THE BASIC ADT OPERATION 
FUNCTIONS OF A DOUBLY LINKED LIST DATA STRUCTURE. SPECIAL THANKS TO OUR MENTOR AND TEACHER 
IN THIS PARTICULAR COURSE MR PROF CHANDAN MAZUMDAR ----- */

#include <stdio.h>
#include <stdlib.h>

#ifndef doublylinkedlist

// defining the Node of a linked list using structure
typedef struct dllnode
{
    int data;
    struct dllnode *prev;
    struct dllnode *next;
} DLLNode;



// create a new Node with integer data
DLLNode * createDLLnode(int data) {
    DLLNode * newnode = (DLLNode *)malloc(sizeof(DLLNode));
    if (newnode == NULL) {
        return NULL;
    } 

    newnode->data = data;
    newnode->prev = NULL;
    newnode->next = NULL;
    return newnode;
}



// initializing a new list
DLLNode * init_l()
{
    return NULL;
}


// check if the list is empty
int empty_l(DLLNode *head)
{
    return (head == NULL);
}



// check if the pointer is in the last of list
int atend_l(DLLNode *cur)
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
DLLNode * delete_front(DLLNode **phead) {
    if (*phead == NULL){
        return NULL;
    }

    DLLNode * temp = *phead;
    *phead = (*phead)->next;
    if(*phead){
        (*phead)->prev = NULL;
    }
    
    temp->next = NULL;
    return(temp);
}


// delete an element after a particular node
DLLNode * delete_after(DLLNode *previous){
    if(previous == NULL || previous->next == NULL){
        return NULL;
    } 

   previous = previous->next;
    previous->prev->next = previous->next;
    if(previous->next){
          previous->next->prev = previous->prev;
    }
  

    previous->next = NULL;
    previous->prev = NULL;
    return previous;

}



// insert a new node at the begining of the list
void insert_front(DLLNode *target, DLLNode **phead) {
    if (target == NULL || *phead == NULL){
        return;
    }

    target->next = *phead;
    (*phead)->prev = target;
    *phead = target;
}


// insert a new node after a specific node 
void insert_after(DLLNode *target, DLLNode *previous) {
    
    if (target == NULL || previous == NULL){
         printf("\nrrr");
        return;
    }

    target->next = previous->next;
    target->prev = previous;
    previous->next = target;
    if(target->next){
         target->next->prev = target;
    }
   
}


// print the complete list
void print_l(DLLNode * head) {
    if (head == NULL) {
        printf("\nList is empty");
        return;
    }

    DLLNode * cur = head;

    while (cur != NULL)
    {
        printf("%d-->", cur->data);
        cur = cur->next;
    }
    
}


// delete the complete list
void delete_l(DLLNode ** phead) {
    if((*phead) == NULL){
        return;
    }

    DLLNode * temp = NULL;
    while(!empty_l(*phead)) {
       temp = delete_front(phead);
       free(temp);
       temp = NULL;
    }
}

#define doublylinkedlist
#endif