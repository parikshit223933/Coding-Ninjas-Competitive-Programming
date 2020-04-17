/* Given 2 strings of S1 and S2 with lengths m and n respectively, find the length of longest common subsequence.
A subsequence of a string S whose length is n, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to n. E.g. subsequences of string "abc" are - "",a,b,c,ab,bc,ac,abc.
Input Format :
Line 1 : String S1
Line 2 : String s2
Output Format :
Line 1 : Length of lcs
Sample Input :
adebc
dcadb
Sample Output :
3 */




#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int lcs_recursion_method(string s1, string s2)//this is the basic recursion method.
{
	if(s1.length()==0||s2.length()==0)
	{
		return 0;
	}
	if(s1[0]==s2[0])
	{
		return 1+lcs_recursion_method(s1.substr(1), s2.substr(1));
	}
	else
	{
		int option1=lcs_recursion_method(s1.substr(1), s2);
		int option2=lcs_recursion_method(s1, s2.substr(1));
		return max(option1, option2);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int lcs_dynamically_recursive_helper(string s1, string s2, int n, int m, int **dp) //dynamically recursive solution
{
	if(s1.length()==0||s2.length()==0)
	{
		return 0;
	}
	if(dp[n][m]>=0)
	{
		return dp[n][m];
	}
	int ans;
	if(s1[0]==s2[0])
	{
		ans= 1+lcs_dynamically_recursive_helper(s1.substr(1), s2.substr(1), n-1, m-1, dp);
	}
	else
	{
		int option1=lcs_dynamically_recursive_helper(s1.substr(1), s2, n-1, m, dp);
		int option2=lcs_dynamically_recursive_helper(s1, s2.substr(1), n, m-1, dp);
		ans=max(option1, option2);
	}
	dp[n][m]=ans;
	return ans;
}
int lcs_dynamic_recursive(string s1, string s2)
{
	int n=s1.length();
	int m=s2.length();
	int**dp=new int* [n+1];
	for(int i=0; i<=n; i++)
	{
		dp[i]=new int [m+1];
		for(int j=0; j<=m; j++)
		{
			dp[i][j]=-1;
		}
	}
	int ans= lcs_dynamically_recursive_helper(s1, s2, n, m, dp);
	for(int i=0; i<n+1; i++)
	{
		delete[]dp[i];
	}
	delete[]dp;
	return ans;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int lcs(string s1, string s2)//iterative soltion
{
	int n=s1.length();
	int m=s2.length();
	int **dp=new int* [n+1];
	for(int i=0; i<n+1; i++)
	{
		dp[i]=new int [m+1];
		for(int j=0; j<m+1; j++)
		{
			dp[i][j]=0;
		}
	}
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(s1[n-i]==s2[m-j])
			{
				dp[i][j]=dp[i-1][j-1]+1;
			}
			else
			{
				dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	int ans= dp[n][m];
    for(int i=0; i<=n; i++)
    {
        delete[]dp[i];
    }
    delete[]dp;
	return ans;
}