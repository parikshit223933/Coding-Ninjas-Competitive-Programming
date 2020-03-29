#include<iostream>
#include<math.h>
using namespace std;
void makeSieve(int n)
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
        count++;
    }
    cout<<count<<endl;
    delete[]isprime;
}
int main()
{
    int n;
    cin>>n;
    makeSieve(n);
    return 0;
}