/* Even and Odd Indexes
Given an array of integers, print two integer values:
First, the sum of all numbers which are even as well as whose index are even.
Second, the sum of all numbers which are odd as well as whose index are odd.
Print the two integers space separated. (Arrays is 0-indexed)
Input:
Given an integer denoting the size of array.
Next line will have a line containing ‘n’ space separated integers.
Constraints:
1<=n<=10^5
1 <= Ai <= 10^6 
Output:
Two space separated integers denoting even and odd sums respectively.
Sample Input:
5
2 3 5 1 4
Sample Output:
6 4 */

#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int>v;
	for(int i=0; i<n; i++)
	{
		int element;
		cin >> element;
		v.push_back(element);
	}
	int even_sum = 0;
	int odd_sum = 0;
	for(int i=0; i<v.size(); i++)
	{
		if(i%2==0 && v[i]%2==0)
		{
			even_sum += v[i];
		}
		else if(i%2!=0&&v[i]%2!=0)
		{
			odd_sum += v[i];
		}
	}
	cout << even_sum <<" "<< odd_sum;
}