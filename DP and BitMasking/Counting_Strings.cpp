/* Given a string 's' consisting of upper case alphabets, i.e. from 'A' to 'Z'. Your task is to find how many strings 't' with length equal to that of 's', also consisting of upper case alphabets are there satisfying the following conditions:
-> String 't' is lexicographical larger than string 's'.
-> When you write both 's' and 't' in the reverse order, 't' is still lexicographical larger than 's'.
Find out number of such strings 't'. As the answer could be very large, take modulo 10^9 + 7.
 */




#define mod 1000000007
#define ll long long int
#include<string>
#include<iostream>
using namespace std;

int countStrings(char *s)
{
    int i, n;
    n = strlen(s);
    ll req = 0, dp[100005], arr[100005], ans = 0;
    for (i = 0; i < n; i++)
    {
        arr[i] = (ll)(90 - s[i]);
    }
    dp[n - 1] = arr[n - 1];
    for (i = n - 2; i >= 0; i--)
    {
        req = (arr[i + 1] + (26 * req) % mod) % mod;
        dp[i] = (arr[i] + (arr[i] * req) % mod) % mod;
    }
    for (i = 0; i < n; i++)
    {
        ans = (ans + dp[i]) % mod;
    }
    ans = ans % mod;
    return ans;
}