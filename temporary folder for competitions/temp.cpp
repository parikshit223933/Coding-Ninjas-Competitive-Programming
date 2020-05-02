#include <iostream>
#include <unordered_map>
#include <vector>
#include<utility>
#include <limits.h>
#include <algorithm>
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
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
    } //I have to work upon those places where there is 1 in the boolean array
    //put all those elements from arr where there is 1 corresponding to boolean array to a vector
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (boolean[i])
        {
            v.push_back(arr[i]);
        }
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