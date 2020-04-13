#include<iostream>
#define endl '\n'
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int count_ways(int n)
{
    if(n==1||n==2)
    {
        return 0;
    }
    if(n%2==0)
    {
        return (n/2)-1;
    }
    else
    {
        return n/2;
    }
}
int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<count_ways(n)<<endl;
    }
}