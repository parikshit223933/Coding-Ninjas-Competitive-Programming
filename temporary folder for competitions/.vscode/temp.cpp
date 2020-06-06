#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define ll long long int
using namespace std;

ll solve(int *arr, int n, int k)
{
    ll sum=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]>k)
        {
            sum+=arr[i]-k;
        }
    }
    return sum;
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