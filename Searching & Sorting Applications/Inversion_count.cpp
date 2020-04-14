/* Let A[0 ... n-1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A (where i and j are indexes of A). Given an integer array A, your task is to find the number of inversions in A.
Input format :
Line 1 : n, array size
Line 2 : Array elements (separated by space).
Output format :
Count of inversions
Constraints :
1 <= n <= 10^5
1 <= A[i] <= 10^9
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Sample Input 2 :
5
2 5 1 3 4
Sample Output 1 :
4 */



#include<iostream>
using namespace std;
long long merge(int *arr, int start, int mid, int end)
{
	int *temp=new int [end-start+1];
	long long count=0;
	int i=start;
	int j=mid;
	int k=0;
	while(i<mid&&j<=end)
	{
		if(arr[i]<=arr[j])
		{
			temp[k]=arr[i];
			i++;
		}
		else
		{
			temp[k]=arr[j];
			j++;
			count+=mid-i;
		}
		k++;
	}
	while(i<mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=end)
	{
		temp[k++]=arr[j++];
	}
	for(int i=start, k=0; i<=end; i++, k++)
	{
		arr[i]=temp[k];
	}
	delete[]temp;
	return count;
}
long long merge_sort(int *arr, int start, int end)
{
	long long count=0;
	if(start<end)
	{
		int mid=(start+end)/2;
		long long count_left=merge_sort(arr, start, mid);
		long long count_right=merge_sort(arr, mid+1, end);
		long long count_merge=merge(arr, start, mid+1, end);
		return count_left+count_right+count_merge;
	}
	return count;
}
long long solve(int *arr, int n)
{
	long long count=merge_sort(arr, 0, n-1);
	return count;
}