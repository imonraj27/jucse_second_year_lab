/* 6. Write a program where class contains void show(int) to display the argument passed. Call the
function once with short as actual parameter and again double as actual parameter. Add another
function as void show(double) . Repeat the calls. Observe the outcomes in each case. */

public class Question06 {
    void show(int a) {
        System.out.println("Inside show(int) and int arg: " + a);
    }

    void show(double d) { // when this function was not there the double parameter pass would have thrown
                          // error
        System.out.println("Inside show(double) and double arg: " + d);
    }

    public static void main(String[] args) {
        Question06 obj = new Question06();
        short a = 12;
        obj.show(a);
        double d = 1300;
        obj.show(d);
    }
}
