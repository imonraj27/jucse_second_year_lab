#include "adtlist.h"

int main()
{
    LIST L = NULL;
    POSITION P;
    int a, choice, ch, element;

    do
    {
        printf("\n1. Create List\n2. Insert into List\n3. Delete from List\n4. Display List\n5. Make empty\n6. Find in List\n7. Is Empty\n8. Is full\n9. Delete List\n10 Exit\n\nEnter your choice: ");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (L == NULL)
                L = Createlist(5);
            else
                printf("\nList is already created");
            break;
        case 2:
            if (L == NULL)
                printf("\nList is not yet created");
            else
            {
                printf("\nEnter the Element to insert:\t");
                scanf("%d", &element);
                if (L->size == 0)
                    Insert(element, L, 0);

                else
                {
                    printf("\n where u want to insert?\t1:Front\t2:Back\t3:middle\t::: ");
                    scanf("%d", &ch);
                    if (ch == 1)
                        Insert(element, L, 0);
                    else if (ch == 2)
                        Insert(element, L, L->size);
                    else if (ch == 3)
                    {
                        printf("\nBefore which element want to insert:\t");
                        scanf("%d", &a);
                        P = Find(a, L);
                        if (P != -1)
                            Insert(element, L, P);
                        else
                            printf("\nElement is not in the list");
                    }
                    else
                        printf("\n Ur choice is not available");
                }
            }
            break;
        case 3:
            if (L == NULL)
                printf("\nList is not yet created");
            if (Isempty(L))
                printf("\nList is empty");
            else
            {
                printf("\nEnter the element to delete:\t");
                scanf("%d", &a);
                Delete(a, L);
            }
            break;
        case 4:
            if (L == NULL)
                printf("\nList is not yet created");
            else if (Isempty(L))
                printf("\nList is empty");
            else
            {
                printf("\nElements present in the list are:");
                Display(L);
            }
            break;
        case 5:
            if (L == NULL)
                printf("\n List is not yet created ");

            else
                MakeEmpty(L);
            break;
        case 6:
            if (L == NULL)
                printf("\n Not yet created");
            else if (Isempty(L))
                printf("\n List is empty");
            else
            {
                printf("\n which element is to find:\t");
                scanf("%d", &a);
                if (Find(a, L) != -1)
                {
                    printf("\nElement found");
                }
                else
                {
                    printf("\nElement not Found!!!!");
                }
            }
            break;
        case 7:
            if (L == NULL)
                printf("\n Not yet created");
            else if (Isempty(L))
                printf("\n List is empty");
            else
                printf("\n List is not empty");
            break;
        case 8:
            if (L == NULL)
                printf("\n Not yet created");
            else if (Isfull(L))
                printf("\n List is FULL");
            else
                printf("\n List is not FULL");
            break;
        case 9:
            if (L == NULL)
                printf("\n Not yet created");
            else
            {
                L = Deletelist(L);
                printf("\n List is Deleted");
            }
            break;
        case 10:
            exit(0);
            break;
        default:
            printf("\n\n *******WRONG ENTRY*******");
            break;
        }
    } while (1);
}