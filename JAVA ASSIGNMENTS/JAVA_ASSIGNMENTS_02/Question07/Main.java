package Question07;

import java.util.Scanner;

public class Main {
    public static int count_of_substring(String str, String substr) {
        int index = 0, count = 0;
        while (true) {
            index = str.indexOf(substr, index);
            if (index != -1) {
                count++;
                index += substr.length();
            } else {
                break;
            }
        }
        return count;

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the input string: ");
        String str = sc.nextLine();

        System.out.println("Number of a's is: " + count_of_substring(str, "a"));
        System.out.println("Number of and's is: " + count_of_substring(str, "and"));

        if (str.startsWith("The")) {
            System.out.println("The string starts with 'The'");
        } else {
            System.out.println("The string DOESN'T start with 'The'");
        }

        char[] letters = str.toCharArray();

        System.out.print("\nThe character array becomes: {");
        for (char c : letters) {
            System.out.print("'" + c + "' ");
        }
        System.out.print("}\n");

        String[] tokens = str.split(" ");
        System.out.println("\n\nThe tokens:  ");
        for (String string : tokens) {
            System.out.print(string + ", ");
        }

        sc.close();
    }
}
