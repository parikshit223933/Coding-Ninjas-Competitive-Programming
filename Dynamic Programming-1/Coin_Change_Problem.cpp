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
