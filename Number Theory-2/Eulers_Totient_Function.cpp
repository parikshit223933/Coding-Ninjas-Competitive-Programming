#include<iostream>
#include<math.h>
using namespace std;
int makeSieve(int n)
{
    float *isprime=new float [n+1];
    for(int i=0; i<n+1; i++)
    {
        isprime[i]=i;
    }
    for(int i=2; i<=(n); i++)
    {
        if(isprime[i]==i)
        {
            isprime[i]=i-1;
            for(int j=2; j*i<=n; j++)
            {
                isprime[j*i]*=(1.0-(1.0/(i*1.0)));
            }
        }
    }
    int ans=isprime[n];
    delete[]isprime;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    cout<<makeSieve(n)<<endl;
}