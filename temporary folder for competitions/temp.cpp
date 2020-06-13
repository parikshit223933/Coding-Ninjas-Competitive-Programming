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


int longest_subarray(int *arr, int n, int x)
{
    int sum=0;
    int j=0;
    int max_length=0;
    for(int i=0; i<n; i++)
    {
        sum+=arr[i];
        if(sum%x!=0)
        {
            max_length=i-j+1;
        }
        else
        {
            sum-=arr[j];
            j++;
        }
    }   
    if(max_length==0)
    {
        return -1;
    }
    return max_length;
}
int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n, x;
        cin>>n>>x;
        int *arr=new int [n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        cout<<longest_subarray(arr, n, x)<<endl;
    }
}