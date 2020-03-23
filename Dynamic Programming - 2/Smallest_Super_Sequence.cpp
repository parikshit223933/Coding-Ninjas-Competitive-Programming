#include<iostream>
#include<algorithm>
using namespace std;
int helper(char str1[], int len1, char str2[], int len2,int **dp)
{
    if(len1==0)
    {
         return len2;
    }
    if(len2==0)
    {
        return len1;
    }
    if(dp[len1][len2]>=0)
    {
        return dp[len1][len2];
    }
    int ans;
    if(str1[0]==str2[0])
    {
        ans= 1+helper(str1+1, len1-1, str2+1, len2-1, dp);
    }
    else
    {
        int option1=helper(str1, len1, str2+1, len2-1, dp);
        int option2=helper(str1+1, len1-1, str2, len2, dp);
        ans= 1+min(option1, option2);
    }
    dp[len1][len2]=ans;
    return ans;
}
int smallestSuperSequence(char str1[], int len1, char str2[], int len2)
{
    int **dp=new int *[len1+1];
    for(int i=0; i<len1+1; i++)
    {
        dp[i]=new int [len2+1];
        for(int j=0; j<len2+1; j++)
        {
            dp[i][j]=-1;
        }
    }
    int ans= helper(str1, len1, str2, len2, dp);
    for(int i=0; i<len1+1; i++)
    {
        delete[]dp[i];
    }
    delete[]dp;
    return ans;
}