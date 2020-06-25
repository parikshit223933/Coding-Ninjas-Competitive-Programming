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

void solve(int a, int b, int c)
{
    int shop1_cost=b*a;
    int shop2_cost=c;
    bool checker1=false;
    int amount1=-1;
    bool checker2=false;
    int amount2=-1;

    for(int i=1; i*i<b; i++)
    {
        int s1=i*a;
        int s2=c;
        if(s1<s2 &&!checker1)
        {
            checker1=true;
            amount1=i;
        }
        else if(s1>s2&&!checker2)
        {
            checker2=true;
            amount2=i;
        }
        if(checker1&&checker2)
        {
            break;
        }
    }
    int temp=b*100;
    for(int i=b; i<temp; i+=i)
    {
        int s1=i*a;
        int s2=c*(i/b);
        if(s1<s2&&!checker1)
        {
            checker1=true;
            amount1=i;
        }
        else if(s1>s2&&!checker2)
        {
            checker2=true;
            amount2=i;
        }
        if(checker1&&checker2)
        {
            break;
        }
    }



    if(checker1 && amount1<1000000000)
    {
        cout<<amount1<<" ";
    }
    else
    {
        cout<<-1<<" ";
    }
    if(checker2 && amount2<1000000000)
    {
        cout<<amount2<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
    return;
}

int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int a, b, c;
        cin>>a>>b>>c;
        solve(a, b, c);
    }
}