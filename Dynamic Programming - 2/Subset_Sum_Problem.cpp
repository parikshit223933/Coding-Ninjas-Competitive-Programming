/* Given a set of n integers, find if a subset of sum k can be formed from the given set. Print Yes or No.

Input Format
First line contains a single integer n (1<=n<=1000)
Second line contains n space separated integers (1<=a[i]<=1000)
Last line contains a single positive integer k (1<=k<=1000)
Output Format
Output Yes if there exists a subset whose sum is k, else output No.
Sample Input
3
1 2 3
4
Sample Output
Yes */



#include<iostream>

bool checker(int *arr, int n, int k, int **dp)
{
	if(k==0)
	{
		return true;
	}
	if(n==0)
	{
		return false;
	}
    if(dp[n][k]>=0)
    {
        return dp[n][k];
    }
    int ans=0;
	if(arr[0]<=k)
	{
		bool option1=checker(arr+1, n-1, k, dp);
		bool option2=checker(arr+1, n-1, k-arr[0], dp);
		if (option1||option2)
        {
            ans=1;
        }
	}
	else
	{
		ans= checker(arr+1, n-1, k, dp);
	}
    dp[n][k]=ans;
    return dp[n][k];
}
using namespace std;
int main()
{
	int n;
	cin>>n;
	int *arr= new int [n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	int k;
	cin>>k;
    int **dp=new int *[n+1];
    for(int i=0; i<=n; i++)
    {
        dp[i]=new int [k+1];
        for(int j=0; j<=k; j++)
        {
            dp[i][j]=-1;
        }
    }
	if(checker(arr, n, k, dp))
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No";
	}
    for(int i=0; i<=n; i++)
    {
        delete[]dp[i];
    }
    delete[]dp;
}