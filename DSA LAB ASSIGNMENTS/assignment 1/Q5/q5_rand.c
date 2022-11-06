#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main()
{
    time_t t;
    srand((unsigned)time(&t));

    int i, j;

    FILE * fp = fopen("random_string.txt", "w");

    for (j = 0; j < 100000; j++) // This loop is for each line of random strings
    {
        for (i = 0; i < 10; i++) // THis loop is for each letter of one random stirng
        {
            fprintf(fp, "%c", 65 + (rand() % 26)); // A has ASCII value 65 and so on
        }
        fprintf(fp, "\n");
    }

    fclose(fp);

    return 0;
}