/* Write a program to store student information in a file and t do the following operations. Information
includes roll, name, and score in five subjects. Use may like to add record (ensure roll number is unique),
display all records showing roll, name and total score. User may search for the record against a roll. User
may edit the details a record. User may delete record. Deletion may be logical (by some means indicate it is
an invalid record and to be avoided in processing) and physical (file will not have the record). */

/* NAME: IMON RAJ
   SECTION: A3
   ROLL: 98
   LAB: PROGRAMMING PRACTICE LAB
   DEPT: CSE */

#include <stdio.h>
#include <stdlib.h>

typedef struct Student
{
    int roll;
    char name[40];
    int scores[5];
} Student;

void createFile() // CREATES A NEW FILE WITH NO CONTENT
{
    FILE *fp = fopen("students.dat", "w");
    fclose(fp);
}

void displayRecords() // DISPLAY ALL THE VALID STUDNT RECORDS FROM THE FILE
{
    FILE *fp = fopen("students.dat", "r");

    if (fp == NULL)
    {
        printf("\nError in opening the file!!");
        return;
    }

    Student st;
    int i, total = 0;

    while (fread(&st, sizeof(Student), 1, fp))
    {

        if (st.roll > 0)
        {
            printf("\nName: %s Roll: %d Total Score: ", st.name, st.roll);
            for (i = 0; i < 5; i++)
            {
                total += st.scores[i];
            }

            printf("%d ", total);

            total = 0;
        }
    }

    fclose(fp);
}

void searchStudent() { // SEARCH A STUDENT DATA AGAINST ROLL NUMBER
    FILE *fp = fopen("students.dat", "r");

    if (fp == NULL)
    {
        printf("\nError in opening the file!!");
        return;
    }

    printf("\nEnter the roll to find data: ");
    int roll;
    scanf("%d", &roll);

    Student s;
    int found=0;

    while (fread(&s, sizeof(Student), 1, fp))
    {
        if(s.roll == roll) { //
            found = 1;
            break;
        }
    }

    if(!found) {
        printf("\nThe roll number doesn't exist..");
        fclose(fp);
        return;
    }

    printf("Student Roll: %d - Student Name: %s - Scores:", s.roll, s.name);

    int i;
    for (i = 0; i < 5; i++)
    {
        printf(" %d", s.scores[i]);
    }
    
    

    fclose(fp);
}

void addStudent() // ADDING A NEW STUDENT DATA TO THE FILE
{
    FILE *fp = fopen("students.dat", "r");

    if (fp == NULL)
    {
        printf("\nNew file is being created");
        createFile();
        fp = fopen("students.dat", "r");
    }

    Student st, s;
    int i;
    printf("\nEnter the roll of student: ");
    scanf("%d", &s.roll);

    printf("\nEnter the name of student: ");
    scanf("%s", s.name);

    printf("\nEnter the score of 5 subjects: ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &s.scores[i]);
    }
    while (fread(&st, sizeof(Student), 1, fp))
    {

        if (st.roll == s.roll) // CHECKING WHEHER THE ROLL NUMBER ALREADY EXISTS 
        {
            printf("Roll number already exists!!");
            fclose(fp);
            return; // IF ROLL EXISTS RETURN
        }
    }

    fclose(fp);
    fp = NULL;

    //Now roll number doesn't exist and we will append the data

    fp = fopen("students.dat", "a"); // OPENIG IN APPEND MODE TO APPEND THE NEW ROLL DATA

    fwrite(&s, sizeof(Student), 1, fp);

    fclose(fp);
}

void deleteStudentLogical() // LOGICALLY DELETE A STUDENT WITH HIS ROLL NUMBER
{
    FILE *fp = fopen("students.dat", "r+");

    if (!fp)
    {
        printf("\nError in opening the file");
        return;
    }

    int roll;
    printf("\nEnter the roll to delete: ");
    scanf("%d", &roll);

    Student s1, dummydata;
    int found = 0;

    while (fread(&s1, sizeof(Student), 1, fp))
    {
        if (s1.roll == roll)
        {
            found = 1; // FOUND FLAG TO 1
            break;
        }
    }

    if (found)
    {
        // GOING TO PREVIOUS LINE AND CHANGING TO DUMMY DATA OF THE GIVEN ROLL
        fseek(fp, (-1) * sizeof(Student), SEEK_CUR);
        dummydata.roll = -1;
        dummydata.name[0] = 'N';
        dummydata.name[1] = 'A';
        dummydata.name[2] = '\0';
        dummydata.scores[0] = 0;
        dummydata.scores[1] = 0;
        dummydata.scores[2] = 0;
        dummydata.scores[3] = 0;
        dummydata.scores[4] = 0;
        fwrite(&dummydata, sizeof(Student), 1, fp);

        printf("\nSuccessful logical deletion..");
    }
    else
    {
        printf("\nNothing to delete");
    }

    fclose(fp);
}

