#include <iostream>
#include <vector>
#include<utility>
using namespace std;
////////////////////////////////////////
const int N = 1e5 + 5;
bool error;
int col[N];
vector<pair<int, int>> adj[N];
////////////////////////////////////////
void dfs(int start)
{
    for (auto edge : adj[start])
    {
        int next = edge.first;
        if (col[next] == -1)
        {
            col[next] = col[start] ^ edge.second;
            dfs(next);
        }
        else if (col[next] != col[start] ^ edge.second)
        {
            error = true;
        }
    }
}
////////////////////////////////////////
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        error = false;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            col[i] = -1;
        }
        while (m--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
        }
        for (int i = 1; i <= n; i++)
        {
            if (col[i] == -1)
            {
                col[i] = 0;
                dfs(i);
            }
        }
        if (error)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
}
