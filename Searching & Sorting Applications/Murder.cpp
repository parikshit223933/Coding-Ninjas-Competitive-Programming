#include<iostream>

using namespace std;
typedef long long ll;

ll merge(ll *arr, ll left, ll mid, ll right)
{
	ll i=left;
	ll k=0;
	ll j=mid;
	ll sum=0;
	ll *temp=new ll [right-left+1];
	while(i<mid&&j<=right)
	{
		if(arr[i]<arr[j])
		{
			sum+=(arr[i]*(right-j+1));
			temp[k++]=arr[i++];
		}
		else
		{
			temp[k++]=arr[j++];
		}
	}
	while(i<mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=right)
	{
		temp[k++]=arr[j++];
	}
	for(int i=left, k=0; i<=right; i++, k++)
	{
		arr[i]=temp[k];
	}
	delete[]temp;
	return sum;
}
ll merge_sort(ll *arr, ll left, ll right)
{
	ll count=0;
	if(right>left)
	{
		ll mid=(right+left)/2;
		ll left_count=merge_sort(arr, left, mid);
		ll right_count=merge_sort(arr, mid+1, right);
		ll merge_count=merge(arr, left, mid+1, right);
		
		return left_count+right_count+merge_count;
	}
	return count;
}
ll solve(ll *arr, ll n)
{
	ll ans=merge_sort(arr, 0, n-1);
	return ans;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		//n== number of stairs;
		ll *arr=new ll [n];
		for(ll i=0; i<n; i++)
		{
			cin>>arr[i];
		}
		cout<<solve(arr, n)<<endl;
	}
}