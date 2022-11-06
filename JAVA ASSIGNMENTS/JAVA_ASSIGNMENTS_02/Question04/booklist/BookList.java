package Question04.booklist;

//import org.jetbrains.annotations.Nullable;

import java.util.Scanner;

public class BookList {
    private final Book[] books;
    private int book_count;
    private final Scanner sc;


    public BookList() {
        this.books = new Book[100];
        this.book_count = -1;
        sc = new Scanner(System.in);
    }

    private boolean isTaken(int book_id){
        int i;
        for (i=0; i<=this.book_count; i++){
            if(this.books[i].getBook_id()==book_id)
                return true;
        }
        return false;
    }

    public Book bookFromBookId(int book_id){
        int i;

        for (i=0; i<=this.book_count; i++){
            if(this.books[i].getBook_id()==book_id)
                return this.books[i];
        }
        return null;
    }

    public void print(int book_id){
        Book b = bookFromBookId(book_id);
        System.out.println("========================================");
        if (b == null) System.out.println("Book With Book id " + book_id + " not found...");
        else b.print();
        System.out.println("========================================");
    }

    public void printAll(){
        int i=0;
        for (i=0; i<=this.book_count; i++){
            this.books[i].print();
        }
    }

    public void addBook(){
        System.out.println("Enter the book id: ");


        int book_id = sc.nextInt();
        sc.nextLine();

        if(isTaken(book_id)){
            System.out.println("Book id already taken....");
            return;
        }

        System.out.println("Enter title of the book: ");
        String title = sc.nextLine();

        System.out.println("Enter total copies: ");
        int total_copies = sc.nextInt();

        try{
            this.books[++this.book_count] = new Book(book_id, title, total_copies, total_copies);

            System.out.println("Book successfully added...");
            this.books[this.book_count].print();
        }catch(ArrayIndexOutOfBoundsException e){
            this.book_count--;
            System.out.println("List full now");
        }

    }

    public void changeAttributes(){
        System.out.println("Enter book id: ");
        Book b = bookFromBookId(sc.nextInt());
        sc.nextLine();
        if (b == null) {
            System.out.println("Book id not found...");
            return;
        }

            System.out.println("Want to change Book title(y/n): ");
            if(sc.nextLine().equals("y")){
                System.out.println("Enter the changed book title: ");
                b.setTitle(sc.nextLine());
            }
            System.out.println("Want to change Book total copies(y/n): ");
            if(sc.next().equals("y")){
                System.out.println("Enter the changed book copies: ");
                b.setTotal_copies(sc.nextInt());
            }
            System.out.println("Want to change Book available copies(y/n): ");
            if(sc.next().equals("y")){
                System.out.println("Enter the changed book available copies: ");
                b.setAvailable_copies(sc.nextInt());
            }

    }

    public void addCopies(){
        System.out.println("Enter book id: ");
        Book b = bookFromBookId(sc.nextInt());
        sc.nextLine();
        if (b == null) {
            System.out.println("Book id not found...");
            return;
        }

        System.out.println("How many copies to add: ");
        b.newCopies(sc.nextInt());
        sc.nextLine();
    }


}
