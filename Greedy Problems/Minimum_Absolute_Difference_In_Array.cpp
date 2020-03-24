// arr - input array
// n - size of array
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
int mod(int a)
{
	if(a<0)
	{
		return -a;
	}
	return a;
}
int minAbsoluteDiff(int arr[], int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
sort(arr, arr+n);
	int i=0;
	int j=1;
	int minimum=INT_MAX;
	while(j<n)
	{
		if(mod(arr[i]-arr[j])<minimum)
		{
			minimum=mod(arr[i]-arr[j]);
		}
		i++;
		j++;
	}
	return minimum;
}
