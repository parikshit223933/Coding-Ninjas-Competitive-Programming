#include<iostream>
using namespace std;
void printer(int** arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << " ";
		}
	}
}
bool checker(int** arr, int i, int j, int n)
{
	for (int p = 0; p < n; p++)
	{
		if (arr[p][j] == 1 && p!=i)
		{
			return false;
		}
	}
	for (int row = i - 1, col = j + 1; row >= 0 && col < n; row--, col++)
	{
		if (arr[row][col] == 1)
		{
			return false;
		}
	}
	for (int row = i - 1, col = j - 1; row >= 0 && col >= 0; col--, row--)
	{
		if (arr[row][col] == 1)
		{
			return false;
		}
	}

	return true;
}
void zero_converter(int **arr, int n, int row)
{
	for(int i=row; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			arr[i][j] = 0;
		}
	}
}
void placer(int** arr, int row, int col, int n)
{
	if (row == n)
	{
		printer(arr, n);
		cout << endl;
		return;
	}
	int i = col;
	for (; i < n; i++)
	{
		zero_converter(arr, n, row);
		if (checker(arr, row, i, n))
		{
			arr[row][i] = 1;
			placer(arr, row + 1, col, n);
			continue;
		}
	}
}
void placeNQueens(int n)
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
	placer(arr, 0, 0, n);
    for(int i=0; i<n; i++)
    {
        delete[]arr[i];
    }
    delete[]arr;
}
