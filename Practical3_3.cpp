/* A community bank sought to enhance its account management system with a digital solution to 
improve efficiency and provide better customer service. The system was required to manage the 
essential details of each account, including the account number, account holder’s name, and balance. 
Additionally, the bank wanted to provide a secure mechanism for transferring money between 
accounts, allowing customers to easily manage their funds. 
The bank also needed a way to track the total number of accounts created, which would be important 
for generating reports and understanding the growth of their customer base. This feature was aimed 
at helping the bank maintain an overview of their account portfolio and analyze trends over time. 
To ensure smooth and reliable operations, the system was designed to store account information in a 
way that would allow easy access and updates. When new accounts were created, they would be 
added to the system dynamically. The management team planned for future scalability and 
performance improvements by considering more efficient storage and retrieval methods after the 
initial system was built, ensuring that the bank could easily accommodate more accounts and 
transactions as the customer base grew. */
    
#include<iostream>
#include<vector>
using namespace std;

class Bank_Account
{
    public:
    string Account_Name;
    string Account_Number;
    double Account_Balance;
    static int count;

    Bank_Account(string A_Name,string A_Number,double A_Balance)
    {
        Account_Name = A_Name;
        Account_Number = A_Number;
        Account_Balance = A_Balance;
        count++;
    }

    void Detail()
    {
        cout<<"Account Name : "<<Account_Name<<endl;
        cout<<"Account Number : "<<Account_Number<<endl;
        cout<<"Account Balance : "<<Account_Balance<<endl<<endl;
    }

    
    int Deposite(double d)
    {
        Account_Balance += d;
        cout<<"Deposited In Account 1 : "<<Account_Balance<<endl;
    }
    
    int Withdraw(double w)
    {
        if(Account_Balance > w)
        {
            Account_Balance -= w;
            cout<<"Withdrawed In Account 2 : "<<Account_Balance<<endl<<endl;
        }
        else
        {
            cout<<"Not Sufficient Balance."<<endl<<"---------------------------------"<<endl<<endl;
        }
    }
    
    void Display_Detail()
    {
        cout<<"Account Name : "<<Account_Name<<endl;
        cout<<"Account Number : "<<Account_Number<<endl;
        cout<<"Account Total Balance : "<<Account_Balance<<endl<<endl;
    }
};


int Bank_Account::count = 0;

void transfer_money(Bank_Account& account_1,Bank_Account& account_2,double amount)
{
    account_1.Account_Balance -= amount;
    account_2.Account_Balance += amount;
    
    cout<<"Transferred "<<amount<<" From Account 1 To Account 2"<<endl;
    cout<<"Deposited In Account 2 : "<<account_2.Account_Balance<<endl<<endl;
}

int main()
{

    Bank_Account account_1("Kishan","1234567890",500.0);
    Bank_Account account_2("Abhishek","9876543210",200.0);
    
    cout<<"<-<-<-<-<- Account 1 Details ->->->->->"<<endl<<endl;
    account_1.Detail();
    cout<<"<-<-<-<-<- Account 2 Details ->->->->->"<<endl<<endl;
    account_2.Detail();

    account_1.Deposite(200.0);
    account_2.Withdraw(100.0);

    transfer_money(account_1,account_2,200.0);

    cout<<"<-<-<-<-<- Account 1 ->->->->->"<<endl<<endl;
    account_1.Display_Detail();
    cout<<"<-<-<-<-<- Account 2 ->->->->->"<<endl<<endl;
    account_2.Display_Detail();

    cout<<"Total Account Created : "<<Bank_Account::count;
    
    cout<<endl<<endl<<"Name : Vadsola Kishan"<<endl;
    cout<<"Id : 24CE134";

}
