#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int x, int y)
{
    if(x<=y)
    {
        int maximum=1;
        for(int i=1; i<=x; i++)
        {
            if(x%i==0&&y%i==0)
            {
                maximum=max(maximum, i);
            }
        }
        return maximum;
    }
    else
    {
        int maximum=1;
        for(int i=1; i<=y; i++)
        {
            if(x%i==0&&y%i==0)
            {
                maximum=max(maximum, i);
            }
        }
        return maximum;
    }
    
}
int main()
{
    int x, y;
    cin>>x>>y;
    cout<<gcd(x, y)<<endl;
}