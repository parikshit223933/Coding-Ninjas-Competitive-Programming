#include<iostream>
#define ll long long int
#define m 1000000007
using namespace std;
ll income(ll first, ll second, ll n, ll *dp)
{
    if(n==1)
    {
        return first;
    }
    if(n==2)
    {
        return second;
    }
    if(dp[n]!=-1)
    {
        return dp[n]%m;
    }
    ll first_part=income(first, second, n-1, dp)%m;
    ll second_part=income(first, second, n-2, dp)%m;
    ll next=(first_part%m+second_part%m+((first_part%m)*(second_part%m))%m)%m;
    dp[n]=next%m;
    return next%m;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll first, second, n;
        cin>>first>>second>>n;
        ll *dp=new ll [n+1];
        for(ll i=0; i<=n; i++)
        {
            dp[i]=-1;
        }
        cout<<income(first, second, n+1, dp)<<endl;
    }
}