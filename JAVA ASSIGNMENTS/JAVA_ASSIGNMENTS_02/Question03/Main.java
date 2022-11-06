package Question03;
import Question03.booklist.*;
import Question03.memberlist.*;
import Question03.transactionlist.*;

import java.util.Scanner;

class LibraryManagement{
    final private BookList bookList = new BookList();
    final private MemberList memberList = new MemberList();
    final private TransactionList transactionList = new TransactionList();
    final private Scanner sc = new Scanner(System.in);

    public void addMember(){
        memberList.addMember();
    }

    public void addBook(){
        bookList.addBook();
    }


    public void returnBook(){
        System.out.println("Enter your member id: ");
        int member_id = sc.nextInt();
        sc.nextLine();

        Member m = memberList.findMemberWithId(member_id);

        if(m==null){
            System.out.println("Invalid Member Id...Please try again...");
            return;
        }



        System.out.println("Enter the book id to return: ");
        int book_id = sc.nextInt();
        sc.nextLine();
        Book b = bookList.bookFromBookId(book_id);

        if(b==null){
            System.out.println("No Book exists with this id...sorry...");
            return;
        }

        boolean borrowed;
       try{
           borrowed = transactionList.isValidTransaction(member_id, book_id).wasValidBorrow();
       }catch (NullPointerException e){
           System.out.println("No such transaction....");
           return;
       }


       if(borrowed){
           transactionList.isValidTransaction(member_id, book_id).returnBook();
           m.updateNumberTaken(-1);
           b.updateCopy(1);
           System.out.println("Successfully Returned Book....");
       }else{
           System.out.println("This book is already returned...");
       }


    }

    public void borrowBook(){
        System.out.println("Enter your Member Id: ");
        int member_id = sc.nextInt();
        sc.nextLine();

        Member m = memberList.findMemberWithId(member_id);

        if(m==null){
            System.out.println("Invalid Member Id...Please try again...");
            return;
        }

        if(!m.canTakeBook()){
            System.out.println("You cannot take more books...sorry");
            return;
        }

        System.out.println("Enter the book id to take: ");
        int book_id = sc.nextInt();
        sc.nextLine();
        Book b = bookList.bookFromBookId(book_id);

        if(b==null){
            System.out.println("No Book exists with this id...sorry...");
            return;
        }

        if(!b.available()){
            System.out.println("No more copies of this book is available sorry...");
            return;
        }

        Transaction t = transactionList.isValidTransaction(member_id, book_id);

        if(t!=null){
            System.out.println("You have already taken this book...sorry...");
            return;
        }

        transactionList.addTransaction(member_id, book_id);
        m.updateNumberTaken(1);
        b.updateCopy(-1);
        System.out.println("Successfully Borrowed Book....");
    }

    public BookList getBookList() {
        return bookList;
    }

    public MemberList getMemberList() {
        return memberList;
    }

    public TransactionList getTransactionList() {
        return transactionList;
    }
}

public class Main {
    public static void spacing(){
        System.out.println();
        System.out.println();
    }
    public static String allChoices(){
        return "1. Add Member to MemberList\n" +
                "2. Add Book to BookList\n" +
                "3. Borrow Book\n" +
                "4. Return Book\n" +
                "5. Print all transactions\n" +
                "6. Print all Books\n" +
                "7. Print all Members\n" +
                "8. Find book with id\n" +
                "9. Change book attributes\n" +
                "10. Add Copies of a book\n" +
                "0. Exit";
    }


    public static void main(String[] args) {
        LibraryManagement libraryManagement = new LibraryManagement();
        Scanner sc = new Scanner(System.in);
        int choice;
        while(true){
            System.out.println(allChoices());
            System.out.println("ENTER YOUR CHOICE: ");
            choice = sc.nextInt();
            sc.nextLine();

            if(choice==0)
                break;

            switch (choice){
                case 1:
                    libraryManagement.addMember();
                    break;
                case 2:
                    libraryManagement.addBook();
                    break;
                case 3:
                    libraryManagement.borrowBook(); //for borrow
                    break;
                case 4:
                    libraryManagement.returnBook(); //for return
                    break;
                case 5:
                    spacing();
                    libraryManagement.getTransactionList().printAll();
                    spacing();
                    break;
                case 6:
                    spacing();
                    libraryManagement.getBookList().printAll();
                    spacing();
                    break;
                case 7:
                    spacing();
                    libraryManagement.getMemberList().printAll();
                    spacing();
                    break;
                case 8:
                    System.out.println("Enter book id to find: ");
                    libraryManagement.getBookList().print(sc.nextInt());
                    sc.nextLine();
                    spacing();
                    break;
                case 9:
                    libraryManagement.getBookList().changeAttributes();
                    break;
                case 10:
                    libraryManagement.getBookList().addCopies();
                    break;
                default:
                    break;

            }
        }
    }
}
