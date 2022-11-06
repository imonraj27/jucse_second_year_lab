package Question01;

import java.util.Scanner;

class CustomerAccount {
    private String name;
    private String phone;
    private long current_loan_amount;
    private Scanner sc;

    private static long totalCredit;

    public CustomerAccount(Scanner sc) {
        CustomerAccount.totalCredit = 200000;
        this.sc = sc;
    }

    public CustomerAccount(String name, String phone, long current_loan_amount, Scanner sc, boolean p) {
        this.name = name;
        this.phone = phone;
        this.current_loan_amount = current_loan_amount;
        CustomerAccount.totalCredit = 200000;
        if (p) {
            CustomerAccount.totalCredit = 400000;
        }
        this.sc = sc;
    }

    public void askForLoan() {
        System.out.println("What is the lone amount you want: ");

        long loan = sc.nextLong();

        if (loan + this.current_loan_amount > CustomerAccount.totalCredit) {
            System.out.println("No more loan can be taken!!");

            return;
        }

        this.current_loan_amount += loan;
        System.out.println("Loan Successfully taken..");

    }

    public void showAcct() {
        System.out.println("----------ACCOUNT CREATED----------");
        System.out.println("Name: " + this.name);
        System.out.println("Phone: " + this.phone);
        System.out.println("Current Loan amount: " + this.current_loan_amount);
        System.out.println("Total credit amount: " + CustomerAccount.totalCredit);
        System.out.println("-----------------------------------");
    }

    public void showTotalCredit() {
        System.out.println("Credit limit is: " + CustomerAccount.totalCredit);
    }

    public void showCurrent() {
        System.out.println("Current Loan amount: " + this.current_loan_amount);
    }

    public void showMyAvailableLoan() {
        System.out.println("My available loan amount: " + (CustomerAccount.totalCredit - this.current_loan_amount));
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("\nEnter your name: ");
        String name = sc.nextLine();
        System.out.print("\nEnter your phone number: ");
        String phone = sc.nextLine();

        System.out.println("Is it a privileged account(y/n): ");
        String c = sc.next();

        boolean isPrivileged = c.equals("y");

        CustomerAccount acct = new CustomerAccount(name, phone, 0, sc, isPrivileged);

        acct.showAcct();

        while (true) {
            System.out.print(
                    "\n\n1. Ask For Loan\n2. Show Current loan\n3. Show Total Credit\n4. Show available amount to take\n\nENTER YOUR CHOICE(0 FOR EXIT):");
            byte choice = sc.nextByte();
            if (choice == 0) {
                break;
            }

            switch (choice) {
                case 1:
                    acct.askForLoan();
                    break;
                case 2:
                    acct.showCurrent();
                    break;
                case 3:
                    acct.showTotalCredit();
                    break;
                case 4:
                    acct.showMyAvailableLoan();
                    break;
                default:
                    break;
            }
        }

    }
}
