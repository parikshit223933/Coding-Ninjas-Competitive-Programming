#include<iostream>
#include<vector>
using namespace std;
void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
bool is_sorted(int *arr, int n)
{
	for(int i=0; i<n-1; i++)
	{
		if(arr[i]>arr[i+1])
		{
			return false;
		}
	}
	return true;
}
bool checker(int *arr, int n)
{
	for(int i=0; i<n-1; i++)
	{
		if(arr[i+1]==arr[i]-1)
		{
			swap(arr[i + 1], arr[i]);
		}
	}
	if(is_sorted(arr, n))
	{
		return true;
	}
	return false;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int* arr = new int[n];
		for(int i=0; i<n; i++)
		{
			cin >> arr[i];
		}
		if(checker(arr, n))
		{
			cout << "Yes"<<endl;
		}
		else
		{
			cout << "No"<<endl;
		}
	}
}