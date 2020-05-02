#include <iostream>
#include <unordered_map>
#include <vector>
#include <limits.h>
#include <algorithm>
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
void performer(int *arr, int n, int k)
{
    
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int k;
        cin>>n>>k;
        int *arr=new int [n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        performer(arr, n, k);
    }
    return 0;
}