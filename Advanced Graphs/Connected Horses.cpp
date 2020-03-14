#include<iostream>
#include<vector>
#include<unordered_set>
#include<utility>
#include<map>
#include<iterator>
using namespace std;
bool isedged(int **grid, int n, int m, int i, int j, map<pair<int, int>, unordered_set<pair<int, int>>> &edges, bool call_by_recursion=false)
{
    if(i<0||j<0||i>=n||j>=m)
    {
        return false;
    }
    if(call_by_recursion)
    {
        return true;
    }
    if(isedged(grid, n, m, i-1, j, edges, true) && grid[i-1][j]==1)//up
    {
        edges[make_pair(i-1, j)].insert(make_pair(i, j));
        edges[make_pair(i, j)].insert(make_pair(i-1, j));
    }
    if(isedged(grid, n, m, i, j-1, edges, true) && grid[i][j-1]==1)//left
    {
        edges[make_pair(i, j-1)].insert(make_pair(i, j));
        edges[make_pair(i, j)].insert(make_pair(i, j-1));
    }
    if(isedged(grid, n, m, i+1, j, edges, true) && grid[i+1][j]==1)//down
    {
        edges[make_pair(i+1, j)].insert(make_pair(i, j));
        edges[make_pair(i, j)].insert(make_pair(i+1, j));
    }
    if(isedged(grid, n, m, i, j+1, edges, true) && grid[i][j+1]==1)//right
    {
        edges[make_pair(i, j+1)].insert(make_pair(i, j));
        edges[make_pair(i, j)].insert(make_pair(i, j+1));
    }
    if(isedged(grid, n, m, i-1, j-1, edges, true) && grid[i-1][j-1]==1)//upper_left
    {
        edges[make_pair(i-1, j-1)].insert(make_pair(i, j));
        edges[make_pair(i, j)].insert(make_pair(i-1, j-1));
    }
    if(isedged(grid, n, m, i+1, j+1, edges, true) && grid[i+1][j+1]==1)//bottom_right
    {
        edges[make_pair(i+1, j+1)].insert(make_pair(i, j));
        edges[make_pair(i, j)].insert(make_pair(i+1, j+1));
    }
    if(isedged(grid, n, m, i-1, j+1, edges, true) && grid[i-1][j+1]==1)//top_right
    {
        edges[make_pair(i-1, j+1)].insert(make_pair(i, j));
        edges[make_pair(i, j)].insert(make_pair(i-1, j+1));
    }
    if(isedged(grid, n, m, i+1, j-1, edges, true) && grid[i+1][j-1]==1)//bottom_left
    {
        edges[make_pair(i+1, j-1)].insert(make_pair(i, j));
        edges[make_pair(i, j)].insert(make_pair(i+1, j-1));
    }
    return true;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, q;
        cin>>n>>m>>q;
        int **grid=new int *[n];
        for(int i=0; i<n; i++)
        {
            grid[i]=new int [m];
            for(int j=0; j<m; j++)
            {
                grid[i][j]=0;
            }
        }
        map<pair<int, int>, unordered_set<pair<int, int>>> edges;
        while(q--)
        {
            int x, y;
            cin>>x>>y;
            grid[x][y]=1;
            if(isedged(grid, n, m, x, y, edges))
            {
                //do nothing, because that boolean function handles everything.
            }
        }
    }
}