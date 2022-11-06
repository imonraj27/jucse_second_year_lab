/* ----- CREATED AND TESTED BY IMON RAJ , JADAVPUR UNIVERSITY , BATCH 2020-2024 COMPUTER
SCINECE AND ENGINEERING DEPARTMENT , THIS HEADER FILE HAS THE BASIC ADT OPERATION 
FUNCTIONS OF A CIRCULAR LINKED LIST DATA STRUCTURE. SPECIAL THANKS TO OUR MENTOR AND TEACHER 
IN THIS PARTICULAR COURSE MR PROF CHANDAN MAZUMDAR ----- */

#include <stdio.h>
#include <stdlib.h>

#ifndef circularlinkedlist

// defining the CLLNode of a linked list using structure
typedef struct CLLNode
{
    int data;
    struct CLLNode *next;
} CLLNode;



// create a new CLLNode with integer data
CLLNode * createCLLNode(int data) {
    CLLNode * newCLLNode = (CLLNode *)malloc(sizeof(CLLNode));
    if (newCLLNode == NULL) {
        return NULL;
    } 

    newCLLNode->data = data;
    newCLLNode->next = newCLLNode;
    return newCLLNode;
}



// initializing a new list
CLLNode * init_l()
{
    return NULL;
}


// check if the list is empty
int empty_l(CLLNode *head)
{
    return (head == NULL);
}



// check if the pointer is in the last of list
int atend_l(CLLNode *cur, CLLNode * head)
{
    if (cur == NULL)
    {
        return 0;
    }
    else
    {
        return (cur->next == head);
    }
}

// delete an element after a particular CLLNode
CLLNode * delete_after(CLLNode *prev, CLLNode ** phead){
    if(prev == NULL || prev->next == NULL){
        return NULL;
    } 

    CLLNode * temp;

  if(atend_l(prev, *phead)){
      temp = *phead;

      if(temp->next == temp){
          *phead = NULL;
          return temp;
      }
      (*phead) = (*phead)->next;
      prev->next = *phead;
      temp->next = temp;
      return temp;
  }else{
      temp = prev->next;
      prev->next = temp->next;
      temp->next = temp;
      return temp;
  }

}




// delete first element of the list
CLLNode * delete_front(CLLNode **phead) {
    if (*phead == NULL){
        return NULL;
    }

    CLLNode * temp = *phead;
    while(!atend_l(temp, *phead)){
        temp = temp->next;
    }
   return delete_after(temp, phead);
}




// insert a new CLLNode at the begining of the list
void insert_front(CLLNode *target, CLLNode **phead) {
    if (target == NULL || *phead == NULL){
        return;
    }

    
    CLLNode * temp = *phead;
    while(!atend_l(temp, *phead)){
        temp = temp->next;
    }

    temp->next = target;
    target->next = *phead;
    *phead = target;
}


// insert a new CLLNode after a specific CLLNode 
void insert_after(CLLNode *target, CLLNode *prev) {
    if (target == NULL || prev == NULL){
        return;
    }

    target->next = prev->next;
    prev->next = target;
}


// print the complete list
void print_l(CLLNode * head) {
    if (head == NULL) {
        printf("\nList is empty");
        return;
    }

    CLLNode * cur = head;
    int i=0;

    while (cur != head || i==0)
    {
        printf("%d-->", cur->data);
        cur = cur->next;
        i++;
    }
    
}


// delete the complete list
void delete_l(CLLNode ** phead) {
    if((*phead) == NULL){
        return;
    }

    CLLNode * temp = NULL;

    while(!empty_l(*phead)) {
       temp = delete_front(phead);
       free(temp);
       temp = NULL;
    }
}

#define circularlinkedlist
#endif