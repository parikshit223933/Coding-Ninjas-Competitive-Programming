/* Calculate and return GCD of two given numbers x and y. Numbers are within range of Integer.
Input format :
x and y (separated by space)
Output format :
GCD of x and y
Sample Input 1:
20 
5
Sample Output 1:
5
Sample Input 2:
96 
14
Sample Output 2:
2 */




#include<iostream>
#include<algorithm>
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
int main()
{
    ll x, y;
    cin>>x>>y;
    cout<<gcd(x, y)<<endl;
}