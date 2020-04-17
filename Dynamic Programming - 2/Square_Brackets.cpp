/* You are given:
a positive integer n,
an integer k, 1<=k<=n,
an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
What is the number of proper bracket expressions of length 2n with opening brackets appearing in positions s1, s2,...,sk?
Illustration
Several proper bracket expressions:
[[]][[[]][]] 
[[[][]]][][[]]
An improper bracket expression:
[[[][]]][]][[]]
There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.
Task
Write a program which for each data set from a sequence of several data sets:
1. reads integers n, k and an increasing sequence of k integers from input,
2. computes the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1,s2,...,sk,
3. writes the result to output.
Input
The first line of the input file contains one integer d, 1 <= d <= 10, which is the number of data sets. The data sets follow. Each data set occupies two lines of the input file. The first line contains two integers n and k separated by single space, 1 <= n <= 19, 1 <= k <= n. The second line contains an increasing sequence of k integers from the interval [1;2n] separated by single spaces.
Output
The i-th line of output should contain one integer - the number of proper bracket expressions of length 2n with opening brackets appearing at positions s1, s2,...,sk.
Sample Input
5 
1 1 
1 
1 1 
2 
2 1 
1 
3 1 
2 
4 2 
5 7 
Sample Output
1 
0 
2 
3 
2  */




#include<iostream>

using namespace std;
int number_of_proper_bracket_expressions(bool *boolean_arr, int n, int number_of_opening_brackets_till_now, int number_of_closing_brackets_till_now, int **dp)
{
	if(boolean_arr[0])
	{
		return 0;
	}
	if(dp[number_of_opening_brackets_till_now][number_of_closing_brackets_till_now]>=0)
	{
		return dp[number_of_opening_brackets_till_now][number_of_closing_brackets_till_now];
	}
	if(number_of_closing_brackets_till_now>n||number_of_opening_brackets_till_now>n)
	{
		return 0;
	}
	if(number_of_closing_brackets_till_now==n&&number_of_opening_brackets_till_now==n)
	{
		return 1;
	}
	int ans;
	if(number_of_closing_brackets_till_now==number_of_opening_brackets_till_now||boolean_arr[number_of_closing_brackets_till_now+number_of_opening_brackets_till_now+1])
	{
		ans= number_of_proper_bracket_expressions(boolean_arr, n, number_of_opening_brackets_till_now+1, number_of_closing_brackets_till_now, dp);
	}
	else if(number_of_opening_brackets_till_now==n)
	{
		ans= number_of_proper_bracket_expressions(boolean_arr, n, number_of_opening_brackets_till_now, number_of_closing_brackets_till_now+1, dp);
	}
	else
	{
		int option1=number_of_proper_bracket_expressions(boolean_arr, n, number_of_opening_brackets_till_now+1, number_of_closing_brackets_till_now, dp);
		int option2=number_of_proper_bracket_expressions(boolean_arr, n, number_of_opening_brackets_till_now, number_of_closing_brackets_till_now+1, dp);
		ans= option1+option2;
	}
	dp[number_of_opening_brackets_till_now][number_of_closing_brackets_till_now]=ans;
	return ans;
}
int main()
{
	int d;
	cin>>d;
	while(d--)
	{
		int n, k;
		cin>>n>>k;
		bool *boolean_arr=new bool [2*n+1];
		for(int i=0; i<=2*n; i++)
		{
			boolean_arr[i]=false;
		}
		for(int i=0; i<k; i++)
		{
			int element;
			cin>>element;
			boolean_arr[element]=true;
		}
		int **dp=new int *[21];
		for(int i=0; i<=20; i++)
		{
			dp[i]=new int [21];
			for(int j=0; j<21; j++)
			{
				dp[i][j]=-1;
			}
		}
		cout<<number_of_proper_bracket_expressions(boolean_arr, n, 0, 0, dp)<<endl;
	}
}