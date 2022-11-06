#include "circularlinkedlist.h"

CLLNode *Build_list()
{
    printf("\nHow many elements: ");
    int n;
    scanf("%d", &n);

    printf("\nEnter the elements of the list: ");
    CLLNode *head = init_l();
    int val;
    scanf("%d", &val);
    head = createCLLNode(val);

    CLLNode *ptr = head;
    while (n > 1)
    {
        scanf("%d", &val);
        CLLNode *newCLLNode = createCLLNode(val);
        insert_after(newCLLNode, ptr);
        ptr = ptr->next;

        n--;
    }

    return head;
}

void print_list_in_reverse(CLLNode *head, CLLNode *ptr)
{ // this is the function for printing the list in reverse
    if (ptr->next == head)
    {
        printf("%d-->", ptr->data);
        return;
    }
    print_list_in_reverse(head, ptr->next);
    printf("%d-->", ptr->data);
}

int size_of_list(CLLNode *head)
{
    CLLNode *ptr = head;
    if (ptr == NULL)
    {
        return 0;
    }

    int count = 0;

    while (ptr->next != head)
    {
        count++;
        ptr = ptr->next;
    }

    return count + 1;
}

CLLNode *delete_nth_CLLNode(CLLNode **phead, int n)
{
    int i;
    CLLNode *temp, *ptr;
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty!!");
        return NULL;
    }

    ptr = *phead;
    if (n == 1)
    {
        return delete_front(phead);
    }
    for (i = 1; i < n - 1; i++)
    {
        if ((temp = ptr->next) == *phead)
        {
            printf("\nInvalid n!!");
            return NULL;
        }

        ptr = temp;
    }

    return delete_after(ptr, phead);
}

CLLNode *delete_last_CLLNode(CLLNode **phead)
{
    int size = size_of_list(*phead);
    return delete_nth_CLLNode(phead, size);
}

int isList_ordered(CLLNode *head)
{
    int ascending = 0, descending = 0, ordered = 1;

    CLLNode *ptr = head, *ptr_later = head->next;

    if (!ptr_later)
    {
        return 1;
    }

    do
    {
        if (ptr->data > ptr_later->data)
        {
            descending = 1;
        }
        else if (ptr->data < ptr_later->data)
        {
            ascending = 1;
        }

        if (ascending * descending)
        {
            ordered = 0;
            break;
        }

        ptr = ptr->next;
        ptr_later = ptr_later->next;
    } while (!atend_l(ptr, head));

    return ordered;
}

void Reverse_list(CLLNode **phead)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }
    CLLNode *previous = NULL;
    CLLNode *current = *phead;
    CLLNode *later = *phead;

    do
    {
        later = current->next;
        current->next = previous;
        previous = current;
        current = later;
    } while (current != *phead);

    current->next = previous;
    *phead = previous;
}

void sort_list(CLLNode **phead)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }
    int temp;
    CLLNode *ptr1 = *phead;
    CLLNode *ptr2 = (*phead)->next;

    do
    {
        ptr2 = ptr1->next;

        do
        {
            if (ptr2->data < ptr1->data)
            {
                temp = ptr2->data;
                ptr2->data = ptr1->data;
                ptr1->data = temp;
            }
            ptr2 = ptr2->next;
        } while (ptr2 != *phead);
        ptr1 = ptr1->next;
    } while (!atend_l(ptr1, *phead));
}

void swap_element_pairwise(CLLNode **phead)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }
    int temp;
    CLLNode *ptr1 = *phead;
    CLLNode *ptr2 = (*phead)->next;

    do
    {
        temp = ptr2->data;
        ptr2->data = ptr1->data;
        ptr1->data = temp;

        ptr1 = ptr1->next->next;
        ptr2 = ptr2->next->next;
    } while (ptr1 != *phead && ptr2 != *phead);
}

void delete_alternate_CLLNode(CLLNode **phead)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }
    int temp;
    CLLNode *ptr1 = *phead;

    do
    {
        delete_after(ptr1, phead);
        ptr1 = ptr1->next;
    } while (ptr1 != *phead && !atend_l(ptr1, *phead));
}

void insert_before(CLLNode **phead, int val, int val2)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }

    CLLNode *ptr1 = *phead;
    CLLNode *ptr2 = ptr1->next;
    CLLNode *newCLLNode = createCLLNode(val);

    do
    {
        if (ptr1->next->data == val2)
        {
            insert_after(newCLLNode, ptr1);
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr1->next;
    } while (ptr2 != *phead);
}

void insert_last(CLLNode **phead, int val)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }

    CLLNode *ptr1 = *phead;
    CLLNode *newCLLNode = createCLLNode(val);

    while (!atend_l(ptr1, *phead))
    {
        ptr1 = ptr1->next;
    }

    insert_after(newCLLNode, ptr1);
}

