/*2. Implement a one-dimensional array of integers where array 
size of the array will be provided during runtime. Accept the
 value for the elements and print those using pointers.*/




#include <stdio.h>
#include <stdlib.h>


int main() {
    int i, n;
    int * arr;

    printf("Enter the length of array: ");
    scanf("%d", &n);

    arr = (int *)malloc(n*sizeof(int)); //Dynamically allocating the memory


    //Taking the array elements
    printf("Enter the values of array elements: ");

    for ( i = 0; i < n; i++)
    {
        scanf("%d", (arr+i));
    }


    //printing the array elements
    printf("\nThe values are: ");

    for ( i = 0; i < n; i++)
    {
        printf("%d ", *(arr+i));
    }
    
    free(arr);
    
    return 0;
}