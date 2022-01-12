/*
According to Ancient Ninjas , string making is an art form . There are various methods of string making , one of them uses previously generated strings to make the new one . Suppose you have two strings A and B , to generate a new string C , you can pick a subsequence of characters from A and a subsequence of characters from B and then merge these two subsequences to form the new string.
Though while merging the two subsequences you can not change the relative order of individual subsequences. What this means is - suppose there two characters Ai and Aj in the subsequence chosen from A , where i < j , then after merging if i acquires position k and j acquires p then k<p should be true and the same apply for subsequence from C.
Given string A , B , C can you count the number of ways to form string C from the two strings A and B by the method described above. Two ways are different if any of the chosen subsequence is different .
As the answer could be large so return it after modulo 10^9+7 .
Input Format :
First line will contain T(number of test cases), each test case consists of three lines.
Line 1 : String A
Line 2 : String B
Line 3 : String C
Output Format :
The number of ways to form string C for each test case in new line.
Constraints :
1 <= T <= 500
1 <= |A| , |B|, |C| <=50
Sample Input :
1
abc
abc 
abc
Sample Output :
8
*/










#include<bits/stdc++.h>
using namespace std;
int mod=pow(10,9)+7;
long long int stringmake(string s1,string s2,string s3)
{
    int n1=s1.length();
    int n2=s2.length();
    int n3=s3.length();
   long long int dp[n1+1][n2+1][n3+1];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            dp[i][j][0]=1;
        }
    }
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            for(int k=1;k<=n3;k++)
            {
                for(int x=i;x>=0;x--)
                {
                    if(s1[x-1]==s3[k-1])
                        dp[i][j][k]=(dp[i][j][k]+dp[x-1][j][k-1]%mod)%mod;
                }
                for(int y=j;y>=0;y--)
                {
                    if(s2[y-1]==s3[k-1])
                        dp[i][j][k]=(dp[i][j][k]+dp[i][y-1][k-1]%mod)%mod;
                }
            }
        }
    }
    return dp[n1][n2][n3];
}
int main(){
    
    int t;
    cin>>t;
    while(t--)
    {
        string s1,s2,s3;
        cin>>s1;
        cin>>s2;
        cin>>s3;
        cout<<stringmake(s1,s2,s3)<<"\n";
    }
    return 0;
}
