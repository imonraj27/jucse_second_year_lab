package Question06;

public class Main {
    public static void main(String[] args) {
        int i = 10;
        Integer I = i;
        System.out.println("Basic type to Wrapper Class Object: " + I);

        Integer J = Integer.valueOf(12);
        int j = J.intValue();

        System.out.println("Wrapper class object to basic type: " + j);
        System.out.println("Object to string: " + J.toString());

        Integer K = Integer.valueOf("10");
        System.out.println("String to Object: " + K);
    }
}
