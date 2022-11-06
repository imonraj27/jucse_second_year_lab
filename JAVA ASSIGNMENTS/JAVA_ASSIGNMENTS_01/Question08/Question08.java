/* 8. Add constructors in the Student class of earlier problem so that
 objects can be created with i) roll only, ii) roll and name only,
  iii) roll, name and score, iv) no value. Also include a copy 
  constructor. Check whether constructors are working or not. Verify,
   copy constructor results into deep coy or not. */

public class Question08 {
    public static void main(String[] args) {
        // constructors with various number of args
        Student s1 = new Student(12);
        Student s2 = new Student(13, "Imon Raj");
        Student s3 = new Student(14, "Aman Raj", 45);
        Student s4 = new Student();
        Student s5 = new Student(s3);

        System.out.println("--------------------------------");
        s1.show();
        System.out.println("--------------------------------");
        s2.show();
        System.out.println("--------------------------------");
        s3.show();
        System.out.println("--------------------------------");
        s4.show();
        System.out.println("--------------------------------");
        s5.show();
    }
}
