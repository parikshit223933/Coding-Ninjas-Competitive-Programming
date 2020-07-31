#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#define fast                          \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);
#define endl '\n'
#define ll long long int
using namespace std;
void makeSieve(int *arr, int n)
{
    int *isprime=new int [n+1];
    for(int i=0; i<n; i++)
    {
        isprime[i]=0;
	}
    isprime[0]=arr[0];
    isprime[1]=arr[0]+arr[1];
    for(int i=sqrt(n); i>=0; i--)
    {
        for(int j=i; j%i==0&&j/i>=0&&j>=0; j--)
        {
            isprime[j*i]+=arr[i];
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

void solve(int *arr, int n)
{
	for(int mul=1; mul<n; mul++)
	[
		for(int i=0; i<n; i+=mul)
		{

		}
	]
}
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int *arr=new int [n];
		for(int i=0; i<n; i++){
			cin>>arr[i];
		}
		solve(arr, n);
		cout<<endl;
	}
}