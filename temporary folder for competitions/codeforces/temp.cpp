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

int mod(int a)
{
    if(a<0)
    {
        return -1*a;
    }
    return a;
}

bool solve(int a, int b, int n, int m)
{
    
}

bool solve2(int a, int b, int n, int m)
{
    /* case 1: n of first type of guests */

    if(m<=min(a, b))
    {
        int rem=max(a, b)+(min(a, b)-m);
        if(n<=rem)
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

int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, n, m;
        cin>>a>>b>>n>>m;
        if(solve(a, b, n, m)||solve2(a, b, m, n))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
}