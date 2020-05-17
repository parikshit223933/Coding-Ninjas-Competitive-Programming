#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <unordered_set>
#include <vector>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
using namespace std;
string ans = "";
bool balancer_is_full(int **balancer, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (balancer[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}
void reset_balancer(int **balancer, char current_character, int r, int c, char**arr)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(arr[i][j]==current_character)
            {
                balancer[i][j]=0;
            }
        }
    }
}
void fill_balancer(int **balancer, int r, int c, char **arr, char current_character)
{
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            if(arr[i][j]==current_character)
            {
                balancer[i][j]=1;
            }
        }
    }
}
bool is_stable(int **balancer, int r, int c, char current_character, char**arr)
{
    fill_balancer(balancer, r, c, arr, current_character);
    for(int j=0; j<c; j++)
    {
        for(int i=1; i<r; i++)
        {
            if(balancer[i][j]==0 && balancer[i-1][j]==1)
            {
                return false;
            }
        }
    }
    return true;
}
bool possible(char **arr, int r, int c, int **balancer, unordered_set<char> uniques)
{
    for (auto unique : uniques)
    {
        char current_character = unique;
        if (is_stable(balancer, r, c, current_character, arr))
        {
            unordered_set<char> new_set_of_uniques = uniques;
            new_set_of_uniques.erase(current_character);
            if (possible(arr, r, c, balancer, new_set_of_uniques))
            {
                ans += current_character;
                return true;
            }
            else
            {
                reset_balancer(balancer, current_character, r, c, arr);
            }
        }
    }
    if (balancer_is_full(balancer, r, c))
    {
        return true;
    }
    return false;
}
void possibility(char **arr, int r, int c)
{
    unordered_set<char> uniques;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            uniques.insert(arr[i][j]);
        }
    }
    int **balancer = new int *[r];
    for (int i = 0; i < r; i++)
    {
        balancer[i] = new int[c];
        for (int j = 0; j < c; j++)
        {
            balancer[i][j] = 0;
        }
    }

    if (possible(arr, r, c, balancer, uniques))
    {
        cout << ans;
    }
    else
    {
        cout << -1;
    }
}
int main()
{
    int t;
    cin >> t;
    for (int p = 1; p <= t; p++)
    {
        int r, c;
        cin >> r >> c;
        char **arr = new char *[r];
        for (int i = 0; i < r; i++)
        {
            arr[i] = new char[c];
            for (int j = 0; j < c; j++)
            {
                cin >> arr[i][j];
            }
        }
        cout << "Case #" << p << ": ";
        possibility(arr, r, c);
        cout << endl;
    }
}