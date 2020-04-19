/* Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. A k-query is a triple (i, j, k) (1 ≤ i ≤ j ≤ n). For each k-query (i, j, k), you have to return the number of elements greater than k in the subsequence ai, ai+1, ..., aj.
Input Format
Line 1: n (1 ≤ n ≤ 30000).

Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^9).

Line 3: q (1 ≤ q ≤ 200000), the number of k- queries.

In the next q lines, each line contains 3 numbers i, j, k representing a k-query (1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ 10^9).
Output Format
For each k-query (i, j, k), print the number of elements greater than k in the subsequence ai, ai+1, ..., aj in a single line.
Sample Input
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 
Sample Output
2
0
3  */



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