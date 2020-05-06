#include <algorithm>
#include <iostream>
#include <utility>
#include <iterator>
#include <limits.h>
#include <vector>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
using namespace std;
vector<pair<char, int>> ans;
int complete_sum_of_array = 0;
struct bots
{
    int index;
    char direction;
};
bool arr_is_empty(int **arr, int n)
{
    if (complete_sum_of_array == 0)
        return true;
    return false;
}
void create_backup(int **backup_array, int **arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            backup_array[i][j] = arr[i][j];
        }
    }
}
void restore_original_array(int **arr, int **backup_array, int n)
{
    int old_sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = backup_array[i][j];
            old_sum += arr[i][j];
        }
    }
    complete_sum_of_array = old_sum;
}
void fire(int **arr, int n, bots way, int f)
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
                complete_sum_of_array -= arr[idx][i];
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
                complete_sum_of_array -= arr[idx][i];
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
                complete_sum_of_array -= arr[i][idx];
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
                complete_sum_of_array -= arr[i][idx];
                arr[i][idx] = 0;
            }
            else
            {
                return;
            }
        }
    }
}
bool no_virus_is_there_in_that_line(int **arr, int n, bots way)
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
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool shots(int **arr, int n, int k, int f, vector<bots> &ways)
{
    if ((!arr_is_empty(arr, n) && k <= 0) || (k < 0))
    {
        return false;
    }
    if (k >= 0 && arr_is_empty(arr, n))
    {
        return true;
    }
    int **backup_array = new int *[n];
    for (int j = 0; j < n; j++)
    {
        backup_array[j] = new int[n];
    }
    for (int i = 0; i < 4 * n; i++)
    {
        if (no_virus_is_there_in_that_line(arr, n, ways[i]))
        {
            continue;
        }
        /* creating a backup */
        create_backup(backup_array, arr, n);
        /* firing the laser */
        fire(arr, n, ways[i], f);
        /* asking recursion for the answer ahead */
        if (shots(arr, n, k - 1, f, ways))
        {
            ans.push_back(make_pair(ways[i].direction, ways[i].index));
            return true;
        }
        else
        {
            restore_original_array(arr, backup_array, n);
            continue;
        }
    }
    for (int i = 0; i < n; i++)
    {
        delete[] backup_array[i];
    }
    delete[] backup_array;
    return false;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void solver(int **arr, int n, int k, int f)
{
    vector<bots> ways;
    for (int i = 0; i < n; i++)
    {
        for (auto dir : {'L', 'R', 'U', 'D'})
        {
            bots b;
            b.direction = dir;
            b.index = i;
            ways.push_back(b);
        }
    }
    if (shots(arr, n, k, f, ways))
    {
        cout << ans.size() << endl;
        for (int i = ans.size() - 1; i >= 0; i--)
        {
            cout << ans[i].first << " " << ans[i].second + 1 << endl;
        }
    }
    else
    {
        cout << -1 << endl;
    }
    for (int i = 0; i < n; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
}
int main()
{
    fast;
    int n, f;
    cin >> n >> f;
    int **arr = new int *[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
            complete_sum_of_array += arr[i][j];
        }
    }
    int k;
    cin >> k;
    solver(arr, n, k, f);
}