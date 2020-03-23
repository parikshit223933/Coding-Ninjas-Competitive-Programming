#include <iostream>
using namespace std;
int getMin(int *arr, int n)
{
    int *dp = new int[n];
    dp[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
        }
        else
        {
            dp[i] = 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i + 1] < arr[i] && dp[i] <= dp[i + 1])
        {
            dp[i] = dp[i + 1] + 1;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += dp[i];
    }
    delete[] dp;
    return sum;
}