/* There are only three phases in Swaps life: Sleep, Play and Study. Also, there are two types of emotions Swaps experiences: Happy and Sad. Each phase of his life brings either kind of emotions.
The sleep and the play phase makes Swaps happy whereas the study phase makes him sad. Quite obvious, isn't it? But we know that life isn't that great, one cannot be happy all the time.
Swaps, being a very sensitive guy, doesn't like to mix his emotions in a particular day. So each day, he is in exactly one of the three phases.
Given N which denotes the number of days and K which denotes the exact number of days Swaps needs to be happy out of these N days, can you tell him in how many ways can he achieve this? Since the output value can be very large, take modulo with 1000000007(10^9+7)
Input:
The first line of the input contains T, denoting the number of test cases.

The next T lines contain two space-separated integers N and K.
Output:
For each test-case, output a single integer, the number of ways modulo 1000000007(10^9+7).
Constraints:
1 ≤ T ≤ 10^5
1 ≤ N ≤ 10^6
1 ≤ K ≤ 10^6
K ≤ N
Sample Input :
3
1 1
2 1
3 2
Sample Output:
2
4
12
Explanation
In the first test case, he needs to be happy on Day 1. Hence, answer is 2 (He can either play or sleep).

In the second test case, he can be happy either on Day 1 or Day 2. So number of ways = 4. */




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