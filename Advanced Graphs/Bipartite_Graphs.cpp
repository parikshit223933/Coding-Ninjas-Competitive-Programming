#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
bool bipartite(vector<int> *edges, int n)
{
    if (n == 0)
    {
        return true;
    }
    unordered_set<int> sets[2];
    vector<int> pending;
    sets[0].insert(0);
    pending.push_back(0);
    while (pending.size() > 0)
    {
        int current = pending.back();
        pending.pop_back(); //here pending vector is being used as a stack
        int set_of_current_element = sets[0].count(current) > 0 ? 0 : 1;
        //is the current element is in pending then it has to be in one of the sets, either 0 or 1.
        //now iterating over all of its neighbours
        for (int i = 0; i < edges[current].size(); i++)
        {
            int adjacent = edges[current][i];
            if (sets[0].count(adjacent) == 0 && sets[1].count(adjacent) == 0)
            {
                sets[1 - set_of_current_element].insert(adjacent);
                pending.push_back(adjacent);
            }
            else //in this case the element is in one of the sets
            {
                if (sets[set_of_current_element].count(adjacent) > 0)
                {
                    return false;
                }
            }
        }
    }
    return true;
    //in this code we have considered that or graph is fully connected. there are not disconnected components
}
int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            return 0;
        }
        vector<int> *edges = new vector<int>[n];
        int m;
        cin >> m;
        for (int i = 0; i < m; i++)
        {
            int j, k;
            cin >> j >> k;
            edges[j - 1].push_back(k - 1); //considering that the vertices are numbered from 1 to n.
            edges[k - 1].push_back(j - 1); //for internal calculation we will consider numbering from 0 to n-1.
        }
        bool ans = bipartite(edges, n);
        if (ans)
        {
            cout << "Bicolorable" << endl;
        }
        else
        {
            cout << "Not Bicolorable" << endl;
        }
        delete[] edges;
    }
}