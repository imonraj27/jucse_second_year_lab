package Question03.booklist;

public class Book {
    final private int book_id;
    private String title;
    private int total_copies;
    private int available_copies;

    public Book() {
        this.book_id = -1;
        this.title = "";
        this.total_copies = 0;
        this.available_copies = 0;
    }

    public int getBook_id() {
        return book_id;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setTotal_copies(int total_copies) {
        this.total_copies = total_copies;
    }

    public void setAvailable_copies(int available_copies) {
        this.available_copies = available_copies;
    }

    public String getTitle() {
        return title;
    }

    public int getTotal_copies() {
        return total_copies;
    }

    public int getAvailable_copies() {
        return available_copies;
    }

    public Book(int book_id, String title, int total_copies, int available_copies) {
        this.book_id = book_id;
        this.title = title;
        this.total_copies = total_copies;
        this.available_copies = available_copies;
    }

    public void updateCopy(int copy) {
        this.available_copies += copy;
    }

    public void newCopies(int n){
        this.available_copies+=n;
        this.total_copies+=n;
    }

    public boolean available() {
        return (this.available_copies != 0);
    }

    public void print() {
        System.out.println("======================================");
        System.out.println("Book Id: " + this.book_id);
        System.out.println("Title: " + this.title);
        System.out.println("Total copies: " + this.total_copies);
        System.out.println("Available copies: " + this.available_copies);
        System.out.println("======================================");
    }
}
