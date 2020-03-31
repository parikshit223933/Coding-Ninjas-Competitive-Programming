#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int *arr=new int [750001];
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        
    }
    delete[]arr;
}