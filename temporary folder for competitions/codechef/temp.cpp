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

void solve()
{
	int k;
	int n = 7;
	cin >> k;
	k--;

	cout << 'O';
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (k > 0)
			{
				cout << '.';
			}
			else
			{
				cout << "X";
			}
			k--;
		}
		n = 8;
		cout << endl;
	}
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		solve();
	}
}