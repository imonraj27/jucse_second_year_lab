/* 2. Write a program that accepts number of command line parameters and displays the parameters and
count of such parameters. */

public class Question02 {
    public static void main(String[] args) { // Command lines arguements are being taken here
        System.out.println("\n\nNumber of arguments: " + args.length); // printing the number of arguements
        System.out.println("\nArguments are: ");
        for (int i = 0; i < args.length; i++) { // printing all arguements
            System.out.println(args[i]);
        }
    }
}
