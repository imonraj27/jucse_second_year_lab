package Question03;

import java.util.Scanner;

class Data {
     private int count;
    synchronized public void readData(){
        System.out.println("READING NOW....");
        System.out.println("Count: "+this.count);
    }
    synchronized public void writeData(int val){
        System.out.println("WRITING NOW....");
        this.count+=val;
    }
}

class ReaderWriterSync {
    private Data d;
    private int read_count;
    private int write_count;
    private int read_req;
    private int write_req;
    private Scanner sc = new Scanner(System.in);

    ReaderWriterSync(){
        this.d = new Data();
    }

    synchronized public void readLock() throws InterruptedException {
        System.out.println("------------READ REQUEST INITIATED---------------");

        if(write_count>0 || read_req>0){
            read_req++;
            System.out.println("Someone else is writing...please wait...");
            wait();
        }
        read_req--;
        this.read_count++;
    }

    synchronized public void readUnlock(){
        this.read_count--;
        notifyAll();
    }

    synchronized public void writeLock() throws InterruptedException {
        System.out.println("------------WRITE REQUEST INITIATED---------------");

        if (write_count>0 || read_count>0){
            write_req++;
            System.out.println("Someone else is writing or reading...please wait...");
           wait();
        }
        write_req--;
        this.write_count++;

    }

    synchronized public void writeUnlock(){
        this.write_count--;
        notifyAll();
    }
}

class ReaderThread extends Thread {
    private ReaderWriterSync rws;
    private Data d;

    ReaderThread(ReaderWriterSync rws, Data d){
        this.rws = rws;
        this.d = d;
    }

    public void run() {
        for (int i = 0; i < 10; i++) {
            try {
                rws.readLock();
//                System.out.println("READING NOW....");
                d.readData();
                Thread.sleep(2000);
                rws.readUnlock();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }


}

class WriterThread extends Thread {
    private ReaderWriterSync rws;
    private Data d;

    WriterThread(ReaderWriterSync rws, Data d){
        this.rws = rws;
        this.d = d;
    }


    public void run() {
        for (int i = 0; i < 10; i++) {
            try {
                rws.writeLock();
                d.writeData(1);
                Thread.sleep(1000);
                rws.writeUnlock();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
    }
}

public class Main {
    public static void main(String[] args) {
        ReaderWriterSync rws = new ReaderWriterSync();
        Data d = new Data();
        ReaderThread rt = new ReaderThread(rws,d);
//        ReaderThread rt2 = new ReaderThread(rws,d);
        WriterThread wt = new WriterThread(rws,d);
//        WriterThread wt2 = new WriterThread(rws,d);

        rt.start();
//        rt2.start();
        wt.start();
//        wt2.start();

        try {
            rt.join();
//            rt2.join();
            wt.join();
//            wt2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

    }
}
