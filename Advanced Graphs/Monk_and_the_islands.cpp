#include <iostream>
#include <vector>
#include <queue>
#include<unordered_set>
using namespace std;

inline int bfs(vector<vector<int>> graph, int n)
{
    bool *visited = new bool[n];//considering the time complexity requirement of this question, an unordered set cant be used
    //for storing visited vertices. because visited.count() would cross the time limit
    
    for (int i = 0; i < n; i++)
        visited[i] = false;

    int *level = new int[n + 1];
    for (int i = 0; i <= n; i++)
        level[i] = 0;

    queue<int> q;
    q.push(0);

    visited[0] = true;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < graph[v].size(); i++)
        {
            int next = graph[v][i];
            if (!visited[next])
            {
                q.push(next);
                visited[next] = true;
                level[next] = level[v] + 1;
            }
        }
    }
    return level[n - 1];
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> graph(n);

        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x - 1].push_back(y - 1);
            graph[y - 1].push_back(x - 1);
        }
        cout << bfs(graph, n) << endl;
    }
    return 0;
}