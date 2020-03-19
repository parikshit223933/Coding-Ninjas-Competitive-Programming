#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long int ll;
bool arranger(ll* positions, ll distance, ll n, ll c)
{
	ll start = 0;
	ll end = 1;
	c--;
	while (c != 0 && end <= n - 1)
	{
		while (positions[end] - positions[start] < distance)
		{
			end++;
		}
		start = end;
		end++;
		c--;
	}
	if (c != 0 || end > n)
	{
		return false;
	}
	else if (c == 0 && end <= n - 1)
	{
		return true;
	}
}
ll largest_minimum_distance(ll* positions, ll n, ll c)
//c is the number of cows
{
	sort(positions, positions + n);

	cout << endl;
	ll start = 0;
	ll end = positions[n - 1] - positions[0];
	ll mid=0;
	while (start < end)
	{
		ll mid_previous = mid;
		mid = (start + end) / 2;
		ll ans = mid;
		//if i can arrange the cows at mid then i will try from mid to end
		//else i will try for start to mid
		if (arranger(positions, mid, n, c))
		{
			start = mid;
		}
		else
		{
			end = mid;
		}
		if(end-start==1)
		{
			if(arranger(positions, end, n, c))
			{
				return end;
			}
			else
			{
				return start;
			}
		}
	}
	return mid;
}
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, c;
		cin >> n >> c;
		ll* positions = new ll[n];
		for (ll i = 0; i < n; i++)
		{
			cin >> positions[i];
		}
		cout << largest_minimum_distance(positions, n, c) << endl;
		//n==number of positions, c==number of cows.
	}
}