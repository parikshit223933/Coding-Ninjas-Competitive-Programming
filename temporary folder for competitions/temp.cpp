#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <limits.h>
#include <algorithm>
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
struct triplet
{
    int a, b, c;
};
void right_shift(int *arr, int left, int mid, int right)
{
    int temp_left = arr[left];
    int temp_mid = arr[mid];
    int temp_right = arr[right];

    arr[left] = temp_right;
    arr[mid] = temp_left;
    arr[right] = temp_mid;
}
void performer(int *arr, int n, int k)
{
    int *arr2 = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr[i];
    }
    sort(arr2, arr2 + n); //sorted
    bool *boolean = new bool[n];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr2[i])
        {
            boolean[i] = true;
        }
        else
        {
            boolean[i] = false;
        }
    }
    vector<triplet> ans;
    while (k--)
    {
        int maximum_element = INT_MIN;
        int mid = 0;
        for (int i = 0; i < n; i++)
        {
            if (boolean[i])
            {
                if (arr[i] > maximum_element)
                {
                    maximum_element = arr[i];
                    mid = i;
                }
            }
        }

        int right = n - 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (boolean[i])
            {
                right = i;
            }
        }

        int left = mid;
        int itr;
        for (int itr = mid - 1; itr >= 0; itr--)
        {
            if (boolean[itr])
            {
                left = itr;
            }
        }
        if (itr < 0)
        {
            cout << -1 << endl;
            return;
        }

        right_shift(arr, left, mid, right);

        boolean[right] = 0;
        if (arr[left] == arr2[left])
        {
            boolean[left] = 0;
        }
        if (arr[mid] == arr2[mid])
        {
            boolean[mid] = 0;
        }
        triplet temp;
        temp.a = left;
        temp.b = mid;
        temp.c = right;
        ans.push_back(temp);
    }
    bool check_in_boolean = false;
    for (int i = 0; i < n; i++)
    {
        if (boolean[i])
        {
            check_in_boolean = true;
            break;
        }
    }
    if (check_in_boolean)
    {
        cout << -1 << endl;
        return;
    }
    //else
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i.a << " " << i.b << " " << i.c << endl;
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
        int k;
        cin >> n >> k;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        performer(arr, n, k);
    }
    return 0;
}