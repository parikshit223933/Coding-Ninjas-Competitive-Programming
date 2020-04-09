#include <iostream>
#include <vector>
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;
int happiness_quotient(vector<int> *edges, int n, int *arr, int start, int end)
{
    
}
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> *edges = new vector<int>[n];
        for (int i = 0; i < n - 1; i++) //adjacency list for edges(roads connecting two diff. cities)
        {
            int x, y;
            cin >> x >> y;
            edges[x - 1].push_back(y - 1);
            edges[y - 1].push_back(x - 1);
        }
        int *arr = new int[n]; //cost of a house in city i is Ai
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int q; //number of queries
        cin >> q;
        while (q--)
        {
            int u, v;
            cin >> u >> v;
            cout << happiness_quotient(edges, n, arr, u, v) << endl;
        }
    }
}