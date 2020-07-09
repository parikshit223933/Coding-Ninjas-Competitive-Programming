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
#define ll long long int
using namespace std;

int main()
{
	fast;
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		ll x_coordinate;
		ll y_coordinate;
		ll k;
		ll x=0;
		ll y=0;

		map<ll, ll> map1;
		map<ll, ll> map2;

		cin >> n;
		ll new_n = (4 * n) - 1;
		while (new_n--)
		{
			cin >> x >> y;
			/* searching x */
			if (map1.find(x) == map1.end())
			{
				map1[x]=1;
			}
			else
			{
				map1[x]++;
			}
			/* searching y */
			if (map2.find(y) == map2.end())
			{
				map2[y]=1;
			}
			else
			{
				map2[y]++;
			}
		}

		for (auto iterator = map1.begin(); iterator != map1.end(); iterator++)
		{

			if ((iterator->second) % 2 != 0)
			{
				x_coordinate = iterator->first;
				break;
			}
		}
		for (auto iterator = map2.begin(); iterator != map2.end(); iterator++)
		{

			if ((iterator->second) % 2 != 0)
			{
				y_coordinate = iterator->first;
				break;
			}
		}
		cout << x_coordinate << " " << y_coordinate << endl;
	}
	return 0;
}