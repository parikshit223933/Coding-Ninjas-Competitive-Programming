#include<iostream>
using namespace std;
int count_palindrome(int n, int total_sum, int k, int **dp)
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
        return dp[n][k];
    }
    int count=0;
    for(int i=1; i<=9; i++)
    {
        if(n>=2)
        {
            count+=count_palindrome(n-2, total_sum+(2*i), k, dp);
        }
        else if(n==1)
        {
            count+=count_palindrome(n-1, total_sum+i, k, dp);
        }
    }
    dp[n][k]=count;
    return count;
}
int main()
{
    int n, k;
    cin>>n>>k;
    int **dp=new int *[n+1];
    for(int i=0; i<=n; i++)
    {
        dp[i]=new int [k+1];
        for(int j=0; j<=k; j++)
        {
            dp[i][j]=-1;
        }
    }
    cout<<count_palindrome(n, 0, k, dp)<<endl;
}