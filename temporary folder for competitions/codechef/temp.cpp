#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define ll long long int
using namespace std;

void test()
{
    ll n;///////////////
    cin >> n;/////////////////
    vector<ll> a, b;//////////////////
    unordered_map<ll, ll> map;////////////
    ll u;/////////////
    ll mi = INT_MAX;/////////////
    for (ll i = 0; i < n; i++)///////////////
    {/////////////
        cin >> u;//////////////
        a.push_back(u);//////////////
        map[a[i]]++;///////////////
        mi = min(mi, a[i]);//////////////
    }///////////////
    for (ll i = 0; i < n; i++)///////////
    {/////////////////
        cin >> u;//////////////
        b.push_back(u);//////////////
        map[b[i]]++;/////////////
        mi = min(mi, b[i]);////////////////////
    }////////////
    bool stop = false;////////////
    unordered_map<ll, ll> corr;//////////
    for (auto it = map.begin(); it != map.end(); it++)////////////
    {////////////
        if (it->second % 2 == 1)///////////
        {/////////////
            stop = true;/////////////
            break;///////////
        }//////////////
        else//////////////////
        {////////////////
            corr[it->first] = it->second / 2;//////////////
        }//////////////
    }///////////////
    if (stop)////////////
    {//////////////////////////////////
        cout << -1 << endl;//////////////////
        return;/////////////////////////
    }//////////////////////////////////
    unordered_map<ll, ll> copy = corr;//////////////
    vector<ll> s1, s2;///////////
    for (ll i = 0; i < n; i++)//////////////
    {///////////////////
        if (copy[a[i]])///////////////
            copy[a[i]]--;///////////////
        else////////////////////
            s1.push_back(a[i]);////////////
    }///////////////
////////////////////
    copy = corr;//////////////////////
    for (ll i = 0; i < n; i++)/////////////////
    {///////////
        if (copy[b[i]])///////////////
            copy[b[i]]--;///////////
        else/////////////////////
            s2.push_back(b[i]);//////////////
    }/////////////
    if (s1.size() == 0)///
    {/////////////////
        cout << 0 << endl;///////////////
        return;////////////
    }/////////////////////
    if (s1.size() != s2.size())//////////////////
    {//////////////
        cout << -1 << endl;////////////
        return;/////////////////
    }////////////
    ll cost = 0;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end(), greater<>());
    for (ll i = 0; i < s1.size(); i++)
    {
        cost += min(2 * mi, min(s1[i], s2[i]));
    }
    cout << cost << endl;
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
        test();
    return 0;
}