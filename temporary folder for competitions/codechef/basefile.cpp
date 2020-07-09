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
#define int long long int
using namespace std;
int solve(int *arr, int n)
{
    int count=0;
    for(int i=0; i<n-1; i++)
    {
        int diff=abs(arr[i]-arr[i+1]);
        int toBeAdded;
        if(diff==0)
        {
            toBeAdded=0;
        }
        else if(diff==1)
        {
            toBeAdded=0;
        }
        else
        {
            toBeAdded=diff-1;
        }
        count+=toBeAdded;
    }
    return count;
}
int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *arr=new int [n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        cout<<solve(arr, n)<<endl;
    }
}