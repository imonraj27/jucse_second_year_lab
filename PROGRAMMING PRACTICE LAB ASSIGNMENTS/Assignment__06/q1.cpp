/*
In a library, for each book book-id, serial number (denotes copy number of a 
book), title, author, publisher and price are stored. Book-id and serial number 
together will be unique identifier for a book. Members are either student or 
faculty. Each member has unique member-id. Name, e-mail, address are also to 
be stored. For any transaction (book issue or return), members are supposed to 
place transactions slip. User will submit member-id, book-id, and serial number 
(only for book return). While processing a transaction, check the validity of the 
member. While issuing, availability of a copy of the book is to be checked. While 
returning a book, it is to be checked whether this copy was issued to the 
member or not. A student member can have 2 books issued at a point of time. 
For faculty members it is 10. Transaction information is to be stored like date of 
transaction, member-id, book-id, serial number, returned or not. An entry is 
made when book is issued and updated when the book is returned. For storing 
the information consider files.
Design the classes and implement.
*/



#include <iostream>
#include <fstream>
#include <string>
#define FILE_NAME "TRANSACTION.txt"
// #include <string.h>
using namespace std;

ofstream dataFile;

void divider() // DECORATION PURPOSE
{
    cout << "\n------------------------------------------\n";
}

void BOOK_ISSUE(){ // DECORATION PURPOSE FOR FILE
     dataFile.open(FILE_NAME, ios_base::app);
        dataFile << "\n-------------------------BOOK ISSUE---------------------------";
        dataFile.close();
}

void RETURN_BOOK(){ // DECORATION PURPOSE FOR FILE
     dataFile.open(FILE_NAME, ios_base::app);
        dataFile << "\n-------------------------BOOK RETURN---------------------------";
        dataFile.close();

}

class Member // MEMBER CLASS
{
    string name;
    string email;
    string address;
    int member_id;
    bool faculty;
    int MAX_BOOKS;
    int book_taken_count;

public:
    Member() // MEMBER CONSTRUCTOR
    {
        name = "__";
        email = "__";
        member_id = -1;
        faculty = false;
        MAX_BOOKS = 2;
        book_taken_count = 0;
    }

    void take_member() // TAKE A MEMBER'S DATA
    {
        cout << "\nEnter member's id: ";
        cin >> member_id;
        cout << "\nEnter member's name: ";
        cin.ignore();
        getline(cin, name);
        cout << "\nEnter member's email: ";
        getline(cin, email);
        cout << "\nEnter member's address: ";
        getline(cin, address);
        cout << "\nIs the member a faculty. y/n: ";
        char c;
        cin >> c;
        if (c == 'y' || c == 'Y')
        {
            faculty = true;
            MAX_BOOKS = 10;
            book_taken_count = 0;
        }
        else
        {
            faculty = false;
            MAX_BOOKS = 2;
            book_taken_count = 0;
        }
    }

    bool can_return_book() // CHECK IF A MEMBER CAN RETURN BOOK
    {
        if (book_taken_count <= 0)
        {
            return false;
        }

        book_taken_count--;
        return true;
    }

    bool can_take_book() // CHECK IF A MEMBER CAN TAKE MORE BOOK
    {
        if (book_taken_count == MAX_BOOKS)
        {
            return false;
        }

        book_taken_count++;
        return true;
    }

    void show_member() // SHOW THE DATA OF A MEMBER
    {
        cout << "\nName: " << name;
        cout << "\nEmail: " << email;
        cout << "\nAddress: " << address;
        cout << "\nMember Id: " << member_id;
        cout << "\nFaculty: " << ((faculty) ? "YES" : "NO");
    }

    void show_mem_in_file(){ // SHOW MEMBER DATA IN FILE
        dataFile.open(FILE_NAME, ios_base::app);
        dataFile << "\nNAME: " << name
                << "\tEMAIL: " << email
                << "\tADDRESS: " << address
                << "\tMEMBER ID: " << member_id
                << "\tFaculty: " << ((faculty) ? "YES" : "NO");
        dataFile.close();        
    }

    int memb_id() const // RETURNING MEMBER ID
    {
        return member_id;
    }
};

class Member_node // A MEMBER NODE FOR LINKED LIST IMPLEMENTATION
{
    Member mem;
    Member_node *next;

public:
    Member_node()
    {
        next = NULL;
    }

