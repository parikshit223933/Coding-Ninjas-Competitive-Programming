#include<bits/stdc++.h>
#define m 1000000007
using namespace std;
typedef unsigned long long int ll;
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	ll** dp = new ll* [n];
	for (int i = 0; i < n; i++)
	{
		dp[i] = new ll[101];
		for (int g = 0; g <= 100; g++)
		{
			dp[i][g] = 0;
		}
	}
	
	dp[0][arr[0]] = 1;
	ll sum=dp[0][1];
	for (int i = 1; i < n; i++)
	{
		for (int k = i - 1; k >= 0; k--)
		{
			if (arr[i] > arr[k])
			{
				for (int g = 1; g <= 100; g++)
				{
					int new_gcd = __gcd(arr[i], g);
					dp[i][new_gcd] =(dp[i][new_gcd]+ dp[k][g])%m;
				}
			}
		}
		dp[i][arr[i]]++;
		sum=(sum+dp[i][1])%m;
	}
	cout<<sum<<endl;
	for (int i = 0; i < n; i++)
	{
		delete[] dp[i];
	}
	delete[]dp;
	delete[]arr;
}