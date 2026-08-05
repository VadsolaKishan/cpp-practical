/* A university managing academic data for its students. The administration seeks to digitize the records 
of student performance, including personal and academic details. The system must store each 
student's roll number, name, and marks in three subjects. Additionally, it should provide 
functionalities to calculate and display the average marks for performance analysis. 
The institution's IT team proposed a solution where student records could be initialized in two ways: 
either with default values for testing purposes or by accepting specific input details for each student. 
Once initialized, the system would allow for viewing comprehensive student details, including their 
roll number, name, marks, and calculated average. This functionality was designed to help faculty and 
administrators track individual student performance efficiently. 
To simulate real-world usage, the team decided to create multiple student records. They planned to 
populate the system with a mix of students initialized using both default and specific values. The 
system's ability to accurately calculate averages and display detailed student information was to be 
tested with this data. */

#include<iostream>
using namespace std;


class Student
{
    public:
    int Roll_Number;
    string Name;
    double Mark[3];

    Student()
    {
        Roll_Number = 0;
        Name = "N/A";
        for(int i=0;i<3;i++)
        {
            Mark[i]=0;
        }
    }

    Student(int R_No,string S_Name,double m1,double m2,double m3)
    {
        Roll_Number = R_No;
        Name = S_Name;
        Mark[0] = m1;
        Mark[1] = m2;
        Mark[2] = m3;
    }

    int Display_Detail()
    {
        cout<<"Student Roll Number : "<<Roll_Number<<endl;
        cout<<"Student Name : "<<Name<<endl;
        cout<<"Student Marks : "<<Mark[0]<<","<<Mark[1]<<","<<Mark[2]<<endl; 
    }

    int Average_Mark()
    {
        double avg;
        avg = (Mark[0]+Mark[1]+Mark[2])/3.0;
        cout<<"Average Mark : "<<avg<<endl<<"---------------------------"<<endl;
    }
};

int main()
{
Student students[3];

students[0] = Student(13,"Kishan",87,94,94);
students[1] = Student(23,"Harsh",76,99,74);
students[2] = Student();

for(int i=0;i<3;i++)
{
    cout<<"Student "<<i+1<<" Detail."<<endl<<endl;
    students[i].Display_Detail();
    students[i].Average_Mark();
}

cout<<endl<<"Name : Vadsola Kishan"<<endl;
cout<<"Id : 24CE134";

}
