/*3. Implement a two-dimensional array of integers 
using a) pointer to an array and b) array of pointers.
 Accept the value for the elements and print those.*/



#include <stdio.h>
#include <stdlib.h>


int main(){
    int rows, cols;
    int i, j;

    printf("Enter the value of rows and cols: ");
    scanf("%d %d", &rows, &cols); //Taking the values of rows and columns

    //IMPLEMENTATION OF 2D ARRAY USING ARRAY OF POINTERS.......

    int *aofp[rows];   //array of pointers

    for ( i = 0; i < rows; i++)
    {
        aofp[i] = (int *)malloc(cols*sizeof(int)); //Dynamically allocating memory for each pointer
    }

    printf("Enter the values of 2D array row-wise: ");

    for ( i = 0; i < rows; i++)
    {
        for ( j = 0; j < cols; j++)
        {
            scanf("%d", (aofp[i] + j)); //Taking elements of 2D array
        }
        
    }

  

    printf("\nThe numbers in the 2D array are: \n");

     for ( i = 0; i < rows; i++)
    {
        for ( j = 0; j < cols; j++)
        {
            printf("%d ", *(aofp[i] + j)); //printing elements of two dimensional array
        }
        printf("\n");
    }

       for ( i = 0; i < rows; i++)
    {
        free(aofp[i]);
    }
    
    //IMPLEMENTATIONS USING POINTER TO ARRAY................

    int (* ptoarr)[cols];

   ptoarr = (int (*)[cols])malloc(rows*sizeof(int [cols])); //allocating memory for pointer to an array of length cols
   
    
    
    printf("Enter the elements row-wise: ");

    for ( i = 0; i < rows; i++)
    {
        for ( j = 0; j < cols; j++)
        {
            scanf("%d", (*(ptoarr+i)+j)); //taking elements of array
        }
        
    }

    printf("\nThe values are: \n");

     for ( i = 0; i < rows; i++)
    {
        for ( j = 0; j < cols; j++)
        {
            printf("%d ", *(*(ptoarr+i)+j)); //printing array elements
        }

        printf("\n");
        
    }

    free(ptoarr); //deallocating the memory 
    
    


    return 0;

}    