/* Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
Write a simple recursive solution.
Input Format :
Integer h
Output Format :
Count % 10^9 + 7
Input Constraints :
1 <= h <= 40
Sample Input 1:
3
Sample Output 1:
15
Sample Input 2:
4
Sample Output 2:
315 */



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
