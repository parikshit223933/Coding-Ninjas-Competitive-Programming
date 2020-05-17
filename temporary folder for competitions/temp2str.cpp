#include <algorithm>
#include <iostream>
#include <utility>
#include<string>
#include <iterator>
#include <limits.h>
#include <vector>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
using namespace std;

int countdowns(int *arr, int n, int k)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        int itr=k;
        if(arr[i]==k)
        {
            while(arr[i]==k && itr!=1)
            {
                i++;
                itr--;
            }
            if(itr==1)
            {
                count++;
            }
        }
    }
    return count;
}
int main()
{
    fast;
    int t;
    cin >> t;
    for (int p = 1; p <= t; p++)
    {
        int n, k;
        cin >> n >> k;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << "Case #" << p << ": " << countdowns(arr, n, k) << endl;
    }
}