package Question04;


import java.io.*;
import java.util.ArrayList;
import java.util.Scanner;

class HandleNamesFile {
    private File file;
    private FileWriter fileWriter;

    public void initFile(){
        this.file = new File("names.txt");
    }

    public void storeNames(ArrayList<String> names) throws IOException {
        this.fileWriter = new FileWriter(this.file);
        for(String name: names){
            fileWriter.write(name+"\n");
        }
        fileWriter.close();
    }

    public void showNames() throws IOException {
        Scanner sc = new Scanner(this.file);

        while(sc.hasNextLine()){
            System.out.println(sc.nextLine());
        }
    }
}

public class Main {
    public static void main(String[] args) {
        HandleNamesFile handleNamesFile = new HandleNamesFile();
        handleNamesFile.initFile();

        ArrayList<String> Names = new ArrayList<String>();
        Scanner sc = new Scanner(System.in);

        while(true){
            System.out.println("Enter name: ");
            Names.add(sc.nextLine());

            System.out.println("Do you want to add a more name(y/n): ");
            if(sc.nextLine().equals("n")){
                break;
            }
        }

    //    String[] names = (String[]) Names.toArray();

        try {
            handleNamesFile.storeNames(Names);
            System.out.println("Names stored in the file are: ");
            handleNamesFile.showNames();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
