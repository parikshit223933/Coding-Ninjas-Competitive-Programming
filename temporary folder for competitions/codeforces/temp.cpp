#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
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

int minimum_moves(int *arr, int n)
{
    unordered_map<string, int>m;
    for(int i=0; i<n; i++)
    {
        if(arr[i]%2!=0)
        {
            m["odd"]++;
        }
        else
        {
            m["even"]++;
        }
    }
    int number_of_odd_indices;
    int number_of_even_indices;
    if(n%2==0)
    {
        number_of_even_indices=n/2;
        number_of_odd_indices=n/2;
    }
    else
    {
        number_of_even_indices=(n/2)+1;
        number_of_odd_indices=n/2;
    }
    if(number_of_even_indices!=m["even"]||number_of_odd_indices!=m["odd"])
    {
        return -1;
    }


    int misplaced_evens=0;
    int misplaced_odds=0;
    for(int i=0; i<n; i++)
    {
        if(i%2==0&&arr[i]%2!=0)
        {
            misplaced_odds++;
        }
        else if(i%2!=0&&arr[i]%2==0)
        {
            misplaced_evens++;
        }
    }
    return misplaced_evens;
    
}

int main()
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
        cout<<minimum_moves(arr, n)<<endl;
    }    
}