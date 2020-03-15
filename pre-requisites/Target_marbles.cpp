#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n, t;
	cin >> n >> t;
	int* arr = new int[n];
	for(int i=0; i<n; i++)
	{
		cin >> arr[i];
	}
	for(int i=0; i<n; i++)
	{

		int sum = 0;
		int number = i;
		vector<int>v;
		
		while((sum!=t)&&(number<n))
		{
			sum += arr[number];
			v.push_back(arr[number]);
			number += 1;
		}
		if(sum==t)
		{
			cout << "true" << endl;
			for(int j=0; j<v.size(); j++)
			{
				cout << v[j] << " ";
			}
			return 0;
		}
	}
	cout << "false";
}