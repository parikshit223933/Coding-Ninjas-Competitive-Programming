#include<iostream>
using namespace std;
typedef unsigned long long int ll;
ll gcd(ll x, ll y)
{
    if(x<y)
    {
        return gcd(y, x);
    }
    if(y==0)
    {
        return x;
    }
    return gcd(y, x%y);   
}
void func(long long n)
{
	ll partial_sum=0;
    for(ll i=1; i<=n-1; i++)
    {
        partial_sum+=(n*n)/gcd(i*1.0, n);
    }
    ll ans=2*n+partial_sum;
    cout<<ans/2;
}
