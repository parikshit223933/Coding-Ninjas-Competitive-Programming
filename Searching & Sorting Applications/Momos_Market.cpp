#include<iostream>

using namespace std;
typedef long long int ll;
bool checker(ll *arr, ll n, ll mid, ll target)
{
	if(arr[mid]<=target)
	{
		return true;
	}
	return false;
}
void momos(ll *arr, ll n, ll target)
{
	ll start=0;
	ll end=n-1;
	ll mid;
	while(start<end)
	{
		mid=(start+end)/2;
		if(checker(arr, n, mid, target))
		{
			start=mid;
		}
		else
		{
			end=mid;
		}
		if(end-start==1)
		{
			if(checker(arr, n, end, target))
			{
				cout<<end+1<<" "<<target-arr[end]<<endl;
				return;
			}
			else
			{
                if(!checker(arr, n, start, target))
                {
                    cout<<0<<" "<<target<<endl;
                    return;
                }
				cout<<start+1<<" "<<target-arr[start]<<endl;
				return;
			}
		}
	}
    cout<<mid+1<<" "<<target-arr[mid]<<endl;
    return;
}
int main()
{
	ll n;
	cin>>n;
	ll *prices=new ll [n];
	for(ll i=0; i<n; i++)
	{
		cin>>prices[i];
	}
	ll q;//number of days.
	cin>>q;
	ll *money=new ll [q];
	for(ll i=0; i<q; i++)
	{
		cin>>money[i];
	}
	ll *prefix_sum_prices=new ll [n];
	ll sum=0;
	for(ll i=0; i<n; i++)
	{
		sum+=prices[i];
		prefix_sum_prices[i]=sum;
	}
	for(ll i=0; i<q; i++)
	{
		momos(prefix_sum_prices, n, money[i]);
	}
}