#include "arraylinkedlist.h"

ArrayLinkedList *plist;
void Build_list()
{
    printf("\nHow many elements: ");
    int n;
    scanf("%d", &n);

    printf("\nEnter the elements of the list: ");
    int val;
    scanf("%d", &val);
    nodeAddress head = createnode(val, plist);
    insert_front(plist, head);

    nodeAddress ptr = head;
    nodeAddress newNode;
    while (n > 1)
    {
        scanf("%d", &val);
        newNode = createnode(val, plist);
        insert_after(ptr, plist, newNode);
        ptr = newNode;

        n--;
    }
}

void print_list_in_reverse(nodeAddress head)
{ // this is the function for printing the list in reverse
    if (head == -1)
    {
        return;
    }
    print_list_in_reverse(plist->array[head].next);
    printf("%d-->", plist->array[head].data);
}

int size_of_list()
{
    nodeAddress ptr = plist->head;
    if (ptr == -1)
    {
        return 0;
    }

    int count = 0;

    while (ptr != -1)
    {
        count++;
        ptr = plist->array[ptr].next;
    }

    return count;
}

void delete_nth_node(int n)
{
    int i;
    nodeAddress temp, ptr;
    if (plist->head == -1)
    {
        printf("\nThe list is empty!!");
        return;
    }

    ptr = plist->head;
    if (n == 1)
    {
        delete_front(plist);
        return;
    }
    for (i = 1; i < n - 1; i++)
    {
        if ((temp = plist->array[ptr].next) == -1)
        {
            printf("\nInvalid n!!");
            return;
        }

        ptr = temp;
    }

    delete_after(ptr, plist);
}

void delete_last_node()
{
    nodeAddress temp, temp2;
    if (plist->head == -1)
    {
        printf("\nThe list is empty!!");
        return;
    }

    if (atend_l(plist->head, plist))
    {
        delete_front(plist);
    }

    temp = plist->array[plist->head].next;

    while (!atend_l(temp, plist))
    {
        temp2 = temp;
        temp = plist->array[temp].next;
    }

    delete_after(temp2, plist);
}

int isList_ordered()
{
    int ascending = 0, descending = 0, ordered = 1;

    nodeAddress ptr = plist->head, ptr_later = plist->array[plist->head].next;

    do
    {
        if (plist->array[ptr].data > plist->array[ptr_later].data)
        {
            descending = 1;
        }
        else if (plist->array[ptr].data < plist->array[ptr_later].data)
        {
            ascending = 1;
        }

        if (ascending * descending)
        {
            ordered = 0;
            break;
        }

        ptr = plist->array[ptr].next;
        ptr_later = plist->array[ptr_later].next;
    } while (!atend_l(ptr, plist));

    return ordered;
}

void Reverse_list()
{
    if ((plist->head) == -1)
    {
        printf("\nThe list is empty..\n");
        return;
    }
    nodeAddress previous = -1;
    nodeAddress current = plist->head;
    nodeAddress later = plist->head;

    while (current != -1)
    {
        later = plist->array[current].next;
        plist->array[current].next = previous;
        previous = current;
        current = later;
    }

    plist->head = previous;
}

void sort_list()
{
    if ((plist->head) == -1)
    {
        printf("\nThe list is empty..\n");
        return;
    }
    int temp;
    nodeAddress ptr1 = plist->head;
    nodeAddress ptr2 = plist->array[plist->head].next;

    while (ptr1 != -1)
    {
        ptr2 = plist->array[ptr1].next;
        while (ptr2 != -1)
        {
            if (plist->array[ptr2].data < plist->array[ptr1].data)
            {
                temp = plist->array[ptr2].data;
                plist->array[ptr2].data = plist->array[ptr1].data;
                plist->array[ptr1].data = temp;
            }
            ptr2 = plist->array[ptr2].next;
        }
        ptr1 = plist->array[ptr1].next;
    }
}

void swap_element_pairwise()
{
    if ((plist->head) == -1)
    {
        printf("\nThe list is empty..\n");
        return;
    }
    int temp;
    nodeAddress ptr1 = plist->head;
    nodeAddress ptr2 = plist->array[plist->head].next;

    while (ptr2 != -1)
    {
        temp = plist->array[ptr2].data;
        plist->array[ptr2].data = plist->array[ptr1].data;
        plist->array[ptr1].data = temp;

        ptr1 = plist->array[plist->array[ptr1].next].next;
        if (plist->array[ptr2].next == -1)
        {
            break;
        }
        ptr2 = plist->array[plist->array[ptr2].next].next;
    }
}

