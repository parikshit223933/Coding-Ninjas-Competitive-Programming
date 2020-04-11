#include<iostream>
#include<vector>
#define endl '\n'
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;
vector<int>primes;
void makeSieve(int n=1000000)
{
    bool *isprime=new bool [n+1];
    for(int i=0; i<n+1; i++)
    {
        isprime[i]=true;
    }
    isprime[0]=false;
    isprime[1]=false;
    for(int i=2; i<=sqrt(n); i++)
    {
        if(isprime[i])
            for(int j=i; j*i<=n; j++)
            {
                isprime[j*i]=false;
            }
    }
    int count=0;
    for(int i=0; i<n+1; i++)
    {
        if(isprime[i])
        primes.push_back(i);
    }
    delete[]isprime;
}
int main()
{
    fast
    makeSieve();
    int t;
    cin>>t;
    while(t--)
    {
        int l, r, k;
        cin>>l>>r>>k;

    }
}