#include <iostream>
#include<algorithm>
using namespace std;
struct event
{
    int first, second, index;
};
bool sorter(event e1, event e2)
{
    return e1.second<e2.second;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n+1];
    for (int i = 1; i < n+1; i++)
    {
        cin>>arr[i];
    }
    int q;
    cin>>q;
    event*query=new event[q];
    for(int i=0; i<n; i++)
    {
        cin>>query[i].first>>query[i].second;
        query[i].index=i;
    }
    sort(query, query+q, sorter);
    int *bit =new int [n+1];
    int *ans=new int [q];
    
    int total
    return 0;
}