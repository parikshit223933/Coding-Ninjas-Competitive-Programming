#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *arr=new int [n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        bool checker=true;
        for(int i=0; i<n; i++)
        {
            if(arr[i])
            {
                int j=i-1;
                while(j>=0 && j>=i-5)
                {
                    if(arr[j])
                    {
                        checker=false;
                        break;
                    }
                    j--;
                }
                j=i+1;
                while(j<=n-1 && j<=i+5)
                {
                    if(arr[j])
                    {
                        checker=false;
                        break;
                    }
                    j++;
                }
            }
            if(!checker)
            {
                break;
            }
        }
        if(!checker)
        {
            cout<<"NO"<<endl;
        }
        else
        {
            cout<<"YES"<<endl;
        }
    }
}