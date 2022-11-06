#include <stdio.h>
#define MAX_SET_ELEMENTS 100

#ifndef adtset

typedef struct set
{
    int arr[2][MAX_SET_ELEMENTS];
    int end_position;
} Set;

Set Initialize_Set()
{
    Set AA;
    int i;
    for (i = 0; i < MAX_SET_ELEMENTS; i++)
    {
        AA.arr[1][i] = -1;
        AA.arr[0][i] = 0;
    }

    AA.end_position = 0;

    return AA;
}

void Insert_Element_In_Set(Set *pS, int value)
{
    int i;

    for (i = 0; i <= (*pS).end_position; i++)
    {
        if ((*pS).arr[1][i] == 1)
        {
            if ((*pS).arr[0][i] == value)
            {
                printf("\nElement already exists in the set..");
                return;
            }
        }
    }

    for (i = 0; i <= (*pS).end_position + 1; i++)
    {
        if (i > (MAX_SET_ELEMENTS - 1))
        {
            printf("\nSet is full..");
            return;
        }
        if ((*pS).arr[1][i] == (-1))
        {
            (*pS).arr[1][i] = 1;
            (*pS).arr[0][i] = value;
            break;
        }
    }

    if (i == ((*pS).end_position + 1))
    {
        (*pS).end_position = i;
    }
}

void Delete_Element_In_Set(Set *pS, int value)
{
    int i;
    for (i = 0; i <= (*pS).end_position; i++)
    {
        if ((*pS).arr[1][i] == 1)
        {
            if ((*pS).arr[0][i] == value)
            {
                (*pS).arr[1][i] = -1;
                (*pS).arr[0][i] == 0;
                printf("\nElement successfully deleted from the set..");
                return;
            }
        }
    }

    printf("\nElement doesn't exist in set to delete..");
}

int Set_Contains(Set s, int value)
{
    int i;

    for (i = 0; i <= s.end_position; i++)
    {
        if (s.arr[1][i] == 1)
        {
            if (s.arr[0][i] == value)
            {
                return 1;
            }
        }
    }
    return 0;
}
Set Union_Of_Sets(Set s1, Set s2)
{
    Set union_set = Initialize_Set();
    int i, j = 0;
    for (i = 0; i <= s1.end_position; i++)
    {
        if (s1.arr[1][i] == 1)
        {
            if (!Set_Contains(s2, s1.arr[0][i]))
            {
                Insert_Element_In_Set(&union_set, s1.arr[0][i]);
                j++;
            }
        }
    }

    for (i = 0; i <= s2.end_position; i++)
    {
        if (s2.arr[1][i] == 1)
        {
            if(j==MAX_SET_ELEMENTS){
                printf("\nThe union set exceeds set capacity..");
                union_set = Initialize_Set();
                return union_set;
            }
            Insert_Element_In_Set(&union_set, s2.arr[0][i]);
            j++;
        }
    }

    return union_set;
}

Set Intersection_Of_Sets(Set s1, Set s2){
     Set intersection_set = Initialize_Set();
    int i;
    for (i = 0; i <= s1.end_position; i++)
    {
        if (s1.arr[1][i] == 1)
        {
            if (Set_Contains(s2, s1.arr[0][i]))
            {
                Insert_Element_In_Set(&intersection_set, s1.arr[0][i]);
            }
        }
    }

    return intersection_set;

}

void Print_Set(Set S)
{
    int i, flag=0;
    printf("\n{ ");
    for (i = 0; i <= S.end_position; i++)
    {
        if (S.arr[1][i] == 1)
        {
            if(flag){
                printf(",");
            }else{
                flag=1;
            }
            printf(" %d ", S.arr[0][i]);
        }
    }
    printf("}");
}

#define adtset
#endif