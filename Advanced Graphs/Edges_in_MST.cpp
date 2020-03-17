#include <iostream>
#include <vector>
#include <algorithm>
#define N 100001
using namespace std;
int n, m, x[N], y[N], z[N], p[N];
int ans[N], f[N], h[N], pe[N], d[N];
vector<pair<int, int>> v[N];
bool cmp(const int &x, const int &y)
{
    return z[x] < z[y];
}
int par(int x)
{
    while (pe[x])
        x = pe[x];
    return x;
}
void uni(int x, int y)
{
    x = par(x);
    y = par(y);
    v[x].clear();
    v[y].clear();
    f[x] = 0;
    f[y] = 0;
    if (x == y)
        return;
    if (h[x] > h[y])
        pe[y] = x;
    else
    {
        pe[x] = y;
        if (h[x] == h[y])
            h[y]++;
    }
}
void add_edge(int x, int y, int i)
{
    if (x == y)
        return;
    ans[i] = 1;
    v[x].push_back({y, i});
    v[y].push_back({x, i});
}
void kruskal(int c, int g, int h)
{
    f[c] = true;
    d[c] = h;
    for (pair<int, int> i : v[c])
        if (!f[i.first])
        {
            kruskal(i.first, i.second, h + 1);
            d[c] = min(d[c], d[i.first]);
        }
        else if (i.second != g)
            d[c] = min(d[c], d[i.first]);
    if (d[c] == h)
        ans[g] = 2;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x[i] >> y[i] >> z[i];
        p[i] = i;
    }
    sort(p + 1, p + m + 1, cmp);
    for (int i = 1; i <= m;)
    {
        int j;
        for (j = i; z[p[j]] == z[p[i]]; j++)
            add_edge(par(x[p[j]]), par(y[p[j]]), p[j]);
        for (j = i; z[p[j]] == z[p[i]]; j++)
        {
            int k = par(x[p[j]]);
            if (!f[k])
                kruskal(k, 0, 0);
        }
        for (j = i; z[p[j]] == z[p[i]]; j++)
            uni(x[p[j]], y[p[j]]);
        i = j;
    }
    for (int i = 1; i <= m; i++)
        if (!ans[i])
            cout << "none" << endl;
        else if (ans[i] == 1)
            cout << "at least one" << endl;
        else
            cout << "any" << endl;
    return 0;
}