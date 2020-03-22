#include<iostream>
using namespace std;
void printer(int *arr, int n)
{
	for(int i=0; i<n; i++)
	{
		cout << arr[i] << " ";
	}
}
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	int count = 0;
	for(int i=n-1; i>=2; i--)
	{
		if(arr[i]==i+1)
		{
			continue;
		}
		else
		{
			if(arr[i-1]==i+1)
			{
				count += 1;
				int temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
			}
			else if(arr[i-2]==i+1)
			{
				count += 2;
				arr[i - 2] = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = i + 1;
			}
			else
			{
				cout << "NO";
				return 0;
			}
		}
	}
	if(arr[0]==2 && arr[1]==1)
	{
		arr[0] = 1;
		arr[1] = 2;
		count += 1;
		cout << "YES" << endl << count;
	}
	else if(arr[0]==1 && arr[1]==2)
	{
		cout << "YES" << endl << count;
	}
	else
	{
		cout << "NO";
	}
}