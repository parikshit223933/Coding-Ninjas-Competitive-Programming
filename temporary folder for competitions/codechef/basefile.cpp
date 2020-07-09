#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#define fast                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);
#define endl '\n'
#define int long long int
using namespace std;

int solve(int *a, int *b, int n)
{
	unordered_map<int, int>map;
	int minimum=INT_MAX;
	for(int i=0; i<n; i++)
	{
		map[a[i]]++;
		map[b[i]]++;
		minimum=min(minimum, a[i]);
		minimum=min(minimum, b[i]);
	}
	bool stop=false;

	unordered_map<int, int>correct;
	for(auto iterator=map.begin(); iterator!=map.end(); iterator++)
	{
		if(iterator->second%2!=0)
		{
			stop=true;
			break;
		}
		else
		{
			correct[(iterator->first)]=(iterator->second)/2;
		}
	}
	if(stop)
	{
		return -1;
	}

	unordered_map<int, int>copyOfCorrect=correct;
	vector<int>s1, s2;
	for(int i=0; i<n; i++)
	{
		if(copyOfCorrect[a[i]])
		{
			copyOfCorrect[a[i]]--;
		}
		else
		{
			s1.push_back(a[i]);
		}
	}
	copyOfCorrect.clear();
	copyOfCorrect=correct;
	for(int i=0; i<n; i++)
	{
		if(copyOfCorrect[b[i]])
		{
			copyOfCorrect[b[i]]--;
		}
		else
		{
			s2.push_back(b[i]);
		}
	}
	
	if(s1.size()==0)
	{
		return 0;
	}
	if(s1.size()!=s2.size())
	{
		return -1;
	}


	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end(), greater<int>());
	int cost=0;
	for(int i=0; i<s1.size(); i++)
	{
		cost+=min(2*minimum, min(s1[i], s2[i]));
	}
	return cost;
}

int32_t main()
{
    fast;
    int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int *a=new int [n];
		int *b=new int [n];
		for(int i=0; i<n; i++)
		{
			cin>>a[i];
		}
		for(int i=0; i<n; i++)
		{
			cin>>b[i];
		}
		cout<<solve(a, b, n)<<endl;
	}
}