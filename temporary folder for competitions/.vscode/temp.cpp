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

void print(int**arr, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

int **get_array(int n)
{
    int **arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
    }
    int count = 1;
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i <= j; i++)
        {
            arr[i][j] = count;
            count++;
        }
        for (int k = j - 1; k >= 0; k--)
        {
            arr[j][k]=count;
            count++;
        }
    }
    return arr;
}

int main()
{
    fast;
    int **arr=get_array(1000);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        print(arr, n);
    }
    delete[]arr;
}