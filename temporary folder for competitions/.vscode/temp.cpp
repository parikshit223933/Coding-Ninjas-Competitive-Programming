#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
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

bool check(int* arr, int n, int count5, int count10, int count15)
{
    if (n <= 0)
    {
        if (count5 >= 0 && count10 >= 0 && count15 >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if (arr[0] == 5)
    {
        return true && check(arr + 1, n - 1, count5 + 1, count10, count15);
    }
    else if (arr[0] == 10)
    {
        if (count5 > 0)
            return true && check(arr + 1, n - 1, count5 - 1, count10 + 1, count15);
        else
            return false;
    }
    else if (arr[0] == 15)
    {
        bool option1 = check(arr + 1, n - 1, count5 - 2, count10, count15 + 1);
        bool option2 = check(arr + 1, n - 1, count5, count10 - 1, count15 + 1);

        if (count5 >= 2)
            option1 = option1 & true;
        else
            option1 = false;

        if (count10 > 0)
            option2 = option2 & true;
        else
            option2 = false;

        return option1 || option2;
    }
    return true;
}

string isPossible(int* arr, int n)
{
    if (arr[0] != 5)
    {
        return "NO";
    }

    if (check(arr, n, 0, 0, 0))
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << isPossible(arr, n) << endl;
    }
}