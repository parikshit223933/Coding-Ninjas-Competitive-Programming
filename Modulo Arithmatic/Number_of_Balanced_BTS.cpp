#include<iostream>
using namespace std;
typedef long long ll;
ll m=1000000000+7;
int balancedBTs(int h) {
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return the output and don’t print it.
  */
    if(h==0||h==1)
	{
		return 1;
	}
	ll x = balancedBTs(h - 1);
	ll y = balancedBTs(h - 2);
	ll ans= (x*x) + 2 * (x * y);
	return ans % m;
}
