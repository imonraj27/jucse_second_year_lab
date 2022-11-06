
/**4. Write a program that accepts radius of a circle and displays 
 * area of the circle. Declare a constant pi equals to 3.14. */

import java.util.Scanner;

public class Question04 {
    final static float PI = 3.14F; // Pi is a constant

    static float showArea(float radius) { // calculates area of circle with radius as arguements
        return (float) (PI * radius * radius);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the radius of circle: ");
        float radius = sc.nextFloat();
        sc.close();

        float area = showArea(radius);

        System.out.println("The area of circle is: " + area);
    }
}
