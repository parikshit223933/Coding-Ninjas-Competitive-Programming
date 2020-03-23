#include<iostream>
#include<algorithm>
using namespace std;
int editDistance(string s1, string s2)
{
	int n=s1.length();
	int m=s2.length();
	int **dp=new int*[n+1];
	for(int i=0; i<=n; i++)
	{
		dp[i]=new int [m+1];
		for(int j=0; j<=m; j++)
		{
			dp[i][j]=0;
		}
	}
	for(int i=1; i<=n; i++)
	{
		dp[i][0]=i;
	}
	for(int i=1; i<=m; i++)
	{
		dp[0][i]=i;
	}
	for(int i =1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(s1[n-i]==s2[m-j])
			{
				dp[i][j]=dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
			}
		}
	}
	int ans=dp[n][m];
	for(int i=0; i<=n; i++)
    {
        delete[]dp[i];
    }
    delete[]dp;
	return ans;
}