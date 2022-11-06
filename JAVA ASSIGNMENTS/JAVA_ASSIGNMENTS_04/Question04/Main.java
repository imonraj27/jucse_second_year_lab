package Question04;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

class Employee {
    private String emp_code;
    private String emp_name;
    private String emp_grade;
    private String emp_dept;

    public Employee() {
    }

    public Employee(String emp_code, String emp_name, String emp_grade, String emp_dept) {
        this.emp_code = emp_code;
        this.emp_name = emp_name;
        this.emp_grade = emp_grade;
        this.emp_dept = emp_dept;
    }

    public String getEmp_code() {
        return emp_code;
    }

    @Override
    public String toString() {
        return "<html><br><b>Employee Code</b>:- " + emp_code +
                "<br><b>Employee Name</b>:- " + emp_name +
                "<br><b>Employee Grade</b>:- " + emp_grade +
                "<br><b>Employee Department</b>:- " + emp_dept+"</html>";
    }
}

class Department {
    private String dept_code;
    private String dept_name;

    public Department() {
    }

    public Department(String dept_code, String dept_name) {
        this.dept_code = dept_code;
        this.dept_name = dept_name;
    }

    @Override
    public String toString() {
        return this.dept_code + " - " +  this.dept_name;
    }
}

class EmployeeList extends Component {
    ArrayList<Employee> employees = new ArrayList<Employee>();

    private boolean empCodeExists(String emp_code){
        for(Employee e: employees){
            if(e.getEmp_code().equals(emp_code)){
                return true;
            }
        }
        return false;
    }

    public Employee searchEmp(String emp_code){
        for(Employee e: employees){
            if(e.getEmp_code().equals(emp_code)){
                return e;
            }
        }
        return null;
    }

    public boolean addEmp(String emp_code, String emp_name, String emp_grade, String emp_dept){
        if(empCodeExists(emp_code)){
            JOptionPane.showMessageDialog(this, "This Employee Code "+emp_code+" already exists..",
                    "ERROR", JOptionPane.ERROR_MESSAGE);
            return false;
        }
        Employee e = new Employee(emp_code, emp_name, emp_grade, emp_dept);
        System.out.println(e);
        employees.add(e);
        return true;
    }
}

