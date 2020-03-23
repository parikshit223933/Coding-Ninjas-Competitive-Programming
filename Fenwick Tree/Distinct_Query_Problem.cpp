#include <iostream>
#include <algorithm>
using namespace std;
struct event
{
    int first, second, index;
};
bool sorter(event e1, event e2)
{
    return e1.second < e2.second;
}
void update(int index, int value, int n, int *bit)
{
    for(; index<=n; index+=index&(-index))
    {
        bit[index]+=value;
    }
}
int value(int index, int *bit)
{
    int count=0;
    for(; index>0; index-=index&(-index))
    {
        count+=bit[index];
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for (int i = 1; i < n + 1; i++)
    {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    event *query = new event[q];
    for (int i = 0; i < n; i++)
    {
        cin >> query[i].first >> query[i].second;
        query[i].index = i;
    }
    sort(query, query + q, sorter);
    int *bit = new int[n + 1];
    int *ans = new int[q];

    int total=0;
    int k=0;
    int *last=new int [1000001];
    for(int i=0; i<1000001; i++)
    {
        last[i]=-1;
    }
    //this is working as a map for us, it determines that, do we have encountered the ith element already or not.
    for(int i=1; i<=n; i++)
    {
        if(last[arr[i]]!=-1)
        {
            update(last[arr[i]], -1, n, bit);
        }
        else
        {
            total++;
        }
        update(i/*for ith index*/, 1/*number of contributions corresponding to ith element*/, n/*how long we can go in BIT*/, bit/*our binary index tree*/);
        last[arr[i]]=i;
        while(k<q && query[k].second==i)
        {
            ans[query[k].index]=total-value(query[k].first-1, bit);
        }
    }
    for(int i=0; i<0; i++)
    {
        cout<<ans[i]<<endl;
    }
    
    
    
    return 0;
}