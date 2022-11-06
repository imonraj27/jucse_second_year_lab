package Question04;
import Question04.booklist.*;
import Question04.memberlist.*;
import Question04.transactionlist.*;

import java.util.Scanner;

interface LibraryInterface {
    void addBook();
    void searchBook();
    void addMember();
    void searchMember();
    void showAllMembers();
    void showAllBooks();
    void issueBook();
    void returnBook();
}

class LibraryManagement implements LibraryInterface{
    final private BookList bookList = new BookList();
    final private MemberList memberList = new MemberList();
    final private TransactionList transactionList = new TransactionList();
    final private Scanner sc = new Scanner(System.in);

    @Override
    public void addMember(){
        memberList.addMember();
    }

    @Override
    public void searchMember() {
        System.out.println("Enter member id to find: ");
        memberList.print(sc.nextInt());
        sc.nextLine();
    }

    @Override
    public void showAllMembers() {
        memberList.printAll();
    }

    @Override
    public void showAllBooks() {
        bookList.printAll();
    }

    @Override
    public void issueBook() {
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

    @Override
    public void addBook(){
        bookList.addBook();
    }

    @Override
    public void searchBook() {
        System.out.println("Enter book id to search: ");
        bookList.print(sc.nextInt());
        sc.nextLine();
    }


    @Override
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


}

public class Main {
    public static void spacing(){
        System.out.println();
        System.out.println();
    }
    public static String allChoices(){
        return "1. Add Member\n" +
                "2. Add Book\n" +
                "3. Issue Book\n" +
                "4. Return Book\n" +
                "5. Show all books\n" +
                "6. Show all members\n" +
                "7. Search Member\n" +
                "8. Search Book\n" +
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
                    libraryManagement.issueBook(); //for borrow
                    break;
                case 4:
                    libraryManagement.returnBook(); //for return
                    break;
                case 5:
                    spacing();
                    libraryManagement.showAllBooks();
                    spacing();
                    break;
                case 6:
                    spacing();
                    libraryManagement.showAllMembers();
                    spacing();
                    break;
                case 7:
                    spacing();
                    libraryManagement.searchMember();
                    spacing();
                    break;
                case 8:
                    libraryManagement.searchBook();
                    spacing();
                    break;

                default:
                    break;

            }
        }
    }
}
