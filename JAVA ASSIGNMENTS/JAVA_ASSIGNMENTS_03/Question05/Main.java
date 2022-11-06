package Question05;

import java.io.*;
import java.util.Scanner;

class Student implements Serializable{
    private int roll;
    private String name;
    private int score;


    Student(){

    }

    Student(int roll, String name, int score){
        this.name = name;
        this.score = score;
        this.roll = roll;
    }

    @Override
    public String toString() {
        return "\n=========================" +
                "\nRoll: " + this.roll +
                "\nName: " + this.name + '\'' +
                "\nScore: " + this.score+
                "\n========================";
    }
}

class HandleBinFile {
    private File file;
    private ObjectOutputStream fileout;
    private ObjectInputStream filein;

    public void createFile() throws IOException {
        file = new File("students.bin");
        if(!file.exists())
            file.createNewFile();

        this.fileout = new ObjectOutputStream(new FileOutputStream(this.file));
        this.filein = new ObjectInputStream(new FileInputStream(this.file));
    }

    public void addStudentToFile() throws IOException {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter Name of Student: ");
        String name = sc.nextLine();
        System.out.println("Enter Roll of Student: ");
        int roll = sc.nextInt();
        System.out.println("Enter Score of Student: ");
        int score = sc.nextInt();

        Student s = new Student(roll, name, score);

        this.fileout.writeObject(s);
    }

    public void showAllStudents() throws IOException, ClassNotFoundException {
        Student s;

        while(true){
            s=(Student) this.filein.readObject();
            if(s==null)
                break;
            System.out.println(s);
        }

    }
}

public class Main {
    public static void main(String[] args) {
        HandleBinFile handleBinFile = new HandleBinFile();
        try{
            handleBinFile.createFile();

            handleBinFile.addStudentToFile();
            handleBinFile.addStudentToFile();
            handleBinFile.addStudentToFile();
            handleBinFile.addStudentToFile();

            handleBinFile.showAllStudents();
        }catch (EOFException eof){
            System.out.println("File finished reading...");
        } catch (IOException | ClassNotFoundException e){
            System.out.println("Some error occured!!!");
        }

    }
}
