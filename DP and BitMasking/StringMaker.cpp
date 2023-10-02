/*According to Ancient Ninjas , string making is an art form . There are various methods of string making , one of them uses previously generated strings to make the new one . Suppose you have two strings A and B , to generate a new string C , you can pick a subsequence of characters from A and a subsequence of characters from B and then merge these two subsequences to form the new string.
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
#define ll long long
int mod=1e9+7;
ll solver(string &a,string &b,string &c,ll x,ll y,ll z,ll dp[][51][51]){
    if(z==0){
        return 1;
    }
    if(x<=0 && y<=0){
        return 0;
    }
    if(dp[x][y][z]!=-1){
        return dp[x][y][z];
    }
    int ways=0;
    for(int i=x-1;i>=0;i--){
        if(a[i]==c[z-1])
            ways=(ways+solver(a,b,c,i,y,z-1,dp))%mod;
    }
    for(int j=y-1;j>=0;j--){
        if(b[j]==c[z-1])
            ways=(ways+solver(a,b,c,x,j,z-1,dp))%mod;
    }
    dp[x][y][z]=ways;
    return dp[x][y][z];
}
ll solve(string a,string b,string c){
    ll lena=a.length();
    ll lenb=b.length();
    ll lenc=c.length();
    ll dp[51][51][51];
    memset(dp,-1,sizeof(dp));
    return solver(a,b,c,lena,lenb,lenc,dp);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b,c;
        cin>>a>>b>>c;
        cout<<solve(a,b,c)<<endl;
    }
    return 0;
}
