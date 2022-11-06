package Question01;

import java.util.*;

class Department {
    private int dept_code;
    private String dept_name;
    private String location;

    public Department() {
    }

    public Department(int dept_code, String dept_name, String location) {
        this.dept_code = dept_code;
        this.dept_name = dept_name;
        this.location = location;
    }

    public int getDept_code() {
        return dept_code;
    }

    public void print(){
        System.out.println("=====================================");
        System.out.println("Dept name: "+this.dept_name);
        System.out.println("Dept Code: "+this.dept_code);
        System.out.println("Dept Location: "+this.location);
        System.out.println("=====================================");
    }
}

class DepartmentList {
    final private ArrayList<Department> dList = new ArrayList<Department>();
    //final private LinkedList<Department> dList = new LinkedList<Department>();

    /*FOR LINIKED LIST IMPLEMENTATION ONLY THE DECLARATION OF THE COLLECTION CLASS WILL BE DIFFERENT AS
     * MENTIONED ABOVE AND THE FUNCTIONS WHICH ARE USED THROUGHOUT THE PROGRAM ARE SAME FOR BOTH ARRAYLIST
     * AND LINKED LIST COLLECTION CLASS*/


    public Department searchDept(int dept_code){
        /*RETURNS THE REFERENCE TO THE PARTICULAR DEPARTMENT
        * OBJECT IF FOUND OTHERWISE RETURNS NULL*/
        for (Department dept: this.dList){
            if(dept.getDept_code()==dept_code){
                return dept;
            }
        }
        return null;
    }

    public void printAll(){
        for (Department dept: this.dList){
            dept.print();
        }
    }

    public void addDept(int dept_code, String dept_name, String dept_location){
        Department dept = new Department(dept_code, dept_name, dept_location);
        this.dList.add(dept);
    }
}

class Employee {
    private int emp_code;
    private long basic;
    private String name;
    private int dept_code;


    public int getEmp_code() {
        return emp_code;
    }

    public int getDept_code() {
        return dept_code;
    }

    public Employee() {
    }

    public Employee(int emp_code, long basic, String name, int dept_code) {
        this.emp_code = emp_code;
        this.basic = basic;
        this.name = name;
        this.dept_code = dept_code;
    }

    public void print(){
        System.out.println("======================================");
        System.out.println("Employee Name: "+this.name);
        System.out.println("Employee Code: "+this.emp_code);
        System.out.println("Employee Basic Pay: "+this.basic);
        System.out.println("Department Code: "+this.dept_code);
        System.out.println("======================================");
    }

    public void setBasic(long basic){
        this.basic = basic;
    }

    public long getBasic() {
        return this.basic;
    }
}

class CompareDescBasic implements Comparator<Employee> {
    @Override
    public int compare(Employee o1, Employee o2) {
        long res = o2.getBasic()-o1.getBasic();
        if(res==0){
            return 0;
        }
        if(res>0){
            return 1;
        }
        return -1;
    }
}

class CompareDeptCode implements Comparator<Employee>{
    @Override
    public int compare(Employee o1, Employee o2) {
       return o1.getDept_code() - o2.getDept_code();
    }
}

class CompareEmpCode implements Comparator<Employee>{
    @Override
    public int compare(Employee o1, Employee o2) {
        return o1.getEmp_code() - o2.getEmp_code();
    }
}

class EmployeeList {
    final private ArrayList<Employee> eList = new ArrayList<Employee>();
    //final private LinkedList<Employee> eList = new LinkedList<Employee>();

    /*FOR LINIKED LIST IMPLEMENTATION ONLY THE DECLARATION OF THE COLLECTION CLASS WILL BE DIFFERENT AS
    * MENTIONED ABOVE AND THE FUNCTIONS WHICH ARE USED THROUGHOUT THE PROGRAM ARE SAME FOR BOTH ARRAYLIST
    * AND LINKED LIST COLLECTION CLASS*/

    public Employee searchEmp(int emp_code){
        /*RETURNS THE REFERENCE TO THE PARTICULAR DEPARTMENT
         * OBJECT IF FOUND OTHERWISE RETURNS NULL*/
        for(Employee emp: this.eList){
            if(emp.getEmp_code()==emp_code){
                return emp;
            }
        }
        return null;
    }

    public void printAll(){
        for(Employee emp: this.eList){
            emp.print();
        }
    }

    public void addEmp(int emp_code, long basic, String name, int dept_code) {
        Employee emp = new Employee(emp_code, basic, name, dept_code);
        this.eList.add(emp);
    }

    public void removeEmp(Employee emp){
        this.eList.remove(emp);
    }

    public long totalBasic(int dept_code){
        long totBasic = 0;
        for(Employee e: this.eList){
            if(e.getDept_code()==dept_code){
                totBasic+=e.getBasic();
            }
        }
        return totBasic;
    }

    public void sortDescBasic() {
        Collections.sort(this.eList, new CompareDescBasic());
    }

    public void sortDeptCode(){
        Collections.sort(this.eList, new CompareDeptCode());
    }

    public void sortEmpCode(){
        Collections.sort(this.eList, new CompareEmpCode());
    }
}


class EmpDeptSystem {
    final private DepartmentList departmentList = new DepartmentList();
    final private EmployeeList employeeList = new EmployeeList();
    final private Scanner sc = new Scanner(System.in);

