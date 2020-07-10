#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#define fast                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);
#define endl '\n'
#define int long long int
using namespace std;

int solve(int *arr, int n, int x)
{
	int x_temporary = x;
	sort(arr, arr + n);
	int *arr_temp = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr_temp[i] = arr[i];
	}
	int d1 = 0;
	int d2 = 0;
	int Start = 0;
	int Max = n;
	while (Start < Max && arr[Start] < x)
	{
		Start += 1;
	}
	int tmpStart = Start;
	if (Start > 0)
	{
		tmpStart = Start - 1;
	}
	int frwd = Start;
	int bkwd = Start - 1;

	while (frwd < Max)
	{
		d1 += 1;
		if (x >= arr[frwd])
		{
			x = arr[frwd];
			arr[frwd] = 0;
			frwd += 1;
		}
		x = x << 1;
	}

	while (bkwd >= 0)
	{
		d1 += 1;
		if (x >= arr[bkwd])
		{
			x = arr[bkwd];
			arr[bkwd] = 0;
			bkwd -= 1;
		}
		x = x << 1;
	}

	frwd = tmpStart;
	bkwd = tmpStart - 1;
	while (frwd < Max)
	{
		d2 += 1;
		if (x_temporary >= arr_temp[frwd])
		{
			x_temporary = arr_temp[frwd];
			arr_temp[frwd] = 0;
			frwd += 1;
		}

		x_temporary = x_temporary << 1;
	}

	while (bkwd >= 0)
	{
		d2 += 1;
		if (x_temporary >= arr_temp[bkwd])
		{
			x_temporary = arr_temp[bkwd];
			arr_temp[bkwd] = 0;
			bkwd -= 1;
		}

		x_temporary = x_temporary << 1;
	}

	return min(d1, d2);
}

int32_t main()
{
	fast;
	int t;
	cin >> t;
	while (t--)
	{
		int n, x;
		cin >> n >> x;
		int *arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cout << solve(arr, n, x) << endl;
	}
}