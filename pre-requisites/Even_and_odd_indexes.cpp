#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>v;
	for(int i=0; i<n; i++)
	{
		int element;
		cin >> element;
		v.push_back(element);
	}
	int even_sum = 0;
	int odd_sum = 0;
	for(int i=0; i<v.size(); i++)
	{
		if(i%2==0 && v[i]%2==0)
		{
			even_sum += v[i];
		}
		else if(i%2!=0&&v[i]%2!=0)
		{
			odd_sum += v[i];
		}
	}
	cout << even_sum <<" "<< odd_sum;
}