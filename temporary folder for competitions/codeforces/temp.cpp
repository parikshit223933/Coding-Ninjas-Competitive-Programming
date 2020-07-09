#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
#include <vector>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long int
using namespace std;

bool solve(int a, int b, int n, int m)
{
    if (m > n)
    {
        if (m <= min(a, b))
        {
            if (n <= a + b - min(a, b) + m)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    else if(m==n)
    {
        if(a+b>=m+n)
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }
    else
    {
        if (max(a, b) - min(a, b) > n)
        {
            if (min(a, b) < m)
            {
                return false;
            }
            else
            {
                return false;
            }
        }
        else if (max(a, b) - min(a, b) == n)
        {
            int temp = min(a, b);
            if (m <= temp)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            int temp = min(a, b);
            n -= max(a, b) - min(a, b);
            if (temp + temp > m + n)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

int32_t main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, n, m;
        cin >> a >> b >> n >> m;
        if (solve(a, b, n, m))
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
}