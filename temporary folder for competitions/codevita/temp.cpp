#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
#include <vector>
#include <cmath>
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

int solve(int n1, int n2)
{   
    return __gcd(n1, n2);
}

int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n1, n2;
        cin>>n1, n2;
        cout<<solve(n1, n2)<<endl;
    }
}