#include<iostream>
#include<vector>
using namespace std;

int nonrecursive_sum(vector<int>arr,int n)
{
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int n;
    cout<<"Enter The Size Of Array : ";
    cin>>n;
    cout<<endl;

    vector<int>arr(n);

    // for(int i=0;i<n;i++)
    // {
    //     cout<<"Enter The Element "<<i+1<<" : ";
    //     cin>>arr[i];
    // }
    
    for(auto& i : arr)
    {
        cout<<"Enter The Element "<<i+1<<" : ";
        cin>>i;
    }

    nonrecursive_sum(arr,n);
    cout<<endl<<"Sum Of Array Elements (nonrecursive sum) : "<<nonrecursive_sum(arr,n)<<endl<<endl;

    cout<<endl<<"Name : Vadsola Kishan"<<endl;
    cout<<"Id : 24CE134";

}
