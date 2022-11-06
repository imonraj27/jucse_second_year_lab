/* 5.	Write a function that will have income and tax rate as arguments 
and will return tax amount. In case tax rate is not provided it will be
 automatically taken as 10%. Call it with and without tax rate. */


#include <iostream>

using namespace std;

float taxVal(int income, float taxrate = 10.00) { // function to find out tax amount
    return income*taxrate/100;
}


int main() {
   int income;
   cout << "Enter the amount of income: ";
   cin >> income;

   float tax = taxVal(income); // passing one argument and other value will be default

   cout << "\nWhen tax rate default 10% Tax = " << tax;

   cout << "\n----------Second Part------------------";
   cout << "\nEnter preferable tax amout: ";
   int tax_rate;
   cin >> tax_rate;

   tax = taxVal(income, tax_rate); // passing both parameters
   cout << "\nWhen tax rate " << tax_rate << "% Tax = " << tax;

   return 0;
}