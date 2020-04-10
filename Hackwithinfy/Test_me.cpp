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
    ll total_count = 0;
    for (ll i = 0; i < n; i++)
    {
        if (arr[i] == 0 || arr[i] % 4 == 0)
        {
            total_count += n - i;
            continue;
        }
        if (check_for_divisibility(arr[i]))
        {
            total_count++;
        }
        ll current_element = arr[i];

        for (ll j = i + 1; j < n; j++)
        {
            current_element *= arr[j];
            if (current_element == 0 || current_element % 4 == 0)
            {
                total_count += n - j;
                break;
            }
            if (check_for_divisibility(current_element))
            {
                total_count++;
            }
        }
    }
    return total_count;
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