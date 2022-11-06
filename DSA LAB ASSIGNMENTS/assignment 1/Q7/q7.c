#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long generateLargeInt() // large integer generation function
{
    long long large = (rand() % 9)+1; // To maintain the large integer length first digit should be 1 to 9

    for (int i = 0; i < 11; i++)
    {
        large = large * 10 + (rand() % 10); // generating digits 0-9 and appending to large int
    }

    return large;
}

int main()
{

    time_t t;
    srand((unsigned)time(&t));

    //Randomly taken four digit prime numbers
    int i, j, primes[8] = {1153, 2371, 3011, 4013, 5023, 6607, 7129, 7919};

    printf("Large Numbers\t");
    for (i = 0; i < 8; i++)
    {
        printf("%d\t", primes[i]);
    }
    printf("\n\n");

    int numberOfLargeInts = 5;
    long long remainder, large;
    for (i = 0; i < numberOfLargeInts; i++)
    {
        large = generateLargeInt();
        printf("%lld\t", large);
        for (j = 0; j < 8; j++)
        {
            remainder = large % primes[j]; // Finding the remainder
            printf("%lld\t", remainder);
        }
        printf("\n");
        large = 0;
    }

    return 0;
}