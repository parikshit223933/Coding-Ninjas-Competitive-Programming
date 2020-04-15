/* There are ‘n’ number of balls in a container. Mr. Sharma and Singh want to take balls out from the container. At each step, Mr. Sharma took ‘k’ balls out of the box and Mr. Singh took one-tenth of the remaining balls. Suppose there are 29 balls at the moment and k=4. Then, Mr. Sharma will take 4 balls and Mr. Singh will take 2 balls (29-4 = 25; 25/10 = 2). If there are less than ‘k’ balls remaining at some moment, then Mr. Sharma will take all the balls which will get the container empty. The process will last until the container becomes empty. Your task is to choose minimal ‘k’ for Mr. Sharma such that Mr. Sharma will take at least half of the balls from the container.
Input Format:
The Only line of input contains a single integer ‘n’.

Output Format:
Print a single integer denoting the minimal value of ‘k’.
Constraints:
1 <= n <= 10^18
Time Limit: 1 second
Sample Input:
68
Sample Output:
3
Explanation:
68-3 = 65; 65/10 = 6; 65-6 = 59
59-3 = 56; 56/10 = 5; 56-5 = 51
51-3 = 48; 48/10 = 4; 48-4 = 44
44-3 = 41; 41/10 = 4; 41-4 = 37
…..
…..
…..
6-3 = 3; 3/10 = 0; 3-0 = 3
3-3 = 0; 0/10 = 0; 0-0 = 0 */




#include<iostream>
using namespace std;
typedef long long ll;
bool check_for_k(ll k, ll n)
{
	ll singh = 0;
	ll sharma = 0;
	ll total_balls = n;
	while (total_balls >= k)
	{
		sharma += k;
		total_balls -= k;
		singh += total_balls / 10;
		total_balls -= total_balls / 10;
	}
	sharma += total_balls;
	if(n%2==0)
	{
		if (sharma >= n / 2)
		{
			return true;
		}
	}
	else if(n%2!=0)
	{
		if(sharma>=(n/2)+1)
		{
			return true;
		}
	}
	
	return false;
}
ll optimizer(ll n)
{
	ll start = 1;
	ll end = n;
	ll mid = (start + end) / 2;
	while (end >= start + 1)
	{
		mid = (start + end) / 2;
		if (check_for_k(mid, n))
		{
			end = mid;
		}
		else
		{
			start = mid;
		}
		if (end - start == 1)
		{
			if (check_for_k(start, n))
			{
				return start;
			}
			return end;
		}
	}
	return mid;
}
int main()
{
	ll n;
	cin >> n;
	cout << optimizer(n);
}