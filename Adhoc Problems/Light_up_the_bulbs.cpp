/* A bulb can be ‘ON’ or ‘OFF’. Mr. Navdeep got ‘n’ number of bulbs and their status, whether they are ‘ON’ or ‘OFF’. Their status is represented in a string of size ‘n’ consisting of 0’s and 1’s, where ‘0’ represents the bulb is in ‘OFF’ condition and ‘1’ represent the bulb is ‘ON’. Mr. Navdeep has been given the task to light up all the bulbs.
He can perform two operations.
First, chose any segment of bulbs and reverse them means chose any substring and reverse it. E.g. “0 110 001” -> “0 011 001”. Substring (1, 3) is reversed here. This operation will cost him Rs. ‘X’.
Second, chose any segment of bulbs and reverse their present condition. i.e. if the bulb is ‘ON’, make it ‘OFF’ and if it is ‘OFF’, make it ‘ON’. E.g. “0 011 001” -> “0 100 001”. Substring (1, 3) is complemented. This operation will cost him Rs. ‘Y’.
You need to help Mr. Navdeep that how much minimum amount it will require to make all the bulbs lightened. (or make all the characters as ‘1’ in the representation string)
Input Format:
The first line will contain three space separated integers: ‘n’, ‘X’, ‘Y’ denoting the number of bulbs, cost of first operation and cost of second operation respectively.
The second line contains a representation string of length ‘n’ consisting of 0’s and 1’s representing whether the bulb is ‘OFF’ or ‘ON’.
Output Format:
Print a single integer denoting the minimum cost required to light up all the bulbs.
Constraints:
1 <= n <= 3,00,000
0 <= X, Y <= 10^9
Time Limit: 1 second
Sample Input:
5 1 10
01000
Sample Output:
11
Explanation:
First, Reverse substring (0, 1): “01000” -> “10000”, COST = 1
Second, Invert substring (1, 4): “10000” -> “11111”, COST = 10
Total cost = 1+10 => 11 */


#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	long long n, x, y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	long long count = 0;
	if(s[0]=='0')
	{
		count = 1;
	}
	for(long long i=1; i<n; i++)
	{
		if((s[i-1]=='1') && (s[i]=='0'))
		{
			count += 1;
		}
	}
	
	if(count==0)
	{
		cout << 0;
	}
	else
	{
		cout << (count-1) * min(x, y) + y;
	}
}