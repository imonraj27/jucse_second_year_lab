/*5. Write a program that accepts a String and assigns it to another. Check the outcome of comparison
with == and equals() method. Take two Strings and put same input for them. Repeat the equality
checking. Observe the outcome. */

import java.util.Scanner;

public class Question05 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the string: ");

        String str = sc.nextLine();

        String str2 = str;

        if (str == str2) { // this checks reference but not the stirng values
            System.out.println("Strings are == after assigning");
        }

        if (str.equals(str2)) { // this check string values
            System.out.println("Strings are equals() after assigning");
        }

        // ---------------SECOND PART-----------------------------

        System.out.print("Now enter first string: ");
        str = sc.nextLine();

        System.out.print("Now enter Second string: ");
        str2 = sc.nextLine();

        if (str == str2) { // this checks reference but not the stirng values
            System.out.println("Strings are == after individual value taking");
        } else {
            System.out.println("Strings are != after individual value taking");
        }

        if (str.equals(str2)) { // this check string values
            System.out.println("Strings are equals after individual value taking");
        } else {
            System.out.println("Strings are NOT equals() after individual value taking");
        }

        sc.close();
    }
}
