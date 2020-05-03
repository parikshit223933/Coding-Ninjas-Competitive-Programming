#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <limits.h>
#include <algorithm>
#define int long long int
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
void solve(int **arr, int n, int f, int k)
{
    char dirs[]={'L', 'R', 'U', 'D'};
    vector<string>possibilities;
    for(auto d:dirs)
    {
        for(int i=0; i<n; i++)
        {
            
        }
    }
}
int32_t main()
{
    int n, f;
    cin>>n>>f;
    int **arr=new int *[n];
    for(int i=0; i<n; i++)
    {
        arr[i]=new int [n];
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }
    int k;
    cin>>k;
    solve(arr, n, f, k);
}