#include<iostream>
using namespace std;
long long int getSum(long long int n)
{
    long long int sum;
    for (sum = 0; n > 0; sum += n % 10, n /= 10);
    return sum;
}

int main()
{
    long long int n;
    cin>>n;
    cout<<getSum(n)<<endl;
}