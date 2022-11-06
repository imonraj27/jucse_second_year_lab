package Question04.memberlist;

public class Member {
    private final int member_id;
    private String name;
    private String dob;
    private int number_of_taken;
    private final static int MAX_BOOKS = 5;

    Member() {
        this.member_id = -1;
        this.name = "";
        this.dob = "";
        this.number_of_taken = 0;
    }

    public Member(int member_id, String name, String dob) {
        this.member_id = member_id;
        this.name = name;
        this.dob = dob;
        this.number_of_taken = 0;
    }

    public int getMember_id() {
        return member_id;
    }

    public void updateNumberTaken(int p) {
        this.number_of_taken += p;
    }

    public boolean canTakeBook() {
        return this.number_of_taken < Member.MAX_BOOKS;
    }

    public String getName() {
        return name;
    }

    public String getDob() {
        return dob;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setDob(String dob) {
        this.dob = dob;
    }

    public void print() {
        System.out.println("==================================================");
        System.out.println("Member Id: " + this.member_id);
        System.out.println("Name: " + this.name);
        System.out.println("Date of Birth: " + this.dob);
        System.out.println("Number of taken books: " + this.number_of_taken);
        System.out.println("Can take books: " + (Member.MAX_BOOKS - this.number_of_taken));
        System.out.println("===================================================");
    }
}
