/* You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. Well, here 
we have for you a similar 
N*M size board with similar arrangement of black and white 
cells.
A few of these cells have Horses placed over them. 
Each horse is unique. Now these horses are not the 
usual horses which could jump to any of the 
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo 
10^9+7
Input:
First line contains 
T which is the number of test cases.
T test cases follow first line of each containing three integers 
N, M and Q where 
N,M is the size of the board and 
Q is the number of horses on it.

Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.
Output:
For each test case, output the number of photographs taken by photographer.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
SAMPLE INPUT
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
SAMPLE OUTPUT
4
2 */



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