#include<iostream>
#include<string>
#define m 1000000007
using namespace std;
typedef long long int ll;
ll subsequences(string s)
{
	ll n=s.length();
	ll *dp=new ll [n+1];
	ll *character_indexer_array=new ll [26];
	for(ll i=0; i<26; i++)
	{
		character_indexer_array[i]=-1;
	}
	dp[0]=1;//there is exactly one subsequence with string of length 0 that is null string.
	for(ll i=1; i<=n; i++)
	{
		dp[i]=(2*dp[i-1])%m;
		if(character_indexer_array[s[i-1]-65]!=-1)
		{
			dp[i]=(dp[i]-dp[character_indexer_array[s[i-1]-65]]+m)%m;
		}
		//and for the current character we will keep a mark in the character_indexer_array.
		character_indexer_array[s[i-1]-65]=i-1;
	}
	ll ans =dp[n]%m;
	delete[]dp;
	delete[]character_indexer_array;
	return ans;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<subsequences(s)<<endl;
	}
}