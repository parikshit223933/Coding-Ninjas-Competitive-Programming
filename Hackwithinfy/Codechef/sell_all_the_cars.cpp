#include<iostream>
#include<algorithm>
#define ll long long int
#define mod 1000000007
using namespace std;
int main()
{
    ll t;
    cin>>t;
    ll *arr=new ll [100001];
    while(t--)
    {
        ll n;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr+n, greater<ll>());
        ll sum=0;
        ll i=0;
        ll decrementor=0;
        while(arr[i]-decrementor>0)
        {
            sum= (sum%mod+(arr[i]%mod-decrementor%mod)%mod)%mod;
            i++;
            decrementor++;
        }
        cout<<sum<<endl;
    }
    delete[]arr;
}