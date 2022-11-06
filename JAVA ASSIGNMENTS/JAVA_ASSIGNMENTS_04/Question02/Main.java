package Question02;

import java.util.Scanner;

class Data {
    private int counter;

    synchronized public void increment(int val){
        counter += val;
    }

    synchronized public void decrement(){
        counter -= 1;
    }

    public int getCounter(){
        return this.counter;
    }
}

class IncrementThread extends Thread {
    private Data d;
    public IncrementThread(Data d){
        super();
        this.d = d;
    }

    @Override
    public void run() {
        for (int i=0; i<4; i++){
            try {
                Thread.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("Some thing went wrong");
            }
            System.out.println("Enter value to increment: ");
            Scanner sc = new Scanner(System.in);
            this.d.increment(sc.nextInt());
            // System.out.println("Counter value: "+this.d.getCounter());
        }
    }
}

class DecrementThread extends Thread {
    private Data d;
    public DecrementThread(Data d){
        super();
        this.d = d;
    }
    @Override
    public void run() {
        for (int i=0; i<4; i++){
            try {
                Thread.sleep(3000);
            } catch (InterruptedException e) {
                System.out.println("Some thing went wrong");
            }
            this.d.decrement();
            // System.out.println("Counter value: "+this.d.getCounter());
        }
    }
}

public class Main {
    public static void main(String[] args) {
        Data d = new Data();
        IncrementThread incrementThread = new IncrementThread(d);
        IncrementThread incrementThread2 = new IncrementThread(d);
        DecrementThread decrementThread = new DecrementThread(d);
        DecrementThread decrementThread2 = new DecrementThread(d);

        incrementThread.start();
        incrementThread2.start();
        decrementThread.start();
        decrementThread2.start();

        try {
            incrementThread.join();
            incrementThread2.join();
            decrementThread.join();
            decrementThread2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }


        System.out.println("COUNTER VALUE: "+d.getCounter());

    }
}
