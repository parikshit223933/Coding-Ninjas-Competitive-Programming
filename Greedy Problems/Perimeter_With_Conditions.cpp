#include<iostream>
#include<algorithm>
using namespace std;
void printer(int *arr, int n)
{
	int start=n-3;
	int mid=n-2;
	int end=n-1;
	while(start+mid<=end)
	{
		start--;
		mid--;
		end--;
		if(start<0)
		{
			cout<<-1<<endl;
			return;
		}
	}
	cout<<arr[start]<<" "<<arr[mid]<<" "<<arr[end];
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int [n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	sort(arr, arr+n);
	printer(arr, n);
}