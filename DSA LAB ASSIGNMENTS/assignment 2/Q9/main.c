#include <stdio.h>
#include <stdlib.h>

int *merge_two_sorted_arrays(int *arr1, int m, int *arr2, int n)
{
    int *merged_array = (int *)malloc((m + n) * sizeof(int));
    int i = 1, j = 0, k = 1, A, B;
    int *primary, *secondary;
    if (arr1[0] > arr2[0])
    {
        primary = arr2;
        secondary = arr1;
        A = n;
        B = m;
    }
    else
    {
        primary = arr1;
        secondary = arr2;
        A = m;
        B = n;
    }

    merged_array[0] = primary[0];
    while (i < A && j < B)
    {
        if (secondary[j] < primary[i])
        {
            merged_array[k] = secondary[j];
            j++;
            k++;
        }
        else
        {
            merged_array[k] = primary[i];
            i++;
            k++;
        }
    }

    while (i < A)
    {
        merged_array[k] = primary[i];
        i++;
        k++;
    }

    while (j < B)
    {
        merged_array[k] = secondary[j];
        j++;
        k++;
    }

    return merged_array;
}

int main()
{
    int m, n;
    printf("\nEnter the lenghts of two sorted arrays: ");
    scanf("%d %d", &m, &n);
    int i, arr1[m], arr2[n];

    printf("\nEnter the first sorted array elements: ");
    for (i = 0; i < m; i++)
    {
        scanf("%d", arr1 + i);
    }

    printf("\nEnter the second sorted array elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", arr2 + i);
    }

    int *merged_array = merge_two_sorted_arrays(arr1, m, arr2, n);

    printf("\nThe merged sorted array is: ");

    for (i = 0; i < m + n; i++)
    {
        printf("%d ", *(merged_array + i));
    }

    return 0;
}