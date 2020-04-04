#include <iostream>
#include <math.h>
#define ll long long int
using namespace std;
ll primeFactors(ll n)
{
    ll count = 0;
    if (n % 2 == 0)
    {
        while (n % 2 == 0)
        {
            count += 1;
            n = n / 2;
        }
    }
    for (ll i = 3; i <= sqrt(n); i = i + 2)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
            {
                count += 1;
                n = n / i;
            }
        }
    }
    if (n > 2)
        count += 1;
    return count;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, k;
        cin >> x >> k;
        if (primeFactors(x) >= k)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}