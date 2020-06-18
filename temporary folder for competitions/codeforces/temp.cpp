#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
#include <vector>
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
unordered_map<int, unordered_map<int,  pair<int, bool>>>dp;
int operations(int a, int b, int n)
{
    if(a>n||b>n)
    {
        dp[a][b].second=true;
        dp[a][b].first=0;
        return 0;
    }
    if(a>b)
    {
        return 1+operations(a, a+b, n);
    }
    else
    {
        return 1+operations(a+b, b, n);
    }
    
}
 
int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        dp.clear();
        int a, b, n;
        cin>>a>>b>>n;
        cout<<operations(a, b, n)<<endl;
    }
}