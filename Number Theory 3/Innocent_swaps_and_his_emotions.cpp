//https://www.hackerearth.com/practice/math/combinatorics/basics-of-combinatorics/practiceproblems/algorithm/innocent-swaps-and-his-emotions-1/description/
/*
Oasis Surana
Delhi Technological University
*/
#include <iostream>
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);
#define ll long long
#define MAX 1000001
#define mod 1000000007
using namespace std;
ll fact[MAX];
ll modexpo(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    fast
        ll n,
        i, t, k, ans;
    fact[0] = 1;
    for (i = 1; i < MAX; i++)
    {
        fact[i] = i * fact[i - 1];
        if (fact[i] >= mod)
            fact[i] %= mod;
    }
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (k > n)
        {
            cout << endl;
            continue;
        }
        ans = modexpo(2, k);
        ans = (ans * fact[n]) % mod;
        ans = (ans * modexpo(fact[k], mod - 2)) % mod;
        ans = (ans * modexpo(fact[n - k], mod - 2)) % mod;
        cout << ans << endl;
    }
    return 0;
}