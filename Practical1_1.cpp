/* A bank wants to create a simple system to manage customer bank accounts. The system should 
allow customers to perform basic banking operations such as depositing money, withdrawing 
money, and checking their account balance. 
Each bank account will need to have an account holder's name, a unique account number, and 
a balance. Deposits should increase the account balance, while withdrawals should only be 
allowed if there are sufficient funds in the account. If an attempt is made to withdraw more 
money than is available, an error message should be displayed. Customers should also have the 
ability to view their account balance whenever required.  
The system must be designed using Object-Oriented Programming principles, focusing on 
creating a simple and efficient solution to manage the accounts effectively. The system should 
ensure that all account details are secure and accessible only through authorized methods. */

#include<iostream>
using namespace std;

class Bank_Account
{
    public:
    string Account_Name;
    string Account_Number;
    double Account_Balance;

    Bank_Account(string A_Name,string A_Number,double A_Balance)
    {
        Account_Name = A_Name;
        Account_Number = A_Number;
        Account_Balance = A_Balance;
    }
     
    int Details()
    {
        cout<<"Account Name : "<<Account_Name<<endl;
        cout<<"Account Number : "<<Account_Number<<endl;
        cout<<"Account Balance : $"<<Account_Balance<<endl<<endl;      
    }        

    int Deposit(int d)
    {
        Account_Balance += d;
        cout<<"Deposited : $"<<d<<endl;
    }

    int Withdraw(int w)
    {
        if(Account_Balance>w)
        {
            Account_Balance -= w;
            cout<<"Withdrew : $"<<w<<endl;
        }
        else
        {
            cout<<"Not Sufficient Balance."<<endl;
        }
    }

    int Display_Balance()
    {
        cout<<"Total Balance : $"<<Account_Balance<<endl<<"---------------------------------"<<endl;
    }
    
};


int main()
{
Bank_Account Account_1("Vadsola_Kishan","2572362862",20000);
Bank_Account Account_2("Vadsola_Sagar","7136728738",50000);

Account_1.Details();
Account_1.Deposit(500);
Account_1.Withdraw(2000);
Account_1.Display_Balance();

Account_2.Details();
Account_2.Deposit(3000);
Account_2.Withdraw(5000);
Account_2.Display_Balance();

cout<<endl<<"Name : Vadsola Kishan"<<endl;
cout<<"Id : 24CE134";

}
