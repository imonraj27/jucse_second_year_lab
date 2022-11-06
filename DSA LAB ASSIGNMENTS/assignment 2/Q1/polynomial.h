#include <stdio.h>
#define MAX_POWER 100

#ifndef polynomial

typedef struct poly
{
    float arr[MAX_POWER + 1]; /*MAXIMUM 100 POWERS POSSIBLE FOR A POLYNOMIAL*/
} Polynomial;

Polynomial Take_Polynomial() /*TAKE THE VALUE OF A POLYNOMIAL*/
{
    Polynomial p;
    int i, choice, power;
    float coeff;
    for (i = 0; i < MAX_POWER + 1; i++)
    {
        p.arr[i] = 0;
    }

    do
    {
        printf("\nEnter the power: ");
        scanf("%d", &power);
        if (power > MAX_POWER)
        {
            printf("\nMax Power Available is %d. Try again...", MAX_POWER);
            choice = 1;
            continue;
        }
        printf("\nEnter the co-efficient of x^%d: ", power);
        scanf("%f", &coeff);
        p.arr[power] = coeff;

        printf("\nTo add one more power term press 1 or 0 to stop: ");
        scanf("%d", &choice);

    } while (choice == 1);

    return p;
}

void Print_polynomial(Polynomial p) /*PRINTS A POLYNOMIAL IN NORMAL READABLE FORMAT*/
{
    int i, flag = 0;
    for (i = MAX_POWER; i >= 0; i--)
    {

        if (p.arr[i] != 0.0)
        {
            if (flag)
            {
                printf(" + ");
            }
            if (p.arr[i] != 1 && p.arr[i] != (-1))
            {
                printf("%0.3f", p.arr[i]);
            }

            if (i != 0 && i != 1)
            {
                printf("x^%d", i);
            }
            else if (i == 1)
            {
                printf("x");
            }

            flag = 1;
        }
    }
    if (!flag)
    {
        printf(" 0");
    }
}

Polynomial Add_Polynomials(Polynomial p1, Polynomial p2) /*ADDS TWO POLYNOMIALS*/
{
    Polynomial p3;
    int i;
    for (i = 0; i < MAX_POWER + 1; i++)
    {
        p3.arr[i] = p1.arr[i] + p2.arr[i];
    }

    return p3;
}

Polynomial Subtract_Polynomials(Polynomial p1, Polynomial p2) /*SUBTRACTION OF TWO POLYNOMIALS*/ 
{
    Polynomial p3;
    int i;
    for (i = 0; i < MAX_POWER + 1; i++)
    {
        p3.arr[i] = p1.arr[i] - p2.arr[i];
    }

    return p3;
}

Polynomial Multiply_Polynomials(Polynomial p, Polynomial q) /*MULTIPLY TWO POLYNOMIALS*/
{
    Polynomial result;
    int i, j, out_of_range=0;
    float mult;
      for (i = 0; i < MAX_POWER + 1; i++)
    {
        result.arr[i] = 0;
    }
    for (i = 0; i < MAX_POWER + 1; i++)
    {
        if(p.arr[i]==0.0){
            continue;
        }
        for (j = 0; j < MAX_POWER + 1; j++)
        {
            if(q.arr[j]==0.0){
                continue;
            }
            if((i+j)>100) {
                printf("\nPower after multply is out of range..");
                out_of_range=1;
                break;
            }
            mult = (p.arr[i])*(q.arr[j]);
            result.arr[i+j] += mult;
        }
        if(out_of_range){
            break;
        }
    }

    return result;
}

#define polynomial
#endif