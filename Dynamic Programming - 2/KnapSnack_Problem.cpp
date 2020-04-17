/* A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Space complexity should be O(W).
Input Format :
Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry
Output Format :
Line 1 : Maximum value V
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output :
13 */



#include<iostream>
#include<algorithm>
using namespace std;
using namespace std;
int knapsack(int* w, int* v, int n, int max_weight)
{
	int* zero = new int[max_weight + 1];
	int* one = new int[max_weight + 1];
	for (int i = 0; i < max_weight + 1; i++)
	{
		zero[i] = 0;
		one[i] = 0;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= max_weight; j++)
		{
			if (j - w[i - 1] >= 0)
			{
				one[j] = max(zero[j], v[i - 1] + zero[j - w[i - 1]]);
			}
			else
			{
				one[j] = zero[j];
			}
		}

		for (int j = 0; j <= max_weight; j++)
		{
			zero[j] = one[j];
			one[j] = 0;
		}
	}
	return zero[max_weight];
}
