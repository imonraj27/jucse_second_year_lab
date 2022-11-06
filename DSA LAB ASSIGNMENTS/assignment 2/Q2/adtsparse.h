#include <stdio.h>
#include <stdlib.h>

#ifndef adtsparse

#define MAX1 3
#define MAX2 3
typedef struct sparsetype
{
    int *sp;
    int row;
} sparse;
void init(sparse *p)
{
    p->sp = NULL;
}
void creat_array(sparse *p)
{
    int i, n;
    p->sp = (int *)malloc(MAX1 * MAX2 * sizeof(int));
    for (i = 0; i < MAX1 * MAX2; i++)
    {
        printf("Enter the elements no. %d : ", i);
        scanf("%d", &n);
        *(p->sp + i) = n;
    }
    printf("\n");
}
void display(sparse p)
{
    int i;
    for (i = 0; i < MAX1 * MAX2; i++)
    {
        if (i % MAX2 == 0)
            printf("\n");
        printf("%d ", p.sp[i]);
    }

    printf("\n\n");
}
int count(sparse p)
{
    int count = 0, i;
    for (i = 0; i < MAX1 * MAX2; i++)
    {
        if (p.sp[i] != 0)
            count++;
    }
    return count;
}
void creat_tuple(sparse *p, sparse s)
{
    int r = 0, c = -1, l = -1, i;
    p->row = count(s) + 1;
    p->sp = (int *)malloc(p->row * 3 * sizeof(int));
    p->sp[0] = MAX1;
    p->sp[1] = MAX2;
    p->sp[2] = p->row - 1;
    l = 2;
    for (i = 0; i < MAX1 * MAX2; i++)
    {
        c++;
        if (i % MAX2 == 0 && i != 0)
        {
            r++;
            c = 0;
        }
        if (s.sp[i] != 0)
        {
            l++;
            p->sp[l] = r;
            l++;
            p->sp[l] = c;
            l++;
            p->sp[l] = s.sp[i];
        }
    }
}
void display_tuple(sparse p)
{
    int i;
    for (i = 0; i < p.row * 3; i++)
    {
        if (i % 3 == 0)
            printf("\n");
        printf("%d\t", p.sp[i]);
    }
}
void delsparse(sparse *p)
{
    free(p->sp);
}
void transpose(sparse *p, sparse s)
{
    int x, q, pos_1, pos_2, col, elem, c, y;
    p->sp = (int *)malloc(s.row * 3 * sizeof(int));
    p->row = s.row;

    p->sp[0] = s.sp[1];
    p->sp[1] = s.sp[0];
    p->sp[2] = s.sp[2];
    col = p->sp[1];
    elem = p->sp[2];
    if (elem <= 0)
        return;
    x = 1;
    for (c = 0; c < col; c++)
    {
        for (y = 1; y <= elem; y++)
        {
            q = y * 3 + 1;
            if (s.sp[q] == c)
            {
                pos_2 = x * 3 + 0;
                pos_1 = y * 3 + 1;
                p->sp[pos_2] = s.sp[pos_1];
                pos_2 = x * 3 + 1;
                pos_1 = y * 3 + 0;
                p->sp[pos_2] = s.sp[pos_1];
                pos_2 = x * 3 + 2;
                pos_1 = y * 3 + 2;
                p->sp[pos_2] = s.sp[pos_1];
                x++;
            }
        }
    }
}

#define adtsparse
#endif