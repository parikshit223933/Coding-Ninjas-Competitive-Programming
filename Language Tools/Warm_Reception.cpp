#include<bits/stdc++.h>
using namespace std;
struct triplets
{
	int st;
	int et;
	int diff;
};
bool sort_according_to_time_difference(triplets t1, triplets t2)
{
	return (t1.diff>t2.diff);
}
bool sort_according_to_starting_time(triplets t1, triplets t2)
{
	return (t1.diff>t2.diff);
}
bool sort_according_to_end_time(triplets t1, triplets t2)
{
	return (t1.diff>t2.diff);
}
int main()
{
	int n;
	cin>>n;
	vector<int>arrival;
	vector<int>departure;
	for(int i=0; i<n; i++)
	{
		int element;
		cin>>element;
		arrival.push_back(element);
	}
	for(int i=0; i<n; i++)
	{
		int element;
		cin>>element;
		departure.push_back(element);
	}
	triplets*arr=new triplets[n];
	for(int i=0; i<n; i++)
	{
		arr[i]={arrival[i], departure[i], departure[i]-arrival[i]};
	}
	
	int max_intersections=0;
	for(int i=0; i<=2359; i++)
	{
		int current_intersections=0;
		for(int j=0; j<n; j++)
		{
			if(i>=arr[j].st&&i<=arr[j].et)// these <= and >= are very important. maine last time ye nahi lagaae the is wajeh se bohot problem hui thi. inhe lagaa bht zaroorie hain check... how... this code uses a time complexity of O(n), where n is 10^6. which is actually pretty good.
			{
				current_intersections++;
			}
		}
		max_intersections=max(max_intersections, current_intersections);
	}
	cout<<max_intersections;
}