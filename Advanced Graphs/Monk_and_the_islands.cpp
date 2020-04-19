/* MONK AND THE ISLAND
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.
Input:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.
Output:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ X, Y ≤ N
SAMPLE INPUT
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
SAMPLE OUTPUT
2
2 */


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