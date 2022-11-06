#include <stdio.h>
#include "polynomial.h"

int main()
{
  Polynomial p, p2, p3;
  int choice;

  do
  {
    printf("\n1. Input first polynomial value\n2. Input second polynomial value\n3. Add Polynomials\n4. Subtract polynomials\n5. Multiply polynomials\n0. EXIT.....\n\nENTER CHOICE: ");
    scanf("%d", &choice);

    if (!choice)
    {
      break;
    }

    switch (choice)
    {
    case 1:
      p = Take_Polynomial();
      break;
    case 2:
      p2 = Take_Polynomial();
      break;
    case 3:
      p3 = Add_Polynomials(p, p2);
      printf("\nThe polynomial after addition is: ");
      Print_polynomial(p3);
      break;
    case 4:
      p3 = Subtract_Polynomials(p, p2);
      printf("\nThe polynomial after subtraction is: ");
      Print_polynomial(p3);
      break;
    case 5:
      p3 = Multiply_Polynomials(p, p2);
      printf("\nThe polynomial after multiplication is: ");
      Print_polynomial(p3);
      break;
    default:
      break;
    }
  } while (1);

  return 0;
}