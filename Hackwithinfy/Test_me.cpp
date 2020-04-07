#include<bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pb push_back
using namespace std;
int outside_the_line(ll a,ll b,ll c,ll x1,ll y1){
    ll intersection=-c-a*x1;
    if(b!=0) intersection/=b;
    if(y1>intersection) return 1; // point is opposite side of Zero
    else if(y1<intersection) return -1; // point is same side of Zero
    else return 0; // point is on the line
}
ll perpendicular_dist(ll a,ll b,ll c,ll x1,ll y1){
    double num=a*x1+b*y1+c;
    double den=sqrt(a*a+b*b);
    return ceil(num/den);
}
ll work1(vector<pair<ll,ll>> posts,ll n){
    vector<ll> y;
    y.pb(0);
    for(ll i=0;i<posts.size();i++){
        if(posts[i].ff<=200&&posts[i].ss<=200){
            y.pb(posts[i].ss);
        }
    }
    y.pb(200);
    sort(y.begin(),y.end());
    ll ans=0;
    for(ll i=0;i<y.size()-1;i++){
        ans=max(ans,(y[i+1]-y[i]));
    }
    return ans-1;
}
int main() {
    ll n;
    cin>>n;
    vector<pair<ll,ll>> posts;
    posts.resize(n+1);
    for(ll i=0;i<n;i++){
        cin>>posts[i].ff;
    }
    for(ll i=0;i<n;i++){
        cin>>posts[i].ss;
    }
    ll work1_ans=work1(posts,n);
    posts.pb({0,0});
    ll ans=INT_MIN;
    for(ll i=0;i<posts.size();i++){
        ll a=posts[i].second;
        ll b=200-posts[i].first;
        ll c=-1*200*a;
        vector<ll> curr_dist;
        for(ll j=0;j<posts.size();j++){
            if(i==j)continue;
            if(outside_the_line(a,b,c,posts[j].ff,posts[j].ss)==1){
                curr_dist.pb(perpendicular_dist(a,b,c,posts[j].ff,posts[j].ss));
            }
        }
        sort(curr_dist.begin(),curr_dist.end());
        for(ll j=curr_dist.size()-1;j>0;j--){
            curr_dist[j]-=curr_dist[j-1];
        }
        ll curr_ans=INT_MIN;
        for(ll j=0;j<curr_dist.size();j++){
            // cout<<curr_dist[j]<<" ";
            curr_ans=max(curr_ans,curr_dist[j]);
        }
        // cout<<endl;
        ans=max(ans,curr_ans);
    }
    cout<<max(work1_ans,ans-1)<<endl;
}