    void take_member()
    {
        mem.take_member();
    }

    void print_member()
    {
        mem.show_member();
    }

    void print_to_file(){
        mem.show_mem_in_file();
    }

    bool atend_memb_node() // IF MEMBER NODE END OF LIST
    {
        return (next == NULL);
    }

    bool if_member(int m_id) // CHECK VALIDITY OF MEMBER NODE PROVIDED THE MEMBER ID
    {
        return (m_id == mem.memb_id());
    }

    int memb_id() const 
    {
        return mem.memb_id();
    }

    bool take_book() // TAKES A BOOK FOR A MEMBER NODE RETURNS TRUE IF DONE
    {
        if (mem.can_take_book())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool return_book() // RETURN BOOK FOR MEMBER AND RETURNS TRUE IF DONE
    {
        if (mem.can_return_book())
        {
            return true;
        }

        return false;
    }

    void insert_after(Member_node *target) // LINKED LIST OPERATION
    {
        if (target == NULL)
        {
            cout << "\nError !!";
            return;
        }

        Member_node *temp = (this)->next;
        (this)->next = target;
        target->next = temp;
    }

    void delete_after()  // LINKED LIST OPERATION
    {
        Member_node *temp = (this)->next;
        (this)->next = temp->next;
        delete[] temp;
    }

    Member_node *advance()  // LINKED LIST OPERATION
    {
        return (this)->next;
    }
};

class Member_list // THE MEMBER LIST LINKED LIST CLASS
{
    Member_node *head;

public:
    Member_list()
    {
        head = NULL;
    }
    Member_list(Member_node *h)
    {
        head = h;
    }

    void insert_member_end(Member_node *target)  // LINKED LIST OPERATION
    {
        if (head == NULL)
        {
            head = target;
            return;
        }

        Member_node *temp = head;
        while (!temp->atend_memb_node())
        {
            temp = temp->advance();
        }

        temp->insert_after(target);
    }

    Member_node *if_found(int m_id) // CHECK IF A MEMBER WITH ID IS FOUND IN LIST OR NOT
    {
        if (head == NULL)
        {
            return NULL;
        }

        Member_node *temp = head;
        while (temp)
        {
            if (temp->if_member(m_id))
            {
                return temp;
            }
            temp = temp->advance();
        }

        return NULL;
    }

    void free_mem_list(){  // LINKED LIST OPERATION
        Member_node * m;
        while(head){
            m = head;
            head = head->advance();
            free(m);
            m = NULL;
        }
    }
};

class Each_book_node // NODE TO STORE EACH BOOK SERIAL AND TAEKN STATUS
{

    int book_serial_no;
    bool taken;
    Member_node *taken_by;
    Each_book_node *next;

public:
    Each_book_node()
    {
        book_serial_no = -1;
        taken = false;
        taken_by = NULL;
        next = NULL;
    }
    Each_book_node(int bsno)
    {
        book_serial_no = bsno;
        taken = false;
        taken_by = NULL;
        next = NULL;
    }

    int serial_no() const
    {
        return book_serial_no;
    }

    void print_serial_to_file(){
        dataFile.open(FILE_NAME, ios_base::app);
        dataFile << "\tSERIAL NO.: " << book_serial_no << endl;
        dataFile.close();   
    }

    void insert_after(Each_book_node *target)  // LINKED LIST OPERATION
    {
        if (target == NULL)
        {
            cout << "\nError !!";
            return;
        }

        Each_book_node *temp = (this)->next;
        (this)->next = target;
        target->next = temp;
    }

    void delete_after()  // LINKED LIST OPERATION
    {
        Each_book_node *temp = (this)->next;
        (this)->next = temp->next;
        delete[] temp;
    }

    Each_book_node *advance()  // LINKED LIST OPERATION
    {
        return (this)->next;
    }

    bool available() // RETURN BOOL OF A BOOK AVAILABILITY
    {
        return (!taken);
    }

