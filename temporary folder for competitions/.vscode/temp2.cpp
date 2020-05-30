#include <algorithm>
#include <iostream>
#include <utility>
#include<string>
#include <iterator>
#include <limits.h>
#include <vector>
#define int long long int
#include<unordered_map>
#include<unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
using namespace std;
int total_distance(int *a, int *b, int n)
{
    int ans=0;
    int **arr=new int *[2];
    arr[0]=new int [n+1];
    arr[1]=new int [n+1];
    arr[0][0]=0;
    arr[1][0]=0;
    for(int i=1; i<=n; i++)
    {
        arr[0][i]=arr[0][i-1]+a[i-1];
        arr[1][i]=arr[1][i-1]+b[i-1];
    }

    for(int i=0; i<n; i++)
    {
        if(arr[0][i]==arr[1][i] && arr[0][i+1]==arr[1][i+1])
        {
            ans+=arr[0][i+1]-arr[0][i];
        }
    }
    return ans;




    /* int dist_a=0;
    int dist_b=0;
    int dist=0;

    if(a[0]==b[0])
    {
        dist+=a[0];
    }

    for(int i=0; i<n-1; i++)
    {
        dist_a+=a[i];
        dist_b+=b[i];
        if(dist_a==dist_b && dist_a+a[i+1]==dist_b+b[i+1])
        {
            dist+=a[i+1];
        }
    }
    return dist; */
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
        int *a=new int [n];
        int *b=new int [n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0; i<n; i++)
        {
            cin>>b[i];
        }
        cout<<total_distance(a, b, n)<<endl;
    }
}