/* A regional banking institution sought to improve its loan management process by developing a system 
that could efficiently handle loan details for applicants. The system was expected to streamline the 
calculation of monthly EMIs (Equated Monthly Instalments) and provide detailed loan summaries for 
customers. This initiative aimed to enhance customer experience by offering accurate and transparent 
information about their loans. 
To meet these requirements, the bank's technology team was tasked with designing a solution. They 
envisioned a system where each loan would be uniquely identified by a loan ID, and additional details 
such as the applicant's name, total loan amount, annual interest rate, and loan tenure in months 
would be stored. The team also emphasized the importance of accurately calculating the EMI using a 
standard formula based on the loan amount, interest rate, and tenure. The formula incorporated 
compound interest principles to determine the fixed monthly payment for the loan term. 
EMI= 𝑃 ∗ 𝑅 ∗ (1 + 𝑅)^𝑇 / ((1+𝑅)^𝑇) −1
 As part of the implementation, the developers planned to initialize loans either with default values for 
testing purposes or with actual customer data provided at the time of application. The system needed 
to include a feature to display comprehensive loan details, including the calculated EMI, in a customer
friendly format. This functionality was intended to aid both customers and bank staff in managing 
loan-related queries effectively. */

#include<iostream>
#include<math.h>
using namespace std;

class Loan
{
    public:

    int Loan_Id;
    string Applicant_Name;
    float Loan_Amount;
    float Loan_Interest_Rate;
    int Loan_Term;

    Loan()
    {
        Loan_Id = 0;
        Applicant_Name = "N/A";
        Loan_Amount = 0.0;
        Loan_Interest_Rate = 0.0;
        Loan_Term = 0;
    }

    Loan(int L_Id,string A_Name,float L_Amount,float L_Interest_Rate,int L_Term)
    {
        Loan_Id = L_Id;
        Applicant_Name = A_Name;
        Loan_Amount = L_Amount;
        Loan_Interest_Rate = L_Interest_Rate;
        Loan_Term = L_Term;
    }

    int Display_Loan_Detail()
    {
        cout<<"Loan Id : "<<Loan_Id<<endl;
        cout<<"Applicant Name : "<<Applicant_Name<<endl;
        cout<<"Loan Amount : "<<Loan_Amount<<endl;
        cout<<"Loan Interest Rate : "<<Loan_Interest_Rate<<"%"<<endl;
        cout<<"Loan Term : "<<Loan_Term<<endl;
    }

    int Calculate_EMI()
    {
        float Monthly_I_R = (Loan_Interest_Rate / 12) / 100;
    
        float EMI = Loan_Amount * Monthly_I_R * pow(1 + Monthly_I_R,Loan_Term) / (pow(1 + Monthly_I_R,Loan_Term)-1);
        cout<<"--------------------------------"<<endl;
        cout<<"Monthly EMI : "<<EMI<<endl;
    }
};



int main()
{
int Loan_Id;
string Applicant_Name;
float Loan_Amount;
float Loan_Interest_Rate;
int Loan_Term;

cout<<"Loan Id : ";
cin>>Loan_Id;

cin.ignore();

cout<<"Applicant Name : ";
getline(cin,Applicant_Name);

cout<<"Loan Amount : ";
cin>>Loan_Amount;

cout<<"Loan Interest Rate : ";
cin>>Loan_Interest_Rate;


cout<<"Loan Term (In Months) : ";
cin>>Loan_Term;

Loan L1(Loan_Id,Applicant_Name,Loan_Amount,Loan_Interest_Rate,Loan_Term);
cout<<endl<<"<-<-<-<-<-Loan Details->->->->->"<<endl<<endl;
L1.Display_Loan_Detail();
L1.Calculate_EMI();

Loan L2;
cout<<endl<<"<-<-<-<-<-Loan Details->->->->->"<<endl<<endl;
L2.Display_Loan_Detail();
L2.Calculate_EMI();

cout<<endl<<"Name : Vadsola Kishan"<<endl;
cout<<"Id : 24CE134";

}
