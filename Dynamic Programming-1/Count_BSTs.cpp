/* Given an integer N, find and return the count of unique Binary search trees (BSTs) are possible with nodes valued from 1 to N.
Output count can be very large, so return the count modulo 10^9+7.
Input Format :
Integer n 
Output Format :
Count of BSTs
Contraints :
1<= N <=1000
Sample Input 1:
8
Sample Output 1:
1430
Sample Input 2:
3
Sample Output 2:
5 */





#include<iostream>

using namespace std;
#define m 1000000007
long long count_trees(int n, int *temp=new int [1001]())
{
	if(n==1||n==0)
	{
		return 1;
	}
	if(temp[n]>0)
	{
		return temp[n];
	}
	long long count=0;
	for(int i=1; i<=n; i++)
	{
		long long left=count_trees(i-1, temp)%m;
		temp[i-1]=left;
		long long right=count_trees(n-i, temp)%m;
		temp[n-i]=right;
		count+= (left*right)%m;
	}
	temp[n]=count;
	return count;
}
int countBST( int n)
{
  /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
int a= count_trees(n)%m;
    return a;
}


