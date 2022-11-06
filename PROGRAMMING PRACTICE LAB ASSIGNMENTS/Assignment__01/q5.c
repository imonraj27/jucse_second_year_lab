/*5. Store name and age of number of persons (number provided at run time).
Collect the data and display data in the ascending order of age. 
Implement without using structure. Write functions for
 memory allocation of the list, sorting and display of data.*/



#include <stdio.h>
#include <stdlib.h>


//function for dynamic memory allocation for ages of persons
int * ageAllocate(int n) {
    int * ages = (int *)malloc(n*sizeof(int));
    return ages;
}


//function for memory allocation for names of persons
char ** nameAllocate(int n) {
    char ** names = (char **)malloc(n*sizeof(char *));
    int i;
    for ( i = 0; i < n; i++)
    {
        *(names+i) = (char *)malloc(40*sizeof(char));
    }
    
    return names;
}

//functions for sorting persons in ascending order of ages

int * sortedIndex(int * ages, int n) {
    int * temp = (int *)malloc(n*sizeof(int));
    int * index = (int *)malloc(n*sizeof(int));
    int i, j, a, b;

    for ( i = 0; i < n; i++)
    {
        temp[i] = ages[i]; //create a temporary array same values as age array
    }

    
    for ( i = 0; i < n; i++)
    {
        index[i] = i; //creating an indexes array to use in sorting purpose
    }


    //sorting using bubble sort

    for (i = 0; i < n; i++) 
        {
 
            for (j = i + 1; j < n; j++)
            {
 
                if (temp[i] > temp[j]) 
                {
 
                    a =  temp[i];
                    b =  index[i];
                    temp[i] = temp[j];
                    index[i] = index[j];
                    temp[j] = a;
                    index[j] = b;
 
                }
 
            }
 
        }

       free(temp);

         

        return index;
    
    
}

//functions for printing data in ascending order

void printAscending(int * ages, char ** names, int * index, int n) {
    printf("\n\nThe persons in the ascending order of ages are: \n");

    int i;
    for ( i = 0; i < n; i++)
    {
       printf("%s %d\n", names[index[i]], ages[index[i]]);
    }
    
}

int main() {
    int i, n;
    printf("Enter the number of persons: ");
    scanf("%d", &n);

    int * ages = ageAllocate(n);
    char ** names = nameAllocate(n);

    
    //taking the data of persons names and ages

    printf("\nEnter the names and ages one person per line: \n");

      for ( i = 0; i < n; i++)
    {
        scanf("%s %d", *(names+i), ages+i);
    }


   
    int * index = sortedIndex(ages, n);

  

    printAscending(ages, names, index, n);


    //deallocating every array memory 
    free(ages);
    free(names);
    free(index);
    

    return 0;
}