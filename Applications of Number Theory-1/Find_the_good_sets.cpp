#include <iostream>
#define m 1000000007
#define ll long long int
using namespace std;
ll size_of_sieve = 750001;
void Seive(ll *arr, ll n)
{
    ll *sieve = new ll[size_of_sieve];
    for (ll i = 0; i < size_of_sieve; i++)
    {
        sieve[i] = 0;
    }
    for (ll i = 0; i < n; i++)
    {
        sieve[arr[i]] = 1;
    }
    for (ll i = 1; i < size_of_sieve; i++)
    {
        ll current_element = i;
        if (sieve[current_element] != 0)
            for (ll j = 2; j * current_element < size_of_sieve; j++)
            {
                if (sieve[j * current_element] != 0)
                {
                    sieve[j * current_element] = (sieve[j * current_element] % m + sieve[i] % m) % m;
                }
            }
    }
    ll total_sum = 0;
    for (ll i = 0; i < size_of_sieve; i++)
    {
        total_sum = (total_sum % m + sieve[i] % m) % m;
    }
    cout << total_sum << endl;
    delete[] sieve;
}
int main()
{
    ll t;
    cin >> t;
    ll *arr = new ll[750001];
    while (t--)
    {
        ll n;
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Seive(arr, n);
    }
    delete[] arr;
}