#include<iostream>
#include<utility>
#include<algorithm>
using namespace std;
bool compare(pair<int, int> i1, pair<int, int> i2)
{
	return i1.second<i2.second;
}
int activities(pair<int, int>*arr, int n)
{
	int current_ending_time=arr[0].second;
	int count=1;
	for(int i=1; i<n; i++)
	{
		if(current_ending_time<=arr[i].first)
		{
			count+=1;
			current_ending_time=arr[i].second;
		}
	}
	return count;
}
int main()
{
	int n;
	cin>>n;
	pair<int, int> *arr=new pair<int, int>[n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr, arr+n, compare);
	cout<<activities(arr, n)<<endl;
}