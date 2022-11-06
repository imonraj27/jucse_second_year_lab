package Question03;

import java.io.File;
import java.io.IOException;
import java.util.Scanner;

class HandleFile {
    private File file;


    public void initFile(String filename){
        file = new File(filename);
    }

    public void createFile(){
        try {
            this.file.createNewFile();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public boolean isFileExists(){
        return this.file.exists();
    }

    public boolean isFileDirectory() {
        return this.file.isDirectory();
    }

    public void showList(){
        String[] files_list = this.file.list();

        if (files_list != null) {
            for(String fileItem: files_list){
                System.out.println(fileItem);
            }
        }else{
            System.out.println("No files inside this directory");
        }
    }

    public void canBeRead(){
        if(this.file.canRead()){
            System.out.println("It Can Be Read...");
        }else{
            System.out.println("It can't be read...");
        }
    }

    public void canBeWritten(){
        if(this.file.canWrite()){
            System.out.println("It Can Be written...");
        }else{
            System.out.println("It can't be written...");
        }
    }


}

public class Main {
    public static void main(String[] args) {
        HandleFile handleFile = new HandleFile();

        System.out.println("Enter the filename: ");
        Scanner sc = new Scanner(System.in);

        handleFile.initFile(sc.nextLine());

        if(handleFile.isFileExists()){
            System.out.println("File already exists");
            if(handleFile.isFileDirectory()){
                System.out.println("It is a directory..\nFiles in the directory\n");
                handleFile.showList();
            }else{
                handleFile.canBeRead();
                handleFile.canBeWritten();
            }
        }else{
            handleFile.createFile();
            System.out.println("New File created");
        }
    }
}
