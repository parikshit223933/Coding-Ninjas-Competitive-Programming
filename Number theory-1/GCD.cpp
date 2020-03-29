#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long int ll;
ll gcd(ll x, ll y)
{
    if(y==0)
    {
        return x;
    }
    return gcd(y, x%y);   
}
int main()
{
    ll x, y;
    cin>>x>>y;
    cout<<gcd(x, y)<<endl;
}