    bool valid_return(Member_list *mlist, int mem_id) // CHECK IF A RETURN IS VALID 
    {
        if (mlist == NULL)
        {
            cout << "\nError!!";
            return false;
        }

        Member_node *tt = mlist->if_found(mem_id);
        if ((taken_by == tt) && taken == true)
        {
            if (tt->return_book())
            {
                taken_by = NULL;
                taken = false;
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    void issue_book(Member_node *tkn_by) // ISSUE A BOOK
    {
        taken_by = tkn_by;
        taken = true;
    }
};

class Book_data_node // BOOK DATA NODE TO STORE OVERALL BOOK DATA
{
    int book_id;
    string author;
    string title;
    string publisher;
    int price;
    Book_data_node *next;
    Each_book_node *books_head;

public:
    Book_data_node()
    {
        book_id = -1;
        author = "__";
        publisher = "__";
        price = 0;
        books_head = NULL;
        next = NULL;
    }

    bool atend_book_node()  // LINKED LIST OPERATION
    {
        return (next == NULL);
    }

    bool if_book_id(int bid)
    {
        return (bid == book_id);
    }

    void insert_after(Book_data_node *target)  // LINKED LIST OPERATION
    {
        if (target == NULL)
        {
            cout << "\nError !!";
            return;
        }

        Book_data_node *temp = (this)->next;
        (this)->next = target;
        target->next = temp;
    }

    void take_book_data() // TAKE NEW BOOK DATA
    {
        cout << "\nEnter new book id: ";
        cin >> book_id;
        cout << "\nEnter title: ";
        cin.ignore();
        getline(cin, title);
        cout << "\nEnter author: ";
        getline(cin, author, '\n');
        cout << "\nEnter publisher: ";
        getline(cin, publisher, '\n');
        cout << "\nEnter price: ";
        cin >> price;

        int num_of_copies, sno;
        cout << "\nHow many copies of this book: ";
        cin >> num_of_copies;
        Each_book_node *temp = NULL, *temp2;
        for (int i = 0; i < num_of_copies; i++)
        {
            cout << "\nEnter serial no of " << i + 1 << "th Copy: ";
            cin >> sno;
            temp2 = temp;
            temp = new Each_book_node(sno);
            if (i == 0)
            {
                books_head = temp;
            }
            else
            {
                temp2->insert_after(temp);
            }
        }

        cout << "\nAll books added to library successfully\n";
    }

    void print_book_data() // PRINT BOOK DATA ON CONSOLE
    {
        cout << "\nBook Name: " << title;
        cout << "\nBook Id: " << book_id;
        cout << "\nAuthor: " << author;
        cout << "\nPublisher: " << publisher;
        cout << "\nPrice: " << price;
    }

    void print_book_to_file(){ // PRINT BOOK DATA ON FILE
        dataFile.open(FILE_NAME, ios_base::app);
        dataFile << "\nBook Name: " << title
                << "\tBook Id: " << book_id
                << "\tAuthor: " << author
                << "\tPublisher: " << publisher
                << "\nPrice: " << price;
        dataFile.close();        
    }

    void issue_book(Member_list *memList) // ISSUE A BOOK
    {
        if (!memList)
        {
            cout << "Error!!";
            return;
        }

        if (books_head == NULL)
        {
            cout << "\nNo books error";
            return;
        }

        Each_book_node *t = books_head;
        while (t)
        {
            if (t->available())
            {
                cout << "\nEnter your member id: ";
                int memb_id;
                cin >> memb_id;

                Member_node *tem = memList->if_found(memb_id);

                if (tem)
                {
                    if (tem->take_book())
                    {
                        t->issue_book(tem);
                        tem->print_member();
                        BOOK_ISSUE();
                        tem->print_to_file();
                        cout << "\nYou are successfully issued the book\n"
                                "Serial No: "
                             << t->serial_no();
                       
                        print_book_data();
                        print_book_to_file();
                         t->print_serial_to_file();     
                        return;
                    }
                    else
                    {
                        cout << "\nYou cannot take more books";
                        return;
                    }
                }
                else
                {
                    cout << "\nWrong member id";
                    return;
                }
            }

            t = t->advance();
        }

        cout << "\nSorry no copy of this book is available";
        return;
    }

    void return_book(Member_list *memList) // RETURN A BOOK
    {
        if (!memList)
        {
            cout << "Error!!";
            return;
        }

        if (books_head == NULL)
        {
            cout << "\nNo books error";
            return;
        }

        Each_book_node *t = books_head;
        int sno;
        cout << "\nEnter serial no of book to return: ";
        cin >> sno;
        while (t)
        {
            if (!t->available() && t->serial_no() == sno)
            {
                cout << "\nEnter your member id: ";
                int memb_id;
                cin >> memb_id;

                if (t->valid_return(memList, memb_id))
                {
                    cout << "\nBook successfully returned by----";
                    (memList->if_found(memb_id))->print_member();
                    RETURN_BOOK();
                    (memList->if_found(memb_id))->print_to_file();
                    print_book_to_file();
                     t->print_serial_to_file();     
                    return;
                }
                else
                {
                    cout << "\nInvalid return!";
                    return;
                }
            }

            t = t->advance();
        }

        cout << "\nSorry Invalid return details";
        return;
    }

    Book_data_node *advance()  // LINKED LIST OPERATION
    {
        return (this)->next;
    }

    void free_each_book(){  // LINKED LIST OPERATION
        Each_book_node * temp;
        while(books_head){
            temp = books_head;
            books_head = books_head->advance();
            free(temp);
            temp = NULL;
        }
    }
};

class Book_list // LIST TO MAINTAIN DATA AND SERIAL NOS OF ALL BOOKS
{
    Book_data_node *book_list_head;

public:
    Book_list()
    {
        book_list_head = NULL;
    }

    void insert_new_book_to_list()  // LINKED LIST OPERATION
    {
        Book_data_node *temp = new Book_data_node(), *temp2;
        temp->take_book_data();
        if (book_list_head == NULL)
        {
            book_list_head = temp;
            return;
        }

        temp2 = book_list_head;
        while (!temp2->atend_book_node())
        {
            temp2 = temp2->advance();
        }
        temp2->insert_after(temp);
    }

    void borrow_book(Member_list *list) // BORROW BOOK FROM THE LIST
    {
        int b_id;
        cout << "\nEnter the book Id to borrow: ";
        cin >> b_id;
        Book_data_node *temp;
        if (book_list_head == NULL)
        {
            cout << "\nNo books";
            return;
        }

        temp = book_list_head;
        while (temp)
        {
            if (temp->if_book_id(b_id))
            {
                temp->issue_book(list);
                return;
            }
            temp = temp->advance();
        }
        cout << "\nError no such book id!!";
    }

    void return_book(Member_list *list) // RETURN A BOOK WITH VALID RETURN DETAILS
    {
        int b_id;
        cout << "\nEnter the book Id to return: ";
        cin >> b_id;
        Book_data_node *temp;
        if (book_list_head == NULL)
        {
            cout << "\nNo books";
            return;
        }

        temp = book_list_head;
        while (temp)
        {
            if (temp->if_book_id(b_id))
            {
                temp->return_book(list);
                return;
            }
            temp = temp->advance();
        }
        cout << "\nError no such book id!!";
    }

    void free_book_list(){ //  // LINKED LIST OPERATION
        Book_data_node * bnode;
        while(book_list_head){
            bnode = book_list_head;
            book_list_head = book_list_head->advance();
            bnode->free_each_book();
            free(bnode);
            bnode = NULL;
        }
    }
};



void control_everything() // FUNCTION TO CONTROL ALL OPERATIONS
{
    Member_list *list = new Member_list(); // NEW MEMBER LIST
    Book_list *Blist = new Book_list(); // NEW BOOKS LIST
    Member_node *membnew;

    int choice;

    do // MENU DRIVEN
    {
        cout << "\n1. Add a new Member"
             << "\n2. Add New book to library"
             << "\n3. Issue Book"
             << "\n4. Return Book"
             << "\n5. Clear Everything"
             << "\n0. exit--"
             << "\n\nENTER YOUR CHOICE: ";
        cin >> choice;

        if (!choice)
        {
            list->free_mem_list();
            Blist->free_book_list();
            break;
        }

        switch (choice)
        {
        case 1:
            divider();
            membnew = new Member_node();
            membnew->take_member();
            list->insert_member_end(membnew);
            divider();
            break;
        case 2:
            divider();
            Blist->insert_new_book_to_list();
            divider();
            break;
        case 3:
            divider();
            Blist->borrow_book(list);
            divider();
            break;
        case 4:
            divider();
            Blist->return_book(list);
            divider();
            break;
        case 5:
            list->free_mem_list();
            Blist->free_book_list();
            break;
        default:
            break;
        }
    } while (true);
}

int main()
{

    control_everything();
    return 0;
}