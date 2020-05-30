#include <algorithm>
#include <iostream>
#include <utility>
#include<string>
#include <iterator>
#include <limits.h>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
using namespace std;
int total_distance(int *a, int *b, int n)
{
    int dist_a=0;
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
    return dist;
}
int main()
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