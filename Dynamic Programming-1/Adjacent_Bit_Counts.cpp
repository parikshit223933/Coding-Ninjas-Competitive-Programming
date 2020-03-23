#include <iostream>
using namespace std;
typedef long long ll;
#define m 1000000007
ll dp[101][101][2];
ll f(int n, int k, int start)
{
    if (dp[n][k][start] >= 0)
    {
        return dp[n][k][start];
    }
    if (n == 1)
    {
        if (k == 0)
        {
            dp[n][k][start] = 1;
            return 1;
        }
        else
        {
            dp[n][k][start] = 0;
            return 0;
        }
    }
    if (k < 0)
    {
        dp[n][k][start] = 0;
        return 0;
    }
    if (start == 1)
    {
        ll sum1 = f(n - 1, k - 1, 1);
        ll sum2 = f(n - 1, k, 0);
        dp[n][k][start] = (sum1 + sum2) % m;
    }
    else
    {
        ll sum1 = f(n - 1, k, 1) % m;
        ll sum2 = f(n - 1, k, 0) % m;
        dp[n][k][start] = (sum1 + sum2) % m;
    }
    return dp[n][k][start];
}
ll adjbc(int n, int k)
{
    ll sum1 = f(n, k, 1) % m;
    ll sum2 = f(n, k, 0) % m;
    return (sum1 + sum2) % m;
}
int main()
{
    int p;
    cin >> p;
    for (int i = 0; i <= 101; i++)
    {
        for (int j = 0; j <= 101; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }
    while (p--)
    {
        int dataset_number, n, k;
        cin >> dataset_number >> n >> k;
        cout << dataset_number << " " << adjbc(n, k) << endl;
    }
    return 0;
}