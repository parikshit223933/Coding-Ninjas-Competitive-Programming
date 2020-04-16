/* Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
Integer N
Output Format :
Required minimum count
Constraints :
1 <= N <= 1000
Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1 */







#include<iostream>
#include<algorithm>
using namespace std;
bool is_perfect_square(int n)
{
	for(int i=1; i<=32; i++)
	{
		if(n==i*i)
		{
			return true;
		}
	}
	return false;
}
int minCount(int n, int *dp=new int [1001])
{
	if(is_perfect_square(n)==true)
	{
		return 1;
	}
	if(n<=3)
	{
		return n;
	}
	int count=n;
	if(dp[n]>0)
	{
		return dp[n];
	}
	for(int i=1; i<=n; i++)
	{
		int temp=i*i;
		if(temp>n)
		{
			break;
		}
		else
		{
			count=min(count, 1+minCount(n-temp, dp));
		}
	}
	dp[n]=count;
	return count;
}