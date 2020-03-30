#include<iostream>
#define m 1000000007
using namespace std;
typedef long long int ll;
ll count_palindrome(ll n, ll total_sum, ll k, ll **dp)
{
    if(n==0 && total_sum%k==0)
    {
        return 1;
    }
    if(n==0 && total_sum%k!=0)
    {
        return 0;
    }
    if(dp[n][k]!=-1)
    {
        return dp[n][k]%m;
    }
    ll count=0;
    for(ll i=1; i<=9; i++)
    {
        if(n>=2)
        {
            count=(count%m+count_palindrome(n-2, total_sum+(2*i), k, dp)%m)%m;
        }
        else if(n==1)
        {
            count=(count%m+count_palindrome(n-1, total_sum+i, k, dp)%m)%m;
        }
    }
    dp[n][k]=count%m;
    return count%m;
}
int main()
{
    ll n, k;
    cin>>n>>k;
    ll **dp=new ll *[n+1];
    for(ll i=0; i<=n; i++)
    {
        dp[i]=new ll [k+1];
        for(ll j=0; j<=k; j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<count_palindrome(n, 0, k, dp)<<endl;
}