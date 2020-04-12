/* Sum Array

Given a 2-d square matrix of order ‘n’, find the sum of elements of both diagonals and all boundaries elements. Boundary elements refer to the elements present on all the four boundaries of matrix.
Input:
First line will have a single integer ‘n’ denoting the order of matrix.
Next ‘n’ lines will have ‘n’ space separated integers each denoting the elements of matrix.
Constraints:
1<=n<=100
Output:
Print a single integer denoting the sum.
Sample input:
3
1 2 3
4 5 6
7 8 9
Sample Output:
45 */


#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n;
	cin >> n;
	vector<vector<int>>v;
    
    if (n==1)
    {
        cout<<1;
        return 0;
    }
	for(int i=0; i<n; i++)
	{
		vector<int>temp;
		for(int j=0; j<n; j++)
		{
			int element;
			cin >> element;
			temp.push_back(element);
		}
		v.push_back(temp);
	}
	int sum = 0;
	//we will first take the sum of first row
	//then last row
	//then first column
	//then last column
	//then both the diagonals
	for(int i=0; i<n; i++)
	{
		sum += v[0][i];
		sum += v[n - 1][i];
	}
	for(int i=1; i<n-1; i++)
	{
		sum += v[i][0];
		sum += v[i][n-1];
	}
	//upto here we have completed all the sides of the square.
	for(int i=1, j=1; i<n-1&&j<n-1; i++, j++)
	{
		sum += v[i][j];
	}
	for(int i=n-2, j=1; i>=1&&j<=n-2; i--, j++)
	{
        if(i==j)
        {
            continue;
        }
		sum += v[i][j];
	}
	cout << sum;
}