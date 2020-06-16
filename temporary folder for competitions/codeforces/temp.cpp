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
#define ll long long int
using namespace std;

int number_of_tables(string s, int n, int k)
{
    int count=0;
    /* handling starting with 0 */
    int starting_index=0;
    int ending_index=n-1;
    if(s[0]=='0')
    {
        bool check=true;
        for(int i=1; i<=k; i++)
        {
            if(s[i]=='1')
            {
                check=false;
                starting_index=i;
                break;
            }
        }
        if(check)
        {
            count++;
            s[0]='1';
        }
    }
    /* handling ending with 0 */
    if(s[n-1]=='0')
    {
        bool check=true;
        for(int i=n-2; i>=n-1-k ; i--)
        {
            if(s[i]=='1')
            {
                check=false;
                ending_index=i;
                break;
            }
        }
        if(check)
        {
            count++;
            s[n-1]='1';
        }
    }
    int temp=0;
    for(int i=starting_index+1; i<ending_index; i++)
    {
        if(s[i]=='0')
        {
            temp++;
        }
        if(s[i]=='1')
        {
            temp=0;
        }

        if(temp==2*k+1)
        {
            count++;
            temp/=2;
        }
    }
    return count;
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        cout << number_of_tables(s, n, k) << endl;
    }
}