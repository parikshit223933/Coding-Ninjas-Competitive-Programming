#include <algorithm>
#include <iostream>
#include <utility>
#include <limits.h>
#include <vector>
#include <unordered_map>
#define int long long int
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
bool all_visited(bool *visited, int n)
{
    bool check = true;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] = false)
        {
            check = false;
            return check;
        }
    }
    return check;
}
bool arr_is_empty(int **arr, int n)
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
int **create_backup(int **backup_array, int **arr, int n)
{
    backup_array=new int *[n];
    for(int i=0;i<n; i++)
    {
        for(int j=0; i<n; j++)
        {
            backup_array[i][j]=arr[i][j];
        }
    }
    return backup_array;
}
void restore_original_array(int **arr, int **backup_array, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            arr[i][j]=backup_array[i][j];
        }
    }
}
void fire(int **arr, int n, bots way, int f)
{
    
}
bool shots(int **arr, int n, int k, int f, bots *ways, bool *visited)
{
    if ((all_visited(visited, 4 * n) && !arr_is_empty(arr, n)) || k > 0)
    {
        return false;
    }
    if(k>=0&&arr_is_empty(arr, n))
    {
        return true;
    }
    for (int i = 0; i < 4 * n; i++)
    {
        if (!visited[i])
        {
            visited[i]=true;
            int **backup_array;
            backup_array=create_backup(backup_array, arr, n);
            fire(arr, n, ways[i], f);
            if(shots(arr, n, k, f, ways, visited))
            {
               return true; 
            }
            else
            {
                restore_original_array(arr, backup_array, n);
                visited[i]=false;
                continue;
            }
            
        }
    }
}
void solver(int **arr, int n, int k, int f)
{
    bots *ways = new bots[4 * n];
    for (int i = 0; i < n; i++)
    {
        for (auto dir : {'L', 'R', 'U', 'D'})
        {
            ways[i].direction = dir;
            ways[i].index = i;
        }
    }
    bool *visited = new bool[4 * n];
    for (int i = 0; i < 4 * n; i++)
    {
        visited[i] = false;
    }
    int number_of_shots = shots(arr, n, k, f, ways, visited);
    cout<<shots(arr, n, k, f, ways, visited)<<endl;
}
int32_t main()
{
    int n, f;
    cin >> n >> f;
    int **arr = new int *[n];
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