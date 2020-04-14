/* There will be ‘t’ test cases having an integer. You have to sum up all the digits of this integer. For e.g. For 6754, the answer will be 6 + 7 + 5 + 4 = 22.
Input Format:
First line will have an integer ‘t’ denoting the number of test cases.
Next ‘t’ lines will have an integer ‘val’ each.
Output format:
Print ‘t’ lines of output denoting the sum of all the digits of the number in each test case.
Constraints:
1 <= t <= 10^5
0 <= val <= 10^18
Sample Input:
2
1547
45876
Sample Output:
17
30
Explanation:
1 + 5 + 4 + 7 = 17
4 + 5 + 8 + 7 + 6 = 30 */
#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n;
		cin>>n;
		int sum=0;
		while(n!=0)
		{
			sum+=n%10;
			n/=10;
		}
		cout<<sum<<endl;
	}
}