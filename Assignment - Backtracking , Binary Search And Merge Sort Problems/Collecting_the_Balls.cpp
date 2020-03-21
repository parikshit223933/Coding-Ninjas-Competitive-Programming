#include<iostream>
using namespace std;
typedef long long ll;
bool check_for_k(ll k, ll n)
{
	ll singh = 0;
	ll sharma = 0;
	ll total_balls = n;
	while (total_balls >= k)
	{
		sharma += k;
		total_balls -= k;
		singh += total_balls / 10;
		total_balls -= total_balls / 10;
	}
	sharma += total_balls;
	if(n%2==0)
	{
		if (sharma >= n / 2)
		{
			return true;
		}
	}
	else if(n%2!=0)
	{
		if(sharma>=(n/2)+1)
		{
			return true;
		}
	}
	
	return false;
}
ll optimizer(ll n)
{
	ll start = 1;
	ll end = n;
	ll mid = (start + end) / 2;
	while (end >= start + 1)
	{
		mid = (start + end) / 2;
		if (check_for_k(mid, n))
		{
			end = mid;
		}
		else
		{
			start = mid;
		}
		if (end - start == 1)
		{
			if (check_for_k(start, n))
			{
				return start;
			}
			return end;
		}
	}
	return mid;
}
int main()
{
	ll n;
	cin >> n;
	cout << optimizer(n);
}