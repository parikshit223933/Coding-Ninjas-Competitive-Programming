#include<iostream>
#include<algorithm>
using namespace std;
int maximum_profit(int *arr, int n, int k, int ongoing_transaction, int ***dp)//the value of ongoing_transaction could be either 0 or 1. I am using it as a boolean.
{
	if(n==0)
	{
		return 0;
	}
	if(k==0)
	{
		return 0;
	}
	if(dp[n][k][ongoing_transaction]>=0)
	{
		return dp[n][k][ongoing_transaction];
	}
	int option1=maximum_profit(arr+1, n-1, k, ongoing_transaction, dp);
	int option2;
	if(ongoing_transaction==1)
	{
		option2=maximum_profit(arr+1, n-1, k-1, 0, dp)+arr[0];
	}
	else
	{
		if(k>0)
		{
			option2=maximum_profit(arr+1, n-1, k, 1, dp)-arr[0];
		}
	}
	dp[n][k][ongoing_transaction]= max(option1, option2);
	return dp[n][k][ongoing_transaction];
}
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int k;
		cin>>k;
		int n;
		cin>>n;
		int *arr=new int [n];
		for(int i=0; i<n; i++)
		{
			cin>>arr[i];
		}
		int ***dp=new int**[n+1];
		for(int i=0; i<=n; i++)
		{
			dp[i]=new int *[k+1];
			for(int j=0; j<k+1; j++)
			{
				dp[i][j]=new int [2];
				for(int p=0; p<2; p++)
				{
					dp[i][j][p]=-1;
				}
			}
		}
		cout<<maximum_profit(arr, n, k, 0, dp)<<endl;
		for(int i=0; i<n+1; i++)
		{
			for(int j=0; j<k+1; j++)
			{
				delete[]dp[i][j];
			}
			delete[]dp[i];
		}
		delete[]dp;
	}
}