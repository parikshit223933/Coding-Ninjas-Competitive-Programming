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

void handleLeft(char *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != '-')
        {
            if (arr[i] == 'A')
            {
                for (int j = 0; j < i; j++)
                {
                    arr[j] = 'A';
                }
            }
            else
                return;
        }
    }
}
void handleRight(char *arr, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != '-')
        {
            if (arr[i] == 'B')
            {
                for (int j = n - 1; j > i; j--)
                {
                    arr[j] = 'B';
                }
            }
            else
                return;
        }
    }
}

void print(char *arr, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

void solve(char *arr, int n)
{
    handleLeft(arr, n);
    handleRight(arr, n);

    int start = 0;
    int end = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != '-')
        {
            start = i;
            break;
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] != '-')
        {
            end = i;
            break;
        }
    }

    for (int i = start; i < end; i++)
    {
        if (arr[i + 1] == '-' && i + 1 < n)
        {
            int j = i + 1;
            while (arr[j] == '-')
            {
                j++;
            }
            int initial_j_pos = j - 1;
            while (j - i > 1)
            {
                char left = arr[i];
                char right = arr[j];
                if (j - i == 2)
                {
                    if (left == 'B' && right == 'A')
                    {
                        i++;
                        continue;
                    }
                    else if (left == 'A' && right == 'B')
                    {
                        i++;
                        continue;
                    }
                    else if (left == 'A' && right == 'A')
                    {
                        i++;
                        arr[i] = 'A';
                        continue;
                    }
                    else if (left == 'B' && right == 'B')
                    {
                        i++;
                        arr[i] = 'B';
                        continue;
                    }
                    else
                    {
                        i++;
                        j--;
                    }
                }
                else
                {
                    if (left == 'B')
                    {
                        i++;
                        arr[i] = 'B';
                    }
                    if (right == 'A')
                    {
                        j--;
                        arr[j] = 'A';
                    }
                    i++;
                    j--;
                }
            }
            i = initial_j_pos;
        }
        else
        {
            continue;
        }
    }
    unordered_map<char, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    if (mp['A'] > mp['B'])
    {
        cout << 'A';
        return;
    }
    else if (mp['B'] > mp['A'])
    {
        cout << 'B';
        return;
    }
    else
    {
        cout << "Coalition government";
        return;
    }
}

int32_t main()
{
    int n;
    cin >> n;
    char *arr = new char[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solve(arr, n);
}