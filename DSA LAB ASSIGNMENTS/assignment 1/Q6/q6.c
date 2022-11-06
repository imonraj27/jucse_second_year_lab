#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void findLargestAndSmallest(char filename[40]) {
    FILE * fp = fopen(filename, "r");

    if(fp == NULL) {
        printf("\nFile doesn't exist or error occured!!");
        return;
    }

    char largestname[60];
    char smallestname[60];

    char temporary[60];
    
    fgets(largestname, 60, fp);
    fgets(smallestname, 60, fp);

    while (!feof(fp)) // Finding the smallest and largest name within  the file
    {
        fgets(temporary, 60, fp);
        if(strcmp(temporary, largestname) > 0) { // strcmp is for comparing strings lexicographically
            strcpy(largestname, temporary);
        } else if (strcmp(temporary, smallestname) < 0) {
            strcpy(smallestname, temporary);
        }
    }

    printf("Largest Name: %s Length: %d\n\n", largestname, strlen(largestname));
    printf("Smallest Name: %s Length: %d", smallestname, strlen(smallestname));

    fclose(fp);
    
}


int main() {
    printf("\nEnter the file name of the classmates names: ");
    char filename[40];
    scanf("%s", filename);
    findLargestAndSmallest(filename);
    return 0;
}