// #include "circularlinkedlist.h"
#include "arraylinkedlist.h"

int main()
{
  ArrayLinkedList *plist = prepare_linked_list();

  if (empty_l(plist))
  {
    printf("\nList is empty");
  }

  nodeAdress temp = createnode(10, plist), temp2;
  temp2 = temp;
  insert_front(plist, temp);

  print_l(plist);

  temp = createnode(50, plist);
  insert_front(plist, temp);

  print_l(plist);

  temp = createnode(55, plist);
  insert_front(plist, temp);

  print_l(plist);

  temp = createnode(225, plist);
  insert_front(plist, temp);

  print_l(plist);

  delete_after(temp, plist);

  print_l(plist);

  insert_after(temp, plist, createnode(233, plist));
  insert_after(temp, plist, createnode(99, plist));
  insert_after(temp2, plist, createnode(555, plist));

  print_l(plist);

  delete_front(plist);

  print_l(plist);

  delete_front(plist);

  print_l(plist);

  delete_front(plist);

  print_l(plist);
}

//   CLLNode * head = init_l();
//   head = createCLLNode(1);

//   insert_front(createCLLNode(2), &head);
//   insert_front(createCLLNode(3), &head);
//   insert_front(createCLLNode(4), &head);

//   print_l(head);

// delete_l(&head);
//    print_l(head);