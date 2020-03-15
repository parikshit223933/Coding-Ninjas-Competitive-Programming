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