class EmployeeManagementFrame extends JFrame{
    private final JPanel jPanel = new JPanel();
    private final JPanel searchPanel = new JPanel();
    private final JLabel searchLabel = new JLabel("Enter Employee Code: ");
    private final JTextField searchEmpCode = new JTextField();
    private final JButton searchBtn = new JButton("Search");
    private final JLabel searchedDataLbl = new JLabel();
    final private JLabel nameLbl = new JLabel("Employee Name: ");
    final private JLabel codeLbl = new JLabel("Employee Code: ");
    final private JLabel gradeLbl = new JLabel("----------------------------Grades----------------------------");
    final private JTextField empName = new JTextField();
    final private JTextField empCode = new JTextField();
    final private JButton saveBtn = new JButton("SAVE");
    private JList<Department> deptList;
    private JList<String> gradeList;
    private JScrollPane gradeHolder;
    private JScrollPane deptHolder;
    private EmployeeList eList = new EmployeeList();
    EmployeeManagementFrame(){
        super("Employee Management System");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(700, 500);
        setLocationRelativeTo(null);
        setResizable(false);

        Department[] depts = {
                new Department("10", "COMPUTER SCIENCE"),
                new Department("20", "ELECTRICAL ENGG."),
                new Department("30", "ELECTRONICS ENGG."),
                new Department("40", "INFORMATION TECHNOLOGY"),
                new Department("50", "PRODUCTION ENGG."),
                new Department("60", "METALLURGY ENGG."),
        };
        this.deptList = new JList<>(depts);

        String[] grades = {"A", "B", "C"};
        this.gradeList = new JList<>(grades);



        nameLbl.setSize(140, 20);
        nameLbl.setLocation(40, 30);
        nameLbl.setFont(new Font("Verdana", Font.PLAIN, 14));
        empName.setSize(180, 20);
        empName.setLocation(180, 30);

        codeLbl.setSize(140, 20);
        codeLbl.setLocation(40, 60);
        codeLbl.setFont(new Font("Verdana", Font.PLAIN, 14));
        empCode.setSize(180, 20);
        empCode.setLocation(180, 60);

        deptList.setBorder(new EmptyBorder(5,10,5,5));
        gradeList.setBorder(new EmptyBorder(5,10,5,5));

        this.jPanel.setLayout(null);
        this.jPanel.add(empName);
        this.jPanel.add(empCode);
        this.jPanel.add(nameLbl);
        this.jPanel.add(codeLbl);

        deptHolder = new JScrollPane(deptList);
        deptHolder.setLocation(40, 90);
        deptHolder.setSize(280, 100);
        this.jPanel.add(deptHolder);

        gradeLbl.setSize(280, 20);
        gradeLbl.setLocation(40, 200);
        gradeLbl.setFont(new Font("Verdana", Font.PLAIN, 14));
        this.jPanel.add(gradeLbl);

        gradeHolder = new JScrollPane(gradeList);
        gradeHolder.setLocation(40, 230);
        gradeHolder.setSize(280, 60);
        this.jPanel.add(gradeHolder);

        saveBtn.setSize(100, 30);
        saveBtn.setLocation(140, 300);
        saveBtn.setFont(new Font("Verdana", Font.BOLD, 14));
        saveBtn.setBackground(Color.decode("#000000"));
        saveBtn.setForeground(Color.decode("#ffffff"));
        this.jPanel.add(saveBtn);

        /////////////////////////////////////////////////////

        searchLabel.setSize(140, 30);
        searchLabel.setLocation(20, 10);
        searchLabel.setFont(new Font("Verdana", Font.PLAIN, 14));

        searchEmpCode.setSize(180, 30);
        searchEmpCode.setLocation(170, 10);

        searchBtn.setSize(100,20);
        searchBtn.setLocation(20,50);
        searchBtn.setFont(new Font("Verdana", Font.BOLD, 14));

        searchedDataLbl.setSize(380, 300);
        searchedDataLbl.setLocation(30, 50);
        searchedDataLbl.setFont(new Font("Verdana", Font.ITALIC, 16));


        this.searchPanel.setLayout(null);
        this.searchPanel.add(searchLabel);
        this.searchPanel.add(searchEmpCode);
        this.searchPanel.add(searchLabel);
        this.searchPanel.add(searchBtn);
        this.searchPanel.add(searchedDataLbl);



        JTabbedPane tabs = new JTabbedPane();
        tabs.setBounds(40,20,300,300);
        tabs.add("New Employee Add", jPanel);
        tabs.add("Search Employee", searchPanel);


        add(tabs);
        setVisible(true);

        saveBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                int res = JOptionPane.showConfirmDialog(null, "ARE YOU SURE TO ADD THIS EMPLOYEE?", "CONFORMATION",
                        JOptionPane.YES_NO_OPTION,
                        JOptionPane.PLAIN_MESSAGE);
                if(res == 0) {
                    System.out.println("Pressed YES");
                    String emp_name = empName.getText();
                    String emp_code = empCode.getText();
                    String emp_grade = gradeList.getSelectedValue().toString();
                    String emp_dept = deptList.getSelectedValue().toString();

                    if(eList.addEmp(emp_code, emp_name, emp_grade, emp_dept)){
                        empName.setText("");
                        empCode.setText("");
                    }
                } else if (res == 1) {
                    System.out.println("Pressed NO");
                }



            }
        });

        searchBtn.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String emp_code = searchEmpCode.getText();
                Employee ee = eList.searchEmp(emp_code);
                if(ee==null){
                    searchedDataLbl.setText("No Such Employee found...");
                    return;
                }
                searchedDataLbl.setText(ee.toString());
            }
        });
    }
}
public class Main {
    public static void main(String[] args) {
        EmployeeManagementFrame empManage = new EmployeeManagementFrame();
    }
}
