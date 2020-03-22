#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
long long cost_calculator(vector<long long>v, long long k, long long l, long long n, long long number)
{
	long long increment = 0;
	long long decrement = 0;
	for(long long i=0; i<n; i++)
	{
		if(v[i]>number)
		{
			decrement += v[i] - number;
		}
		else if(v[i]<number)
		{
			increment += number - v[i];
		}
	}
	if(decrement>increment)
	{
		return INT_MAX;
	}
	return (decrement * k) + ((increment - decrement)*l);
}
int main()
{
	long long n, k, l;
	cin >> n >> k >> l;
	vector<long long>v;
	for(long long i=0; i<n; i++)
	{
		long long element;
		cin >> element;
		v.push_back(element);
	}
	long long minimum=9999999, maximum=-1;
	for(long long i=0; i<n; i++)
	{
		if(v[i]<minimum)
		{
			minimum = v[i];
		}
		if(v[i]>maximum)
		{
			maximum = v[i];
		}
	}
	long long cost = INT_MAX;
	for(long long i=minimum; i<=maximum; i++)
	{
		cost = min(cost, cost_calculator(v, k, l, n, i));
	}
	cout << cost;
}