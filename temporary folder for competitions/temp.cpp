/* #include <iostream>
#include <unordered_map>
#include <vector>
#include <limits.h>
#include <algorithm>
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
int find_in_queue(string s, int n, int c, unordered_map<char, int> m)
{

    int total_in_queue = 0;
    for (auto i : m)
    {
        if (i.second > c)
        {
            total_in_queue += i.second - c;
        }
    }
    return total_in_queue;
}
int main()
{
    fast;
    int t; //number of test cases
    cin >> t;
    while (t--)
    {
        int n; //number of people
        int q; //number of queries
        cin >> n >> q;
        string s; //diseases -> n sized -> for n people
        cin >> s;
        unordered_map<char, int> m;
        for (auto i : s)
        {
            m[i]++;
        }
        while (q--)
        {
            int c; //number of available isolation centres
            cin >> c;
            cout << find_in_queue(s, n, c, m) << endl;
        }
    }
} */