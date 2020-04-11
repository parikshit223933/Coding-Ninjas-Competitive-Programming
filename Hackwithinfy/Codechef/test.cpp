#include<iostream>
#define endl '\n'
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define ll long long int
using namespace std;
inline bool check_for_divisibility(ll x)
{
    if (abs(x) % 2 == 1 || x == 0 || abs(x) % 4 == 0)
    {
        return true;
    }
    return false;
}
ll count_subs(ll* arr, ll n)
{
    ll count=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]==0||arr[i]%4==0)
        {
            count+=n-i;
        }
        else if()
    }
}
int main()
{
    fast;
    ll t;
    cin >> t;
    ll* arr = new ll[100001];
    while (t--)
    {
        ll n;
        cin >> n;
        for (ll i = 0; i < n; i++)
        {
            int element;
            cin >> element;
            arr[i] = element % 4;
        }
        cout << count_subs(arr, n) << endl;
    }
    delete[]arr;
    return 0;
}