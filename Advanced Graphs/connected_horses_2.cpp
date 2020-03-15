#include <iostream>
using namespace std;
#define ll long long int
#define mod int(1e9 + 7)
int mat[1001][1001], n, m;
ll fact(ll t)
{
	int ans = 1;
	for (ll i = 1; i <= t; i++)
	{
		ans = (ans * i) % mod;
	}
	return ans;
}
int bfs(ll i, ll j)
{
	ll total = 1;
	mat[i][j] = 2;
	// now we have to write the conditions where the horse moves
	if (i - 2 >= 1 && j + 1 <= m && mat[i - 2][j + 1] == 1)
	{
		total += bfs(i - 2, j + 1);
	}
	if (i - 2 >= 1 && j - 1 >= 1 && mat[i - 2][j - 1] == 1)
	{
		total += bfs(i - 2, j - 1);
	}
	if (i + 2 <= n && j + 1 <= m && mat[i + 2][j + 1] == 1)
	{
		total += bfs(i + 2, j + 1);
	}
	if (i + 2 <= n && j - 1 >= 1 && mat[i + 2][j - 1] == 1)
	{
		total += bfs(i + 2, j - 1);
	}
	////////////////////////////////////////////////////////
	if (i - 1 >= 1 && j + 2 <= m && mat[i - 1][j + 2] == 1)
	{
		total += bfs(i - 1, j + 2);
	}
	if (i - 1 >= 1 && j - 2 >= 1 && mat[i - 1][j - 2] == 1)
	{
		total += bfs(i - 1, j - 2);
	}
	if (i + 1 <= n && j + 2 <= m && mat[i + 1][j + 2] == 1)
	{
		total += bfs(i + 1, j + 2);
	}
	if (i + 1 <= n && j - 2 >= 1 && mat[i + 1][j - 2] == 1)
	{
		total += bfs(i + 1, j - 2);
	}
	return total;
}
void func()
{
	ll ans = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (mat[i][j] == 1)
			{
				ll t = bfs(i, j);
				ans = (ans * fact(t)) % mod;
			}
		}
	}
	cout << ans << endl;
}
void input()
{
	int q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			mat[i][j] = 0;
		}
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		mat[x][y] = 1;
	}
	func();
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		input();
	}
	return 0;
}