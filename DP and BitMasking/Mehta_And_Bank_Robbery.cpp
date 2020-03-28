#include <iostream>
#include <utility>
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
typedef long long int ll;
int main()
{
    int n, w;
    cin >> n >> w;
    pair<ll, ll> *arr = new pair<ll, ll>[n];
    for (int i = 0; i < n; i++)
    {
        //first== value of the item
        //second== weight of the item
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n);
    ll ***dp = new ll **[2];
    for (int i = 0; i < 2; i++)
    {
        dp[i] = new ll *[n + 1];
        for (int j = 0; j < n + 1; j++)
        {
            dp[i][j] = new ll[w + 1];
            for (int k = 0; k < w + 1; k++)
            {
                dp[i][j][k] = 0;
            }
        }
    }
    int primes[11] = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
    //now at the dp[0][i][j] the answer of out typical knapsack problem must be there
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            dp[0][i][j] = dp[0][i - 1][j];
            if (j >= arr[i - 1].second)
            {
                dp[0][i][j] = max(dp[0][i][j], dp[0][i - 1][j - arr[i - 1].second] + arr[i - 1].first);
            }
        }
    }
    for (int prime = 1; prime <= 10; prime++)
    {
        int p = prime % 2;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                dp[p][i][j] = dp[p][i - 1][j];
                if (j > arr[i - 1].second)
                {
                    dp[p][i][j] = max(dp[p][i][j], max(arr[i - 1].first + dp[p][i - 1][j - arr[i - 1].second], dp[p ^ 1][i - 1][j - arr[i - 1].second] + arr[i - 1].first * primes[prime]));
                }
            }
        }
    }
    cout << dp[0][n][w] << endl;
}