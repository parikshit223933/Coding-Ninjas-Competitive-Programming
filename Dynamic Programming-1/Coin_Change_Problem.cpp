/* You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
Note : Return 0, if change isn't possible.
Input Format
Line 1 : Integer n i.e. total number of denominations
Line 2 : N integers i.e. n denomination values
Line 3 : Value V
Output Format
Line 1 :  Number of ways i.e. W
Constraints :
1<=n<=10
1<=V<=1000
Sample Input 1 :
3
1 2 3
4
Sample Output
4
Sample Output Explanation :
Number of ways are - 4 total i.e. (1,1,1,1), (1,1, 2), (1, 3) and (2, 2). */



#include <iostream>
using namespace std;
int worker(int arr[], int n, int value, int **temp)
{
    if (n == 0)
    {
        return 0;
    }
    if (value == 0)
    {
        return 1;
    }
    if (value < 0)
    {
        return 0;
    }
    if (temp[n][value] > 0)
    {
        return temp[n][value];
    }
    int ans1 = worker(arr + 1, n - 1, value, temp);
    int ans2 = worker(arr, n, value - arr[0], temp);
    temp[n][value] = ans1 + ans2;
    return ans1 + ans2;
}
int countWaysToMakeChange(int arr[], int n, int value)
{
    int **temp = new int *[11];
    for (int i = 0; i < 11; i++)
    {
        temp[i] = new int[1001];
        for (int j = 0; j < 1001; j++)
        {
            temp[i][j] = 0;
        }
    }
    int ans = worker(arr, n, value, temp);
    for (int i = 0; i < 11; i++)
    {
        delete[] temp[i];
    }
    delete[] temp;
    return ans;
}
