#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector < pair <int,int > >a;

vector < pair <pair <int,int >,pair <int,int> > > queries;

int ans[200002];
int bit[30002];
int query(int r,int n)
{
    int ans=0;
    while(r>0)
    {
        ans+=bit[r];
        r-=(r&-r);
    }
    return ans;
}
void update(int i,int n)
{
    while(i<=n)
        bit[i]++,i+=(i&-i);

}
int main()
{
    int n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a.push_back({x,i});
    }
    sort(a.begin(),a.end());
    int q;
    cin>>q;
    for(i=1;i<=q;i++)
    {
        int l,r,k;
        cin>>l>>r>>k;
        queries.push_back({{k,i},{l,r}});
    }
    sort(queries.begin(),queries.end(),greater<pair <pair <int,int> ,pair <int,int> > >());
    for(pair <pair <int,int> ,pair <int,int> > p:queries)
    {
        int k = p.first.first;
        i =p.first.second;
        int l= p.second.first;
        int r = p.second.second;
        int j=a.size()-1;
        while(j>=0)
        {
            if(a[j].first>k)
            {
                update(a[j].second,n);
                a.pop_back();
            } 
            else
                break;
            j--;
        }
        int temp= query(r,n)-query(l-1,n);
        ans[i]=temp;
    }
    for(i=1;i<=queries.size();i++)
        cout<<ans[i]<<"\n";//I have tried endl in place of \n and i found out that \n is much more faster than endl
    return 0;
}