void move_last_to_first(CLLNode **phead)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }

    CLLNode *ptr1 = *phead;

    while (!atend_l(ptr1, *phead))
    {
        ptr1 = ptr1->next;
    }

    *phead = ptr1;
}

void check_equal_lists(CLLNode *h1, CLLNode *h2)
{
    if (h1 == NULL || h2 == NULL)
    {
        printf("\nThe lists are not equal..");
        return;
    }

    CLLNode *ptr1 = h1, *ptr2 = h2;
    do
    {
        if (ptr1->data != ptr2->data)
        {
            printf("\nNot equal lists...");
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    } while (ptr1 != h1 && ptr2 != h2);

    if (ptr1 == h1 && ptr2 == h2)
    {
        printf("\nEqual lists...");
    }
    else
    {
        printf("\nNot equal lists...");
    }
}

void append_second_after_first(CLLNode *h1, CLLNode *h2)
{
    if (h1 == NULL)
    {
        printf("\nThe first list is empty...");
        return;
    }

    CLLNode *ptr = h1;
    while (!atend_l(ptr, h1))
    {
        ptr = ptr->next;
    }

    ptr->next = h2;

    ptr = h2;

    while (!atend_l(ptr, h2))
    {
        ptr = ptr->next;
    }

    ptr->next = h1;
}

int main()
{
    int choice, n, val, val2;
    CLLNode *head = Build_list();
    CLLNode *ptr, *head2, *newCLLNode;

    do
    {
        printf("\n1. Print List in Same order\n2. Print list in reverse order\n3. Find Size of list\n4. Delete nth CLLNode\n5. Delete Last CLLNode\n6. Delete first CLLNode\n7. Check if list is ordered\n8. Delete a list\n9. Reverse a list\n10. Sort a list\n11. Swap elements pairwise\n12. Move last element to front of list\n13. Delete alternate CLLNode of a list\n14. Insert CLLNode at begining\n15. Insert before a specified CLLNode\n16. Insert at end\n0. EXIT THE LOOP\n\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            delete_l(&head);
            break;
        }

        switch (choice)
        {
        case 1:
            printf("\nThe list in order is: ");
            print_l(head);
            break;

        case 2:
            printf("\nThe list in reverse order is: ");
            print_list_in_reverse(head, head);
            break;
        case 3:
            printf("\nSize of list is: %d", size_of_list(head));
            break;
        case 4:
            printf("\nEnter the CLLNode number to delete: ");
            scanf("%d", &n);
            ptr = delete_nth_CLLNode(&head, n);
            free(ptr);
            break;
        case 5:
            ptr = delete_last_CLLNode(&head);
            free(ptr);
            break;
        case 6:
            ptr = delete_nth_CLLNode(&head, 1);
            free(ptr);
            break;
        case 7:
            if (isList_ordered(head))
            {
                printf("\nThe list is ordered...");
            }
            else
            {
                printf("\nNO, The list is not ordered...");
            }
            break;
        case 8:
            delete_l(&head);
            printf("\nThe list has been deleted");
            break;
        case 9:
            Reverse_list(&head);
            break;
        case 10:
            sort_list(&head);
            break;
        case 11:
            swap_element_pairwise(&head);
            break;
        case 12:
            move_last_to_first(&head);
            break;
        case 13:
            delete_alternate_CLLNode(&head);
            break;
        case 14:
            printf("\nEnter the value to insert: ");
            scanf("%d", &val);
            newCLLNode = createCLLNode(val);
            insert_front(newCLLNode, &head);
            break;
        case 15:
            printf("\nEnter the CLLNode value to insert before that: ");
            scanf("%d", &val2);
            printf("\nEnter the new CLLNode value: ");
            scanf("%d", &val);
            insert_before(&head, val, val2);
            break;
        case 16:
            printf("\nEnter the new CLLNode value: ");
            scanf("%d", &val);
            insert_last(&head, val);
            break;
        default:
            delete_l(&head);
            break;
        }
    } while (1);

    printf("\n--------------------Two list operations-------------------- \n");
    printf("\nGIVE THE FIRST LIST\n");
    head = Build_list();
    printf("\nGIVE THE SECOND LIST\n");
    head2 = Build_list();

    do
    {
        printf("\n\n1. Check two lists are equal?\n2. Append second list after first list\n0. EXIT\n\nEnter your choice: ");
        scanf("%d", &choice);
        if (!choice)
        {
            delete_l(&head);
            delete_l(&head2);
            break;
        }

        switch (choice)
        {
        case 1:
            check_equal_lists(head, head2);
            break;
        case 2:
            append_second_after_first(head, head2);
            print_l(head);
            break;
        default:
            break;
        }
    } while (1);

    return 0;
}