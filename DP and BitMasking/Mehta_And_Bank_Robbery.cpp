/* One fine day, when everything was going good, Mehta was fired from his job and had to leave all the work. So, he decided to become a member of gangster squad and start his new career of robbing. Being a novice, mehta was asked to perform a robbery task in which he was given a bag having a capacity W units. So, when he reached the house to be robbed, there lay N items each having particular weight and particular profit associated with it. But, theres a twist associated, He has first 10 primes with him, which he can use atmost once, if he picks any item x, then he can multiply his profit[x] with any of the first 10 primes and then put that item into his bag. Each prime can only be used with one particular item and one item can only have atmost one prime multiplied with its profit. Its not necessary to pick all the items. If he doesnt want to use a prime with any particular item, he can simply add the profit as it is, more specifically, 1*profit[x] for xth item will get added to its total profit, and that he can do with as many items as he wants. He cannot fill his bag more than weight W units. Each item should be picked with its whole weight, i.e it cannot be broken into several other items of lesser weight. So, now to impress his squad, he wishes to maximize the total profit he can achieve by robbing this wealthy house.
Input:
First Line of input containts two integers N and W. Next N lines contain information of ith item, describing profit and weight of the ith item, profit and weight are separated by single space.
Output:
In a single line, output the maximum profit obtainable.
Constraints:
1 <= N <= 2000, 1 <= W <= 2000

1 <= Profit[i] <= 10^9, 1 <= Weight[i] <= 2000

SAMPLE INPUT
3 4

1 1

2 1

3 1

SAMPLE OUTPUT
152

Explanation:
As all, the items can be picked, so maximum profit is equal to = 1 X 19 + 2 X 23 + 3 X 29 = 152 */




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