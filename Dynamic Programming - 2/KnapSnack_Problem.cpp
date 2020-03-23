#include<iostream>
#include<algorithm>
using namespace std;
using namespace std;
int knapsack(int* w, int* v, int n, int max_weight)
{
	int* zero = new int[max_weight + 1];
	int* one = new int[max_weight + 1];
	for (int i = 0; i < max_weight + 1; i++)
	{
		zero[i] = 0;
		one[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= max_weight; j++)
		{
			if (j - w[i - 1] >= 0)
			{
				one[j] = max(zero[j], v[i - 1] + zero[j - w[i - 1]]);
			}
			else
			{
				one[j] = zero[j];
			}
		}

		for (int j = 0; j <= max_weight; j++)
		{
			zero[j] = one[j];
			one[j] = 0;
		}
	}
	return zero[max_weight];
}
