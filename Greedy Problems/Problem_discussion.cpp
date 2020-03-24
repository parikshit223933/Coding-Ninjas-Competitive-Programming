#include<iostream>
#include<algorithm>
using namespace std;
int get_min_difference(int *arr, int n, int k)
{
	if(n==1)
	{
		return 0;
	}
	sort(arr, arr+n);
	int ans=arr[n-1]-arr[0];
	int small=arr[0]+k;
	int big=arr[n-1]-k;
	if(small>big)
	{
		int temp=big;
		big=small;
		small=temp;
	}
	for(int i=1; i<n-1; i++)
	{
		int subtract=arr[i]-k;
		int add=arr[i]+k;
		if(subtract>=small || add<=big)
		{
			continue;
		}
		if(big-subtract<=add-small)
		{
			small=subtract;
		}
		else
		{
			big=add;
		}
	}
	return min(ans, big-small);
}
int main()
{
	int n, k;
	cin>>n>>k;
	int *arr=new int [n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cout<<get_min_difference(arr, n, k)<<endl;
}