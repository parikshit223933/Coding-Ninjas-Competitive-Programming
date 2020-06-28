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

int solve(int n)
{
    int temp=n;
    int count3=0;
    while(n%3==0)
    {
        n/=3;
        count3++;
    }
    int count2=0;
    while(n%2==0)
    {
        n/=2;
        count2++;
    }
    if(count3==0)
    {
        if(temp==1)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    if(count3==count2)
    {
        if(temp/pow(6, count2)==1)
        {
            return count2;
        }
        else
        {
            return -1;
        }
    }
    if(count3>count2)
    {
        if((temp)/(pow(3, count3)*pow(2, count2))==1)
        {
            return count3+(count3-count2);
        }
        else
        {
            return -1;
        }
    }
    if(count3<count2)
    {
        return -1;
    }
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
        cout<<solve(n)<<endl;
    }
}