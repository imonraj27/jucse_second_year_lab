package Question02;

import java.util.Scanner;

class Address {
    private int premises;
    private String state;
    private String city;
    private String pin;
    private String street;

    public int getPremises() {
        return this.premises;
    }

    public void setPremises(int premises) {
        this.premises = premises;
    }

    public String getState() {
        return this.state;
    }

    public void setState(String state) {
        this.state = state;
    }

    public String getCity() {
        return this.city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getPin() {
        return this.pin;
    }

    public void setPin(String pin) {
        this.pin = pin;
    }

    public String getStreet() {
        return this.street;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    @Override
    public String toString() {
        String str = "\nPremises: " + this.premises + "\nStreet: " + this.street + "\nCity: " + this.city + "\nState: "
                + this.state + "\nPin: " + this.pin;
        return str;
    }

}

class Person {
    protected String name;
    protected String phone;
    protected String email;
    protected Address address;
    protected Scanner sc;

    public Person(Scanner sc) {
        this.sc = sc;
        this.address = new Address();
    }

    public void modifyAddress() {
        System.out.println("Want to change premises? y/n: ");
        if (sc.nextLine().equals("y")) {
            System.out.println("Enter premises number: ");
            int premis = sc.nextInt();
            sc.nextLine();
            this.address.setPremises(premis);
        }

        System.out.println("Want to change city? y/n: ");
        if (sc.nextLine().equals("y")) {
            System.out.println("Enter city: ");
            String city = sc.nextLine();
            this.address.setCity(city);
        }

        System.out.println("Want to change street? y/n: ");
        if (sc.nextLine().equals("y")) {
            System.out.println("Enter street: ");
            String street = sc.nextLine();
            this.address.setStreet(street);
        }

        System.out.println("Want to change pin? y/n: ");
        if (sc.nextLine().equals("y")) {
            System.out.println("Enter pin: ");
            String pin = sc.nextLine();
            this.address.setPin(pin);
        }

        System.out.println("Want to change state? y/n: ");
        if (sc.nextLine().equals("y")) {
            System.out.println("Enter state: ");
            String state = sc.nextLine();
            this.address.setState(state);
        }
    }

    public void setAddress() {
        System.out.println("Enter the premises number: ");
        int premises = sc.nextInt();
        sc.nextLine();
        this.address.setPremises(premises);

        System.out.println("Enter the city: ");
        String city = sc.nextLine();
        this.address.setCity(city);

        System.out.println("Enter the Street: ");
        String street = sc.nextLine();
        this.address.setStreet(street);

        System.out.println("Enter the pin: ");
        String pin = sc.nextLine();
        this.address.setPin(pin);

        System.out.println("Enter the State: ");
        String state = sc.nextLine();
        this.address.setState(state);
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getPhone() {
        return this.phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public String getEmail() {
        return this.email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    @Override
    public String toString() {
        String str = "\nName: " + this.name + "\nPhone: " + this.phone + "\nEmail: " + this.email
                + this.address.toString();
        return str;
    }

}

class Student extends Person {
    private int roll;
    private String course;

    public Student(Scanner sc) {
        super(sc);
    }

    public int getRoll() {
        return this.roll;
    }

    public void setRoll(int roll) {
        this.roll = roll;
    }

    public String getCourse() {
        return this.course;
    }

    public void setCourse(String course) {
        this.course = course;
    }

    public void setStudentData() {
        System.out.println("Enter student's name: ");
        setName(sc.nextLine());

        System.out.println("Enter student's email: ");
        setEmail(sc.nextLine());

        System.out.println("Enter student's phone: ");
        setPhone(sc.nextLine());

        System.out.println("Enter student's address: ");
        setAddress();

        System.out.println("Enter student's roll: ");
        setRoll(Integer.parseInt(sc.nextLine()));

        System.out.println("Enter student course: ");
        setCourse(sc.nextLine());

    }

    @Override
    public String toString() {
        return super.toString() + "\n===STUDENT===" + "\nRoll: " + this.roll + "\nCourse: " + this.course;
    }
}

class Faculty extends Person {
    int empid;
    String dept;
    String specialisation;

    public Faculty(Scanner sc) {
        super(sc);
    }

    public void setEmpid(int empid) {
        this.empid = empid;
    }

    public void setDept(String dept) {
        this.dept = dept;
    }

    public void setSpecialisation(String specialisation) {
        this.specialisation = specialisation;
    }

    public void setFaculty() {
        System.out.println("Enter faculty's name: ");
        setName(sc.nextLine());

        System.out.println("Enter faculty's email: ");
        setEmail(sc.nextLine());

        System.out.println("Enter faculty's phone: ");
        setPhone(sc.nextLine());

        System.out.println("Enter faculty's address: ");
        setAddress();

        System.out.println("Enter faculty's employee id: ");
        setEmpid(sc.nextInt());

        sc.nextLine();

        System.out.println("Enter faculty's department: ");
        setDept(sc.nextLine());

        System.out.println("Enter faculty's specialization: ");
        setSpecialisation(sc.nextLine());
    }

    @Override
    public String toString() {
        return super.toString() + "\n===FACULTY===" + "\nEmployee id: " + this.empid + "\nDepartment: " + this.dept
                + "\nSpecialization: " + this.specialisation;
    }

}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Student s = new Student(sc);

        System.out.println("========================TAKE STUDENT DATA==========================");
        s.setStudentData();

        System.out.println("========================STUDENT DATA==========================");
        System.out.println(s);

        Faculty f = new Faculty(sc);

        System.out.println("========================TAKE FACULTY DATA==========================");
        f.setFaculty();
        System.out.println("========================FACULTY DATA==========================");
        System.out.println(f);
    }
}
