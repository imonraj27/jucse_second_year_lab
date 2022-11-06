#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int randIndex() // Generates an index number between 0 to 99999 approxiamtely
{
   
    float frac1 = rand()/32768.000; // generates fraction between 0 to 1
    float frac2 = rand()/32768.000; // generates fraction between 0 to 1

    float val = (frac1*frac2)*99999; // multiplying to fractions to make it more random
    int index = floor(val);
    
    return index;
}

void shuffle(int *arr) // Function to shuffle the array 
{
    int temp, i, j, k;

    for (k = 0; k < 100000; k++) // First shuffle depending on the rand() function the first elements mostly shuffled
    {
        do
        {
            i = randIndex();
            j = randIndex();

        } while (i == j);

       
        temp = *(arr + i);
        *(arr + i) = *(arr + j);
        *(arr + j) = temp;
    }

    for (k = 0; k < 100000; k++) // shuffle another time to last elements be shufled properly
    {
        do
        {
            i = randIndex();
            j = randIndex();

        } while (i == j);

       
        temp = *(arr + 99999- i);
        *(arr + 99999- i) = *(arr + 99999- j);
        *(arr + 99999- j) = temp;
    }
}

int main()
{
    time_t t;
    srand((unsigned)time(&t));

    int *arr = (int *)malloc(100000 * sizeof(long));

    int i;
    for (i = 0; i < 100000; i++)
    {
        *(arr + i) = i + 1;
    }

   

    shuffle(arr);

    FILE * fp = fopen("random_numbers.txt", "w");


    for (i = 0; i < 100000; i++)
    {
        fprintf(fp, "%d \n", *(arr + i)); // Storing the shuffled array values into a file
    }

    fclose(fp);
    free(arr);
    return 0;
}