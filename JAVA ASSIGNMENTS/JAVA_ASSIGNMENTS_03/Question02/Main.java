package Question02;

import java.util.ArrayList;
import java.util.Scanner;

class Account {
    private long account_number;
    private String account_holder;
    private long balance;

    Account(){}

    Account(long account_number, String account_holder, long balance){
        this.account_holder = account_holder;
        this.account_number = account_number;
        this.balance = balance;
    }

    public long getAccount_number() {
        return account_number;
    }

    public void updateBalance(long amount){
        if((amount+this.balance)<0){
            System.out.println("Not sufficient balance...Sorry....");
            return;
        }

        this.balance += amount;
    }

    public void print(){
        System.out.println("=========================");
        System.out.println("Account Number: "+this.account_number);
        System.out.println("Account Holder: "+this.account_holder);
        System.out.println("Account Balance: "+this.balance);
        System.out.println("=========================");
    }
}

class AllAccounts {
    final private ArrayList<Account> list = new ArrayList<Account>();
    final private  Scanner sc = new Scanner(System.in);

    public Account accountExists(long account_number){
      for (Account acc: this.list){
          if(acc.getAccount_number()==account_number)
              return acc;
      }
      return null;
    }

    public void accountExists(){
        System.out.println("Enter account number to check: ");
        long acc_num = sc.nextLong();
        sc.nextLine();

        Account acc = accountExists(acc_num);

        if(acc==null){
            System.out.println("No Such Account...sorry...");
            return;
        }

        System.out.println("-----ACCOUNT FOUND-----");
        acc.print();

    }

    public void addAccount(){

        System.out.println("Enter Account number: ");
        long account_number = sc.nextLong();
        sc.nextLine();

        if(accountExists(account_number)!=null){
            System.out.println("This account Number already exists....");
            return;
        }

        System.out.println("Enter account holder's name: ");
        String name = sc.nextLine();

        System.out.println("Enter account balance: ");
        long balance = sc.nextLong();
        sc.nextLine();

        Account acc = new Account(account_number, name, balance);

        this.list.add(acc);
        System.out.println("Account successfully added....");


    }

    public void provideAccBalance(){
        System.out.println("Enter account number: ");
        long acc_num = sc.nextLong();
        sc.nextLine();

        Account acc = accountExists(acc_num);

        if(acc==null){
            System.out.println("No such account...sorry...");
            return;
        }

        System.out.println("Enter amount to transaction(+ve for credit and -ve for debit): ");
        long amnt = sc.nextLong();
        sc.nextLine();

        acc.updateBalance(amnt);

    }

    public void displayAll(){
        System.out.println("---------------ALL ACCOUNTS--------------");
        for (Account acc : this.list){
            acc.print();
        }
        System.out.println("-----------------------------------------\n");
    }
}

public class Main {
    public static void options(){
        System.out.println("1. Update Account Balance");
        System.out.println("2. Add Account");
        System.out.println("3. Check Account Existance");
        System.out.println("4. Display All Accounts");
        System.out.println("0. EXIT ");
        System.out.println();
        System.out.println("ENTER YOUR OPTION: ");
    }
    public static void main(String[] args) {
        AllAccounts all = new AllAccounts();

        short option;
        Scanner sc = new Scanner(System.in);

        while (true){
            options();
            option = sc.nextShort();
            sc.nextLine();

            if(option==0)
                break;

            switch (option){
                case 1:
                    all.provideAccBalance();
                    break;
                case 2:
                    all.addAccount();
                    break;
                case 3:
                    all.accountExists();
                    break;
                case 4:
                    all.displayAll();
                    break;
                default:
                    System.out.println("choose valid option please");
                    break;
            }
        }
    }
}
