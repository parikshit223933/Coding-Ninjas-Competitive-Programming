#include<iostream>
#include<vector>
using namespace std;
int count_cycles(int** arr, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j && arr[i][j]==1)
			{
				for (int k = 0; k < n; k++)
				{
					if (j != k && k != i && arr[j][k]==1)
					{
						if (arr[i][k] == 1)
						{
							count += 1;
						}
					}
				}
			}
		}
	}
	return count;
}
int solve(int n,int m,vector<int>u,vector<int>v)
{
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < m; i++)
	{
		arr[u[i]-1][v[i]-1] = 1;
		arr[v[i]-1][u[i]-1] = 1;
	}
	return count_cycles(arr, n)/6;
}