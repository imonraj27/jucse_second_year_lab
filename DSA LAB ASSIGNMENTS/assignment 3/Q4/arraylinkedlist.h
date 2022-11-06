/* ----- CREATED AND TESTED BY IMON RAJ , JADAVPUR UNIVERSITY , BATCH 2020-2024 COMPUTER
SCINECE AND ENGINEERING DEPARTMENT , THIS HEADER FILE HAS THE BASIC ADT OPERATION 
FUNCTIONS OF A LINKED LIST DATA STRUCTURE USING ARRAYS. SPECIAL THANKS TO OUR MENTOR AND TEACHER 
IN THIS PARTICULAR COURSE MR PROF CHANDAN MAZUMDAR ----- */

#include <stdio.h>
#include <stdlib.h>

#ifndef arraylinkedlist

#define MAX_LINKED_LIST_SIZE 50
#define nodeAddress int

// defining the linked list using array

typedef struct node
{
    int data;
    int next; // default -1 means null
    int used; // default 0 when not in use or when deleted node
} ALLNode;

typedef struct array_linked_list
{
    nodeAddress head;
    ALLNode array[MAX_LINKED_LIST_SIZE];
} ArrayLinkedList;

ArrayLinkedList *prepare_linked_list()
{
    ArrayLinkedList *plist = (ArrayLinkedList *)malloc(sizeof(ArrayLinkedList));

    int i;
    for (i = 0; i < MAX_LINKED_LIST_SIZE; i++)
    {
        plist->array[i].data = 0;
        plist->array[i].used = 0;
        plist->array[i].next = -1;
    }

    plist->head = -1;

    return plist;
}

nodeAddress createnode(int value, ArrayLinkedList *plist)
{
    nodeAddress temp = -1;
    int i;
    for (i = 0; i < MAX_LINKED_LIST_SIZE; i++)
    {
        if (plist->array[i].used == 0)
        {
            temp = i;
            plist->array[i].data = value;
            plist->array[i].next = -1;
            plist->array[i].used = 1;
            break;
        }
    }

    if (temp == -1)
    {
        printf("\nList is full");
    }

    return temp;
}

int empty_l(ArrayLinkedList *plist)
{
    return (plist->head == -1);
}

int atend_l(nodeAddress node, ArrayLinkedList *plist)
{
    return (plist->array[node].next == -1);
}

void insert_front(ArrayLinkedList *plist, nodeAddress target)
{

    if (target == -1)
    {
        printf("\nList full!!!");
        return;
    }
    else
    {
        plist->array[target].next = plist->head;
        plist->head = target;
    }
}

void insert_after(nodeAddress prev, ArrayLinkedList *plist, nodeAddress target)
{

    if (target == -1)
    {
        printf("\nList full!!!");
        return;
    }

    plist->array[target].next = plist->array[prev].next;
    plist->array[prev].next = target;
}

void delete_after(nodeAddress prev, ArrayLinkedList *plist)
{
    nodeAddress temp = plist->array[prev].next;
    plist->array[prev].next = plist->array[temp].next;

    plist->array[temp].used = 0;
    plist->array[temp].next = -1;
}

void delete_front(ArrayLinkedList *plist)
{
    nodeAddress temp = plist->head;

    plist->head = plist->array[plist->head].next;

    plist->array[temp].used = 0;
    plist->array[temp].next = -1;
}

void print_l(ArrayLinkedList *plist)
{
    nodeAddress temp = plist->head;

    printf("\n");
    while (temp != -1)
    {
        printf("%d -> ", plist->array[temp].data);
        temp = plist->array[temp].next;
    }
}

void delete_l(ArrayLinkedList *plist)
{
    int i;
    for (i = 0; i < MAX_LINKED_LIST_SIZE; i++)
    {
        plist->array[i].used = 0;
        plist->array[i].next = -1;
    }
    plist->head = -1;
}

#define arraylinkedlist
#endif