#include<iostream>
#include<climits>
#include<unordered_map>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define um unordered_map<int, int>
using namespace std;
void choices(int **arr, int n, int m, int k)
{
    um*arr_mapper=new um[n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++)
        {
            arr_mapper[i][k]++;
        }
    }
    for(int i=0; i<n; i++)
    {
        int maximum_frequency_number;
        int maximum_frequency=INT_MIN;
        for(auto j:arr_mapper[i])
        {
            if(j.second>maximum_frequency)
            {
                maximum_frequency=j.second;
                maximum_frequency_number=j.first;
            }
        }
        cout<<maximum_frequency_number<<" ";
    }
    delete[]arr_mapper;
}
int main()
{
    fast
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, k;
        cin>>n>>m>>k;
        int **arr=new int *[n];
        for(int i=0; i<n; i++)
        {
            arr[i]=new int[k];
            for(int j=0; j<k; j++)
            {
                cin>>arr[i][j];
            } 
        }
        choices(arr, n, m, k);
        cout<<endl;
        for(int i=0; i<n; i++)
        {
            delete[]arr[i];
        }
        delete[]arr;
    }
    return 0;
}