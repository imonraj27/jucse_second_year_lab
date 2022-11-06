package Question04.memberlist;

import java.util.Scanner;

public class MemberList {
    final private Member[] members = new Member[100];
    private int index_of_last_member;
    final private Scanner sc = new Scanner(System.in);

    public MemberList(){
        this.index_of_last_member = -1;
    }

    public Member findMemberWithId(int member_id){
        for (int i = 0; i <= this.index_of_last_member; i++) {
            if(this.members[i].getMember_id()==member_id){
                return this.members[i];
            }
        }
        return null;
    }

    public void addMember(){
        System.out.println("Enter Member id: ");
        int member_id = sc.nextInt();
        sc.nextLine();

        Member m = findMemberWithId(member_id);
        if(m!=null){
            System.out.println("Member id already taken...");
            return;
        }

        try{
            this.members[++this.index_of_last_member] = new Member();
        }catch(ArrayIndexOutOfBoundsException e){
            System.out.println("Member list is full..Sorry");
            this.index_of_last_member--;
            return;
        }


        System.out.println("Enter Member's name: ");
        String name = sc.nextLine();
        System.out.println("Enter Member's Date of birth: ");
        String dob = sc.nextLine();

        m = new Member(member_id, name, dob);

        this.members[this.index_of_last_member] = m;
        System.out.println("Member successfully added to the list..");

    }

    public void printAll(){
        for (int i = 0; i <= this.index_of_last_member; i++) {
            this.members[i].print();
        }
    }

    public void print(int member_id){
        Member m = findMemberWithId(member_id);
        if(m==null) {
            System.out.println("No Such Member found....");
            return;
        }

        m.print();
    }

}
