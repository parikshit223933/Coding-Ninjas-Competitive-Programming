#include<iostream>
#include<algorithm>
using namespace std;
typedef long long int ll;
class triplet
{
public:
    ll x, y, gcd;
};
triplet extended_euclid(ll a, ll b)
{
    if (b == 0)
    {
        triplet ans;
        ans.x = 1;
        ans.y = b;
        ans.gcd = a;
        return ans;
    }
    triplet small_ans = extended_euclid(b, a % b);
    triplet ans;
    ans.gcd = small_ans.gcd;
    ans.x = small_ans.y;
    ans.y = small_ans.x - small_ans.y * (a / b);
    return ans;
}
ll Multiplicative_Modulo_Inverse(ll a, ll m)
{
    ll ans=extended_euclid(a, m).x;
    return (ans%m+m)%m;
}
ll count_ways(ll a, int b, ll d)
{
    ll y1=((d%a)*Multiplicative_Modulo_Inverse(b, a))%a;
    ll first_value=d/b;
    if((d/b)<y1)
    {
        return 0;
    }
    ll n=(first_value-y1)/a;
    return n+1;
}
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll a, b, d;
        cin>>a>>b>>d;
        ll g=__gcd(a, b);
        if(d%g!=0)
        {
            cout<<0<<endl;
            continue;
        }
        a/=g;
        b/=g;
        d/=g;
        cout<<count_ways(a, b, d)<<endl;
    }
}