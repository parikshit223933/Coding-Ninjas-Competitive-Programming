/* Harshit knows by his resources that this time the winning lottery number is the smallest number whose sum of the digits is S and the number of digits is D. You have to help Harshit and print the winning lottery number.
Input Format
The Input line contains two space-separated integers: S,D
Output Format
The output contains a single integer denoting the winning lottery number
Constraints
1 <= D <= 1000
1 <= S <= 9*D
Time Limit: 1 second
Sample Input1:
9 2
Sample Output1:
18
Explanation
There are many other possible numbers like 45, 54, 90, etc with the sum of digits as 9 and number of digits as 2. The smallest of them is 18. */



#include<iostream>
using namespace std;
void lottery(int s, int n)
{
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = 0;
	}
	int sum = s;
	arr[0] = 1;
	sum -= 1;
	int i = n - 1;
	while (i >= 0)
	{
		if (i == 0)
		{
			arr[i] += sum;
		}
		if (sum > 9)
		{
			arr[i] = 9;
			sum -= 9;
		}
		else if (sum <= 9)
		{
			arr[i] += sum;
			sum = 0;
		}
		i--;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i];
	}
}
int main()
{
	int s, d;
	cin >> s >> d;
	lottery(s, d);
}