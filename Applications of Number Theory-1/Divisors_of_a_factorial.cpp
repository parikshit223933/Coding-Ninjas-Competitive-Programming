#include <iostream>
#include<math.h>
using namespace std;
void makeSieve(int n)
{
    bool *isprime = new bool[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        isprime[i] = true;
    }
    isprime[0] = false;
    isprime[1] = false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (isprime[i])
            for (int j = i; j * i <= n; j++)
            {
                isprime[j * i] = false;
            }
    }
    int total_divisors = 1;
    for (int i = 0; i < n + 1; i++)
    {
        if(isprime[i])
        {
            int current_sum=0;
            for(int j=1; pow(i, j)<=n; j++)
            {
                current_sum+=n/pow(i, j);
            }
            total_divisors*=(current_sum+1);
        }
    }
    cout << total_divisors << endl;
    delete[] isprime;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        makeSieve(n);
    }
}