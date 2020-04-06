#include <bits/stdc++.h>
using namespace std;
#define error(x) cout << #x << " = " << x << endl;
#define endl "\n"
#define F first
#define S second
#define pb push_back
#define mod 1000000007
#define int long long int
#define all(x) x.begin(), x.end()
#define fast                     \
    ios::sync_with_stdio(false); \
    cin.tie(0)
#define scan(arr, a, n)             \
    for (int i = (a); i < (n); i++) \
        cin >> (arr)[i];
#define print(arr, a, n)            \
    for (int i = (a); i < (n); i++) \
        cout << (arr)[i] << " ";
int a[100000];
int l;
bool check(int x)
{
    if (abs(x) % 2 == 1 || x == 0)
        return true;
    if (abs(x) % 4 == 0)
        return true;
    return false;
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    fast;
    //  SieveOfEratosthenes();
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        int a[n];
        scan(a, 0, n);
        int mx = 0;
        int count = 0;
        for (int k = 0; k < n; k++)
        {
            //    if(a[k]==0)
            //     continue;
            if (check(a[k]))
                count++;
            int s = a[k];
            for (int j = k + 1; j < n; j++)
            {
                //     if(a[j]==0)
                //      break;
                s = s * a[j];
                if (check(s))
                    count++;
            }
        }
        cout << count << '\n';
    }
    return 0;
}