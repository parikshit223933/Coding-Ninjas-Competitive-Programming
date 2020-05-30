#include <algorithm>
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
bool checker(int *arr, int p, int n)
{
    int total_sum=0;
    for(int i=0; i<n; i++)
    {
        total_sum+=p*arr[i];
    }
    return (total_sum>(24*5));
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n=5;
        int *arr=new int [n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        int p;
        cin>>p;
        if(checker(arr, p, n))
        {
            cout<<"Yes"<<endl;
        }
        else
        {
            cout<<"No"<<endl;
        }
    }
}