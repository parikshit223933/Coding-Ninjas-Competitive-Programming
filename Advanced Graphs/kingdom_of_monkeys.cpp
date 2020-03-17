#include<iostream>
#include<vector>
#include<climits>
using namespace std;
typedef long long int ll;
ll dfs(vector<ll>* edges, ll* arr, ll n, bool* visited, ll start)
{
    ll sum = arr[start];
    visited[start] = true;
    for (ll i = 0; i < edges[start].size(); i++)
    {
        ll adjacent = edges[start][i];
        if (!visited[adjacent])
        {
            sum += dfs(edges, arr, n, visited, adjacent);
        }
    }
    return sum;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<ll>* edges = new vector<ll>[n];
        for (ll i = 0; i < m; i++)
        {
            ll x, y;
            cin >> x >> y;
            edges[x - 1].push_back(y - 1);
            edges[y - 1].push_back(x - 1);
        }
        ll* arr = new ll[n];
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool* visited = new bool[n];
        for (ll i = 0; i < n; i++)
        {
            visited[i] = false;
        }
        ll maximum = INT_MIN;
        for (ll i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                ll current_component_total_bananas = dfs(edges, arr, n, visited, i);
                if (current_component_total_bananas > maximum)
                {
                    maximum = current_component_total_bananas;
                }
            }
        }
        cout << maximum << endl;
    }
}