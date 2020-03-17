#include<bits/stdc++.h>
using namespace std;
vector<string> splitter(string s)
{
	vector<string>v;
	int start=0;
	int end=0;
	while(end<s.length())
	{
		while(s[end]!=' ')
		{
			end++;
		}
		v.push_back(s.substr(start, end-start));
		end++;
		start=end;
	}
	return v;
}
int main()
{
	string s;
	getline(cin, s);
	map<string, int>m;
	vector<string>v=splitter(s);
	for(int i=0; i<v.size(); i++)
	{
		m[v[i]]+=1;
	}
	map<string, int>::iterator it;
	for(it=m.begin(); it!=m.end(); it++)
	{
		string name=it->first;
		int freq=it->second;
		if(freq>1)
		{
			cout<<name<<" "<<freq<<endl;
		}
	}
}