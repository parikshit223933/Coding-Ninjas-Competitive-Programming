/* Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows. 
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Sample Input :
1
5 3
1
2
8
4
9
Sample Output:
3 
Output details:
FJ can put his 3 cows in the stalls at positions 1, 4 and 8, 
resulting in a minimum distance of 3. */


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