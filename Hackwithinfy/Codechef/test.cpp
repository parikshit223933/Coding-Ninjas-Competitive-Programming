#include<iostream>
#define endl '\n'
using namespace std;
int good_subsequences(int *arr, int n, bool even1=false, bool even2=false, bool odd1=false, bool odd2=false)
{
    if((even1&&even2)||(odd1&&odd2))
    {
        return 1;
    }
    if(n==0)
    {
        return 0;
    }
    int option1;
    int option2;
    if(arr[0]%2==0)
    {
        if(even1=true)
        {
            option1=1+good_subsequences(arr+1, n-1, )
        }
        else
        {
            
        }
        
    }
    else
    {
        
    }
    

}
int main()
{
    int t;
    cin>>t;
    int *arr=new int [100001];
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        cout<<good_subsequences(arr, n)<<endl;
    }
    delete[]arr;
}