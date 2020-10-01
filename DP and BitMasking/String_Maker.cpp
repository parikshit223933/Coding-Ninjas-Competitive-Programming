/* According to Ancient Ninjas , string making is an art form . There are various methods of string making , one of them uses previously generated strings to make the new one . Suppose you have two strings A and B , to generate a new string C , you can pick a subsequence of characters from A and a subsequence of characters from B and then merge these two subsequences to form the new string.
Though while merging the two subsequences you can not change the relative order of individual subsequences. What this means is - suppose there two characters Ai and Aj in the subsequence chosen from A , where i < j , then after merging if i acquires position k and j acquires p then k<p should be true and the same apply for subsequence from C.
Given string A , B , C can you count the number of ways to form string C from the two strings A and B by the method described above. Two ways are different if any of the chosen subsequence is different .
As the answer could be large so return it after modulo 10^9+7 .
Input Format :
Line 1 : String A
Line 2 : String B
Line 3 : String C
Output Format :
The number of ways to form string C
Constraints :
1 <= |A|, |B|, |C| <= 50
Sample Input :
abc
abc 
abc
Sample Output :
8 */






//See previous commits for simple recursive and dynamic solutions




#include<iostream>
using namespace std;
#define m 1000000007
typedef long long int ll;
int helper(string a, string b, string c, ll ***dp)
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
        return dp[a.length()][b.length()][c.length()]%m;
    }
    ll ans=0;
    for(ll i=0; i<a.length(); i++)
    {
        if(a[i]==c[0])
        {
            ans+=helper(a.substr(i+1), b, c.substr(1), dp)%m;
        }
    }
    for(ll i=0; i<b.length(); i++)
    {
        if(b[i]==c[0])
        {
            ans+=helper(a, b.substr(i+1), c.substr(1), dp)%m;
        }
    }
    dp[a.length()][b.length()][c.length()]=ans%m;
    return ans%m;
}
int solve(string a, string b, string c)
{
    ll ***dp=new ll **[51];
    for(ll i=0; i<51; i++)
    {
        dp[i]=new ll *[51];
        for(ll j=0; j<51; j++)
        {
            dp[i][j]=new ll [51];
            for(ll k=0; k<51; k++)
            {
                dp[i][j][k]=-1;
            }
        }
    }
    ll ans= helper(a, b, c, dp)%m;
    for(ll i=0; i<51; i++)
    {
        for(ll j=0; j<51; j++)
        {
            delete[]dp[i][j];
        }
    }
    return ans;
}
