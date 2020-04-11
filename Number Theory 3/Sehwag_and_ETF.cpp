#include<bits/stdc++.h>
#define ll long long
#define MAX 1100001
#define ss(n) scanf("%lld", &n)
using namespace std;
bool primes[MAX];
ll phi[MAX];
ll p[300001];
ll num[MAX];
int main()
{
    ll t, a, b, k, i, j, x, base;
    cin >> t;
    for (i = 3; i < MAX; i += 2)
        primes[i] = 1;
    primes[2] = 1;
    for (i = 3; i * i < MAX; i += 2)
    {
        if (primes[i])
        {
            for (j = i * i; j < MAX; j += 2 * i)
                primes[j] = 0;
        }
    }
    p[0] = 2;
    ll c = 1;
    for (i = 3; i < MAX; i += 2)
    {
        if (primes[i])
            p[c++] = i;
    }
    while (t--)
    {
        cin >> a >> b >> k;
        if (k == 1)
        {
            std::cout << std::fixed;
            std::cout << std::setprecision(6) << 1 << endl;
            continue;
        }
        for (i = a; i <= b; i++)
        {
            phi[i - a] = i;
            num[i - a] = i;
        }
        for (i = 0; p[i] * p[i] <= b; i++)
        {
            base = a / p[i] * p[i];
            while (base < a)
                base += p[i];
            while (base < p[i])
                base += p[i];
            if (base == p[i])
            {
                // cout<<phi[base-a]<<endl;
                base += p[i];
            }
            for (j = base; j <= b; j += p[i])
            {
                while (num[j - a] % p[i] == 0)
                    num[j - a] /= p[i];
                phi[j - a] -= phi[j - a] / p[i];
                //cout<<j<<" "<<phi[j-a]<<endl;
            }
        }
        for (i = a; i <= b; i++)
        {
            if (num[i - a] > 1)
                phi[i - a] -= phi[i - a] / num[i - a];
            num[i - a] = 1;
        }
        ll c = 0;
        for (i = a; i <= b; i++)
        {
            //cout<<i<<" "<<phi[i-a]<<endl;
            if (phi[i - a] % k == 0)
                c++;
        }
        double ans = c;
        ans /= (b - a + 1);
        std::cout << std::fixed;
        std::cout << std::setprecision(6) << ans << endl;
    }
    return 0;
}