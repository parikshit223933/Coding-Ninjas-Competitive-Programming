#include<iostream>
#define endl '\n'
#define fast ios::sync_with_stdio(false);cin.tie(0)
#define ll long long int
using namespace std;
ll count_subs(ll* arr, ll n)
{
    ll total_count = 0;
    int multiplier=1;
    for(int i=0; i<n; i++)
    {
        multiplier=multiplier*arr[i];
        if(arr[i]%4==0||arr[i]==0)//divisible by 4 or 0
        {
            total_count+=n-i;
        }
        else if (multiplier%2!=0)//is odd
        {
            int count=0;
            while(multiplier%4!=0&&i<n)
            {
                i++;
                multiplier*=arr[i];
                count++;
            }
            total_count+=(count*(count+1))/2;
        }
        else if (multiplier%2==0)
        {
            int count=0;
            while(multiplier%2!=0&&i<n)
            {
                i++;
                multiplier*=arr[i];
                count++;
            }
            total_count+=(count*(count+1))/2;
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