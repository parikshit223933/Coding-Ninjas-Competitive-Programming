#include<iostream>
using namespace std;
void printer(int **arr, int n)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout << arr[i][j]<<" ";
		}
	}
	cout << endl;
}
void positioner(int arr[][20], int n, int ** solution, int row, int col)
{
	//row and col denotes the current position of the rat.
	if(row==n-1&&col==n-1)
	{
		solution[row][col] = 1;
		printer(solution, n);
		solution[row][col] = 0;
		return;
	}
	int i = row;
	int j = col;
	solution[i][j] = 1;
	if(arr[i][j]==0)//not moving to zero.
	{
		return;
	}
	if(i<n-1 && solution[i+1][j]!=1 && arr[i+1][j]!=0)//moving down
	{
		positioner(arr, n, solution, i + 1, j);
		
	}
	if(j<n-1 && solution[i][j+1]!=1 && arr[i][j+1]!=0)//moving right
	{
		positioner(arr, n, solution, i, j + 1);
	}
	if(i>0 && solution[i-1][j]!=1 && arr[i-1][j]!=0)//moving up
	{
		positioner(arr, n, solution, i - 1, j);
	}
	if(j>0 && solution[i][j-1]!=1 && arr[i][j-1]!=0)//moving left
	{
		positioner(arr, n, solution, i, j - 1);
	}
	solution[i][j] = 0;
}
void ratInAMaze(int arr[][20], int n)
{
	int** solution = new int* [n];
	for (int i = 0; i < n; i++)
	{
		solution[i] = new int [n];
		for(int j=0; j<n; j++)
		{
			solution[i][j] = 0;
		}
	}
	positioner(arr, n, solution,0 , 0);
}

