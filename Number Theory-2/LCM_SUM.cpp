/* Given n, calculate and print the sum :
LCM(1,n) + LCM(2,n) + .. + LCM(n,n)
where LCM(i,n) denotes the Least Common Multiple of the integers i and n.
Input Format :
Line 1 : Integer n
Output Format :
Required sum
Constraints :
1 <= T <= 300000
1 <= n <= 1000000
Sample Input 1 :
5
Sample Output 1 :
55
Sample Input 2 :
2
Sample Output 2 :
4 */


#include<iostream>
using namespace std;
typedef unsigned long long int ll;
ll gcd(ll x, ll y)
{
    if(x<y)
    {
        return gcd(y, x);
    }
    if(y==0)
    {
        return x;
    }
    return gcd(y, x%y);   
}
void func(long long n)
{
	ll partial_sum=0;
    for(ll i=1; i<=n-1; i++)
    {
        partial_sum+=(n*n)/gcd(i*1.0, n);
    }
    ll ans=2*n+partial_sum;
    cout<<ans/2;
}
