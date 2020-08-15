#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long int
#define uint unsigned long long int
using namespace std;

int largestFactor(int n)
{
    // Vector to store half of the divisors
    vector<int> v;
    v.push_back(1);
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            v.push_back(n / i);
        }
    }

    sort(v.begin(), v.end());
    v.pop_back();
    return v[v.size() - 1];
}
int solve(int m, int n)
{
    vector<int> v1;
    v1.push_back(m);
    int ele = largestFactor(m);
    int count = 1;
    while (ele != 1)
    {
        v1.push_back(ele);
        count++;
        if (ele == n)
        {
            return count-1;
        }
        ele = largestFactor(ele);
    }

    vector<int> v2;
    v2.push_back(n);
    ele = largestFactor(n);
    int count2 = 1;
    while (ele != 1)
    {
        v2.push_back(ele);
        count2++;
        if (ele == m)
        {
            return count2-1;
        }
        ele = largestFactor(ele);
    }
    return count + count2;
}
int32_t main()
{
    fast;
    int m, n;
    cin >> m >> n;
    cout << solve(m, n) << endl;
}