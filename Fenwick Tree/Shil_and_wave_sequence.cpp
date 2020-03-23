#include<iostream>

#define MOD 1000000007
using namespace std;

int main()
{
    long long n, x, t, sum1, sum2;
    cin >> n;
    long long dpl[100001] = {0}, dph[100001] = {0}, a[100001] = {0};
    for (long long i = 1; i < n + 1; i++)
    {
        cin >> x;
        t = 100000;
        sum1 = 0, sum2 = 0;
        while (t)
        {
            sum1 = (sum1 + dph[t] + a[t]) % MOD;
            t -= (t & (-t));
        }
        t = x;
        while (t)
        {
            sum1 = (sum1 - dph[t] - a[t] + MOD) % MOD;
            t -= (t & (-t));
        }
        t = x - 1;
        while (t)
        {
            sum2 = (sum2 + dpl[t] + a[t]) % MOD;
            t -= (t & (-t));
        }
        t = x;
        while (t < 100001)
        {
            dpl[t] = (dpl[t] + sum1) % MOD;
            dph[t] = (sum2 + dph[t]) % MOD;
            a[t] += 1;
            t += (t & (-t));
        }
    }
    long long ans = 0;
    sum1 = 0;
    sum2 = 0;
    t = 100000;
    while (t)
    {
        ans = (ans + dph[t]) % MOD;
        ans = (ans + dpl[t]) % MOD;
        t -= (t & (-t));
    }
    cout << ans;
}