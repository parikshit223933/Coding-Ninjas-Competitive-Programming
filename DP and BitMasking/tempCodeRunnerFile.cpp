int candies(int **like, int n, int person, int mask, int *dp)
{
    if (person >= n)
    {
        return 1;
    }
    if(dp[mask]!=0)
    {
        return dp[mask];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!(mask & (1 << i)) && like[person][i])
        {
            ans += candies(like, n, person + 1, mask | (1 << i), dp);
        }
    }
    dp[mask]=ans;
    return ans;
}