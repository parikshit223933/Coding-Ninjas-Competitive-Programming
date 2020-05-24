/* #include <algorithm>
#include <iostream>
#include <utility>
#include<string>
#include <iterator>
#include <limits.h>
#include <vector>
#include<unordered_map>
#include<unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
using namespace std;
bool checker(int *arr, int n)
{
    unordered_map<int, int> m;
    for(int i=0; i<n; i++)
    {
        m[arr[i]]++;
    }
    unordered_set<int>keys;
    unordered_set<int>values;
    for(auto i:m)
    {
        keys.insert(i.first);
        values.insert(i.second);
    }
    if(keys.size()!=values.size())
    {
        return false;
    }
    



    int *arr_temp=new int [1001];
    bool *visited=new bool[1001];
    for(int i=0; i<1001; i++)
    {
        arr_temp[i]=0;
        visited[i]=false;
    }
    arr_temp[arr[0]]++;
    for(int i=1; i<n; i++)
    {
        arr_temp[arr[i]]++;
        if(arr[i]!=arr[i-1])
        {
            visited[arr[i-1]]=true;
        }
        if(visited[arr[i-1]])
        {
            if(m[arr[i-1]]!=arr_temp[arr[i-1]])
            {
                return false;
            }
        }
    }
    return true;
}
int32_t main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *arr=new int [n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        if(checker(arr, n))
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        
    }
} */