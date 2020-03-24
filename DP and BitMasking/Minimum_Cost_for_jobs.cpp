#include<iostream>
#include<climits>
using namespace std;
int min_cost(int cost[4][4], int n, int p, int mask)
{
    if(p>=n)
    {
        return 0;
    }
    int minimum=INT_MAX;
    // what all jobs can i assign to pth person
    for(int i=0; i<n; i++)
    {
        if(!(mask&(1<<i)))
        {
            int ans=min_cost(cost, n, p+1, mask|(1<<i))+cost[p][i];
            if(ans<minimum)
            {
                minimum=ans;
            }
        }
    }
    return minimum;
}
int main()
{
    int cost[][4]={{10, 2, 6, 5}, {1, 15, 12, 8}, {7, 8, 9, 3}, {15, 13, 4, 10}};
    cout<<min_cost(cost, 4/*number of persons*/, 0/*0th person*/, 0/*mask*/)<<endl;
}