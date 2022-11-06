package Question03.transactionlist;

public class TransactionList {
    final private Transaction[] transactions = new Transaction[500];
    int index_of_last_transaction;

    public TransactionList(){
        this.index_of_last_transaction = -1;
    }

    public Transaction isValidTransaction(int member_id, int book_id){
        for (int i = 0; i <= this.index_of_last_transaction; i++) {
            if(this.transactions[i].getBook_id() == book_id && this.transactions[i].getMember_id() == member_id){
                return this.transactions[i];
            }
        }
        return null;
    }

    public boolean addTransaction(int member_id, int book_id){
        Transaction t = isValidTransaction(member_id, book_id);

        if(t!=null){
            return false;
        }

        t = new Transaction(member_id, book_id);

        try{
            this.transactions[++this.index_of_last_transaction] = t;
            return true;
        }catch (ArrayIndexOutOfBoundsException e){
            this.index_of_last_transaction--;
            return false;
        }
    }

    public void printAll(){
        for (int i = 0; i <= this.index_of_last_transaction; i++) {
            System.out.println("----------------------");
            this.transactions[i].print();
            System.out.println("----------------------");
        }
    }


}
