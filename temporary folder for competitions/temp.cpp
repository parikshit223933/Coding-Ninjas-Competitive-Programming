/* #include <iostream>
#include <vector>
#include<limits.h>
#include <algorithm>
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
void find_answer(int* arr, int n)
{
    vector<vector<int>> final_vector;
    vector<int> temp;
    for (int i = 1; i < n; i++)
    {
        int distance = arr[i] - arr[i - 1];
        if (distance <= 2)
        {
            temp.push_back(arr[i-1]);
        }
        else
        {
            temp.push_back(arr[i-1]);
            final_vector.push_back(temp);
            temp.clear();
        }
    }
    if (arr[n - 1] - arr[n - 2] <= 2)
    {
        temp.push_back(arr[n - 1]);
    }
    if (temp.size() != 0)
    {
        final_vector.push_back(temp);
    }
    else
    {
        temp.push_back(arr[n - 1]);
        final_vector.push_back(temp);
    }
    int minimum=INT_MAX;
    int maximum=INT_MIN;
    for(int i=0; i<final_vector.size(); i++)
    {
        maximum=max(maximum, (int)final_vector[i].size());
        minimum=min(minimum, (int)final_vector[i].size());
    }
    cout<<minimum<<" "<<maximum<<endl;
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
        sort(arr, arr + n);
        find_answer(arr, n);
    }
} */