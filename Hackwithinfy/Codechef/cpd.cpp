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
vector<int> vec[1000001];
bool vis1[100001];
int a[100001];
int N, s, d;
int k1;
unordered_map<int, int> mp;
void countDivisors(int n)
{
    int cnt = 0;
    if (n % 2 == 0)
    {
        while (n % 2 == 0)
            n = n / 2, ++mp[2];
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        if (n % i == 0)
        {
            // If divisors are equal,
            // count only one
            while (n % i == 0)
            {
                n = n / i;
                ++mp[i];
            }
        }
    }
    if (n > 1)
        ++mp[n];
}
void solve(int i, vector<int> &v)
{
    ;
    //cout<<1<<"*";
    if (d == i)
    {
        k1 = 1;
        v.pb(i);
        return;
    }
    vis1[i] = 1;
    v.pb(i);
    for (auto it : vec[i])
    {
        if (!vis1[it] && k1 == 0)
        {
            solve(it, v);
        }
        if (k1 == 1)
            return;
    }
    if (k1 == 1)
        return;
    v.pop_back();
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
        cin >> N;
        for (int i = 0; i < N - 1; i++)
        {
            int x, y;
            cin >> x >> y;
            vec[x].pb(y);
            vec[y].pb(x);
        }

        scan(a, 1, N + 1);
        int Q;
        cin >> Q;
        while (Q--)
        {
            mp.clear();
            cin >> s >> d;
            vector<int> v;
            memset(vis1, 0, sizeof(vis1));
            //   v.pb(d);
            int x = 1;
            //   cout<<ans<<" ";//<<vec[s].size()<<" ";
            k1 = 0;
            solve(s, v);
            for (auto i : v)
            {
                countDivisors(a[i]);
            }
            //cout<<mp.size()<<' ';
            int res = 1;
            for (auto i : mp)
            {
                res *= (i.S + 1);
                res = res % mod;
            }

            cout << res << '\n';
        }
    }
    return 0;
}