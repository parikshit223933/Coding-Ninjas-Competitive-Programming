#include<iostream>
#define endl '\n'
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
int count_ways(int n)
{
    if(n==0)
    {
        return 0;
    }
    int a=1+count_ways(n-1)
}
int main()
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