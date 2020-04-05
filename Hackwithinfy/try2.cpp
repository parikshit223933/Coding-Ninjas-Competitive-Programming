#include <iostream>
#include <vector>
#include <math.h>
#define m 1000000007
#define ll long long int
#include <unordered_set>
#include <algorithm>
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
    vector<vector<ll>>ans;
    vector<ll>primes;
    primes.push_back(1);
    for(ll i=2; i<=n; i++)
    {
        if(isprime[i])
        {
            primes.push_back(i);
        }
    }
    ans.push_back(primes);
    for(ll i=4; i<=n; i+=2)
    {
        if(isprime[i])
        {
            continue;
        }
        vector<ll>temp;
        temp.push_back(i);
        ll multiplied=i;
        for(ll j=i+1; j<=n; j+=2)
        {
            if(!isprime[j]&&__gcd(multiplied, j)==1)
            {
                temp.push_back(j);
                multiplied=((multiplied)%m*(j)%m)%m;
                isprime[j]=true;
            }
        }
        ans.push_back(temp);
    }
    cout<<ans.size()<<endl;
    for(auto i : ans)
    {
        cout<<i.size()<<" ";
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
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