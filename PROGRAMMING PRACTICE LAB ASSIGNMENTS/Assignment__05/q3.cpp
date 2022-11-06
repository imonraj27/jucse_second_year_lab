/*
Employee has unique emp-id, name, designation and basic pay. An employee is 
either a permanent one or contractual. For permanent employee salary is 
computed as basic pay+ hra (30% of basic pay) + da (80% of basic pay). For 
contractual employee it is basic pay + allowance (it is different for different 
contractual employee). An employee pointer may point to either of the two 
categories and accordingly the salary has to be created.
Design the classes and implement
*/


#include <iostream>
#include <ctime>
using namespace std;

class Employee // THE EMPLOYEE CLASS(ABSTRACT BASE CLASS)
{
private:
    string employee_id;
    string name;
    string designation;
    int basicPay;

public:
    Employee(string employee_id, string name, string designation, int basicPay);
    Employee(){
        employee_id = "null";
        name = "__";
        designation = "none";
        basicPay = 0;
    }
    int basic_pay() const{ return basicPay; }
    virtual float Calculate_Salary() { return 0.0; }; // VIRTUAL TO MAINTAIN POLYMORPHISM OF FUNCS IN DERIVED CLASSES
    virtual float Calculate_Salary(float) { return 0.0; }; //SAME
};

Employee::Employee(string employee_id, string name, string designation, int basicPay)
{
    this->employee_id = employee_id;
    this->name = name;
    this->designation = designation;
    this->basicPay = basicPay;
}

class Permanent_Employee : public Employee // DERIVING A PERMANENT EMPLOYEE
{
    using Employee::Employee;

public:
    float Calculate_Salary() // CALCULATE SALARY FOR PERMANENT EMP
    {
        float hra = 0.3 * basic_pay();
        float da = 0.8 * basic_pay();
        return basic_pay() + hra + da;
    }
};

class Contractual_Employee : public Employee // DERIVING A CONTRACTUAL EMPLOYEE
{
    using Employee::Employee;

public:
    float Calculate_Salary(float allowence) // CALCULATE SALARY FOR CONTRACTUAL EMP
    {
        return basic_pay() + allowence;
    }
};

int main()
{
    string empid, name, designation;
    int basic;
    Permanent_Employee perm__employee;
    Contractual_Employee cont__employee;

    cout << "\nEnter Permanent employee name: ";
    getline(cin, name);
     cout << "\nEnter Permanent employee Id: ";
    getline(cin, empid);
     cout << "\nEnter Permanent employee designation: ";
    getline(cin, designation);
     cout << "\nEnter Permanent employee Basic Salary: ";
   cin >> basic;

   perm__employee = Permanent_Employee(empid, name, designation, basic);

    cin.ignore();
     cout << "\n\nEnter Contractual employee name: ";
    getline(cin, name);
     cout << "\nEnter Contractual employee Id: ";
    getline(cin, empid);
     cout << "\nEnter Contractual employee designation: ";
    getline(cin, designation);
     cout << "\nEnter Contractual employee Basic Salary: ";
   cin >> basic;

   cont__employee = Contractual_Employee(empid, name, designation, basic);

   float allowence;
   cout << "\nEnter allowence for contractual emplyee: ";
   cin >> allowence;

    cout << "\n\nPermanent Employee Salary: " << perm__employee.Calculate_Salary() << endl;
    cout << "\nContractual Employee Salary: " << cont__employee.Calculate_Salary(allowence) << endl;


    Employee *Emp = &perm__employee; // Pointer to base class points to child class
    cout << "\n\nPermanent Employee Salary(USING POINTERS): " << Emp->Calculate_Salary() << endl;
    Emp = &cont__employee; // Pointer to base class points to child class
    cout << "\nContractual Employee Salary(USING POINTER): " << Emp->Calculate_Salary(allowence) << endl;

    return 0;
}