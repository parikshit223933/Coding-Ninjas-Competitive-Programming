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

inline int power(int n)
{
    int sum;
    for (sum = 0; n > 0; sum += n % 10, n /= 10);
    return sum;
}

void solve(int *a, int *b, int n)
{
    int sumA=0;
    int sumB=0;
    for(int i=0; i<n; i++)
    {
        if(power(a[i])>power(b[i]))
        {
            sumA+=1;
        }
        else if(power(a[i])<power(b[i]))
        {
            sumB+=1;
        }
        else
        {
            sumA+=1;
            sumB+=1;
        }
    }
    if(sumA>sumB)
    {
        cout<<0<<" "<<sumA<<endl;
    }
    else if(sumA<sumB)
    {
        cout<<1<<" "<<sumB<<endl;
    }
    else
    {
        cout<<2<<" "<<sumA<<endl;
    }
}

int32_t main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *a = new int[n];
        int *b = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
        }
        solve(a, b, n);
    }
}