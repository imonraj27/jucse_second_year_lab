/* ----- CREATED AND TESTED BY IMON RAJ , JADAVPUR UNIVERSITY , BATCH 2020-2024 COMPUTER
SCINECE AND ENGINEERING DEPARTMENT , THIS HEADER FILE HAS THE BASIC ADT OPERATION 
FUNCTIONS OF A CIRCULAR DOUBLY LINKED LIST DATA STRUCTURE. SPECIAL THANKS TO OUR MENTOR AND TEACHER 
IN THIS PARTICULAR COURSE MR PROF CHANDAN MAZUMDAR ----- */

#include <stdio.h>
#include <stdlib.h>

#ifndef circulardoublylinkedlist

// defining the CDLLNode of a linked list using structure
typedef struct CDLLNode
{
    int data;
    struct CDLLNode *next;
    struct CDLLNode *prev;
} CDLLNode;

// create a new CDLLNode with integer data
CDLLNode *createCDLLNode(int data)
{
    CDLLNode *newCDLLNode = (CDLLNode *)malloc(sizeof(CDLLNode));
    if (newCDLLNode == NULL)
    {
        return NULL;
    }

    newCDLLNode->data = data;
    newCDLLNode->next = newCDLLNode;
    newCDLLNode->prev = newCDLLNode;
    return newCDLLNode;
}

// initializing a new list
CDLLNode *init_l()
{
    return NULL;
}

// check if the list is empty
int empty_l(CDLLNode *head)
{
    return (head == NULL);
}

// check if the pointer is in the last of list
int atend_l(CDLLNode *cur, CDLLNode *head)
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

// delete an element after a particular CDLLNode
CDLLNode *delete_after(CDLLNode *prev, CDLLNode **phead)
{
    if (prev == NULL || prev->next == NULL)
    {
        return NULL;
    }

    CDLLNode *temp;

    if (atend_l(prev, *phead))
    {
        temp = *phead;

        if (temp->next == temp)
        {
            *phead = NULL;
            return temp;
        }
        (*phead) = (*phead)->next;
        prev->next = *phead;
        (*phead)->prev = prev;

        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    else
    {
        temp = prev->next;
        prev->next = temp->next;
        temp->next->prev = prev;

        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
}

// delete first element of the list
CDLLNode *delete_front(CDLLNode **phead)
{
    if (*phead == NULL)
    {
        return NULL;
    }

    CDLLNode *temp = *phead;
    while (!atend_l(temp, *phead))
    {
        temp = temp->next;
    }
    return delete_after(temp, phead);
}

// insert a new CDLLNode at the begining of the list
void insert_front(CDLLNode *target, CDLLNode **phead)
{
    if (target == NULL)
    {
        return;
    }

    if (*phead == NULL)
    {
        *phead = target;
    }

    CDLLNode *temp = *phead;
    while (!atend_l(temp, *phead))
    {
        temp = temp->next;
    }

    temp->next = target;
    target->prev = temp;
    target->next = *phead;
    (*phead)->prev = target;
    *phead = target;
}

// insert a new CDLLNode after a specific CDLLNode
void insert_after(CDLLNode *target, CDLLNode *prev)
{
    if (target == NULL || prev == NULL)
    {
        return;
    }

    target->next = prev->next;
    target->prev = prev;
    prev->next = target;
    target->next->prev = target;
}

// print the complete list
void print_l(CDLLNode *head)
{
    if (head == NULL)
    {
        printf("\nList is empty");
        return;
    }

    CDLLNode *cur = head;
    int i = 0;

    while (cur != head || i == 0)
    {
        printf("%d-->", cur->data);
        cur = cur->next;
        i++;
    }
}

// delete the complete list
void delete_l(CDLLNode **phead)
{
    if ((*phead) == NULL)
    {
        return;
    }

    CDLLNode *temp = NULL;

    while (!empty_l(*phead))
    {
        temp = delete_front(phead);
        free(temp);
        temp = NULL;
    }
}

#define circulardoublylinkedlist
#endif