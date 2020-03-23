#include <iostream>
#include <algorithm>
using namespace std;

int strength(int **arr, int r, int c)
{
    int **temp = new int *[r];
    for (int i = 0; i < r; i++)
    {
        temp[i] = new int[c]();
    }
    temp[r - 1][c - 1] = 1;
    temp[r - 2][c - 1] = 1;
    temp[r - 1][c - 2] = 1;

    for (int i = c - 3; i >= 0; i--)
    {
        if (arr[r - 1][i + 1] < 0)
        {
            temp[r - 1][i] = temp[r - 1][i + 1] - arr[r - 1][i + 1];
        }
        else
        {
            temp[r - 1][i] = max(1, temp[r - 1][i + 1] - arr[r - 1][i + 1]);
        }
    }
    for (int i = r - 3; i >= 0; i--)
    {
        if (arr[i + 1][c - 1] < 0)
        {
            temp[i][c - 1] = temp[i + 1][c - 1] - arr[i + 1][c - 1];
        }
        else
        {
            temp[i][c - 1] = max(1, temp[i + 1][c - 1] - arr[i + 1][c - 1]);
        }
    }
    for (int i = r - 2; i >= 0; i--)
    {
        for (int j = c - 2; j >= 0; j--)
        {
            int down;
            int right;
            if (arr[i + 1][j] < 0)
            {
                down = temp[i + 1][j] - arr[i + 1][j];
            }
            else
            {
                down = max(1, temp[i + 1][j] - arr[i + 1][j]);
            }
            if (arr[i][j + 1] < 0)
            {
                right = temp[i][j + 1] - arr[i][j + 1];
            }
            else
            {
                right = max(1, temp[i][j + 1] - arr[i][j + 1]);
            }
            temp[i][j] = min(down, right);
        }
    }
    int ans = temp[0][0];
    for (int i = 0; i < r; i++)
    {
        delete[] temp[i];
    }
    delete[] temp;
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        int **arr = new int *[r];
        for (int i = 0; i < r; i++)
        {
            arr[i] = new int[c];
            for (int j = 0; j < c; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << strength(arr, r, c) << endl;
    }
}