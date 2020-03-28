#include<iostream>
#include<math.h>
using namespace std;
bool check_prime(int n)
{
    int count_factors=0;
    for(int i=1; i<=sqrt(n); i++)
    {
        if(n%i==0)
        {
            if(i*i==n)
            {
                count_factors+=1;
            }
            else
            count_factors+=2;
        }
    }
    return count_factors==2;
    
}
int main()
{
    int n;
    cin>>n;
    int count=0;
    for(int i=1; i<=n; i++)
    {
        if(check_prime(i))
        {
            count+=1;
        }
    }
    cout<<count<<endl;
}