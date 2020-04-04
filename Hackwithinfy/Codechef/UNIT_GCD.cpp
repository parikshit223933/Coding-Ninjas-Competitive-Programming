#include<iostream>
#include<vector>
using namespace std;
vector<int> prime_divisors(int n)
{
    vector<int> v;
    int x = n;
    for (int i = 2; x != 1; i++)
    {
        if (x % i == 0)
        {
            v.push_back(i);
            while (x % i == 0)
            {
                x = x / i;
            }
        }
    }
    if (v.empty())
    {
        v.push_back(n);
    }
    return v;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *arr=new int [n+1];
        bool *marked=new bool[n+1];
        for(int i=0; i<=n; i++)
        {

        }
    }
}