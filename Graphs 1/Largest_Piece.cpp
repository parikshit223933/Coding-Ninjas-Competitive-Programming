/* Its Gary's birthday today and he has ordered his favourite square cake consisting of '0's and '1's . But Gary wants the biggest piece of '1's and no '0's . A piece of cake is defined as a part which consist of only '1's, and all '1's share an edge with eachother on the cake. Given the size of cake N and the cake , can you find the size of the biggest piece of '1's for Gary ?
Constraints :
1<=N<=50
Input Format :
Line 1 : An integer N denoting the size of cake 
Next N lines : N characters denoting the cake
Output Format :
Size of the biggest piece of '1's and no '0's
Sample Input :
2
11
01
Sample Output :
3 */





#include <iostream>
using namespace std;
int count_ones(int **arr, int n, int i, int j, bool **visited)
{
    int count = 1;
    if (i > 0 && !visited[i - 1][j] && arr[i - 1][j] == 1) //up
    {
        visited[i - 1][j] = true;
        count += count_ones(arr, n, i - 1, j, visited);
    }
    if (j > 0 && !visited[i][j - 1] && arr[i][j - 1] == 1) //left
    {
        visited[i][j - 1] = true;
        count += count_ones(arr, n, i, j - 1, visited);
    }
    if (i < n - 1 && !visited[i + 1][j] && arr[i + 1][j] == 1) //down
    {
        visited[i + 1][j] = true;
        count += count_ones(arr, n, i + 1, j, visited);
    }
    if (j < n - 1 && !visited[i][j + 1] && arr[i][j + 1] == 1) //right
    {
        visited[i][j + 1] = true;
        count += count_ones(arr, n, i, j + 1, visited);
    }
    return count;
}

int solve(int n, char cake[NMAX][NMAX])
{
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = cake[i][j] - '0';
        }
    }

    int maximum = 0;
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 1)
            {
                visited[i][j] = true;
                int current_maximum = count_ones(arr, n, i, j, visited);
                if (current_maximum > maximum)
                {
                    maximum = current_maximum;
                }
                for (int p = 0; p < n; p++)
                {
                    for (int q = 0; q < n; q++)
                    {
                        visited[p][q] = false;
                    }
                }
            }
        }
    }
    return maximum;
}