/* You want to paint your house. The total area of your house is D units. There are a total of N workers. The ith worker is available after time Ti, has hiring cost Xi and speed Yi. This means he becomes available for hiring from time Ti and remains available after that. Once available, you can hire him with cost Xi, after which he will start painting the house immediately, covering exactly Yi units of house with paint per time unit. You may or may not hire a worker and can also hire or fire him at any later point of time. However, no more than 1 worker can be painting the house at a given time.
Since you want the work to be done as fast as possible, figure out a way to hire the workers, such that your house gets painted at the earliest possible time, with minimum cost to spend for hiring workers.
Note: You can hire a previously hired worker without paying him again.
Input
The first line of input contains two integers "N D", the number of workers and the area of your house respectively. The ith of the next N lines denotes the ith worker, and contains three integers "Ti Xi Yi", described in the statement.
Output
Output one integer, the minimum cost that you can spend in order to get your house painted at the earliest.
Constraints
1 ≤ N, T, X, Y ≤ 10^5
1 ≤ D ≤ 10^11
Sample Input
3 3
1 1 1
2 2 2
3 1 5
Sample Output
3 */



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