#include <algorithm>
#include <iostream>
#include <utility>
#include<string>
#include <iterator>
#include<cstring>
#include<math.h>
#include <limits.h>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
using namespace std;
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        n=sqrt(n);
        cout<<n;
        int i=1;
        int j=n;
        bool switcher=false;
        int ans=0;
        while(i!=j)
        {
            ans+=(i&j);
            if(switcher)
            {
                j--;
                switcher=false;
            }
            else
            {
                i++;
                switcher=true;
            }
        }
        if(ans==0)
            cout<<-1<<endl;
        else
            cout<<ans<<endl;
    }
}