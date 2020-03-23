#include<iostream>
#include<algorithm>
using namespace std;
int minimum_money(int *captain, int *assistant, int n, int difference_between_assistants_and_captains, int **dp)
{
	if(n==0)
	{
		return 0;
	}
	if(dp[n][difference_between_assistants_and_captains]>=0)
	{
		return dp[n][difference_between_assistants_and_captains];
	}
	int ans;
	if(difference_between_assistants_and_captains==0)
	{
		ans= assistant[0]+minimum_money(captain+1, assistant+1, n-1, difference_between_assistants_and_captains+1, dp);
	}
	else if(difference_between_assistants_and_captains==n)
	{
		ans= captain[0]+minimum_money(captain+1, assistant+1, n-1, difference_between_assistants_and_captains-1, dp);
	}
	else
	{
		int option1=assistant[0]+minimum_money(captain+1, assistant+1, n-1, difference_between_assistants_and_captains+1, dp);
		int option2=captain[0]+minimum_money(captain+1, assistant+1, n-1, difference_between_assistants_and_captains-1, dp);
		ans= min(option1, option2);
	}
	dp[n][difference_between_assistants_and_captains]=ans;
	return ans;
}
int main()
{
	int n;
	cin>>n;
	int *assistant=new int [n];
	int *captain=new int [n];
	for(int i=0; i<n; i++)
	{
		cin>>captain[i]>>assistant[i];
	}
	int **dp=new int *[n];
	for(int i=0; i<=n; i++)
	{
		dp[i]=new int [n];
		for(int j=0; j<=n; j++)
		{
			dp[i][j]=-1;
		}
	}
	cout<<minimum_money(captain, assistant, n, 0, dp)<<endl;
    for(int i=0; i<=n; i++)
    {
        delete[]dp[i];
    }
    delete[]dp;
}