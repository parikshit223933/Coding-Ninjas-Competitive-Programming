#include <iostream>
#include <vector>
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
using namespace std;
const int MAX = 1000001;

int factor[MAX] = {0};

void generatePrimeFactors()
{
    factor[1] = 1;

    for (int i = 2; i < MAX; i++)
        factor[i] = i;

    for (int i = 4; i < MAX; i += 2)
        factor[i] = 2;

    for (int i = 3; i * i < MAX; i++)
    {

        if (factor[i] == i)
        {

            for (int j = i * i; j < MAX; j += i)
            {

                if (factor[j] == j)
                    factor[j] = i;
            }
        }
    }
}

int calculateNoOFactors(int n)
{
    if (n == 1)
        return 1;
    int ans = 1;
    int dup = factor[n];
    int c = 1;
    int j = n / factor[n];
    while (j != 1)
    {
        if (factor[j] == dup)
            c += 1;
        else
        {
            dup = factor[j];
            ans = ans * (c + 1);
            c = 1;
        }
        j = j / factor[j];
    }
    ans = ans * (c + 1);

    return ans;
}
int happiness_quotient(vector<int> *edges, int n, int *arr, int start, int end)
{
    if (start == endl)
    {
        return calculateNoOFactors(end);
    }
}

int main()
{
    fast;
    generatePrimeFactors();
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