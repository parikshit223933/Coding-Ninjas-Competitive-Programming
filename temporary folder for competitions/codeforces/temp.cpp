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

bool allsame(string s)
{
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool check(string s)
{
    if (allsame(s)||s.length()==0)
    {
        return false;
    }

    int zeros=0;
    int ones=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='0')
        {
            zeros++;
        }
        else
        {
            ones++;
        }
    }

    int count=min(zeros, ones);
    if(count%2==0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        if (check(s))
        {
            cout << "DA" << endl;
        }
        else
        {
            cout << "NET" << endl;
        }
    }
}