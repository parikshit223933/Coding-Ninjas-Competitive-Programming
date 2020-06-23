#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
#include <vector>
#include <cstring>
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

int max_happiness(int *arr, int *each_friend, int n, int k)
{
    sort(arr, arr+n);
    sort(each_friend, each_friend+k);

    int index=k-1;
    int sum=0;

    for(int i=0; i<k; i++)
    {
        if(each_friend[i]!=1)
        {
            index+=each_friend[i]-1;
            sum+=arr[index];
        }
    }
    int i;
    for(i=0; i<k; i++)
    {
        sum+=arr[i];
    }
    int count=0;
    for(; i<k; i++)
    {
        if(each_friend[i]==1)
        {
            count++;
        }
    }
    for(int i=0; i<count; i++)
    {
        sum+=arr[i];
    }
    return sum;
}

int32_t main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int *each_friend = new int[k];
        for (int i = 0; i < k; i++)
        {
            cin >> each_friend[i];
        }
        cout << max_happiness(arr, each_friend, n, k) << endl;
    }
}