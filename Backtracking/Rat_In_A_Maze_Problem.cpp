/* You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.
Input Format
Line 1 : Integer N
Next N Lines : Each line will contain ith row elements (separated by space)
Output Format :
One Line for every possible solution. 
Every line will have N*N maze elements printed row wise and are separated by space. Only cells that are part of solution path should be 1, rest all cells should be 0.
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Sample Output 1 Explanation :
Only 1 path is possible
Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 
Sample Output 2 Explanation :
4 paths are possible */



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

