/* A small retail store is facing challenges in managing its inventory effectively. The store sells a 
variety of products, each identified by a unique product ID, a name, the available quantity in 
stock, and the price per unit. To streamline their operations, the store needs a basic system to 
manage this inventory efficiently. 
The system must provide the ability to add new products to the inventory, ensuring that each 
product has its ID, name, quantity, and price properly recorded. Additionally, the system should 
allow the store staff to update the quantity of any existing product, such as when new stock 
arrives or when items are sold. 
Another essential feature of the system is the calculation of the total value of all products in 
the inventory, which is determined by multiplying the quantity of each product by its price and 
summing these values for all products. 
The store management is exploring two approaches for this system: a procedural approach and 
an object-oriented approach. The goal is to evaluate these approaches by comparing their ease 
of implementation, code reusability, and overall complexity. 
The system's design and implementation should consider these requirements and provide an 
effective solution (either procedural approach or an object-oriented approach) to the store's 
inventory management problems. */

#include <iostream>
using namespace std;

struct Product 
{
    int Id;
    string Name;
    int Quantity;
    double Price;

void Add_Product(int P_I,string P_N,int P_Q,double P_P) 
{
    Id = P_I;
    Name = P_N;
    Quantity = P_Q;
    Price = P_P;

    cout<<"Id : "<<Id<<endl;
    cout<<"Name : "<<Name<<endl;
    cout<<"Quantity : "<<Quantity<<endl;
    cout<<"Price : "<<Price<<endl<<endl;
}

void Update_Quantity(int U_Q,int a) 
{
    Quantity += U_Q;
    cout<<"Update Quantity "<<a<<" : "<<U_Q<<endl;
}


void Total_Price(int a) 
{
    double total = Quantity * Price;
    cout<<"Total Price "<<a<<" : "<<total<<endl;
    }
    
};

int main() 
{
Product P_1, P_2;

cout<<"<-<-<-<-<-Product 1 Detail->->->->->"<<endl<<endl;
P_1.Add_Product(1,"Laptop",2,50000);

cout<<"<-<-<-<-<-Product 2 Detail->->->->->"<<endl<<endl;
P_2.Add_Product(2,"Phone",3, 20000);

cout<<"------------------------------------"<<endl<<endl;
P_1.Update_Quantity(3,1);
P_2.Update_Quantity(2,2);

P_1.Total_Price(1);
P_2.Total_Price(2);

cout<<endl<<"Name : Vadsola Kishan"<<endl;
cout<<"Id : 24CE134";

}
