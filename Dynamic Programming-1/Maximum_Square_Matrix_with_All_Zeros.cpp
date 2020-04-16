/* Given a n*m matrix which contains only 0s and 1s, find out the size of maximum square sub-matrix with all 0s. You need to return the size of square with all 0s.
Input format :
Line 1 : n and m (space separated positive integers)
Next n lines : m elements of each row (separated by space).
Output Format:
Line 1 : Size of maximum square sub-matrix
Sample Input :
3 3
1 1 0
1 1 1
1 1 1
Sample Output :
1 */




#include<iostream>
#include<algorithm>
using namespace std;
int findMaxSquare(int** arr, int n, int m, int **temp)
{
	int max_element=0;
	if(arr[n-1][m-1]==0)
	{
		temp[n-1][m-1]=1;
		max_element=1;
	}
	else
	{
		temp[n-1][m-1]=0;
	}
	for(int i=n-2; i>=0; i--)
	{
		if(arr[i][m-1]==0)
		{
			temp[i][m-1]=1;
		}
		else
		{
			temp[i][m-1]=0;
		}
		max_element=max(max_element, temp[i][m-1]);
	}
	for(int i=m-2; i>=0; i--)
	{
		if(arr[n-1][i]==0)
		{
			temp[n-1][i]=1;
		}
		else
		{
			temp[n-1][i]=0;
		}
		max_element=max(max_element, temp[n-1][i]);
	}
	for(int i=n-2; i>=0; i--)
	{
		for(int j=m-2; j>=0; j--)
		{
			
			if(arr[i][j]==1)
			{
				temp[i][j]=0;
			}
			else
			{
				if(temp[i+1][j]>=1 && temp[i][j+1]>=1 && temp[i+1][j+1]>=1)
				{
					temp[i][j]=1+min(temp[i+1][j+1], min(temp[i+1][j], temp[i][j+1]));
				}
				else
				{
					temp[i][j]=1;
				}
			}
			max_element=max(max_element, temp[i][j]);
		}
	}
    for(int i=0; i<n; i++)
    {
        delete[]temp[i];
    }
    delete[]temp;
	return max_element;
}
int findMaxSquareWithAllZeros(int** arr, int n, int m){
    
    /* Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    
	int **temp=new int *[n];
	for(int i=0; i<n; i++)
	{
		temp[i]=new int [m];
        for(int j=0; j<m; j++)
        {
            temp[i][j]=0;
        }
	}
	return findMaxSquare(arr, n, m, temp);
    
}