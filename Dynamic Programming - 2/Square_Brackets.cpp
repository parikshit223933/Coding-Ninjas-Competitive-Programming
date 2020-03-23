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