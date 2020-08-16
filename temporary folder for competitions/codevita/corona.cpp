#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long int
#define uint unsigned long long int
using namespace std;

struct position
{
    int x;
    int y;
    string direction;
    bool attempt1;
    bool attempt2;
};
char** invert(char** arr, int n, int m)
{
    char** new_arr = new char* [n];
    for (int i = n - 1; i >= 0; i--)
    {
        new_arr[n - i - 1] = new char[m];
        for (int j = 0; j < m; j++)
        {
            new_arr[n - i - 1][j] = arr[i][j];
        }
    }
    return new_arr;
}
void print(char** arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j];
        }
        cout << endl;
    }
}
position move(char** arr, int n, int m, position current)
{
    position newP;
    if (arr[current.x][current.y] == 'c')
    {
        newP.attempt1 = current.attempt1;
        newP.attempt2 = current.attempt2;
        if (current.direction == "top left")
        {
            newP.direction = "bottom left";
            newP.x = current.x + 1;
            newP.y = current.y - 1;
        }
        else if (current.direction == "bottom left")
        {
            newP.direction = "bottom right";
            newP.x = current.x + 1;
            newP.y = current.y + 1;
        }
        else if (current.direction == "top right")
        {
            newP.direction = "top left";
            newP.x = current.x - 1;
            newP.y = current.y - 1;
        }
        else if (current.direction == "bottom right")
        {
            newP.direction = "top right";
            newP.x = current.x - 1;
            newP.y = current.y + 1;
        }
    }
    else if (arr[current.x][current.y] == 'a')
    {
        newP.attempt1 = current.attempt1;
        newP.attempt2 = current.attempt2;
        if (current.direction == "top left")
        {
            newP.direction = "top right";
            newP.x = current.x - 1;
            newP.y = current.y + 1;
        }
        else if (current.direction == "bottom left")
        {
            newP.direction = "top left";
            newP.x = current.x - 1;
            newP.y = current.y - 1;
        }
        else if (current.direction == "top right")
        {
            newP.direction = "bottom right";
            newP.x = current.x + 1;
            newP.y = current.y + 1;
        }
        else if (current.direction == "bottom right")
        {
            newP.direction = "bottom left";
            newP.x = current.x + 1;
            newP.y = current.y - 1;
        }
    }
    else if (arr[current.x][current.y] == '.')
    {
        newP.attempt1 = current.attempt1;
        newP.attempt2 = current.attempt2;
        if (current.direction == "top left")
        {
            newP.x = current.x - 1;
            newP.y = current.y - 1;
        }
        else if (current.direction == "bottom left")
        {
            newP.x = current.x + 1;
            newP.y = current.y - 1;
        }
        else if (current.direction == "top right")
        {
            newP.x = current.x - 1;
            newP.y = current.y + 1;
        }
        else if (current.direction == "bottom right")
        {
            newP.x = current.x + 1;
            newP.y = current.y + 1;
        }
        newP.direction = current.direction;
    }
    else if (arr[current.x][current.y] == '*')
    {
        if (current.attempt1)
        {
            current.attempt2 = true;
            return current;
        }
        else
        {
            current.attempt1 = true;
        }

        newP.attempt1 = current.attempt1;
        newP.attempt2 = current.attempt2;

        if (current.direction == "top left")
        {
            if (current.x == 0)
            {
                newP.direction = "bottom left";
                newP.x = current.x + 1;
                newP.y = current.y - 1;
            }
            else if (current.y == 0)
            {
                newP.direction = "top right";
                newP.x = current.x - 1;
                newP.y = current.y + 1;
            }
        }
        else if (current.direction == "bottom left")
        {
            if (current.x == 8)
            {
                newP.direction = "top left";
                newP.x = current.x - 1;
                newP.y = current.y - 1;
            }
            else if (current.y == 0)
            {
                newP.direction = "bottom right";
                newP.x = current.x + 1;
                newP.y = current.y + 1;
            }
        }
        else if (current.direction == "top right")
        {
            if (current.x == 0)
            {
                newP.direction = "bottom right";
                newP.x = current.x + 1;
                newP.y = current.y + 1;
            }
            else if (current.y == 19)
            {
                newP.direction = "top left";
                newP.x = current.x - 1;
                newP.y = current.y - 1;
            }
        }
        else if (current.direction == "bottom right")
        {
            if (current.x == 8)
            {
                newP.direction = "top right";
                newP.x = current.x - 1;
                newP.y = current.y + 1;
            }
            else if (current.y == 19)
            {
                newP.direction = "bottom left";
                newP.x = current.x + 1;
                newP.y = current.y - 1;
            }
        }
    }
    return newP;
}
void solve(char** arr, int n, int m)
{
    position current;
    current.x = 0;
    current.y = 0;
    current.attempt1 = false;
    current.attempt2 = false;
    current.direction = "bottom right";

    vector<position> v;
    v.push_back(current);
    current.x += 1;
    current.y += 1;
    v.push_back(current);

    while (!current.attempt1 || !current.attempt2)
    {
        current = move(arr, n, m, current);
        v.push_back(current);
    }
    v.pop_back();
    for (auto i : v)
    {
        cout << i.y << " " << i.x << endl;
        if (arr[i.x][i.y] == 'a' || arr[i.x][i.y] == 'c')
        {
            arr[i.x][i.y] = '-';
        }
    }
    char** final_ans = invert(arr, n, m);

    int safe = 0;
    int infected = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (final_ans[i][j] == 'a' || final_ans[i][j] == 'c')
            {
                safe++;
            }
            if (final_ans[i][j] == '-')
            {
                infected++;
            }
        }
    }
    print(final_ans, n, m);
    cout << "safe=" << safe << endl << "infected=" << infected << endl;
}

int32_t main()
{
    int n = 9;
    int m = 20;

    char** arr = new char* [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new char[m];
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    char** new_arr = invert(arr, n, m);
    solve(new_arr, n, m);
}