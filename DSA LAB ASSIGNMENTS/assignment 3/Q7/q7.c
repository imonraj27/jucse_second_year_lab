#include <stdio.h>
#include <string.h>
#define MAX_SIZE 80

typedef struct number
{
    short arr[MAX_SIZE];
} Number;

Number init_number()
{
    Number n;
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        n.arr[i] = 0;
    }
    return n;
}

Number take_number()
{
    Number n = init_number();
    printf("Enter Number: ");
    char str[MAX_SIZE];
    fflush(stdin);
    gets(str);
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++)
    {
        n.arr[MAX_SIZE - len + i] = (short)(str[i]) - 48;
    }

    return n;
}

Number add_numbers(Number n1, Number n2)
{
    int i, rem = 0;
    Number out = init_number();
    for (i = MAX_SIZE - 1; i >= 0; i--)
    {
        out.arr[i] = n1.arr[i] + n2.arr[i] + rem;
        rem = out.arr[i] / 10;
        out.arr[i] %= 10;
    }

    return out;
}

void print_number(Number n)
{
    int i;
    for (i = 0; i < MAX_SIZE; i++)
    {
        if (n.arr[i] != 0)
        {
            printf("%d", n.arr[i]);
        }
    }
}

int main()
{
    Number n1 = take_number();
    Number n2 = take_number();
    Number n = add_numbers(n1, n2);
    printf("\nSum: ");
    print_number(n);
}