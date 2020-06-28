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

int solve(string s, int n)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        if(count>0)
        {
            if(s[i]==')')
            {
                count--;
            }
            else
            {
                count++;
            }
        }
        else if(count==0)
        {
            if(s[i]==')')
            {
                continue;
            }
            else
            {
                count++;
            }
            
        }
    }
    return count;
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
        string s;
        cin>>s;
        cout<<solve(s, n)<<endl;
    }
}