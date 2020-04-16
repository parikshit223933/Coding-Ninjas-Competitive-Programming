/* Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29 */





#include <iostream>
#include <algorithm>
using namespace std;
int kadane_sum(int *arr, int n)
{
    int current_sum = 0;
    int best_sum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        current_sum += arr[i];
        if (best_sum < current_sum)
        {
            best_sum = current_sum;
        }
        if (current_sum < 0)
        {
            current_sum = 0;
        }
    }
    return best_sum;
}
int max_sum(int **arr, int n, int m)
{
    int sum = INT_MIN;
    for (int left = 0; left < m; left++)
    {
        int *temp = new int[n]();
        for (int right = left; right < m; right++)
        {
            for (int i = 0; i < n; i++)
            {
                temp[i] += arr[i][right];
            }
            sum = max(sum, kadane_sum(temp, n));
        }
    }
    return sum;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << max_sum(arr, n, m) << endl;
}