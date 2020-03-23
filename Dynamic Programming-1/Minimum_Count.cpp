#include<iostream>
#include<algorithm>
using namespace std;
bool is_perfect_square(int n)
{
	for(int i=1; i<=32; i++)
	{
		if(n==i*i)
		{
			return true;
		}
	}
	return false;
}
int minCount(int n, int *dp=new int [1001])
{
	if(is_perfect_square(n)==true)
	{
		return 1;
	}
	if(n<=3)
	{
		return n;
	}
	int count=n;
	if(dp[n]>0)
	{
		return dp[n];
	}
	for(int i=1; i<=n; i++)
	{
		int temp=i*i;
		if(temp>n)
		{
			break;
		}
		else
		{
			count=min(count, 1+minCount(n-temp, dp));
		}
	}
	dp[n]=count;
	return count;
}