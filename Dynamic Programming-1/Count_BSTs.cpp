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


