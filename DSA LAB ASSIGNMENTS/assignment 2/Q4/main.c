#include "adtset.h"

int main() {
    Set s=Initialize_Set(), s2=Initialize_Set(), s3=Initialize_Set();
    int choice, val, temp;

     do{
   printf("\n\n1. Insert element into First set\n2. Insert element into Second set\n3. Delete element in first set\n4. Delete element in second set\n5. Union of two sets\n6. Intersection of two sets\n7. Print first set\n8. Print second set\n9. First set contains value\n10. Second set contains value\n0. exit\n\nENTER YOUR CHOICE: ");
    scanf("%d", &choice);

    if(!choice){
      break;
    }

    switch (choice)
    {
    case 1:
      printf("\nEnter the value to insert: ");
      scanf("%d", &val);
       Insert_Element_In_Set(&s, val);
      break;
    case 2:
         printf("\nEnter the value to insert: ");
      scanf("%d", &val);
       Insert_Element_In_Set(&s2, val);
      break;  
    case 3:
       printf("\nEnter the value to delete: ");
      scanf("%d", &val);
       Delete_Element_In_Set(&s, val);
      break; 
    case 4:
        printf("\nEnter the value to delete: ");
      scanf("%d", &val);
       Delete_Element_In_Set(&s2, val);
      break;  
    case 5:
     s3 = Union_Of_Sets(s, s2);
     printf("\nThe set after union: ");
     Print_Set(s3);
      break; 
    case 6:
     s3 = Intersection_Of_Sets(s, s2);
     printf("\nThe set after intersection: ");
     Print_Set(s3);
      break;

    case 7:
     Print_Set(s);
      break; 
    case 8:
     Print_Set(s2);
      break;  

    case 9:
         printf("\nEnter the value to find: ");
      scanf("%d", &val);
     temp = Set_Contains(s, val);
        if(temp){
            printf("\nElement found in set");
        }else{
            printf("\nElement not found!!");
        }
      break;   
    case 10:
         printf("\nEnter the value to find: ");
      scanf("%d", &val);
     temp = Set_Contains(s2, val);
        if(temp){
            printf("\nElement found in set");
        }else{
            printf("\nElement not found!!");
        }
      break;            
    default:
      break;
    }
  }while(1);
    return 0;
}