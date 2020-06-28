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
#define ll long long int
using namespace std;

int solve(int *arr, int n, int k)
{
    sort(arr, arr+n);
    unordered_map<int, int>m;
    for(int i=0; i<n; i++)
    {
        if(arr[i]<k)
        {
            int mul=1;
            while(m[(mul*k)-arr[i]]==1)
            {
                mul++;
            }
            m[(mul*k)-arr[i]]++;
        }
        else if(arr[i]>k)
        {
            int mul=1;
            while(m[(mul*k)-(arr[i]%(mul*k))]==1)
            {
                mul++;
            }
            m[(mul*k)-(arr[i]%(mul*k))]++;
        }
        else
        {
            int mul=1;
            while(m[mul*arr[i]]==1)
            {
                mul++;
            }
            m[mul*arr[i]]++;
        }
    }
    int maxi=INT_MIN;
    for(auto i:m)
    {
        maxi=max(maxi, i.first);
    }
    return maxi+1
    ;
}

int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int *arr=new int [n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        cout<<solve(arr, n, k)<<endl;
    }
}