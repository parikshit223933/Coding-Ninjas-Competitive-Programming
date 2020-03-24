#include<iostream>
#include<math.h>
#include<algorithm>
#define ll unsigned long long int
using namespace std;
ll minimum_miles(ll *arr, ll n)
{
	ll total_miles=0;
	for(ll i=0; i<n; i++)
	{
		total_miles+=pow(2, i)*arr[n-1-i];
	}
	return total_miles;
}
int main()
{
	ll n;
	cin>>n;
	ll *arr=new ll [n];
	for(ll i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	sort(arr, arr+n);
	cout<<minimum_miles(arr, n)<<endl;
}