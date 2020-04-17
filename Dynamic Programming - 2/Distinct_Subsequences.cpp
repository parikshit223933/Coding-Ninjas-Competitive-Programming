/* Given a string, count the number of distinct subsequences of it ( including empty subsequence ). For the uninformed, A subsequence of a string is a new string which is formed from the original string by deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.
Input
First line of input contains an integer T which is equal to the number of test cases. You are required to process all test cases. Each of next T lines contains a string s.
Output
Output consists of T lines. Ith line in the output corresponds to the number of distinct subsequences of ith input string. Since, this number could be very large, you need to output ans%1000000007 where ans is the number of distinct subsequences. 
Constraints and Limits
T ≤ 100, length(S) ≤ 100000

All input strings shall contain only uppercase letters.
Sample Input
3
AAA
ABCDEFG
CODECRAFT
Sample Output
4
128
496 */




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