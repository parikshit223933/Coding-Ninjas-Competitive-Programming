#include<iostream>
using namespace std;
void Sieve_Array_Filler(int*arr)
{
    for(int i=0; i<1000001; i++)
    {
        arr[i]=0;
    }
    arr[1]=1;
    for(int i=2; i<=100; i++)
    {
        int current_cubic_number=i*i*i;
        for(int j=1; current_cubic_number*j<1000001;j++)
        {
            arr[current_cubic_number*j]=-1;
        }
    }
    int k=1;
    for(int i=1; i<=1000000; i++)
    {
        if(arr[i]!=-1)
        {
            arr[i]=k;
            k++;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    int *arr=new int [1000001];
    Sieve_Array_Filler(arr);
    for(int test_case=1; test_case<=t; test_case++)
    {
        int n;
        cin>>n;
        if(arr[n]!=-1)
        {
            cout<<"Case "<<test_case<<": "<<arr[n]<<endl;
        }
        else
        {
            cout<<"Case "<<test_case<<": "<<"Not Cube Free"<<endl;
        }
    }
}