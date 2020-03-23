#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int solve(int n,vector<int>A)
{
    int *freq=new int[1005];
    int *dp=new int[1005];
    for(int i=0;i<1005;i++)
    {
        freq[i]=dp[i]=0;
    }
    for(int i=0;i<n;i++)
        freq[A[i]]++;
    
    dp[1]=freq[1];
    
    for(int i=2;i<=1000;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+i*freq[i]);
    }
    int maximum=dp[1000];
    delete[] freq;
    delete[] dp;
    return maximum;
}