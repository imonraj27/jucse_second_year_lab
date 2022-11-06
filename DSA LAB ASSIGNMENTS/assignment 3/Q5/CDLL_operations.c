#include "circulardoublylinkedlist.h"

void line_break(const char *str)
{
    printf("\n\n%s\n", str);
}

int main()
{
    CDLLNode *head = init_l();

    insert_front(createCDLLNode(10), &head);
    insert_front(createCDLLNode(20), &head);

    line_break("Two insert_front of 10 and 20");
    print_l(head);

    CDLLNode *temp = createCDLLNode(30);
    insert_front(temp, &head);
    insert_front(createCDLLNode(40), &head);

    line_break("insert_front 30 and 40");
    print_l(head);

    delete_after(temp, &head);
    line_break("delete_after 30 node");
    print_l(head);

    delete_front(&head);
    line_break("delete_front");
    print_l(head);

    insert_after(createCDLLNode(333), temp);
    line_break("insert_after 30 node");
    print_l(head);

    delete_l(&head);
    line_break("delete list");
    print_l(head);
}