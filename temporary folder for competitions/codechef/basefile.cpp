#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define ll long long int
using namespace std;

void printer(char **arr)
{
    int n = 8;
    for (int i = n-1; i >=0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

bool checker(int i, int j)
{
    if (i >= 0 && i < 8 && j >= 0 && j < 8)
    {
        return true;
    }
    return false;
}

void configurer(char **arr)
{
    int n = 8;

    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (arr[i][j] == 'X')
            {
                if (checker(i - 1, j - 1) && arr[i - 1][j - 1] != 'X' && !visited[i - 1][j - 1]) //top left
                {
                    return;
                }
                if (checker(i, j - 1) && arr[i][j - 1] != 'X' && !visited[i][j - 1]) //left
                {
                    return;
                }
                if (checker(i - 1, j) && arr[i - 1][j] != 'X' && !visited[i - 1][j]) //top
                {
                    return;
                }
                if (checker(i + 1, j - 1) && arr[i + 1][j - 1] != 'X' && !visited[i + 1][j - 1]) //bottom left
                {
                    return;
                }
                if (checker(i - 1, j + 1) && arr[i - 1][j + 1] != 'X' && !visited[i - 1][j + 1]) //top right
                {
                    return;
                }
                if (checker(i + 1, j + 1) && arr[i + 1][j + 1] != 'X' && !visited[i + 1][j + 1]) //bottom right
                {
                    return;
                }
                if (checker(i, j + 1) && arr[i][j + 1] != 'X' && !visited[i][j + 1]) //right
                {
                    return;
                }
                if (checker(i + 1, j) && arr[i + 1][j] != 'X' && !visited[i + 1][j]) //bottom
                {
                    return;
                }
                arr[i][j] = '.';
                visited[i][j] = true;
            }
        }
    }
}

void solve(int k)
{
    int n = 8;
    char **arr = new char *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new char[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = 'X';
        }
    }
    arr[0][0] = 'O';

    k--;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (k == 0)
            {
                configurer(arr);
                printer(arr);
                return;
            }

            if (i == 0 && j == 0)
            {
                continue;
            }

            arr[i][j] = '.';
            k--;
        }
    }
    configurer(arr);
    printer(arr);
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        solve(k);
    }
}