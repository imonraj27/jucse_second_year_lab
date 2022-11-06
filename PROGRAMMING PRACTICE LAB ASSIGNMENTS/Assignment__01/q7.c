/*7. Maintain a list to store roll, name and score of students.
As and when required student record may be added or deleted. Also,
the list has to be displayed. Design suitable functions for
different operations.   */



#include <stdio.h>
#include <stdlib.h>

struct Student { //sturcture to add student informations
    int roll;
    char name[40];
    int scores[5];
};

struct Node { //structure to implement the linked list
    struct Student student;
    struct Node * next;
};


//Function for adding a student
struct Node * addStudent(struct Node * head) {
    struct Node * new = (struct Node *)malloc(sizeof(struct Node));

    if(new==NULL){
        printf("Memory Error!!");
        return NULL;
    }

    printf("Enter the name and roll: ");
    scanf("%s %d", new->student.name, &(new->student.roll));

    printf("\nEnter the scores in 5 subjects: ");

    int i;
    for ( i = 0; i < 5; i++)
    {
        scanf("%d", &(new->student.scores[i]));
    }
    
    new->next = head;

    return new;
}



//Function for printing all student
void printStudents(struct Node * head) {
    struct Node * ptr = head;
    int i, count=1;

     printf("\nName\tRoll\t Scores");

    while(ptr != NULL) {
        printf("\n%d %s\t%d\t", count, ptr->student.name, ptr->student.roll);
        for ( i = 0; i < 5; i++)
        {
            printf(" %d", ptr->student.scores[i]);
        }
        count++;
        ptr = ptr->next;
        
    }
}


//Function for deleting a student
struct Node * deleteStudent(struct Node * head, int sn) {
    if(head == NULL) {
        printf("\n\nNo student to delete..");
        return NULL;
    }

    int temp = 1;

     struct Node * ptr = head;
     struct Node * ptr2 = NULL;

    if(sn==1) { //if the first student to be deleted
        head = head->next;
        free(ptr);
        return head;
    }


    while(temp<sn-1 && ptr->next != NULL) {
        ptr = ptr->next;
        temp++;
    }

    if (ptr->next == NULL)
    {
        printf("\nInvalid serial number!!!"); //if the serial number of the student is out of range
        return head;
    }
    
    //deleting one node and freeing the memory
    ptr2 = ptr->next;
    ptr->next = ptr2->next;
    free(ptr2);

    return head;
}

int main() {
    int choice;
    int si;
  
    struct Node * head = NULL;

    do //showing options to users of various operations until he/she exits the program
    {
        printf("\n\nEnter your choice: \n\t1) Add student\n\t2) Delete student\n\t3) Print students\n\t0) Exit\n\t YOUR CHOICE: ");
        scanf("%d", &choice);

        if(choice == 1) {
            head = addStudent(head);
        } else if (choice == 2) {
            printf("Enter the serial of student to delete: ");
            scanf("%d", &si);
            head = deleteStudent(head, si);
        } else if(choice == 3) {
            printStudents(head);
        } else {
            break;
        }
    } while (choice != 0);
    
    



    return 0;
}