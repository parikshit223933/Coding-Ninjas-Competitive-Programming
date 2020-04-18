/* Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
There is a path from any cell to all its neighbouring cells. A neighbour may share an edge or a corner.
Input Format :
Line 1 : Two space separated integers N  and M, where N is number of rows and M is number of columns in the matrix.
Next N lines : N rows of the matrix. First line of these N line will contain 0th row of matrix, second line will contain 1st row and so on
Assume input to be 0-indexed based
Output Format :
Return 1 if there is a path which makes the sentence “CODINGNINJA” else return 0.
Constraints :
1 <= N <= 100
1 <= M <= 100
Sample Input :
2 11
CXDXNXNXNXA
XOXIXGXIXJX
Sample Output :
1 */



#include<iostream>
using namespace std;
bool checker(char arr[][MAXN], int n, int m, int i, int j, string s, bool**visited)
{
	if (s.length() == 0)
	{
		return true;
	}
	if (i < 0 || j < 0 || i >= n || j >= m)
	{
		return false;
	}
	int row_array[] = { i - 1, i, i + 1 };
	int col_array[] = { j - 1, j, j + 1 };
	for (int p = 0; p < 3; p++)
	{
		for (int q = 0; q < 3; q++)
		{
			if (row_array[p] == i && col_array[q] == j)
			{
				continue;
			}

			int row = row_array[p];
			int col = col_array[q];
			if (row < 0 || col < 0 || row >= n || col >= m)
			{
				continue;
			}
			if (arr[row][col] == s[0] && !visited[row][col])
			{
				visited[row][col] = true;
				bool checked = checker(arr, n, m, row, col, s.substr(1), visited);
				if (checked)
				{
					return checked;
				}
				else
				{
					visited[row][col] = false;
				}
			}
		}
	}
	return false;
}




int solve(char arr[][MAXN],int n, int m)
{
    
    bool** visited = new bool* [n];
    for (int i = 0; i < n; i++)
	{
		visited[i] = new bool[m];
		for (int j = 0; j < m; j++)
		{
			visited[i][j] = false;
		}
	}
    
    
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == 'C')
			{
                //creating dynamic boolean 2d array
				
                
                //checking
				if(checker(arr, n, m, i, j, "ODINGNINJA", visited))
				{
					return 1;
				}
                
                //deleting dynamic boolean array
				for(int p=0; p<n; p++)
                {
                    for(int q=0; q<m; q++)
                    {
                        visited[p][q]=false;
                    }
                }
			}
		}
	}
	return 0;
}