#include<iostream>
#include<algorithm>
using namespace std;
bool checker(int *arr, int n, int mid, int k)
{
	int sum=0;
	for(int i=0; i<n; i++)
	{
		sum+=arr[i]/mid;
		if(sum>=k)
		{
			return true;
		}
	}
	return false;
}
int maximum_candies(int *arr, int n, int k)
{
	sort(arr, arr+n);
	int start=0;
	int end=arr[n-1];
	int mid=0;
	while(start<end)
	{
		mid=(start+end)/2;
		if(checker(arr, n, mid, k))
		{
			start=mid;
		}
		else
		{
			end=mid;
		}
		if(end-start==1)
		{
			if(checker(arr, n, end, k))
			{
				return end;
			}
			else
			{
				return start;
			}
		}
	}
	return mid;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		int k;
		cin>>n>>k;
		int *arr=new int [n];
		for(int i=0; i<n; i++)
		{
			cin>>arr[i];
		}
		cout<<maximum_candies(arr, n, k)<<endl;
	}
}