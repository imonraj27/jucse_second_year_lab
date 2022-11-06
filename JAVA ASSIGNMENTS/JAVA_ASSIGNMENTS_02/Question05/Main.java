package Question05;

import java.util.Scanner;

class InvalidScoreException extends Exception {
    @Override
    public String toString() {
        return "Score should be non-negative and can't exceed 100";
    }
}

class Student {
    long roll;
    String name;
    int score;

    public Student(String name, long roll) {
        this.name = name;
        this.roll = roll;
    }

    public void setScore() throws InvalidScoreException {
        System.out.println("Enter the score: ");
        Scanner sc = new Scanner(System.in);
        int score = sc.nextInt();

        if (score < 0 || score > 100) {
            sc.close();
            throw new InvalidScoreException();
        } else {
            this.score = score;
        }

        sc.close();
    }

    @Override
    public String toString() {
        String str = "Name: " + this.name + "\nRoll: " + this.roll + "\nScore: " + this.score;
        return str;
    }

}

public class Main {
    public static void main(String[] args) {
        Student s = new Student("Imon", 867667686);
        try {
            s.setScore();
        } catch (InvalidScoreException e) {
            System.out.println(e);
        }
        System.out.println(s);
    }
}
