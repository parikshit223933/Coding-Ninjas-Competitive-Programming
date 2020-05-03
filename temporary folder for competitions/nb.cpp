#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <limits.h>
#include <algorithm>
#define int long long int
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
struct possibility
{
    char direction;
    int index;
};
bool arr_is_empty(int **arr, int n)
{
    bool check = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}
void apply_operation(int **arr, int n, int f, char direction, int index)
{
    if (direction == 'L')
    {
        int i=0;
        while(f>=arr[index][i])
        {
            int value=arr[index][i];
            arr[index][i]-=value;
            f-=value;
            i++;
        }
    }
    else if (direction == 'R')
    {
        int i=n-1;
        while(f>=arr[index][i])
        {
            int value=arr[index][i];
            arr[index][i]-=value;
            f-=value;
            i--;
        }
    }
    else if (direction == 'U')
    {
        int i=0;
        while(f>=arr[i][index])
        {
            int value=arr[i][index];
            arr[i][index]-=value;
            f-=value;
            i++;
        }
    }
    else if (direction == 'D')
    {
        int i=n-1;
        while(f>=arr[i][index])
        {
            int value=arr[i][index];
            arr[i][index]-=value;
            f-=value;
            i--;
        }
    }
}
int laser(int **arr, int n, int f, int k, possibility *poss, int n_poss)
{
    if (n_poss == 0 || k == 0)
    {
        return INT_MAX;
    }
    
    int count=0;
    int option1=
}
void solve(int **arr, int n, int f, int k)
{
    vector<possibility> poss;
    char dirs[] = {'L', 'R', 'U', 'D'};
    for (auto d : dirs)
    {
        for (int i = 0; i < n; i++)
        {
            possibility p;
            p.direction = d;
            p.index = i;
            poss.push_back(p);
        }
    }
    int n_poss = poss.size();
    possibility *possibility_array = new possibility[n_poss];
    for (int i = 0; i < n_poss; i++)
    {
        possibility_array[i] = poss[i];
    }
    int minimum_shots = laser(arr, n, f, k, possibility_array, n_poss);
    cout << minimum_shots << endl;
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
    solve(arr, n, f, k);
}