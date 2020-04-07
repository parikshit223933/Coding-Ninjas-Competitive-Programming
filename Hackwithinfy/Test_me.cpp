#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>*egdes=new vector<int>[n];
        for(int i=0; i<n-1; i++)
        {
            int j, k;
            cin>>j>>k;
            edges[j-1].push_back(k-1);
            edges[k-1].push_back(j-1);
        }
    }
}