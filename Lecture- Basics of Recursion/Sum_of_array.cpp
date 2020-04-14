/* Given an array of length N, you need to find and return the sum of all elements of the array.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
Sum
Constraints :
1 <= N <= 10^3
Sample Input :
3
9 8 9
Sample Output :
26 */
int sum(int input[], int n)
{
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return input[0];
    }
    int small_sum=sum(input+1, n-1);
    return input[0]+small_sum;
}
