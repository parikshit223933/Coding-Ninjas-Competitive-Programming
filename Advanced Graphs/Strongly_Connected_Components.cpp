//KosaRaju's Algorithm
#include <iostream>
#include <vector>
#include <stack>
#include <iterator>
#include <unordered_set>
using namespace std;
void dfs(vector<int> *edges, unordered_set<int> &visited, stack<int> &finished_vertices, int start)
{
    visited.insert(start);
    for (int i = 0; i < edges[start].size(); i++)
    {
        int adjacent_element = edges[start][i];
        if (visited.count(adjacent_element) == 0)
        {
            dfs(edges, visited, finished_vertices, adjacent_element);
        }
    }
    finished_vertices.push(start);
}
void dfs2(vector<int> *edgesT, int start, unordered_set<int> &visited, unordered_set<int> *component)
{
    visited.insert(start);
    component->insert(start);
    for (int i = 0; i < edgesT[start].size(); i++)
    {
        int adjacent = edgesT[start][i];
        if (visited.count(adjacent) == 0)
        {
            dfs2(edgesT, adjacent, visited, component);
        }
    }
}
unordered_set<unordered_set<int> *> *getSCC(vector<int> *edges, vector<int> *edgesT, int n)
{
    unordered_set<int> visited;
    stack<int> finished_vertices;
    for (int i = 0; i < n; i++)
    {
        if (visited.count(i) == 0)
        {
            dfs(edges, visited, finished_vertices, i);
        }
    }
    unordered_set<unordered_set<int> *> *output = new unordered_set<unordered_set<int> *>();
    visited.clear();
    while (!finished_vertices.empty())
    {
        int element = finished_vertices.top();
        finished_vertices.pop();
        if (visited.count(element) != 0)
        {
            continue;
        }
        unordered_set<int> *component = new unordered_set<int>();
        dfs2(edgesT, element, visited, component);
        output->insert(component);
    }
    return output;
}
int main()
{
    int n; //number of vertices
    cin >> n;
    vector<int> *edges = new vector<int>[n];
    vector<int> *edgesT = new vector<int>[n];
    int m; //number of eges
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int j, k;
        cin >> j >> k;
        edges[j - 1].push_back(k - 1);
        edgesT[k - 1].push_back(j - 1);
    }
    unordered_set<unordered_set<int> *> *components = getSCC(edges, edgesT, n);

    unordered_set<unordered_set<int> *>::iterator it1 = components->begin();
    while (it1 != components->end())
    {
        unordered_set<int> *component = *it1;
        unordered_set<int>::iterator it2 = component->begin();
        while (it2 != component->end())
        {
            cout << *it2 + 1 << " ";
            it2++;
        }
        cout << endl;
        delete component;
        it1++;
    }

    delete components;
    delete[] edges;
    delete[] edgesT;
}