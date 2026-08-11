/* A growing organization sought to enhance its payroll process to improve accuracy and efficiency in 
calculating employee salaries. The goal was to manage details such as the employee's name, basic 
salary, and bonus amount. While most employees would receive a default bonus, there was a need 
for flexibility to provide customized bonuses for exceptional performers or those in specialized roles. 
To ensure real-time computation of each employee's total salary, the system would dynamically 
calculate the total salary by adding the basic salary and the bonus. An inline function was chosen for 
this task, allowing the system to compute the total salary instantly during processing. The system was 
designed to initialize employee records using a constructor, where the bonus could either be set to a 
default value or adjusted according to specific employee criteria. 
As the organization expanded, managing employee records efficiently became a key consideration. 
The solution involved storing employee details dynamically, ensuring the system could handle a 
growing number of records while maintaining scalability and flexibility. Each employee record would 
include their personal details, basic salary, and bonus information, with the system displaying a 
breakdown of each employee’s details along with their total salary. */


#include<iostream>
#include<vector>

using namespace std;

class Employee
{
    public: 
    string Name;
    double Basic_Salary;
    double Bonus;
    double Total_Salary;

    Employee(string E_Name,double E_Basic_Salary,double E_Bonus=0)
    {
        Name = E_Name;
        Basic_Salary = E_Basic_Salary;
        Bonus = E_Bonus;
    }

    void Cal_Total_Salary()
    {
        Total_Salary = Basic_Salary + Bonus;
    }

    void Display_Detail()
    {
        cout<<"Employee Name : "<<Name<<endl;
        cout<<"Employee Basic Salary : "<<Basic_Salary<<endl;
        cout<<"Employee Bonus : "<<Bonus<<endl;
        cout<<"Employee Total Salary : "<<Total_Salary<<endl;
        cout<<"------------------------------------"<<endl;
    }

};

int main()
{
    vector<Employee>employees;

    employees.push_back(Employee("Kishan",50000,5000));
    employees.push_back(Employee("Abhishek",20000));
    employees.push_back(Employee("Prince",60000,5000));
    employees.push_back(Employee("Shrey",10000));
    
    for(auto& emp : employees)
    {
        emp.Cal_Total_Salary();
        emp.Display_Detail();
    }

    cout<<"Name : Vadsola Kishan"<<endl;
    cout<<"Id : 24CE134";
}
