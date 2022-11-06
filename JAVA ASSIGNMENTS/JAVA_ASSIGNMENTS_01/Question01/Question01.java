/* 1. Write a program to accept two short integers from user and display the sum. */

import java.util.Scanner;

public class Question01 {
    short a;
    short b;

    Question01(short a, short b) {
        this.a = a;
        this.b = b;
    }

    short Sum() {
        return (short) (this.a + this.b);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); // NEW SCANNER OBJECT FOR TAKING VALUES

        System.out.print("Enter first short: ");
        short a = sc.nextShort(); // TAKING FIRST SHORT TYPE

        System.out.print("Enter second short: ");
        short b = sc.nextShort(); // TAKING SECOND SHORT TYPE

        sc.close();

        Question01 obj = new Question01(a, b);
        System.out.println("Sum of two shorts is: " + obj.Sum()); // PRINTING THE SUM OF TWO SHORTS
    }
}