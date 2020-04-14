#include <iostream>
#include <climits>
#include <algorithm>
#include <unordered_map>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

#define endl '\n'
using namespace std;
int solve(int *arr, int n)
{
    if (n < 2)
    {
        return 0;
    }
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    int maximum_frequency = INT_MIN;
    int number_of_unique_elements = 0;
    for (auto i : m)
    {
        if (i.second > maximum_frequency&& i.second!=1)
        {
            maximum_frequency = i.second;
        }
        if (i.second == 1)
        {
            number_of_unique_elements++;
        }
    }
    if(maximum_frequency<0)
    {
        maximum_frequency=0;
    }
    if(maximum_frequency==0)
    {
        return 1;
    }
    if(number_of_unique_elements==1)
    {
        return 2;
    }
    return min(maximum_frequency, number_of_unique_elements);
}
int32_t main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << solve(arr, n) << endl;
    }
}