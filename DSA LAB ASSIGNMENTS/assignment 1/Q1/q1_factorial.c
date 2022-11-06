#include <stdio.h>

long long iterativeFact(long long n) { // ITERATIVE FUNCTION FOR FACTORIAL
    long long i;

    if (n<0){
        return -1;
    }else if(n==0 || n==1) { // Factorial of 0 or 1 is equal to 1
        return 1;
    }

    long long fact=1;

    for ( i = 1; i <= n; i++)
    {
        fact = fact*i;
        // Factorial calculation iteratively
    }

    return fact;
    
}

long long recursiveFact(long long n) { // RECURSIVE FUNCTION FOR FACTORIAL
    if (n < 0){
        return -1;
    }else if(n==0 || n==1) {  // Base case of recursion
        return 1;
    }

    return n*recursiveFact(n-1); // Recursive function call
}

void main() {

    long long n;
    printf("Enter the value of n: ");
    scanf("%lld", &n);

    long long result = iterativeFact(n);

    printf("\niteration factorial: %lld", result); // iterative factorial

    long long result2 = recursiveFact(n);

     printf("\nrecursion factorial: %lld", result2); // recursive factorial


}