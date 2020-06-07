#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long int
using namespace std;

bool check(int *arr, int n)
{
    if(n==0)
    {
        return true;
    }
    if(arr[0]!=5)
    {
        return false;
    }
    int ans=1; // denotes true
    int count5=1;
    int count10=0;
    int count15=0;
    for(int i=1; ans==1&&i<n; i++)
    {
        if(arr[i]==5)
        {
            count5++;
        }
        else if(arr[i]==10)
        {
            count10++;
        }
        else
        {
            count15++;
        }
        int remaining=arr[i]-5;
        if(remaining==5)
        {
            if(count5>0)
            {
                count5--;
            }
            else
            {
                ans=0;
                return false;
            }
        }
        else if(remaining==10)
        {
            if(count10>0)
            {
                count10--;
            }
            else if(count5>=2)
            {
                count5-=2;
            }
            else
            {
                ans=0;
                return false;
            }
        }
    }
    if(ans==1)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

string isPossible(int *arr, int n)
{
    if (check(arr, n))
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

int32_t main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << isPossible(arr, n) << endl;
    }
    return 0;
}