#include <algorithm>
#include <iostream>
#include <utility>
#include <limits.h>
#include <vector>
#include <unordered_map>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
using namespace std;
struct bots
{
    int index;
    char direction;
};
bool arr_is_empty(int** arr, int n)
{
    bool check = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; i < n; j++)
        {
            if (arr[i][j] != 0)
            {
                check = false;
                return check;
            }
        }
    }
    return true;
}
void create_backup(int** backup_array, int** arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            backup_array[i][j] = arr[i][j];
        }
    }
}
void restore_original_array(int** arr, int** backup_array, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = backup_array[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        delete[]backup_array[i];
    }
    delete[]backup_array;
}
void fire(int** arr, int n, bots way, int f)
{
    char dir = way.direction;
    int idx = way.index;
    if (dir == 'L')
    {
    for (int i = 0; i < n; i++)
    {
        if (arr[idx][i] <= f)
        {
            f -= arr[idx][i];
            arr[idx][i] = 0;
        }
        else
        {
            return;
        }
    }
    }
    else if (dir == 'R')
    {
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[idx][i] <= f)
        {
            f -= arr[idx][i];
            arr[idx][i] = 0;
        }
        else
        {
            return;
        }
    }
    }
    else if (dir == 'U')
    {
    for (int i = 0; i < n; i++)
    {
        if (arr[i][idx] <= f)
        {
            f -= arr[i][idx];
            arr[i][idx] = 0;
        }
        else
        {
            return;
        }
    }
    }
    else if (dir == 'D')
    {
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i][idx] <= f)
        {
            f -= arr[i][idx];
            arr[i][idx] = 0;
        }
        else
        {
            return;
        }
    }
    }
}
bool no_virus_is_there_in_that_line(int** arr, int n, bots way)
{
    char dir = way.direction;
    int idx = way.index;
    if (dir == 'L')
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[idx][i] != 0)
            {
                return false;
            }
        }
    }
    else if (dir == 'R')
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[idx][i] != 0)
            {
                return false;
            }
        }
    }
    else if (dir == 'U')
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i][idx] != 0)
            {
                return false;
            }
        }
    }
    else if (dir == 'D')
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i][idx] != 0)
            {
                return false;
            }
        }
    }
    return true;
}
bool shots(int** arr, int n, int k, int f, bots* ways)
{
    if ((!arr_is_empty(arr, n) && k <= 0) || (k < 0))
    {
        return false;
    }
    if (k >= 0 && arr_is_empty(arr, n))
    {
        return true;
    }
    for (int i = 0; i < 4 * n; i++)
    {
        if (no_virus_is_there_in_that_line(arr, n, ways[i]))
        {
            continue;
        }
        int** backup_array = new int* [n];
        for (int i = 0; i < n; i++)
        {
            backup_array[i] = new int[n];
        }
        create_backup(backup_array, arr, n);
        fire(arr, n, ways[i], f);
        if (shots(arr, n, k - 1, f, ways))
        {
            return true;
        }
        else
        {
            restore_original_array(arr, backup_array, n);
            continue;
        }
    }
    return false;
}
void solver(int** arr, int n, int k, int f)
{
    bots* ways = new bots[4 * n];
    for (int i = 0; i < n; i++)
    {
        for (auto dir : { 'L', 'R', 'U', 'D' })
        {
            ways[i].direction = dir;
            ways[i].index = i;
        }
    }
    int number_of_shots = shots(arr, n, k, f, ways);
    cout << shots(arr, n, k, f, ways) << endl;
}
int main()
{
    int n, f;
    cin >> n >> f;
    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int k;
    cin >> k;
    solver(arr, n, k, f);
}