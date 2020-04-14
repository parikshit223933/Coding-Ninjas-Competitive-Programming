/* There is only one beauty parlour in the town CodingNinjasLand. The receptionist at the beauty parlor is flooded with appointment requests because the “Hakori” festival is round the corner and everyone wants to look good on it.
She needs your help. The problem is they don’t have chairs in reception. They are ordering chairs from NinjasKart. They don’t want to order more than required. You have to tell the minimum number of chairs required such that none of the customers has to stand.
Input Format :
First line contains the number of customers that will come. Second line contains N space-separated integers which represent the arrival timings of the customer. Third line contains N space-separated integers which represent the departure timings of the customer. Arrival and departure timings are given in 24-hour clock.
Constraints:
1<= N <= 100
Arrival and departure timings lie in the range [0000 to 2359]
Time Limit: 1 second
Output Format :
You have to print the minimum number of chairs required such that no customer has to wait standing. 
Sample Test Cases:
Sample Input 1 :
5
900 1000 1100 1030 1600
1900 1300 1130 1130 1800
Sample Output 1:
4
Explanation:
4 because at 1100 hours, we will have maximum number of customers at the shop, throughout the day. And that maximum number is 4.  */
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