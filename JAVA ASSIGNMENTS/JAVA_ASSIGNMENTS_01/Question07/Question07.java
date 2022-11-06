/* 7. Design and implement Student class with roll, name and score as attributes. It will have methods to
set attributes (attribute values passed as arguments), display the attributes, copy (that copies the
content of invoking object to another object passed as argument). Verify that methods are working
properly. */

import java.util.Scanner;

class Student {
    int roll;
    String name;
    int score;

    // different types of constructors
    public Student() {
        System.out.println("No args Constructor called");
    }

    public Student(int roll) {
        this.roll = roll;
        System.out.println("roll arg Constructor called");
    }

    public Student(int roll, String name) {
        this.roll = roll;
        this.name = name;
        System.out.println("roll, name args Constructor called");
    }

    public Student(int roll, String name, int score) {
        this.roll = roll;
        this.name = name;
        this.score = score;
        System.out.println("roll, name, score args Constructor called");
    }

    public Student(Student s) { // the copy constructors
        this.roll = s.roll;
        this.name = s.name;
        this.score = s.score;
        System.out.println("Copy Constructor called");
    }

    // getters and setters

    void setRoll(int roll) {
        this.roll = roll;
    }

    void setName(String name) {
        this.name = name;
    }

    void setScore(int score) {
        this.score = score;
    }

    void showRoll() {
        System.out.println("Roll: " + this.roll);
    }

    void showScore() {
        System.out.println("Score: " + this.score);
    }

    void showName() {
        System.out.println("Name: " + this.name);
    }

    void show() { // for showing
        showName();
        showRoll();
        showScore();
    }

}

public class Question07 {
    public static void main(String[] args) {
        Student s1 = new Student();

        Scanner sc = new Scanner(System.in);
        System.out.print("Enter name: ");
        String name = sc.nextLine();
        s1.setName(name);

        System.out.print("Enter roll: ");
        int roll = sc.nextInt();
        s1.setRoll(roll);

        System.out.print("Enter score: ");
        int score = sc.nextInt();
        s1.setScore(score);

        System.out.println("----------Student's data----------------");
        s1.show();

        Student s2 = s1;

        System.out.println("----------New copy Student's data after copy----------------");
        s2.show();

        sc.close();
    }
}
