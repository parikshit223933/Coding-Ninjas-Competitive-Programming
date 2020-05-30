#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
using namespace std;
vector<vector<int>>ans;
bool check_all(int *arr_a, int *arr_b, int n)
{
    for(int i=0; i<n; i++)
    {
        if(arr_a[i]!=arr_b[i])
        {
            return false;
        }
    }
    return true;
}
void caller(int *arr_a, int *arr_b, int n)
{
    if(check_all(arr_a, arr_b, n))
    {
        return;
    }
    int minimum_in_arr_a=INT_MAX;
    int index_of_minimum_in_arr_a=-1;
    for (int i = 0; i < n; i++)
    {
        if(arr_a[i]<minimum_in_arr_a)
        {
            minimum_in_arr_a=arr_a[i];
            index_of_minimum_in_arr_a=i;
        }
    }

    vector<int>temp;
    temp.push_back(index_of_minimum_in_arr_a);
    for(int i=0; i<n; i++)
    {
        if(arr_a[i]>arr_b[i])
        {
            if(arr_a[i]>minimum_in_arr_a)
            {
                arr_a[i]=minimum_in_arr_a;
                temp.push_back(i);
            }
        }
    }
    ans.push_back(temp);
    caller(arr_a, arr_b, n);
}
void check_if_possible(string a, string b, int n)
{
    int *arr_a = new int[n];
    int *arr_b = new int[n];
    for (int i = 0; i < n; i++)
    {
        int int_a = a[i];
        int int_b = b[i];
        arr_a[i] = int_a;
        arr_b[i] = int_b;
    }

    //arr_a
    //arr_b
    caller(arr_a, arr_b, n);

    for(auto i:ans)
    {
        for(auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
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
        string a, b;
        cin >> a >> b;
        check_if_possible(a, b, n);
    }
    return 0;
}