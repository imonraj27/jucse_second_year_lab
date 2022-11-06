/* 11.  Each Instructor has name and phone number. One can view instructor information 
and set the information. Textbook has a title, author name and publisher. 
One can set the data for a textbook and view the same. Each course has a 
course name, instructor and text book. One can set the course data and view
 the same.  Design and implement the classes . */

import java.util.Scanner;

class Instructor { // Instructors class
    private String name;
    private String phone;

    public void setName(String name) {
        this.name = name;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public void showName() {
        System.out.println("Name of Instructor: " + this.name);
    }

    public void showPhone() {
        System.out.println("Phone of Instructor: " + this.phone);
    }

    public void setInstructor() {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter instructor name: ");
        setName(sc.nextLine());

        System.out.print("Enter instructor phone: ");
        setPhone(sc.nextLine());

        sc.close();
    }

    public void show() {
        showName();
        showPhone();
    }
}

class Textbook { // Textbook class
    private String title;
    private String author;
    private String publisher;

    public void setTitle(String title) {
        this.title = title;
    }

    public void setAuthor(String author) {
        this.author = author;
    }

    public void setPublisher(String publisher) {
        this.publisher = publisher;
    }

    public void setTextbook() { // setting textbook data
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter textbook title: ");

        setTitle(sc.nextLine());

        System.out.print("Enter textbook author: ");
        setAuthor(sc.nextLine());

        System.out.print("Enter textbook publisher: ");
        setPublisher(sc.nextLine());
    }

    public void showTitle() {
        System.out.println("Book Title: " + this.title);
    }

    public void showAuthor() {
        System.out.println("Book Author: " + this.author);
    }

    public void showPublisher() {
        System.out.println("Book Publisher: " + this.publisher);
    }

    public void show() {
        showTitle();
        showAuthor();
        showPublisher();
    }
}

class Course { // course class
    private String course_name;
    private Instructor ins = new Instructor();
    private Textbook txtbook = new Textbook();

    public void setCourse() { // setting course data
        System.out.print("Enter Course Name: ");
        Scanner sc = new Scanner(System.in);
        this.course_name = sc.nextLine();
        txtbook.setTextbook();
        ins.setInstructor();
        sc.close();
    }

    public void show() {
        System.out.println("----------COURSE DETAILS-------------");
        System.out.println("Course Name: " + this.course_name);
        System.out.println("--Instructor--");
        ins.show();
        System.out.println("--Textbook--");
        txtbook.show();
    }
}

public class Question11 {
    public static void main(String[] args) {
        Course c = new Course();
        c.setCourse();
        c.show();
    }
}
