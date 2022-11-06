/* 3. Write a program that accepts height in cm as int and displays the height 
in feet and inches. Assume, 1 inch equals to 2.54 cm and 1 foot equals to 30.5 cm. */

import java.util.Scanner;

public class Question03 {

    static void convertHeight(int cmheight) { // convert centimeter height to Feet and inches
        float cm_to_inch_ratio = 2.54F;
        float cm_to_foot_ratio = 30.5F;

        int foot = (int) (cmheight / cm_to_foot_ratio);
        float inch = (cmheight - foot * cm_to_foot_ratio) / cm_to_inch_ratio;

        System.out.println("The height is: " + foot + "\' " + (int) inch + "\"");
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the height in CM: ");
        int cmheight = sc.nextInt();
        sc.close();

        convertHeight(cmheight);
    }
}
