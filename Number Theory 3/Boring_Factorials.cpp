#include<iostream>
#define ll long long int
using namespace std;
ll pow1(ll a, ll b, ll c)
{
    ll ans = 1LL;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans * a) % c;
        a = (a * a) % c;
        b = b >> 1;
    }
    return ans;
}
int main()
{
    ll n, p, i, ans, fact;
    int t;
    cin>>t;
    while (t--)
    {
        fact = 1;
        cin>>n>>p;
        if (n >= p)
        {
            cout<<0<<endl;
            continue;
        }
        for (i = n + 1; i <= p - 1; i++)
        {
            fact = (fact * i) % p;
            if (fact == 0)
                break;
        }
        ans = pow1(fact, p - 2, p);
        cout<<p-ans<<endl;
    }
    return 0;
}