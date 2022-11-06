#include "doublylinkedlist.h"

DLLNode *Build_list()
{
    printf("\nHow many elements: ");
    int n;
    scanf("%d", &n);

    printf("\nEnter elements of the list: ");
    DLLNode *head = init_l();
    int val;
    scanf("%d", &val);
    head = createDLLnode(val);

    DLLNode *ptr = head;
    while (n > 1)
    {
        scanf("%d", &val);

        DLLNode *newDLLNode = createDLLnode(val);
        insert_after(newDLLNode, ptr);
        ptr = ptr->next;

        n--;
    }

    return head;
}

void print_list_in_reverse(DLLNode *head)
{ // this is the function for printing the list in reverse
    if (head == NULL)
    {
        return;
    }
    print_list_in_reverse(head->next);
    printf("%d-->", head->data);
}

int size_of_list(DLLNode *head)
{
    DLLNode *ptr = head;
    if (ptr == NULL)
    {
        return 0;
    }

    int count = 0;

    while (ptr != NULL)
    {
        count++;
        ptr = ptr->next;
    }

    return count;
}

DLLNode *delete_nth_DLLnode(DLLNode **phead, int n)
{
    int i;
    DLLNode *temp, *ptr;
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
        if ((temp = ptr->next) == NULL)
        {
            printf("\nInvalid n!!");
            return NULL;
        }

        ptr = temp;
    }

    return delete_after(ptr);
}

DLLNode *delete_last_DLLnode(DLLNode *head)
{
    DLLNode *temp;
    if (head == NULL)
    {
        printf("\nThe list is empty!!");
        return NULL;
    }

    if (atend_l(head))
    {
        return head;
    }

    temp = head;

    while (!atend_l(temp))
    {
        head = temp;
        temp = temp->next;
    }

    return delete_after(head);
}

int isList_ordered(DLLNode *head)
{
    int ascending = 0, descending = 0, ordered = 1;

    DLLNode *ptr = head, *ptr_later = head->next;

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
    } while (!atend_l(ptr));

    return ordered;
}

void Reverse_list(DLLNode **phead)
{
    DLLNode *current, *temp;

    current = (*phead);
    while (!atend_l(current))
    {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    }

    current->next = current->prev;
    current->prev = NULL;
    (*phead) = temp;
}

void sort_list(DLLNode **phead)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }
    int temp;
    DLLNode *ptr1 = *phead;
    DLLNode *ptr2 = (*phead)->next;

    while (ptr1 != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr2->data < ptr1->data)
            {
                temp = ptr2->data;
                ptr2->data = ptr1->data;
                ptr1->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

void swap_element_pairwise(DLLNode **phead)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }
    int temp;
    DLLNode *ptr1 = *phead;
    DLLNode *ptr2 = (*phead)->next;

    while (ptr2 != NULL)
    {
        temp = ptr2->data;
        ptr2->data = ptr1->data;
        ptr1->data = temp;

        ptr1 = ptr1->next->next;
        if (ptr2->next == NULL)
        {
            break;
        }
        ptr2 = ptr2->next->next;
    }
}

void delete_alternate_DLLnode(DLLNode **phead)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }
    int temp;
    DLLNode *ptr1 = *phead;

    while (ptr1 != NULL && !atend_l(ptr1))
    {
        delete_after(ptr1);
        ptr1 = ptr1->next;
    }
}

void insert_before(DLLNode **phead, int val, int val2)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }

    DLLNode *ptr1 = *phead;
    DLLNode *ptr2 = ptr1->next;
    DLLNode *newDLLNode = createDLLnode(val);

    while (ptr2 != NULL)
    {
        if (ptr1->next->data == val2)
        {
            insert_after(newDLLNode, ptr1);
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr1->next;
    }
}

void insert_last(DLLNode **phead, int val)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }

    DLLNode *ptr1 = *phead;
    DLLNode *newDLLNode = createDLLnode(val);

    while (!atend_l(ptr1))
    {
        ptr1 = ptr1->next;
    }

    insert_after(newDLLNode, ptr1);
}

