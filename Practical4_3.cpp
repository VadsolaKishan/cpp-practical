/* A vehicle manufacturing company sought to create a robust system to organize and manage the 
details of various cars produced under its brand. To accomplish this, a hierarchical structure was 
conceptualized, reflecting the essential components of a vehicle. At the foundation, a class was 
designed to represent the type of fuel a vehicle uses. Another class was created to capture the brand 
name of the vehicle. These two foundational elements were then combined into a derived class 
specifically representing cars, integrating both fuel type and brand information. 
Constructors were used at each level to ensure proper initialization of attributes, allowing seamless 
integration of all details. Additionally, the ability to display complete information about a car, including 
its fuel type and brand, was incorporated into the system. To simulate a real-world scenario such as a 
service queue, multiple cars were organized and processed sequentially using a structured approach. 
This not only streamlined the handling of cars but also provided an opportunity to compare different 
methods of managing the collection and processing of vehicle data. */

#include<iostream>
#include<vector>
using namespace std;

class Fuel
{
    string Fuel_Type;

    public:
    Fuel(string fuel_name)
    {
        Fuel_Type = fuel_name;
    }

    string Get_Fuel_Type()
    {
        return Fuel_Type;
    }
};

class Brand : private Fuel
{
    string Brand_Type;

    public:
    Brand(string fuel_name,string brand_name) : Fuel(fuel_name)
    {
        Brand_Type = brand_name;
    }
    
    string Get_Fuel_Type()
    {
        return Fuel::Get_Fuel_Type();
    }

    string Get_Brand_Type()
    {
        return Brand_Type;
    }
};

class Car : private Brand
{
    public:
    Car(string fuel_name,string brand_name) : Brand(fuel_name,brand_name)
    {  
    }
    void Display_Car_Details()
    {
        cout<<"Fuel Type : "<<Get_Fuel_Type()<<endl;
        cout<<"Brand Type : "<<Get_Brand_Type()<<endl;
    }

};

int main()
{
    vector<Car>cars;
    int n;
    cout<<"Enter The Number Of Cars : ";
    cin>>n;
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        string fuel_name,brand_name;
        cout<<"<-<-<-<-<-"<<"Car - "<<i+1<<" ->->->->->"<<endl;
        cout<<"Enter The Fuel Name : ";
        cin>>fuel_name;
        cout<<"Enter The Brand Name : ";
        cin>>brand_name;
        cout<<endl;

        Car C(fuel_name,brand_name);
        cars.push_back(C);
    }

    for(int i=0;i<n;i++)
    {
        cars[i].Display_Car_Details();
        cout<<endl;
    }
    cout<<"Name : Vadsola Kishan"<<endl;
    cout<<"Id : 24CE134";
}
