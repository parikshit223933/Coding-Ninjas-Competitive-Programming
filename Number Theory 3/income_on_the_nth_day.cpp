/* Daulat Ram is an affluent business man. After demonetization, IT raid was held at his accommodation in which all his money was seized. He is very eager to gain his money back, he started investing in certain ventures and earned out of them. On the first day, his income was Rs. X, followed by Rs. Y on the second day. Daulat Ram observed his growth as a function and wanted to calculate his income on the Nth day.
The function he found out was FN = FN-1 + FN-2 + FN-1×FN-2
Given his income on day 0 and day 1, calculate his income on the Nth day (yeah Its that simple).
Input:
The first line of input consists of a single integer T denoting number of test cases.

Each of the next T lines consists of three integers F0, F1 and N respectively.
Output:
For each test case, print a single integer FN, as the output can be large, calculate the answer modulo 10^9+7.
CONSTRAINTS:
1 ≤ T ≤ 10^5

0 ≤ F0, F1, N ≤ 10^9
Sample Input :
2
0 1 2
1 2 4
Sample Output:
1
107
Explanation
In the second test case his income on day 0 is 1 and the income on day 1 is 2. We need to calculate his income on day 4.

F0=1

F1=2

F2=1 + 2 + 1×2 = 5

F3=2 + 5 + 2×5 = 17

F4=5 + 17 + 5×17 = 107 */



//https://www.hackerearth.com/problem/algorithm/recurrence/description/
/*
F(n) = F(n-1)+F(n-2)+F(n-1)*F(n-2)
F(n) = (1+F(n-1))*(1+F(n-2)) - 1
1+F(n) = (1+F(n-1))*(1+F(n-2))
Let G(n) = 1+F(n)
-> G(n)=G(n-1)*G(n-2)
let a=G(0)=1+F(0)
b=G(1)=1+F(1)
G(2)=a*b;
G(3)=a*b^2
G(4)=a^2*b^3
.
.
G(n)=a^fib(n-1)*b^fib(n)
where fib is fibbonacci series
Now fib can also be very large..now as mod is prime, we can use fermat's little theorem
*/
#include<iostream>
#define ll long long
#define mod 1000000007
using namespace std;
ll fib(ll n)
{
    if (n == 0 || n == 1 || n == 5)
        return n;
    if (n == 2)
        return 1;
    n--;
    ll a[2][2] = {1, 1,
                  1, 0};
    ll ans[2][2] = {
        1, 0,
        0, 1};
    ll temp[2][2];
    ll m = mod - 1, i, j, k;
    while (n)
    {
        if (n & 1)
        {
            //ans=ans*a
            for (i = 0; i < 2; i++)
                for (j = 0; j < 2; j++)
                {
                    temp[i][j] = 0;
                    for (k = 0; k < 2; k++)
                    {
                        temp[i][j] += a[i][k] * ans[k][j];
                        temp[i][j] %= m;
                    }
                }
            for (i = 0; i < 2; i++)
                for (j = 0; j < 2; j++)
                    ans[i][j] = temp[i][j];
        }
        //a=a*a
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
            {
                temp[i][j] = 0;
                for (k = 0; k < 2; k++)
                {
                    temp[i][j] += a[i][k] * a[k][j];
                    temp[i][j] %= m;
                }
            }
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
                a[i][j] = temp[i][j];
        n >>= 1;
    }
    return ans[0][0];
}
ll mpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    int t;
    ll a, b, c, n, i, x, y;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> n;
        if (n == 0)
            cout << a << endl;
        else if (n == 1)
            cout << b << endl;
        else
        {
            x = fib(n - 1);
            y = fib(n);
            //cout<<x<<" "<<y<<endl;
            c = mpow(a + 1, x) * mpow(b + 1, y);
            c--;
            c = c % mod;
            if (c < 0)
                c += mod;
            cout << c << endl;
        }
    }
    return 0;
}