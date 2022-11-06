#include "linkedlist.h"

Node *Build_list_reverse()
{

    FILE *fp = fopen("numbers.txt", "r");
    if (!fp)
    {
        printf("\nError in opening the file!!");
    }

    Node *head = init_l();
    int val;
    fscanf(fp, "%d", &val);
    head = createnode(val);

    while (fscanf(fp, "%d", &val) == 1)
    {
        Node *newNode = createnode(val);
        insert_front(newNode, &head);
    }

    fclose(fp);
    return head;
}

Node *Build_list()
{
    FILE *fp = fopen("numbers.txt", "r");
    if (!fp)
    {
        printf("\nError in opening the file!!");
    }

    Node *head = init_l();
    int val;
    fscanf(fp, "%d", &val);
    head = createnode(val);

    Node *ptr = head;
    while (fscanf(fp, "%d", &val) == 1)
    {
        Node *newNode = createnode(val);
        insert_after(newNode, ptr);
        ptr = ptr->next;
    }

    fclose(fp);
    return head;
}

void Print_list(Node *head)
{
    Node *ptr = head;

    printf("\nThe list is : ");

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    printf("\nIn reverse order---");
    Node *head = Build_list_reverse();
    Print_list(head);
    delete_l(&head);

    printf("\nIn same order---");
    Node *head2 = Build_list();
    Print_list(head2);
    delete_l(&head2);
    return 0;
}
