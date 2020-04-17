/* Given two strings S and T, find and return the length of their smallest super-sequence.
A shortest super sequence of two strings is defined as the shortest possible string containing both strings as subsequences.
Note that if the two strings do not have any common characters, then return the sum of lengths of the two strings.
Input Format:
Line 1 : A string
Line 2: Another string
Output Format:
Length of the smallest super-sequence of given two strings. 
Sample Input:
ab
ac
Sample Output:
3
Sample Output Explanation:
Their smallest super-sequence can be "abc" which has length=3. */



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