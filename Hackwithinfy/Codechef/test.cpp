#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, k;
        cin>>n>>m>>k;
        int **arr=new int* [n];
        for(int i=0; i<n; i++)
        {
            arr[i]=new int [k];
            for(int j=0; j<k; j++)
            {
                cin>>arr[i][j];
            }
        }



        

    }
}