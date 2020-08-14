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
int solve(string s1, string s2, int x, int y)
{
	if(s2.length()>s1.length())
	{
		return INT_MAX;
	}
	int min_length=min(s1.length(), s2.length());
	int totalScore=0;
	for(int i=0; i<min_length; i++)
	{
		if(s2[i]=='_')
		{
			totalScore+=x;
		}
		else if(s1[i]==s2[i])
		{
			totalScore+=y;
		}
	}
		
}
int main()
{
	string s1, s2;
	cin>>s1>>s2;
	int x, y;
	cin>>x>>y;

	cout<<solve(s1, s2, x, y)<<endl;
}