#include <iostream>
#include <math.h>
#define m 1000000007
#define ll long long int
using namespace std;
void makeSieve(ll n)
{
    bool *isprime = new bool[n + 1];
    for (ll i = 0; i < n + 1; i++)
    {
        isprime[i] = true;
    }
    isprime[0] = false;
    isprime[1] = false;
    for (ll i = 2; i <= sqrt(n); i++)
    {
        if (isprime[i])
            for (ll j = i; j * i <= n; j++)
            {
                isprime[j * i] = false;
            }
    }
    ll total_divisors = 1;
    for (ll i = 0; i < n + 1; i++)
    {
        if (isprime[i])
        {
            ll current_sum = 0;
            for (ll j = 1; pow(i, j) <= n; j++)
            {
                current_sum += n / pow(i, j);
            }
            total_divisors =(total_divisors%m * (current_sum + 1)%m)%m;
        }
    }
    cout << total_divisors << endl;
    delete[] isprime;
}
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        makeSieve(n);
    }
}