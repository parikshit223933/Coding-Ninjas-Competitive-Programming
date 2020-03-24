#include<iostream>
#include<algorithm>
#define ll long long int
using namespace std;
struct worker
{
	ll ti;
	ll xi;
	ll yi;
};
bool sorter(worker w1, worker w2)
{
	if(w1.ti==w2.ti)
	{
		if(w1.yi==w2.yi)
		{
			return w1.xi<w2.xi;
		}
		return w1.yi>w2.yi;
	}
	return w1.ti<w2.ti;
}
ll minimum_cost(worker *arr, ll n, ll d)
{
	ll current_cost=arr[0].xi;
	ll current_area_covered=0;
	ll current_worker_index=0;
	for(ll i=1; i<n&& current_area_covered<d; i++)
	{
		current_area_covered+=(arr[i].ti-arr[i-1].ti)*arr[current_worker_index].yi;
		if(current_area_covered>=d)
		{
			return current_cost;
		}
		if(arr[current_worker_index].yi<arr[i].yi)
		{
			current_worker_index=i;
			current_cost+=arr[current_worker_index].xi;
		}
	}
	return current_cost;
}
int main()
{
	ll n, d;// d is the area to be painted;
	cin>>n>>d;
	worker*arr=new worker[n];
	for(ll i=0; i<n; i++)
	{
		cin>>arr[i].ti>>arr[i].xi>>arr[i].yi;
	}
	sort(arr, arr+n, sorter);
	cout<<minimum_cost(arr, n, d)<<endl;
}