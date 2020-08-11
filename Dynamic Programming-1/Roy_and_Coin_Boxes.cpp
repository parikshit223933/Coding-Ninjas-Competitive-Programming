/* Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.
Input
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a
Output
For each query output the result in a new line.
Constraints
1 ≤ N ≤ 1000000

1 ≤ M ≤ 1000000

1 ≤ L ≤ R ≤ N

1 ≤ Q ≤ 1000000

1 ≤ X ≤ N
Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4 */







#include<iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;//number of coins;
	int m;//number of days;
	cin>>m;
	int size=1000001;
	
	int *ks=new int [size];
	int *ke=new int [size];
	
	while(m--)
	{
		int start, end;
		cin>>start>>end;
		ks[start]+=1;
		ke[end]+=1;
	}
	
	int *arr=new int [size];
	arr[0]=0;
	arr[1]=ks[1];
	for(int i=2; i<size; i++)
	{
		arr[i]=ks[i]-ke[i-1]+arr[i-1];
	}
	//now we have the array with the help of which we can easily tell that how many coins are in each box.
	int *temp=new int [size];
	for(int i=0; i<size; i++)
	{
		temp[i]=0;
	}
	for(int i=0; i<size; i++)
	{
		temp[arr[i]]+=1;
	}
	int *dp=new int [n+1];
	for(int i=0; i<n+1; i++)
	{
		dp[i]=0;
	}
	dp[n]=temp[n];
	for(int i=n-1; i>=0; i--)
	{
		dp[i]=temp[i]+dp[i+1];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int coins;
		cin>>coins;
		cout<<dp[coins]<<"\n";
	}
	delete[]ke;
	delete[]ks;
	delete[]arr;
	delete[]temp;
	delete[]dp;
}
