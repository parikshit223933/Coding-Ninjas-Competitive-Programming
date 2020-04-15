/* Professor Jain has a class full of notorious students. To get anything done from them is a herculean task. Prof Jain wanted to organize a test. He gave this responsibility to Aahad. Aahad did an excellent job of organizing the test. As a reward, the professor gave him an sequence of numbers to play with. But Aahad likes playing with "interesting" sequence of numbers, which are sequences that have equal elements.
Now, the problem is - Prof Jain has a sequence with elements, and that sequence isn't always "interesting”. To ensure sequence has equal elements, Prof Jain has 2 options:
1) Choose two elements of sequence . DECREASE the first element by 1 and INCREASE the second element by 1. This operation costs 'k' coins.
2) Choose one element of array and INCREASE it by 1. This operation costs 'l' coins.
What’s the minimum number of coins Prof Jain needs to turn his sequence into a “interesting" sequence for Aahad?
Input Format
The first line of input contains three space-separated integers: n, k, l . Integer n is the size of array . Integer k is the number of coins needed to perform the first operation. Integer l is the number of coins needed to perform the second operation.

The second line contains n integers: (a1, a2, a3... an) representing sequence.
Constraints:
1 <= n, k, l <= 1000
1 <= ai <= 1000
Time Limit: 1 second
Output Format
In single line, print one integer number: the minimum number of coins required to make "interesting" sequence.
Sample Test Cases:
Sample Input 1:
4 1 2
3 4 2 2
Sample Output 1:
3
Explanation Output 1 :
The professor has a sequence with 4 elements. To perform the first operation, they must pay 1 coin and to perform the second operation, they must pay 2 coins. The optimal strategy is:

-Perform the second operation on the fourth element. Now the sequence is {3, 4, 2, 3}. This costs 2 coins.

-Perform the first operation on the second and third element. The sequence is now "interesting", and it looks like {3, 3, 3, 3}. This costs 1 coin. 

The total amount of coins needed is 2 + 1 = 3.
Sample Input 2:
3 2 1
5 5 5
Sample Output 2:
0
Explanation Output 2 :
The given sequence is already "interesting". The professor would spend 0 coins.
Sample Input 3:
5 2 1
1 2 3 4 5
Sample Output 3:
6
Explanation Output 3 :
The professor has a sequence with 5 elements. To perform the first operation, they must pay 2 coin and to perform the second operation, they must pay 1 coin. The optimal strategy is:

-Perform the first operation on the first and last element. Now the sequence is {2, 2, 3, 4, 4}. This costs 2 coins.

-Perform the first operation again on the first and last element. Now the sequence is {3, 2, 3, 4, 3}. This costs 2 coins.

-Perform the first operation on the second and second last element. Now the sequence is {3, 3, 3, 3, 3}. This costs 2 coins.

The total amount of coins needed is 2 + 2 + 2 = 6. */



#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
long long cost_calculator(vector<long long>v, long long k, long long l, long long n, long long number)
{
	long long increment = 0;
	long long decrement = 0;
	for(long long i=0; i<n; i++)
	{
		if(v[i]>number)
		{
			decrement += v[i] - number;
		}
		else if(v[i]<number)
		{
			increment += number - v[i];
		}
	}
	if(decrement>increment)
	{
		return INT_MAX;
	}
	return (decrement * k) + ((increment - decrement)*l);
}
int main()
{
	long long n, k, l;
	cin >> n >> k >> l;
	vector<long long>v;
	for(long long i=0; i<n; i++)
	{
		long long element;
		cin >> element;
		v.push_back(element);
	}
	long long minimum=9999999, maximum=-1;
	for(long long i=0; i<n; i++)
	{
		if(v[i]<minimum)
		{
			minimum = v[i];
		}
		if(v[i]>maximum)
		{
			maximum = v[i];
		}
	}
	long long cost = INT_MAX;
	for(long long i=minimum; i<=maximum; i++)
	{
		cost = min(cost, cost_calculator(v, k, l, n, i));
	}
	cout << cost;
}