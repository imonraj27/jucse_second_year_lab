#include <stdio.h>

long iterativeFib(long n) { // ITRERATIVE FUNCTION FOR FIBONACCI
    long i;
    
    if(n<1){
        return -1;
    } else if(n==1 || n==2) {
        return 1;
    }

    long prev=1;
    long before=1;
    long sum=0;

    for ( i = 3; i <= n; i++)
    {
        sum = prev+before;
         before = prev;
        prev = sum;
    }
    
    return sum;
    
}

long recursiveFib(long n) { // RECURSIVE FUNCTION FOR FIBONACCI
      if(n<1){
        return -1;
    } else if(n==1 || n==2) {
        return 1;
    }

    return recursiveFib(n-1)+recursiveFib(n-2); // RECURSIVE FUNCTION CALLS
}

void main() {
    long n;
    printf("Enter the value of n(to find nTH fib number): ");
    scanf("%ld", &n);

    long res = iterativeFib(n);
     printf("\nIterative Fib Number: %ld", res);

    long res2 = recursiveFib(n);
    printf("\nRecursive Fib Number: %ld", res2);


}