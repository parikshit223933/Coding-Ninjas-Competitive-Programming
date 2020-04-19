/* Edges in MST
You are given a connected weighted undirected graph without any loops and multiple edges.

Let us remind you that a graph's spanning tree is defined as an acyclic connected subgraph of the given graph that includes all of the graph's vertexes. The weight of a tree is defined as the sum of weights of the edges that the given tree contains. The minimum spanning tree (MST) of a graph is defined as the graph's spanning tree having the minimum possible weight. For any connected graph obviously exists the minimum spanning tree, but in the general case, a graph's minimum spanning tree is not unique.

Your task is to determine the following for each edge of the given graph: whether it is either included in any MST, or included at least in one MST, or not included in any MST.
Input
The first line contains two integers n and m (2 ≤ n ≤ 105, ) — the number of the graph's vertexes and edges, correspondingly. Then follow m lines, each of them contains three integers — the description of the graph's edges as "ai bi wi" (1 ≤ ai, bi ≤ n, 1 ≤ wi ≤ 106, ai ≠ bi), where ai and bi are the numbers of vertexes connected by the i-th edge, wi is the edge's weight. It is guaranteed that the graph is connected and doesn't contain loops or multiple edges.
Output
Print m lines — the answers for all edges. If the i-th edge is included in any MST, print "any"; if the i-th edge is included at least in one MST, print "at least one"; if the i-th edge isn't included in any MST, print "none". Print the answers for the edges in the order in which the edges are specified in the input.
Sample input 1
4 5
1 2 101
1 3 100
2 3 2
2 4 2
3 4 1
sample output 1
none
any
at least one
at least one
any
Sample input 2
3 3
1 2 1
2 3 1
1 3 2
sample output 2
any
any
none
sample input 3
3 3
1 2 1
2 3 1
1 3 1
sample output 3
at least one
at least one
at least one
Note
In the second sample the MST is unique for the given graph: it contains two first edges.

In the third sample any two edges form the MST for the given graph. That means that each edge is included at least in one MST. */




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