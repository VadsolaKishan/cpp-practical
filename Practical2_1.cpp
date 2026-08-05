/* A local construction company frequently deals with rectangular plots and structures of varying 
dimensions. To streamline their planning and estimation processes, the company requires a simple 
system to manage and analyze rectangular shapes efficiently. 
The system must be able to handle multiple rectangles, each with distinct dimensions. For each 
rectangle, the length and width need to be defined and stored securely. Additionally, the company 
needs the ability to calculate two key metrics for any given rectangle: 
The area, to estimate usable space or material coverage. The perimeter, to estimate boundary lengths 
or material requirements for edges. To make this system functional, there should be a way to define 
or update the dimensions of any rectangle as required. The system should be capable of creating and 
managing multiple rectangle records, performing calculations for each, and displaying the results 
clearly for analysis and planning purposes. */
#include<iostream>
using namespace std;


class Rectangle
{
    int Length;
    int Width;
    
    public:
    void Set_Dimension(int L,int W)
    {
        Length = L;
        Width = W;
    }

    int Area()
    {
        return Length * Width;
    }

    int Perimeter()
    {
        return 2 * (Length + Width);
    }
};

int main()
{
Rectangle r1,r2,r3;

r1.Set_Dimension(5,6);
r2.Set_Dimension(8,9);
r3.Set_Dimension(9,15);

cout<<"Area R1 : "<<r1.Area()<<" "<<"Perimeter R1 : "<<r1.Perimeter()<<endl;
cout<<"Area R2 : "<<r2.Area()<<" "<<"Perimeter R2 : "<<r2.Perimeter()<<endl;
cout<<"Area R3 : "<<r3.Area()<<" "<<"Perimeter R3 : "<<r3.Perimeter()<<endl;

cout<<endl<<"Name : Vadsola Kishan"<<endl;
cout<<"Id : 24CE134";
}
