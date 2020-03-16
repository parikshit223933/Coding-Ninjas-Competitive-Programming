#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;
void dfs(vector<int> *edges, int start, unordered_set<int> &visited, stack<int> &finished_vertices_stack)
{
    visited.insert(start);
    for (int i = 0; i < edges[start].size(); i++)
    {
        int adjacent = edges[start][i];
        if (visited.count(adjacent) == 0)
        {
            dfs(edges, adjacent, visited, finished_vertices_stack);
        }
    }
    finished_vertices_stack.push(start);
    return;
}
void dfs2(vector<int> *edges, int start, unordered_set<int> &visited)
{
    visited.insert(start);
    for (int i = 0; i < edges[start].size(); i++)
    {
        int adjacent = edges[start][i];
        if (visited.count(adjacent) == 0)
        {
            dfs2(edges, adjacent, visited);
        }
    }
    return;
}
void getSCC(vector<int> *edges, int n)
{
    unordered_set<int> visited;
    stack<int> finished_vertices_stack;
    for (int i = 0; i < n; i++)
    {
        if (visited.count(i) == 0)
        {
            dfs(edges, i, visited, finished_vertices_stack);
        }
    }
    visited.clear();
    int count = 0;
    while (!finished_vertices_stack.empty())
    {
        int element = finished_vertices_stack.top();
        finished_vertices_stack.pop();
        if (visited.count(element) == 0)
        {
            count++;
            dfs2(edges, element, visited);
            //note that we are not using transposed graph in this question because we are not exactly looking for
            //strongly connected components. think why? :)
        }
    }
    cout << count << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int m;
        cin >> n >> m;
        vector<int> *edges = new vector<int>[n];
        int x, y;
        for (int i = 0; i < m; i++)
        {
            cin >> x >> y;
            edges[x - 1].push_back(y - 1);
        }
        getSCC(edges, n); //not using transposed graph.
        delete[] edges;
    }
}