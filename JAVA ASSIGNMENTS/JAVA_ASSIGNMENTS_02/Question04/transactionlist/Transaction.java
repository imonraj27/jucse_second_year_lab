package Question04.transactionlist;

public class Transaction {
    final private int member_id;
    final private int book_id;
    private boolean bookReturned;

    public Transaction() {
        this.member_id = -1;
        this.book_id = -1;
        this.bookReturned = false;
    }

    public Transaction(int member_id, int book_id) {
        this.member_id = member_id;
        this.book_id = book_id;
        this.bookReturned = false;
    }

    public int getMember_id() {
        return member_id;
    }

    public int getBook_id() {
        return book_id;
    }

    public boolean isBookReturned() {
        return bookReturned;
    }

    public boolean wasValidBorrow() {
        return !this.bookReturned;
    }

    public void returnBook() {
        this.bookReturned = true;
    }

    public void print() {
        System.out.println("Member Id: " + this.member_id);
        System.out.println("Book Id: " + this.book_id);
        System.out.println("Status: " + ((this.bookReturned) ? "RETURNED" : "NOT RETURNED"));
    }
}
