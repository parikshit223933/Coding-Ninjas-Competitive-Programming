#include<iostream>
using namespace std;
void eulerphi(int n)
{
    int *phi=new int [n+1];
    for(int i=1; i<=n; i++)
    {
        phi[i]=i;
    }
    for(int i=2; i<=n; i++)
    {
        if(phi[i]==i)
        {
            phi[i]=i-1;
            for(int j=i*2; j<=n; j+=i)
            {
                phi[j]=(phi[j]*(i-1))/i;
            }
        }
    }
    cout<< phi[n]<<endl;
    delete[]phi;
}
int main()
{
    int n;
    cin>>n;

    for(int i=1; i<=n; i++)
    eulerphi(i);
}