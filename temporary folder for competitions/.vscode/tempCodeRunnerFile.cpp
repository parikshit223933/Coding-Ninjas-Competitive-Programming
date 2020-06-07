#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
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

int calculate(int ts)
{
    if( ts <= 2 )
    {
        return 0;
    }
	if( ts % 2 != 0 )
		return  (ts/2) ;
	else
	{
        int count=0;
		int js = ts ;
		while( js > 1 && js % 2 == 0 )
		{
			js /= 2 ;
		}
		if( js > 1 )
        {
            count=js/2;
        }
        return count;
    }
}

int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int ts;
        cin>>ts;
        cout<<calculate(ts)<<endl;
    }
}