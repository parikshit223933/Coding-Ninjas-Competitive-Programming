/* A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format
Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house
Output Format
 Line 1 : Maximum amount of money looted
Input Constraints
1 <= n <= 10^4
1 <= A[i] < 10^4
Sample Input :
6
5 5 10 100 10 5
Sample Output 1 :
110 */





#include<iostream>
#include<algorithm>
using namespace std;
int getMaxMoney(int arr[], int n, int i=0, int *temp=new int[10002]()){

	/*Write your code here.
	 *Don’t write main(). 
	 *Don’t take input, it is passed as function argument.
	 *Don’t print output.
	 *Taking input and printing output is handled automatically.
         */ 
    if(i>=n)
	{
		return 0;
	}
    if(temp[i]>0)
    {
        return temp[i];
    }
	int maximum=0;
	int including=arr[i]+getMaxMoney(arr, n, i+2, temp);
	int not_including=getMaxMoney(arr,n, i+1, temp);
	maximum=max(including, not_including);
    temp[i]=maximum;
	return maximum;
}
