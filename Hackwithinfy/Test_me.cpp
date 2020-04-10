#include <iostream>
#include <vector>
#include<math.h>
#include<unordered_map>
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long int
#define mod 1000000007
using namespace std;
vector<ll>primes;
ll MAX = 1000001;
unordered_map<ll, ll>m;
void makeSieve()
{
    bool* isprime = new bool[MAX];
    for (ll i = 0; i < MAX; i++)
    {
        isprime[i] = true;
    }
    isprime[0] = false;
    isprime[1] = false;
    for (ll i = 2; i <= sqrt(MAX - 1); i++)
    {
        if (isprime[i])
            for (ll j = i; j * i <= MAX - 1; j++)
            {
                isprime[j * i] = false;
            }
    }
    for (ll i = 0; i < MAX; i++)
    {
        if (isprime[i])
            primes.push_back(i);
    }
    delete[]isprime;
}
ll calculateNoOFactors(ll n)
{
    ll i = 0;
    while (n != 1)
    {
        if (n % primes[i] == 0)
        {
            n /= primes[i];
            m[primes[i]]++;
        }
        else
        {
            i++;
        }
    }
    return 1;
}
ll happiness_quotient(vector<ll>* edges, ll n, ll* arr, ll start, ll end, unordered_map<ll, ll>& visited)
{
    if (start == end)
    {
        return calculateNoOFactors(arr[end]);
    }
    ll total_happiness = 0;
    for (ll i = 0; i < edges[start].size(); i++)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            ll forward_happiness = happiness_quotient(edges, n, arr, edges[start][i], end, visited);
            if (forward_happiness != 0)
            {
                total_happiness = calculateNoOFactors(arr[start]) + forward_happiness;
            }
        }

    }
    return total_happiness;
}

int main()
{
    fast
        makeSieve();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll>* edges = new vector<ll>[n];
        for (ll i = 0; i < n - 1; i++) //adjacency list for edges(roads connecting two diff. cities)
        {
            ll x, y;
            cin >> x >> y;
            edges[x - 1].push_back(y - 1);
            edges[y - 1].push_back(x - 1);
        }
        ll* arr = new ll[n]; //cost of a house in city i is Ai
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        ll q; //number of queries
        cin >> q;
        unordered_map<ll, ll> visited;
        while (q--)
        {
            visited.clear();
            ll u, v;
            cin >> u >> v;
            ll a = happiness_quotient(edges, n, arr, u - 1, v - 1, visited);
            ll ans = 1;
            for (auto i : m)
            {
                ans = ((ans % mod) * ((i.second + 1) % mod)) % mod;
            }
            cout << ans << endl;
            m.clear();
        }
    }
}