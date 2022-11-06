 /* 1. Write a program that will have an integer variable 
and a pointer (say, p) pointing to it. Also have a pointer
 to pointer pointing to p. Take the value for the integer
  variable and print it using p, and pp.*/




#include <stdio.h>
#include <conio.h>

int main() {
    //Declaring the pointers and integer
    int n;
    int * p = NULL; //pointer to integer
    int ** pp = NULL; //pointer to pointer to integer

    printf("Enter the value of integer n: ");
    scanf("%d", &n); //Taking the value of the integer in n

    p = &n;
    pp = &p;

    //Printng using the pointers
    printf("The value of n using p is %d\n", *p);
    printf("The value of n using pp is %d\n", **pp);
    return 0;
}