#include <stdio.h>
#include <stdlib.h>

char **names;

void func()
{
    names = (char **)malloc(50 * sizeof(char *));

    int i;
    for (i = 0; i < 50; i++)
    {
        names[i] = (char *)malloc(100 * sizeof(char));
    }

    for (i = 0; i < 50; i++)
    {
        printf("\nEnter the name of %d th student: ");
        fflush(stdin);
        gets(names[i]);
    }
}

int main()
{
    return 0;
}