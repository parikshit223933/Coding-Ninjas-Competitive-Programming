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

int solve(int x, int y, int n)
{
    /* k % x = y  */
    int current_rem=n%x;
    if(current_rem)
}

int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int x, y, n;
        cin>>x>>y>>n;
        cout<<solve(x, y, n)<<endl;
    }
}