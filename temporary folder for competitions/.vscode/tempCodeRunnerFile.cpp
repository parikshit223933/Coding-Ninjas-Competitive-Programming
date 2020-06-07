#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define ll long long int
using namespace std;

int maximum_pairs(string s)
{
    int n = s.length();
    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'x')
        {
            arr[i] = 1;
        }
        else
        {
            arr[i] = 0;
        }
    }

    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }

    int count = 0;
    if (m[0] > m[1]) /* there are less ones */
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 1)
            {
                if (i == 0)
                {
                    if (arr[i + 1] == 0)
                    {
                        count++;
                        arr[i] = 2;
                        arr[i+1]=2;
                    }
                    continue;
                }
                else if (i == n - 1)
                {
                    if (arr[i - 1] == 0)
                    {
                        count++;
                        arr[i] = 2;
                        arr[i-1]=2;
                    }
                    continue;
                }
                else
                {
                    if (arr[i - 1] == 0)
                    {
                        arr[i] = 2;
                        arr[i - 1] = 2;
                        count++;
                    }
                    else if (arr[i + 1] == 0)
                    {
                        arr[i] = 2;
                        arr[i + 1] = 2;
                        count++;
                    }
                }
            }
        }
    }
    else /* there are less zeros */
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                if (i == 0)
                {
                    if (arr[i + 1] == 1)
                    {
                        count++;
                        arr[i] = 2;
                        arr[i+1]=2;
                    }
                    continue;
                }
                if (i == n - 1)
                {
                    if (arr[i - 1] == 1)
                    {
                        count++;
                        arr[i] = 2;
                        arr[i-1]=2;
                    }
                    continue;
                }
                else
                {
                    if (arr[i - 1] == 1)
                    {
                        arr[i] = 2;
                        arr[i - 1] = 2;
                        count++;
                    }
                    else if (arr[i + 1] == 1)
                    {
                        arr[i] = 2;
                        arr[i + 1] = 2;
                        count++;
                    }
                }
            }
        }
    }
    delete[] arr;
    return count;
}
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << maximum_pairs(s) << endl;
    }
}