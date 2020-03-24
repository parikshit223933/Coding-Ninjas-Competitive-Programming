#include<iostream>
using namespace std;
void lottery(int s, int n)
{
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
	int sum = s;
	arr[0] = 1;
	sum -= 1;
	int i = n - 1;
	while (i >= 0)
	{
		if (i == 0)
		{
			arr[i] += sum;
		}
		if (sum > 9)
		{
			arr[i] = 9;
			sum -= 9;
		}
		else if (sum <= 9)
		{
			arr[i] += sum;
			sum = 0;
		}
		i--;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
	}
}
int main()
{
	int s, d;
	cin >> s >> d;
	lottery(s, d);
}