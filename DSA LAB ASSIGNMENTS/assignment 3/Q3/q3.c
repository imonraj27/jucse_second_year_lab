#include "linkedlist.h"

Node *Build_list()
{
    printf("\nHow many elements: ");
    int n;
    scanf("%d", &n);

    printf("\nEnter the elements of the list: ");
    Node *head = init_l();
    int val;
    scanf("%d", &val);
    head = createnode(val);

    Node *ptr = head;
    while (n > 1)
    {
        scanf("%d", &val);
        Node *newNode = createnode(val);
        insert_after(newNode, ptr);
        ptr = ptr->next;

        n--;
    }

    return head;
}

void print_list_in_reverse(Node *head)
{ // this is the function for printing the list in reverse
    if (head == NULL)
    {
        return;
    }
    print_list_in_reverse(head->next);
    printf("%d-->", head->data);
}

int size_of_list(Node *head)
{
    Node *ptr = head;
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

Node *delete_nth_node(Node **phead, int n)
{
    int i;
    Node *temp, *ptr;
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

Node *delete_last_node(Node *head)
{
    Node *temp;
    if (head == NULL)
    {
        printf("\nThe list is empty!!");
        return NULL;
    }

    if (atend_l(head))
    {
        return head;
    }

    temp = head->next;

    while (!atend_l(temp))
    {
        head = temp;
        temp = temp->next;
    }

    return delete_after(head);
}

int isList_ordered(Node *head)
{
    int ascending = 0, descending = 0, ordered = 1;

    Node *ptr = head, *ptr_later = head->next;

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

void Reverse_list(Node **phead)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }
    Node *previous = NULL;
    Node *current = *phead;
    Node *later = *phead;

    while (current != NULL)
    {
        later = current->next;
        current->next = previous;
        previous = current;
        current = later;
    }

    *phead = previous;
}

void sort_list(Node **phead)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }
    int temp;
    Node *ptr1 = *phead;
    Node *ptr2 = (*phead)->next;

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

void swap_element_pairwise(Node **phead)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }
    int temp;
    Node *ptr1 = *phead;
    Node *ptr2 = (*phead)->next;

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

void delete_alternate_node(Node **phead)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }
    int temp;
    Node *ptr1 = *phead;

    while (ptr1 != NULL && !atend_l(ptr1))
    {
        delete_after(ptr1);
        ptr1 = ptr1->next;
    }
}

void insert_before(Node **phead, int val, int val2)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }

    Node *ptr1 = *phead;
    Node *ptr2 = ptr1->next;
    Node *newNode = createnode(val);

    while (ptr2 != NULL)
    {
        if (ptr1->next->data == val2)
        {
            insert_after(newNode, ptr1);
            break;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr1->next;
    }
}

void insert_last(Node **phead, int val)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }

    Node *ptr1 = *phead;
    Node *newNode = createnode(val);

    while (!atend_l(ptr1))
    {
        ptr1 = ptr1->next;
    }

    insert_after(newNode, ptr1);
}

void move_last_to_first(Node **phead)
{
    if ((*phead) == NULL)
    {
        printf("\nThe list is empty..\n");
        return;
    }

    Node *ptr1 = *phead, *ptr2;

    while (!atend_l(ptr1))
    {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
    }

    ptr2->next = NULL;
    ptr1->next = (*phead);
    *phead = ptr1;
}

void check_equal_lists(Node *h1, Node *h2)
{
    if (h1 == NULL || h2 == NULL)
    {
        printf("\nThe lists are not equal..");
        return;
    }

    Node *ptr1 = h1, *ptr2 = h2;
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

void append_second_after_first(Node *h1, Node *h2)
{
    if (h1 == NULL)
    {
        printf("\nThe first list is empty...");
        return;
    }

    Node *ptr = h1;
    while (!atend_l(ptr))
    {
        ptr = ptr->next;
    }

    ptr->next = h2;
}
Node *mergeLinkedList(Node *head1, Node *head2)
{
    Node *resultHead, *resultTail, *temp;
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

        /* Check whether current node of 
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
        /*Add smaller node to result linked list  */
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
    Node *head = Build_list();
    Node *ptr, *head2, *newNode;

    do
    {
        printf("\n1. Print List in Same order\n2. Print list in reverse order\n3. Find Size of list\n4. Delete nth node\n5. Delete Last Node\n6. Delete first node\n7. Check if list is ordered\n8. Delete a list\n9. Reverse a list\n10. Sort a list\n11. Swap elements pairwise\n12. Move last element to front of list\n13. Delete alternate node of a list\n14. Insert Node at begining\n15. Insert before a specified node\n16. Insert at end\n0. EXIT THE LOOP\n\nENTER YOUR CHOICE: ");
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
            printf("\nEnter the node number to delete: ");
            scanf("%d", &n);
            ptr = delete_nth_node(&head, n);
            free(ptr);
            break;
        case 5:
            ptr = delete_last_node(head);
            free(ptr);
            break;
        case 6:
            ptr = delete_nth_node(&head, 1);
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
            delete_alternate_node(&head);
            break;
        case 14:
            printf("\nEnter the value to insert: ");
            scanf("%d", &val);
            newNode = createnode(val);
            insert_front(newNode, &head);
            break;
        case 15:
            printf("\nEnter the node value to insert before that: ");
            scanf("%d", &val2);
            printf("\nEnter the new node value: ");
            scanf("%d", &val);
            insert_before(&head, val, val2);
            break;
        case 16:
            printf("\nEnter the new node value: ");
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