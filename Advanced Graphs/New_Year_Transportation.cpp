#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<int>*edges, int n, int start, bool*visited)
{
    visited[start]=true;
    for(int i=0; i<edges[start].size(); i++)
    {
        int adjacent=edges[start][i];
        if(!visited[adjacent])
        {
            dfs(edges, n, adjacent, visited);
        }
    }
}
bool checker(vector<int> *edges, int n, int t)
{
    bool *visited=new bool[n];
    for(int i=0; i<n; i++)
    {
        visited[i]=false;
    }
    dfs(edges, n, 0, visited);
    if(visited[t-1])
    {
        return true;
    }
    return false;
}
int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> *edges = new vector<int>[n];
    for (int i = 1; i <= n - 1; i++)
    {
        int a;
        cin >> a;
        edges[i - 1].push_back(i + a - 1); // i-th (1 ≤ i ≤ n - 1) portal connects cell i and cell (i + ai)
    }
    if (checker(edges, n, t))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}