void editStudentData() // EDIT A STUDENT DATA WITH HIS ROLL NUBER GIVEN
{
    FILE *fp = fopen("students.dat", "r+");

    if (!fp)
    {
        printf("\nError in opening the file");
        return;
    }

    int roll;
    printf("\nEnter the roll to edit student data: ");
    scanf("%d", &roll);

    Student s1;
    int found = 0, i;

    while (fread(&s1, sizeof(Student), 1, fp))
    {
        if (s1.roll == roll)
        {
            found = 1; // MAKE FOUND FLAG AS 1
            break;
        }
    }

    if (found) // EDITING OF DATA AVAILABLE IF FOUND THE ROLL NUMBER
    {
        fseek(fp, (-1) * sizeof(Student), SEEK_CUR); // GOING BACK TO PREVIOUS LINE TO EDIT THE RECORD OF GIVEN ROLL

        printf("\nEnter the new(corrected) name: ");
        scanf("%s", s1.name);
        printf("\nEnter the new scores in 5 subjects: ");
        for (i = 0; i < 5; i++)
        {
            scanf("%d", &s1.scores[i]);
        }

        fwrite(&s1, sizeof(Student), 1, fp);
    }
    else
    {
        printf("\nNothing to delete");
    }

    fclose(fp);
}

void eraseDummy() { // ERASE ALL THE DUMMY DATAS
    FILE * fp = fopen("students.dat", "r");
    FILE * fp2 = fopen("temp.dat", "w");

    if(fp==NULL || fp2==NULL) {
        printf("\nError in opening the file!!");
    }

   printf("\n\nAre you sure to erase all dummy data: 1) YES 0) NO\n Your choice: ");
   int choice;
   scanf("%d", &choice);

   if(choice!=1) {
       return;
   }

    Student s1;

    while(fread(&s1, sizeof(Student), 1, fp)) { // COPYING TO ANOTHER FILE EXCEPTING THE DUMMY DATA 
        if (s1.roll != -1) {
            fwrite(&s1, sizeof(Student), 1, fp2);
        }
    }

    
    fclose(fp);
    fclose(fp2);
    remove("students.dat");
    rename("temp.dat", "students.dat");

    printf("\nAll dummy data is deleted...");
}

void deleteStudentPhysical() { // DELTE A STUDENT DATA PHYSCIALLLY WITH ROLL NUMBER
    FILE * fp = fopen("students.dat", "r");
    FILE * fp2 = fopen("temp.dat", "w");

    if(fp==NULL || fp2==NULL) {
        printf("\nError in opening the file!!");
    }

    int roll;
    printf("\nEnter the roll to physically delte: ");
    scanf("%d", &roll);

    Student s1;

    while(fread(&s1, sizeof(Student), 1, fp)) {
        if (s1.roll != roll) {
            fwrite(&s1, sizeof(Student), 1, fp2);
        }
    }

    
    fclose(fp);
    fclose(fp2);

    remove("students.dat");

    rename("temp.dat", "students.dat");

    printf("\nSuccessful physical deletion..");

}

int main()
{

    int choice = 0;

    do
    {
        printf("\n\n1) ADD STUDENT\n2) SEARCH STUDENT\n3) LOGICAL DELETE STUDENT\n4) PHYSICAL DELTE STUDENT\n5) EDIT STUDENT\n6) DISPLAY ALL STUDENTS\n7) ERASE DUMMY DATA\n0) EXIT THE PROGRAM\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;
         case 2:
            searchStudent();
            break;    
        case 3:
            deleteStudentLogical();
            break;
        case 4: 
            deleteStudentPhysical();   
            break; 
        case 5:
            editStudentData(); 
            break;
        case 6:
            displayRecords();    
            break; 
        case 7:
             eraseDummy();
            break;     
        default:
            break;
        }
    } while (choice);

    

    return 0;
}