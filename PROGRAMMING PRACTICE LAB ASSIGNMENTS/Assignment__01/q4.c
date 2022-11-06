/*4. Implement the programs in Q.2 and 3 breaking it
 into functions for i) getting the dimensions from user, 
 ii) dynamic memory allocation, iii) accepting the values
  and iv) printing the values.*/



#include <stdio.h>
#include <stdlib.h>


//Functions for question number 2

int lenOfOneDArray(){ //Taking the length of one dimensional array
    int n;
    printf("\nEnter the length of one dimensional array: ");
    scanf("%d", &n);
    return n;
}

int * allocOneDArray(int n) { //dynamically allocating space for one d array
    int * arr = (int *)malloc(n*sizeof(int));

    if(arr==NULL){
        printf("Memory Error!!");
        return NULL;
    }

    return arr;
}

void takeOneDArrayValues(int * arr, int n) { //taking elements of one d array
    int i;
    printf("\n\nEnter the values of one dimensional array: ");
    for ( i = 0; i < n; i++)
    {
        scanf("%d", arr+i);
    }
    
}

void printOneDArray(int * arr, int n) { //printing the one d array
    printf("\n\nThe values are: ");

    int i;
    for ( i = 0; i < n; i++)
    {
        printf(" %d", *(arr+i));
    }
    
}


//Functions for question number 3

int takeDimValue() { //taking rows and columns value of 2d array
    int x;
    scanf("%d", &x);
    return x;
}

int ** allocTwoDArray(int r, int c) { //dynamically allocating the two dim array
    int ** arr = (int **)malloc(r*sizeof(int *));

    int i;
    for ( i = 0; i < r; i++)
    {
        *(arr+i) = (int *)malloc(c*sizeof(int));
    }

    return arr;
    
}

void takeTwoDArrayValues(int ** arr, int r, int c) { //taking the 2d array values
    int i, j;
    printf("\n\nEnter the values of two dimensional array row wise: ");
    for ( i = 0; i < r; i++)
    {
        for ( j = 0; j < c; j++)
        {
            scanf("%d", (*(arr+i)+j));
        }
        
    }
    
}

void printTwoDArray(int ** arr, int r, int c) { //printing the 2d array values
    int i, j;
    printf("\n\nThe values of 2D array are: \n");
    for ( i = 0; i < r; i++)
    {
        for ( j = 0; j < c; j++)
        {
            printf("%d ", *(*(arr+i)+j));
        }
        printf("\n");
    }
    
}

int main() {

    //For question number 2

    int n = lenOfOneDArray();
    int * arr = allocOneDArray(n);
    takeOneDArrayValues(arr, n);
    printOneDArray(arr, n);

    free(arr); //deallocating the memory

    //For question number 3

    printf("\n\nEnter the number of rows and columns: ");

    int r = takeDimValue();
    int c = takeDimValue();

    int ** arr2d = allocTwoDArray(r, c);
    takeTwoDArrayValues(arr2d, r, c);
    printTwoDArray(arr2d, r, c);

    
    int i;
    for ( i = 0; i < r; i++)
    {
        free(*(arr2d+i));
    }
    free(arr2d); //deallocating the memory

    

    return 0;
}