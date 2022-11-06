/*IMPLEMENT QUESTION 5 USING STRUCTURES*/


#include <stdio.h>
#include <stdlib.h>

struct Person { //making a structure variable
    char name[40];
    int age;
};

int main() {
    int n;
    printf("Enter the number of persons: ");
    scanf("%d", &n);
    struct Person * persons;

    persons = (struct Person *)malloc(n*sizeof(struct Person));

    //Taking The data of persons--

    printf("Enter the name and age of persons one person per line: ");

    int i, j;
    for ( i = 0; i < n; i++)
    {
        scanf("%s %d", (persons+i)->name, &((persons+i)->age));
    }

    //sorting using bubble sort

    struct Person temp;

    for ( i = 0; i < n; i++)
    {
        for ( j = i+1; j < n; j++)
        {
            if((persons+i)->age > (persons+j)->age) {
                temp = *(persons+i);
                *(persons+i) = *(persons+j);
                *(persons+j) = temp;
            }
        }
        
    }

    //printing the sorted result

    printf("The persons in the ascending order of ages are: \n\tName\tAge\n");

    for ( i = 0; i < n; i++)
    {
        printf("\t%s\t%d\n", (persons+i)->name, (persons+i)->age);
    }
    
    free(persons);
    
    
}