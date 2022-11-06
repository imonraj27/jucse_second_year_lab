/*9. Design a BankAcct class with account number, balance and interest rate as attribute.
  Interest rate is same for all account. Support must be there to initialize, change and
   display the interest rate.  Also supports are to be there to return balance
    and calculate interest. */

class BankAcct {
    String account_number;
    double balance;
    static float rate; // rate is same for all accounts

    public static void setRate(float r) { // set rate value
        rate = r;
    }

    public static void showRate() { // show rate value
        System.out.println("The interest rate: " + rate);
    }

    public BankAcct(String account_number, double balance) {
        this.account_number = account_number;
        this.balance = balance;
    }

    public void calculateInterest() { // calculates interest
        System.out.println("Account Number: " + this.account_number);
        System.out.println("Interest: " + (this.balance * BankAcct.rate * 0.01));
    }

    public void showBalance() { // shows balance
        System.out.println("Account Number: " + this.account_number);
        System.out.println("Balance: " + this.balance);
    }
}

public class Question09 {
    public static void main(String[] args) {
        BankAcct acct = new BankAcct("1300455877", 12000);
        BankAcct.setRate(5);

        BankAcct.showRate();

        acct.showBalance();
        acct.calculateInterest();
    }
}