void delete_alternate_node()
{
    if ((plist->head) == -1)
    {
        printf("\nThe list is empty..\n");
        return;
    }
    int temp;
    nodeAddress ptr1 = plist->head;

    while (ptr1 != -1 && !atend_l(ptr1, plist))
    {
        delete_after(ptr1, plist);
        ptr1 = plist->array[ptr1].next;
    }
}

void insert_before(int val, int val2)
{
    if ((plist->head) == -1)
    {
        printf("\nThe list is empty..\n");
        return;
    }

    nodeAddress ptr1 = plist->head;
    nodeAddress ptr2 = plist->array[ptr1].next;
    nodeAddress newNode = createnode(val, plist);

    int data;

    while (ptr2 != -1)
    {
        data = plist->array[plist->array[ptr1].next].data;
        if (data == val2)
        {
            insert_after(ptr1, plist, newNode);
            break;
        }
        ptr1 = plist->array[ptr1].next;
        ptr2 = plist->array[ptr1].next;
    }
}

void insert_last(int val)
{
    if ((plist->head) == -1)
    {
        printf("\nThe list is empty..\n");
        return;
    }

    nodeAddress ptr1 = plist->head;
    nodeAddress newNode = createnode(val, plist);

    while (!atend_l(ptr1, plist))
    {
        ptr1 = plist->array[ptr1].next;
    }

    insert_after(ptr1, plist, newNode);
}

void move_last_to_first()
{
    if ((plist->head) == -1)
    {
        printf("\nThe list is empty..\n");
        return;
    }

    nodeAddress ptr1 = plist->head, ptr2;

    while (!atend_l(ptr1, plist))
    {
        ptr2 = ptr1;
        ptr1 = plist->array[ptr1].next;
    }

    plist->array[ptr2].next = -1;
    plist->array[ptr1].next = (plist->head);
    plist->head = ptr1;
}

int main()
{
    int choice, n, val, val2;
    plist = prepare_linked_list();
    Build_list();
    nodeAddress ptr, newNode;

    do
    {
        printf("\n1. Print List in Same order\n2. Print list in reverse order\n3. Find Size of list\n4. Delete nth node\n5. Delete Last Node\n6. Delete first node\n7. Check if list is ordered\n8. Delete a list\n9. Reverse a list\n10. Sort a list\n11. Swap elements pairwise\n12. Move last element to front of list\n13. Delete alternate node of a list\n14. Insert Node at begining\n15. Insert before a specified node\n16. Insert at end\n0. EXIT THE LOOP\n\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            delete_l(plist);
            break;
        }

        switch (choice)
        {
        case 1:
            printf("\nThe list in order is: ");
            print_l(plist);
            break;

        case 2:
            printf("\nThe list in reverse order is: ");
            print_list_in_reverse(plist->head);
            break;
        case 3:
            printf("\nSize of list is: %d", size_of_list());
            break;
        case 4:
            printf("\nEnter the node number to delete: ");
            scanf("%d", &n);
            delete_nth_node(n);
            break;
        case 5:
            delete_last_node();
            break;
        case 6:
            delete_nth_node(1);
            break;
        case 7:
            if (isList_ordered())
            {
                printf("\nThe list is ordered...");
            }
            else
            {
                printf("\nNO, The list is not ordered...");
            }
            break;
        case 8:
            delete_l(plist);
            printf("\nThe list has been deleted");
            break;
        case 9:
            Reverse_list();
            break;
        case 10:
            sort_list();
            break;
        case 11:
            swap_element_pairwise();
            break;
        case 12:
            move_last_to_first();
            break;
        case 13:
            delete_alternate_node();
            break;
        case 14:
            printf("\nEnter the value to insert: ");
            scanf("%d", &val);
            newNode = createnode(val, plist);
            insert_front(plist, newNode);
            break;
        case 15:
            printf("\nEnter the node value to insert before that: ");
            scanf("%d", &val2);
            printf("\nEnter the new node value: ");
            scanf("%d", &val);
            insert_before(val, val2);
            break;
        case 16:
            printf("\nEnter the new node value: ");
            scanf("%d", &val);
            insert_last(val);
            break;
        default:
            delete_l(plist);
            break;
        }
    } while (1);

    return 0;
}