#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

#define STUDENTS_NUMBER 82  // TOTAL NUMBER OF STUDENTS




int main() {

    FILE * fp = fopen("names.txt", "r"); // Reading from this file
    FILE * fp2 = fopen("sorted.txt", "w"); // Writing in this file after sorting

    if(fp == NULL || fp2 == NULL) { // Exiting the program if files are not opened properly
        printf("\nError in opening the file..");
        exit(0);
    }

    char name[STUDENTS_NUMBER][60]; // An array to store the names after retrieving from the file
    int i, j; // Loop variables

    for(i=0; i<STUDENTS_NUMBER; i++) {
        fgets(name[i], 60, fp); // Reading from file and storing in the array
    }

    char temp[60]; // A temporary string to be used in swapping

    for (i = 0; i < STUDENTS_NUMBER; i++) // Bubble sorting
    {
        for (j = i+1; j < STUDENTS_NUMBER; j++)
        {
            if(strcmp(name[i], name[j]) > 0) { // Swapping whenever needed
                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
            }
        }
        
    }

    for (i = 0; i < STUDENTS_NUMBER; i++)
    {
         fprintf(fp2, "%s", name[i]); // Printing the sorted names into the new file
    }
    
    

    // CLOSING BOTH THE FILES AFTER OPERATION
    fclose(fp2);
    fclose(fp);
  
    return 0;
}