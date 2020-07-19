#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#define fast                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);
#define endl '\n'
#define ll long long int
using namespace std;
void solve(string s)
{
	unordered_map<char, int>m;
	for(int i=0; i<s.length(); i++)
	{
		m[s[i]]++;
	};
	char max_char=0;
	int max_length=0;
	for(auto i: m)
	{
		if(max_length<i.second)
		{
			max_length=i.second;
			max_char=i.first;
		}
	}
	if(max_length==1)
	{
		char lmc;
		char mc='z';
		for(int i=0; i<s.length(); i++)
		{
			if((int)s[i]<(int)mc)
			{
				lmc=s[i];
			}
		}
		cout<<lmc<<endl;
	}
	else
	{
		for(int i=0; i<max_length; i++)
		{
			cout<<max_char;
		}
		cout<<endl;
	}
}
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		solve(s);
	}
}