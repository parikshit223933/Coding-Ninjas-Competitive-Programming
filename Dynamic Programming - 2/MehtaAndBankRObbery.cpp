#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,wi;
        cin>>n>>wi;
        pair<ll,ll> *arr=new pair<ll,ll>[n];
      for(int i=0;i<n;i++){
            cin>>arr[i].first;
        }
        for(int i=0;i<n;i++){
            cin>>arr[i].second;
        }
        sort(arr,arr+n);
        ll prime[11]={0,2,3,5,7,11,13,17,19,23,29};
        ll ***dp=new ll**[2];
        for(int i=0;i<2;i++){
            dp[i]=new ll *[n+1];
            for(int j=0;j<=n;j++){
                dp[i][j]=new ll[wi+1];
                for(int k=0;k<=wi;k++){
                    dp[i][j][k]=0;
                }
            }
        }
        //base case
        for(int i=1;i<=n;i++){
            for(int j=1;j<=wi;j++){
                dp[0][i][j]=dp[0][i-1][j];
                if(j>=arr[i-1].second){
                    dp[0][i][j]=max(dp[0][i][j],dp[0][i-1][j-arr[i-1].second]+arr[i-1].first);
                }
            }
        }
        //follow-up
        int curr=0;
        for(int p=1;p<=10;p++){
            curr=p%2;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=wi;j++){
                    dp[curr][i][j]=dp[curr][i-1][j];
                        if(j>=arr[i-1].second)
                            dp[curr][i][j]=max(dp[curr][i][j],max(dp[curr][i-1][j-arr[i-1].second]+arr[i-1].first,dp[curr^1][i-1][j-arr[i-1].second]+arr[i-1].first*prime[p]));
                }
            }
        }
        cout<<dp[0][n][wi]<<endl;
    }
    return 0;
}
