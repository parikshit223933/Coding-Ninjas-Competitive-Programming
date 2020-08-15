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
int32_t main()
{
    int n;
    cin>>n;
    cout<<largestFactor(n)<<endl;
}