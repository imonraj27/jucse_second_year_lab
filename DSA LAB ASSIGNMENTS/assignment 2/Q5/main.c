#include "adtstring.h"


int main() {
    String s, s2, s3;
    int leng, temp;
    int choice;

  do{
   printf("\n\n1. Enter a string\n2. Convert to uppercase\n3. Convert to lowercase\n4. Find string length\n5. Print the string\n0. exit\n\nENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    if(!choice){
      break;
    }

    switch (choice)
    {
    case 1:
        printf("\nEnter the string value: ");
        fflush(stdin);
        s = take_string();
      break;
    case 2:
      s = into_uppercase(s);
      printf("\nThe string in uppercase is: ");
      print_string(s);
      break;  
    case 3:
       s = into_lowercase(s);
      printf("\nThe string in lowercase is: ");
      print_string(s);
      break; 
    case 4:
        leng = length_string(s);
        printf("The string length: %d", leng);
      break;  
    case 5:
      printf("\nThe string is : ");
      print_string(s);
      break;  
    default:
      break;
    }
  }while(1);


  do{
   printf("\n\n1. Enter the first string\n2. Enter the second string\n3. Copy second string to first string\n4. Concat strings\n5. Compare two strings\n0. exit\n\nENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    if(!choice){
      break;
    }

    switch (choice)
    {
    case 1:
        printf("\nEnter the first string value: ");
        fflush(stdin);
        s = take_string();
      break;
    case 2:
         printf("\nEnter the second string value: ");
        fflush(stdin);
        s2 = take_string();
      break;  
    case 3:
       s = copy_string(s2);
        printf("\nSuccessfully copied");
      break; 
    case 4:
        s3 = concat_string(s, s2);
        printf("\nThe string after concatenation will be: ");
        print_string(s3);
      break;  
    case 5:
      temp = compare_string(s, s2);
      if(temp==0){
          printf("\nEqual strings");
      }else if(temp == 1){
          printf("\nFirst string larger");
      }else{
          printf("\nSecond string larger");
      }
      break;  
    default:
      break;
    }
  }while(1);
    return 0;
}