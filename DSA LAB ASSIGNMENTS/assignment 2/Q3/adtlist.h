#include <stdio.h>
#include <stdlib.h>

#ifndef adtlist

struct list
{
    int capacity;
    int size;
    int *array;
};
typedef struct list *ptrToNode;
typedef ptrToNode LIST;
typedef int POSITION;

int Isempty(LIST L)
{
    return L->size == 0;
}

void MakeEmpty(LIST L)
{
    if (Isempty(L))
        printf("\n LIST is already Empty");
    else
    {
        L->size = 0;
        printf("\n Now List becomes Empty");
    }
}

LIST Createlist(int max)
{
    LIST L;
    L = (struct list *)malloc(sizeof(struct list));
    if (L == NULL)
        printf("\n Fatal Error");
    else
    {
        L->capacity = max;
        L->array = (int *)malloc(sizeof(int) * max);
        if (L->array == NULL)
            printf("\n Fatal Error");
        else
        {
            L->size = 0;
            printf("\n List is Created successfully");
        }
    }
    return L;
}

int Isfull(LIST L)
{
    return L->size == L->capacity;
}

void Insert(int x, LIST L, POSITION P)
{
    int i;
    if (Isfull(L))
        printf("\n List is Full");
    else
    {
        for (i = L->size - 1; i >= P; i--)
            L->array[i + 1] = L->array[i];
        L->size++;
        L->array[P] = x;
    }
}

POSITION Findprevious(int x, LIST L)
{
    POSITION P;
    P = -1;
    while (P != L->size && L->array[P + 1] != x)
    {
        P++;
    }
    return P;
}

POSITION Find(int x, LIST L)
{
    POSITION P;
    P = 0;
    int found = 0;
    while (P != L->size && L->array[P] != x)
    {
        P++;
    }
    if (L->array[P] == x)
    {
        found = 1;
    }

    return (found) ? P : (-1);
}

void Delete(int x, LIST L)
{
    int i;
    POSITION P;
    P = Find(x, L);
    if (P == L->size)
        printf("\n Element not found in the list");
    else
    {
        for (i = P; i < L->size; i++)
            L->array[i] = L->array[i + 1];
        L->size--;
    }
}

LIST Deletelist(LIST L)
{
    MakeEmpty(L);
    free(L);
    L = NULL;
    return L;
}

void Display(LIST L)
{
    int i;
    for (i = 0; i < L->size; i++)
        printf("\n %d", L->array[i]);
}

#define adtlist
#endif