    public void addEmployee(){
        System.out.println("Enter employee code: ");
        int emp_code = sc.nextInt();
        sc.nextLine();
        Employee emp = this.employeeList.searchEmp(emp_code);

        if(emp!=null){
            System.out.println("Employee code already exists...");
            return;
        }

        System.out.println("Enter department code: ");
        int dept_code = sc.nextInt();
        sc.nextLine();

        Department dept = this.departmentList.searchDept(dept_code);

        if(dept==null){
            System.out.println("No such department...");
            return;
        }



        System.out.println("Enter employee name: ");
        String emp_name = sc.nextLine();

        System.out.println("Enter employee basic pay: ");
        long emp_basic = sc.nextLong();
        sc.nextLine();

       this.employeeList.addEmp(emp_code, emp_basic, emp_name, dept_code);

    }

    public void addDepartment(){
        System.out.println("Enter Department code: ");
        int dept_code = sc.nextInt();
        sc.nextLine();

        Department dept = this.departmentList.searchDept(dept_code);

        if(dept!=null){
            System.out.println("Department Code already exists..");
            return;
        }

        System.out.println("Enter department name: ");
        String dept_name = sc.nextLine();

        System.out.println("Enter department location: ");
        String dept_location = sc.nextLine();

        this.departmentList.addDept(dept_code,dept_name,dept_location);
    }

    public void searchEmployee(){
        System.out.println("Enter employee code: ");
        int emp_code = sc.nextInt();

        Employee emp = this.employeeList.searchEmp(emp_code);

        if(emp==null){
            System.out.println("No Such employee...");
            return;
        }

        emp.print();
        System.out.println("---department---");
        this.departmentList.searchDept(emp.getDept_code()).print();
    }

    public void printAllEmployee(){
        this.employeeList.printAll();
    }

    public void printAllDept(){
        this.departmentList.printAll();
    }

    public void removeEmp(){
        System.out.println("Employee code to remove: ");
        Employee emp = this.employeeList.searchEmp(sc.nextInt());
        sc.nextLine();

        if(emp==null){
            System.out.println("No such employee...");
            return;
        }

        this.employeeList.removeEmp(emp);
    }

    public void modifyEmpBasic(){
        System.out.println("Enter employee code: ");
        Employee emp = this.employeeList.searchEmp(sc.nextInt());
        sc.nextLine();

        if(emp==null){
            System.out.println("No such employee...");
            return;
        }

        System.out.println("Enter new Basic: ");
        long basic = sc.nextLong();

        emp.setBasic(basic);
    }

    public void totalBasicDept(){
        System.out.println("Enter department code to find total basic pay: ");
        int dept_code = sc.nextInt();
        sc.nextLine();

        Department dept = this.departmentList.searchDept(dept_code);

        if(dept==null){
            System.out.println("No Such department");
            return;
        }

        long totalBasic = this.employeeList.totalBasic(dept_code);

        System.out.println("--------------Total Basic pay of Department-----------------------------");
        System.out.println("////--------- AMOUNT:"+totalBasic+" ------------////");
        dept.print();
        System.out.println("-------------------------------------------------------------------------");
    }

    public void sortDescBasic(){
        this.employeeList.sortDescBasic();
        System.out.println("Employee list sorted in descending order of basic pay....");
    }


    public void sortDeptCode(){
        this.employeeList.sortDeptCode();
        System.out.println("Employee list sorted according to dept code....");
    }

    public void sortEmpCode(){
        this.employeeList.sortEmpCode();
        System.out.println("Employee list sorted according to employee code....");
    }
}

public class Main {
    public static void options(){
        System.out.println("1. ADD EMPLOYYEE");
        System.out.println("2. ADD DEPARTMENT");
        System.out.println("3. DISPLAY EMPLOYEE DETAILS ALONG WITH HIS/HER DEPT");
        System.out.println("4. FIND TOTAL BASIC OF A DEPARTMENT");
        System.out.println("5. DETAILS OF ALL EMPLOYEES");
        System.out.println("6. REMOVE AN EMPLOYEE");
        System.out.println("7. MODIFY BASIC OF AN EMPLOYEE");
        System.out.println("8. PRINT ALL DEPARTMENTS");
        System.out.println("9. SORT EMPLOYEES DESCENDING OF BASIC PAY");
        System.out.println("10. SORT EMPLOYEES WITH DEPARTMENT CODE");
        System.out.println("11. SORT EMPLOYEES WITH EMPLOYEE CODE");
        System.out.println("0. EXIT");
        System.out.println("\nEnter your option: ");
    }
    public static void main(String[] args) {
        EmpDeptSystem empDeptSystem = new EmpDeptSystem();
        Scanner sc = new Scanner(System.in);

        int choice;

        while(true){
            options();
            choice = sc.nextInt();
            sc.nextLine();

            if(choice==0)
                break;

            switch (choice){
                case 1:
                    empDeptSystem.addEmployee();
                    break;
                case 2:
                    empDeptSystem.addDepartment();
                    break;
                case 3:
                    empDeptSystem.searchEmployee();
                    break;
                case 4:
                    empDeptSystem.totalBasicDept();
                    break;
                case 5:
                    empDeptSystem.printAllEmployee();
                    break;
                case 6:
                    empDeptSystem.removeEmp();
                    break;
                case 7:
                    empDeptSystem.modifyEmpBasic();
                    break;
                case 8:
                    empDeptSystem.printAllDept();
                    break;
                case 9:
                    empDeptSystem.sortDescBasic();
                    break;
                case 10:
                    empDeptSystem.sortDeptCode();
                    break;
                case 11:
                    empDeptSystem.sortEmpCode();
                    break;
                default:
                    System.out.println("Please enter valid option");
                    break;
            }
        }

    }
}
