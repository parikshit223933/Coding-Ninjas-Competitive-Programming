#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
#include<algorithm>
#include <iterator>
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
    stack<int> finished_vertices_stack;
    for (int i = 0; i < n; i++)
    {
        if (visited.count(i) == 0)
        {
            dfs(edges, i, visited, finished_vertices_stack);
        }
    }
    visited.clear();
    unordered_set<unordered_set<int> *> *output = new unordered_set<unordered_set<int> *>();
    while (!finished_vertices_stack.empty())
    {
        int element = finished_vertices_stack.top();
        finished_vertices_stack.pop();
        if (visited.count(element) == 0)
        {
            unordered_set<int> *component = new unordered_set<int>();
            dfs2(edgesT, element, visited, component);
            output->insert(component);
        }
    }
    return output;
}
int main()
{
    while (true)
    {
        int v; //vertices
        cin >> v;
        if (v == 0)
        {
            return 0;
        }
        int e;
        cin >> e;
        vector<int> *edges = new vector<int>[v];
        vector<int> *edgesT = new vector<int>[v];
        for (int i = 0; i < e; i++)
        {
            int j, k;
            cin >> j >> k;
            edges[j - 1].push_back(k - 1);
            edgesT[k - 1].push_back(j - 1);
        }
        unordered_set<unordered_set<int> *> *components = getSCC(edges, edgesT, v);

        auto it = components->begin();
        vector<int> ans;
        while (it != components->end())
        {
            int flag = 0;
            auto it2 = (*it)->begin();
            while (it2 != (*it)->end())
            {
                for (int i = 0; i < edges[*it2].size(); ++i)
                {

                    if ((*it)->count(edges[*it2].at(i)) == 0)
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 1)
                {
                    break;
                }
                it2++;
            }
            if (flag == 0)
            {
                it2 = (*it)->begin();
                while (it2 != (*it)->end())
                {
                    ans.push_back(*it2 + 1);
                    it2++;
                }
            }

            it++;
        }
        sort(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); ++i)
        {
            cout << ans.at(i) << " ";
        }
        cout<<endl;
    }
}