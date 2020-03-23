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