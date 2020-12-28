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
int smallestSuperSequenceHelper(string s1,string s2,int m,int n,int **dp){
    
    for(int i=m;i>=0;i--){
        for(int j=n;j>=0;j--){
            if(s1[i]==s2[j]){
                dp[i][j]=dp[i+1][j+1]+1;
            }
            else{
                dp[i][j]=min(dp[i+1][j],dp[i][j+1])+1;
            }
        }
    }

    return dp[0][0];
}

int smallestSuperSequence(string s1,string s2){
    int m=s1.length(),n=s2.length();
    int **dp=new int*[m+1];
    for(int i=0;i<=m;i++){
        dp[i]=new int[n+1];
    }
    int count=0;
    for(int i=n;i>=0;i--){
        dp[m][i]=count++;
    }
    count=0;
    for(int i=m;i>=0;i--){
        dp[i][n]=count++;
    }

    int ans=smallestSuperSequenceHelper(s1,s2,m-1,n-1,dp);
    return ans;
}
