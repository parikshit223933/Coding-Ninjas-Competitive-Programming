#include<iostream>
using namespace std;
int helper(string a, string b, string c, int ***dp)
{
    if(c.length()==0)
    {
        return 1;
    }
    if(a.length()<=0&&b.length()<=0)
    {
        return 0;
    }
    if(dp[a.length()][b.length()][c.length()]>-1)
    {
        return dp[a.length()][b.length()][c.length()];
    }
    int ans=0;
    for(int i=0; i<a.length(); i++)
    {
        if(a[i]==c[0])
        {
            ans+=helper(a.substr(i+1), b, c.substr(1), dp);
        }
    }
    for(int i=0; i<b.length(); i++)
    {
        if(b[i]==c[0])
        {
            ans+=helper(a, b.substr(i+1), c.substr(1), dp);
        }
    }
    dp[a.length()][b.length()][c.length()]=ans;
    return ans;
}
int solve(string a, string b, string c)
{
    int ***dp=new int **[51];
    for(int i=0; i<51; i++)
    {
        dp[i]=new int *[51];
        for(int j=0; j<51; j++)
        {
            dp[i][j]=new int [51];
            for(int k=0; k<51; k++)
            {
                dp[i][j][k]=-1;
            }
        }
    }
    int ans= helper(a, b, c, dp);
    for(int i=0; i<51; i++)
    {
        for(int j=0; j<51; j++)
        {
            delete[]dp[i][j];
        }
    }
    return ans;
}
int main()
{
    string a, b, c;
    cin>>a>>b>>c;
    cout<<solve(a, b, c)<<endl;
}