/* A growing organization wanted to develop a system to manage its hierarchy and represent its 
structure in a programmatic way. To achieve this, a multilevel approach was designed, reflecting the 
natural progression of roles within the organization. At the foundation, a class was created to 
represent a person, capturing the basic details such as name and age. Building on this, an intermediate 
level was introduced to represent employees, adding a unique identifier for each. Finally, at the 
topmost level, a class for managers was created, which included additional details such as the 
department they oversee. 
The system needed to handle the initialization of all these attributes through constructors at each 
level, ensuring the proper propagation of information across the hierarchy. Additionally, the 
functionality to display details at every level was included to provide clear insights into the 
organization's structure. Two approaches were explored for managing multiple managers: one relied 
on an efficient method for retrieval and organization based on employee identifiers, while the other 
used a straightforward and static method for storage. */

#include<iostream>
#include<vector>
using namespace std;

class Person
{
    private:
    string Name;
    int Age;

    public:
    Person(string name,int age)
    {
        Name = name;
        Age = age;
    }

    string Get_Name()
    {
        return Name;
    }

    int Get_Age()
    {
        return Age;
    }
};

class Employee : private Person
{
    private:
    int Employee_Id;

    public:
    Employee(string name,int age,int emp_id) : Person(name,age)
    {
        Employee_Id = emp_id;
    }

    string Get_Emp_Name()
    {
        return Get_Name();
    }

    int Get_Emp_Age()
    {
        return Get_Age();
    }
    int Get_Id()
    {
        return Employee_Id;
    }
};

class Manager : private Employee
{
    private:
    string Department;

    public:
    Manager(string name,int age,int emp_id,string department) : Employee(name,age,emp_id)
    {
        Department = department;
    }
    
    void Display_Details()
    {
        cout<<"Name : "<<Get_Emp_Name()<<endl;
        cout<<"Age : "<<Get_Emp_Age()<<endl;
        cout<<"Employee Id : "<<Get_Id()<<endl;
        cout<<"Department : "<<Department<<endl;
    }
};

int main()
{
    vector<Manager>managers;

    int n;
    cout<<"Enter The Number Of Managers : ";
    cin>>n;
    cout<<endl;

    for(int i=0;i<n;i++)
    {
        string name,department;
        int age,emp_id;
        cout<<"<-<-<-<-<-"<<"Manager - "<<i+1<<" ->->->->->"<<endl<<endl;
        cout<<"Enter The Name : ";
        cin>>name;
        cout<<"Enter The Age : ";
        cin>>age;
        cout<<"Enter The Employee Id : ";
        cin>>emp_id;
        cout<<"Enter The Department : ";
        cin>>department;
    
        Manager M(name,age,emp_id,department);
        managers.push_back(M);
    }

    for(int i=0;i<n;i++)
    {
        cout<<endl;
        managers[i].Display_Details();
    }
    cout<<endl<<"Name : Vadsola Kishan"<<endl;
    cout<<"Id : 24CE134";
}
