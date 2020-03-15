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
	for(int i=0, j=n-1; i<n&&j>=0&&i!=j&&i<j; i++, j--)
	{
		int sum = v[i] + v[j];
		cout << int(sum / 10) << " " << sum % 10 << endl;
	}
}