void move_last_to_first(DLLNode **phead)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }

    DLLNode *ptr1 = *phead;

    while (!atend_l(ptr1))
    {
        ptr1 = ptr1->next;
    }

    ptr1->prev->next = NULL;
    ptr1->prev = NULL;
    ptr1->next = (*phead);
    (*phead)->prev = ptr1;
    *phead = ptr1;
}

void check_equal_lists(DLLNode *h1, DLLNode *h2)
{
    if (h1 == NULL || h2 == NULL)
    {
        printf("\nThe lists are not equal..");
        return;
    }

    DLLNode *ptr1 = h1, *ptr2 = h2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data != ptr2->data)
        {
            printf("\nNot equal lists...");
            return;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    if (ptr1 == NULL && ptr2 == NULL)
    {
        printf("\nEqual lists...");
    }
    else
    {
        printf("\nNot equal lists...");
    }
}

void append_second_after_first(DLLNode *h1, DLLNode *h2)
{
    if (h1 == NULL)
    {
        printf("\nThe first list is empty...");
        return;
    }

    DLLNode *ptr = h1;
    while (!atend_l(ptr))
    {
        ptr = ptr->next;
    }

    ptr->next = h2;
}
DLLNode *mergeLinkedList(DLLNode *head1, DLLNode *head2)
{
    DLLNode *resultHead, *resultTail, *temp;
    resultHead = resultTail = NULL;
    while (1)
    {
        /* */
        if (head1 == NULL)
        {
            resultTail->next = head2;
            break;
        }

        if (head2 == NULL)
        {
            resultTail->next = head1;
            break;
        }

        /* Check whether current DLLnode of 
        which Linked list is smaller*/
        if (head1->data <= head2->data)
        {
            temp = head1;
            head1 = head1->next;
        }
        else
        {
            temp = head2;
            head2 = head2->next;
        }
        /*Add smaller DLLnode to result linked list  */
        if (resultHead == NULL)
        {
            resultHead = resultTail = temp;
        }
        else
        {
            resultTail->next = temp;
            resultTail = temp;
        }
        resultTail->next = NULL;
    }

    return resultHead;
}

int main()
{
    int choice, n, val, val2;
    DLLNode *head = Build_list();
    DLLNode *ptr, *head2, *newDLLNode;

    do
    {
        printf("\n1. Print List in Same order\n2. Print list in reverse order\n3. Find Size of list\n4. Delete nth DLLnode\n5. Delete Last DLLNode\n6. Delete first DLLnode\n7. Check if list is ordered\n8. Delete a list\n9. Reverse a list\n10. Sort a list\n11. Swap elements pairwise\n12. Move last element to front of list\n13. Delete alternate DLLnode of a list\n14. Insert DLLNode at begining\n15. Insert before a specified DLLnode\n16. Insert at end\n0. EXIT THE LOOP\n\nENTER YOUR CHOICE: ");
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
            print_list_in_reverse(head);
            break;
        case 3:
            printf("\nSize of list is: %d", size_of_list(head));
            break;
        case 4:
            printf("\nEnter the DLLnode number to delete: ");
            scanf("%d", &n);
            ptr = delete_nth_DLLnode(&head, n);
            free(ptr);
            break;
        case 5:
            ptr = delete_last_DLLnode(head);
            free(ptr);
            break;
        case 6:
            ptr = delete_nth_DLLnode(&head, 1);
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
            delete_alternate_DLLnode(&head);
            break;
        case 14:
            printf("\nEnter the value to insert: ");
            scanf("%d", &val);
            newDLLNode = createDLLnode(val);
            insert_front(newDLLNode, &head);
            break;
        case 15:
            printf("\nEnter the DLLnode value to insert before that: ");
            scanf("%d", &val2);
            printf("\nEnter the new DLLnode value: ");
            scanf("%d", &val);
            insert_before(&head, val, val2);
            break;
        case 16:
            printf("\nEnter the new DLLnode value: ");
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
        printf("\n\n1. Check two lists are equal?\n2. Append second list after first list\n3. Merge the two sorted lists\n0. EXIT\n\nEnter your choice: ");
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
        case 3:
            ptr = mergeLinkedList(head, head2);
            print_l(head);
            head2 = NULL;
            break;
        default:
            break;
        }
    } while (1);

    return 0;
}