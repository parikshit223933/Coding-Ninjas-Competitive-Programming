#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <vector>
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
bool checker(string s, int n, int m)
{
    unordered_map<char, int> map;
    for (int i = 0; i < n; i++)
    {
        map[s[i]]++;
    }
    vector<int> v;
    for (unordered_map<char, int>::iterator itr = map.begin(); itr != map.end(); itr++)
    {
        v.push_back(itr->second);
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.size(); i++)
    {
        if (m <= v[i])
        {
            return true;
        }
        else
        {
            if (v[i] % 2 == 0)
                m -= v[i];
            else if(v[i]==1)
                continue;
            else
                m-=v[i];
        }
    }
    if (m > 0)
    {
        return false;
    }
    return true;
}
int main()
{
    fast int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        if (checker(s, n, m))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}