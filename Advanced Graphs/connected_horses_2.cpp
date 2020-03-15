#include <iostream>
using namespace std;
#define p int(1e9 + 7)
#define ll long long int
int mat[1001][1001], n, m;
ll fac(ll t)
{
    ll ans = 1;
    for (ll i = 1; i <= t; i++)
    {
        ans=(ans*i)%p;
    }
    return ans;
}
ll bfs(ll i, ll j)
{
    ll t=1;
    mat[i][j]=2;
    // the eight conditions
    if(i-2>=1 && j+1<=m && mat[i-2][j+1]==1)
        t+=bfs(i-2,j+1);
    if(i-1>=1 && j+2<=m && mat[i-1][j+2]==1)
        t+=bfs(i-1,j+2);
    if(i+1<=n && j+2<=m && mat[i+1][j+2]==1)
        t+=bfs(i+1,j+2);
    if(i+2<=n && j+1<=m && mat[i+2][j+1]==1)
        t+=bfs(i+2,j+1);
    if(i-2>=1 && j-1>=1 && mat[i-2][j-1]==1)
        t+=bfs(i-2,j-1);
    if(i-1>=1 && j-2>=1 && mat[i-1][j-2]==1)
        t+=bfs(i-1,j-2);
    if(i+1<=n && j-2>=1 && mat[i+1][j-2]==1)
        t+=bfs(i+1,j-2);
    if(i+2<=n && j-1>=1 && mat[i+2][j-1]==1)
        t+=bfs(i+2,j-1);
    return t;
}
void func()
{
    long long ans = 1, t;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (mat[i][j] == 1)
            {
                t = bfs(i, j);
                ans = (ans * fac(t)) % p;
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
    int x, y;
    while (q--)
    {
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
}