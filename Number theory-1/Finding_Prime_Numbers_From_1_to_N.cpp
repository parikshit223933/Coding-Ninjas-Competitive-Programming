#include<iostream>
#include<math.h>
using namespace std;
bool check_prime(int n)
{
    for(int i=2; i<sqrt(n); i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    int count=0;
    for(int i=2; i<=n; i++)
    {
        if(check_prime(i))
        {
            count+=1;
        }
    }
    cout<<count<<endl;
}