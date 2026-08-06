/* A technology firm aimed to develop a flexible and reusable solution for managing collections of various 
data types, including integers, floating-point numbers, and characters. The system was intended to 
perform fundamental operations on these collections, such as finding the maximum value, reversing 
the collection, and displaying all elements. To achieve versatility and avoid redundancy in code, the 
solution was designed to use function templates, allowing the same logic to be applied seamlessly to 
different data types. 
The team recognized the importance of using dynamic arrays to store the collections, enabling 
efficient management of varying collection sizes. The design emphasized scalability and flexibility, 
ensuring that the system could handle different data types and their associated operations with 
minimal changes to the core logic. 
In practice, the system allowed for the creation of collections for various data types, such as integers, 
floating-point numbers, and characters. The operations on these collections included determining the 
maximum value, reversing the order of elements, and printing the collection contents. */


#include<iostream>
#include<vector>
using namespace std;

template<typename T>
void Find_Max(const vector<T>& vec,int n)
{
    T max = vec[0];
    for(int i=0;i<n;i++)
    {
        if(vec[i]>max)
        {
            max = vec[i];
        }
    }
    cout<<"Integer Max Value Is : "<<max<<endl;
}

template<typename T>
void Reverse_Vector(const vector<T>& vec,int n)
{
    cout<<"Reverse Integer Collection : ";
    for(int i=n-1;i>=0;i--)
    {
        cout<<vec[i]<<" ";
    }
}

int main()
{
   int n;

   cout<<"----------Integer Collection----------"<<endl;
   cout<<"Enter The Size Of Intger Collection : ";
   cin>>n;
   vector<int>Int_Collection(n);

   for(int i=0;i<n;i++)
   {
      cout<<"Enter The Intger Element "<<i+1<<" : ";
      cin>>Int_Collection[i];
   }

   Find_Max(Int_Collection,n);
   Reverse_Vector(Int_Collection,n);


   cout<<endl<<endl<<"----------Float Collection----------"<<endl;
   cout<<"Enter The Size Of Float Collection : ";
   cin>>n;
   vector<float>Float_Collection(n);

   for(int i=0;i<n;i++)
   {
      cout<<"Enter The Float Element "<<i+1<<" : ";
      cin>>Float_Collection[i];
   }

   Find_Max(Float_Collection,n);
   Reverse_Vector(Float_Collection,n);


   cout<<endl<<endl<<"----------Character Collection----------"<<endl;
   cout<<"Enter The Size Of Charater Collection : ";
   cin>>n;
   vector<char>Char_Collection(n);

   for(int i=0;i<n;i++)
   {
      cout<<"Enter The Char Element "<<i+1<<" : ";
      cin>>Char_Collection[i];
   }

    
   Find_Max(Char_Collection,n);
   Reverse_Vector(Char_Collection,n);

   cout<<endl<<endl<<"Name : Vadsola Kishan"<<endl;
   cout<<"Id : 24CE134";

}
