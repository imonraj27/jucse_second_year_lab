#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define number_of_keywords 6

/*
---------- KEYWORDS LIST -----------|
 .                                  |
there                               |
this                                |
is                                  |
new                                 |
our                                 |
and                                 |
 .                                  |
------------------------------------|
*/

int keywords_count[number_of_keywords];

FILE *renew;

void make_inverted_index(char *filename, char **keywords)
{
    FILE *fp = fopen(filename, "r");
    FILE *fp2 = fopen("inv_index.txt", "a");
    int i;

    if (!fp || !fp2)
        printf("\nFile doesn't exist");

    char str[20];

    for (i = 0; i < number_of_keywords; i++)
    {
        keywords_count[i] = 0;
    }

    while (!feof(fp))
    {
        fscanf(fp, "%s", str);
        for (i = 0; i < number_of_keywords; i++)
        {
            if (strcmp(str, keywords[i]) == 0)
            {
                keywords_count[i]++;
            }
        }
    }

    fprintf(fp2, "\n\n\nFOR FILE %s ::---", filename);
    for (i = 0; i < number_of_keywords; i++)
    {
        fprintf(fp2, "\n%s - %d", keywords[i], keywords_count[i]);
    }

    fclose(fp);
    fclose(fp2);
}

int main()
{

    char **keywords = (char **)malloc(number_of_keywords * sizeof(char *));

    int i;
    for (i = 0; i < number_of_keywords; i++)
    {
        keywords[i] = (char *)malloc(10 * sizeof(char));
    }

    for (i = 0; i < number_of_keywords; i++)
    {
        printf("\nEnter the %dth keyword: ", i + 1);
        fflush(stdin);
        gets(keywords[i]);
    }

    renew = fopen("inv_index.txt", "w");
    fclose(renew);

    make_inverted_index("f1.txt", keywords);
    make_inverted_index("f2.txt", keywords);
    make_inverted_index("f3.txt", keywords);
    make_inverted_index("f4.txt", keywords);
    make_inverted_index("f5.txt", keywords);
    make_inverted_index("f6.txt", keywords);

    for (i = 0; i < number_of_keywords; i++)
    {
        free(keywords[i]);
    }

    free(keywords);
}