#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;
int minimum_fare(int **arr, int n, int m, int i, int j, int **dp)
{
	if(i==n)
	{
		return 0;
	}
	if(dp[i][j]>=0)
	{
		return dp[i][j];
	}
	int option1=arr[i][j]+minimum_fare(arr, n, m, i+1, j, dp);
	int option2=INT_MAX;
	if(j+1<m)
	{
		option2=arr[i][j]+minimum_fare(arr, n, m, i+1, j+1, dp);
	}
	int option3=INT_MAX;
	if(j-1>=0)
	{
		option3=arr[i][j]+minimum_fare(arr, n, m, i+1, j-1, dp);
	}
	dp[i][j]= min(option1, min(option2, option3));
	return dp[i][j];
}
int main()
{
	int n, m;
	cin>>n>>m;
	int **arr=new int*[n];
	for(int i=0; i<n; i++)
	{
		arr[i]=new int [m];
		for(int j=0; j<m; j++)
		{
			cin>>arr[i][j];
		}
	}
	
	int **dp=new int *[n+1];
	for(int i=0; i<n+1; i++)
	{
		dp[i]=new int [m+1];
	}
	
	int minimum=INT_MAX;
	for(int bus=0; bus<m; bus++)
	{
		for(int i=0; i<n+1; i++)
		{
			for(int j=0; j<m+1; j++)
			{
				dp[i][j]=-1;
			}
		}
		minimum=min(minimum, minimum_fare(arr, n, m, 0, bus, dp));
	}
    for(int i=0; i<n+1; i++)
    {
        delete[]dp[i];
    }
    delete[]dp;
	cout<<minimum<<endl;
}