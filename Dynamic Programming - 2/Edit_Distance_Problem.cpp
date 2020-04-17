/* Given two strings s and t of lengths m and n respectively, find the Edit Distance between the strings. Edit Distance of two strings is minimum number of steps required to make one string equal to other. In order to do so you can perform following three operations only :
1. Delete a character

2. Replace a character with another one

3. Insert a character
Note - Strings don't contain spaces
Input Format :
Line 1 : String s
Line 2 : String t
Output Format :
Line 1 : Edit Distance value
Constraints
1<= m,n <= 20
Sample Input 1 :
abc
dc
Sample Output 1 :
2 */



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