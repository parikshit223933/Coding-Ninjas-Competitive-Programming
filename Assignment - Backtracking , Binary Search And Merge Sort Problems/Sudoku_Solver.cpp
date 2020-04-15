/* Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :
9 Lines where ith line contains ith row elements separated by space
Output Format :
 true or false
Sample Input :
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output :
true */



#include<iostream>
using namespace std;
int n=9;
bool find_empty_location(int **arr, int& row, int &col)
{
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(arr[i][j]==0)
			{
				row = i;
				col = j;
				return true;
			}
		}
	}
	return false;
}
bool vertical(int **arr, int row, int col, int value)
{
	for(int i=0; i<n; i++)
	{
		if(arr[i][col]==value)
		{
			return false;
		}
	}
	return true;
}
bool horizontal(int **arr, int row, int col, int value)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[row][i] == value)
		{
			return false;
		}
	}
	return true;
}
bool box(int **arr, int row, int col, int value)
{
	int row_factor = row - (row % 3);
	int col_factor = col - (col % 3);
	for(int i=0; i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			if(arr[i+row_factor][j+col_factor]==value)
			{
				return false;
			}
		}
	}
	return true;
}
bool checker(int **arr, int value, int row, int col)
{
	if(vertical(arr, row, col, value)&&horizontal(arr, row, col, value)&&box(arr, row, col, value))
	{
		return true;
	}
	return false;
}
bool solveSudoku(int **arr)
{
	int row=0, col=0;
	if(!find_empty_location(arr, row, col))
	{
		return true;
	}
	for(int i=1; i<=n; i++)
	{
		if(checker(arr, i, row, col))
		{
			arr[row][col] = i;
			if(solveSudoku(arr))
			{
				return true;
			}
			else
			{
				arr[row][col] = 0;
			}
		}
	}
	return false;
}
bool sudokuSolver(int board[][9])
{
    int **arr=new int *[n];
    for(int i=0; i<n; i++)
    {
        arr[i]=new int [n];
        for(int j=0; j<n; j++)
        {
            arr[i][j]=board[i][j];
        }
    }
    return solveSudoku(arr);
}
