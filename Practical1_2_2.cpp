#include <iostream>
using namespace std;

class Product
{
    public:
    int Id;
    string Name;
    int Quantity;
    double Price;
    
    Product(int P_Id,string P_Name,int P_Quantity,double P_Price)
    {
        Id = P_Id;
        Name = P_Name;
        Quantity = P_Quantity;
        Price = P_Price;
    }
    
    void Detail()
    {
        cout<<"Id : "<<Id<<endl;
        cout<<"Name : "<<Name<<endl;
        cout<<"Quantity : "<<Quantity<<endl;
        cout<<"Price : "<<Price<<endl;
    }
    
    void Add_Product(int A_P_Quantity,int a)
    {
        Quantity += A_P_Quantity;
        cout<<"Update Quantity Product "<<a<<" : "<<A_P_Quantity<<endl;
    }
    
    void Total_Price(int a)
    {
        double Total_Price = Quantity * Price;
        cout<<"Total Price Product "<<a<<" : "<<Total_Price<<endl;
    }
    
};

int main() 
{
Product P_1(1,"Laptop",2,50000);
Product P_2(2,"Phone",3,20000);

cout<<"---------- Product - 1 ----------"<<endl;
P_1.Detail();
cout<<"---------- Product - 2 ----------"<<endl;
P_2.Detail();

cout<<"---------------------------------"<<endl;
P_1.Add_Product(3,1);
P_2.Add_Product(2,2);

cout<<endl;
P_1.Total_Price(1);
P_2.Total_Price(2);

cout<<endl<<"Name : Vadsola Kishan"<<endl;
cout<<"Id : 24CE134";
}
