/* 10. Design a Metric class that supports Kilometre to Mile conversion with distance 
in Kilometre as argument and Mile to Kilometre conversion with distance in mile as argument. 
Assume, one Mile equals 1.5 Kilometre. */

import java.util.Scanner;

class Metric {
    float Kilometers;
    float Miles;

    public void printMetric() {
        System.out.println("Kilometers: " + Kilometers);
        System.out.println("Miles: " + Miles);
    }

    public void kmToMile(float km) { // km to mile converter
        this.Kilometers = km;
        this.Miles = (km / 1.5F);
        System.out.println("After Km to Mile Conversion: ");
        printMetric();
    }

    public void mileToKm(float miles) { // mile to km converter
        this.Miles = miles;
        this.Kilometers = miles * 1.5F;
        System.out.println("After Mile to Km Conversion: ");
        printMetric();
    }
}

public class Question10 {
    public static void main(String[] args) {
        Metric m = new Metric();
        System.out.print("Enter Kilometers value: ");
        Scanner sc = new Scanner(System.in);
        float km = sc.nextFloat();
        m.kmToMile(km);
        System.out.print("Enter Miles value: ");
        float miles = sc.nextFloat();
        m.mileToKm(miles);
        sc.close();
    }
}
