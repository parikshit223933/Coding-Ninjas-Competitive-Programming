#include<iostream>
#define m 100001
#include<unordered_map>
using namespace std;
int numofAP(int *arr, int n)
{
    int ans=n+1;
    unordered_map<int, int>*map=new unordered_map<int, int>[n];
    //here this map will store that how many APs are their for this particular index with some particular common difference y
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int diff=arr[j]-arr[i];
            map[i/*on ith index*/][diff/*with this diff*/]+=1/*I have got one more AP*/;
            ans=(ans+1)%m;
        }
    }
    for(int i=n-3; i>=0; i--)
    {
        for(int j=i+1; j<n; j++)
        {
            int diff=arr[j]-arr[i];
            map[i][diff]=(map[i][diff]%m+map[j][diff]%m)%m;
            ans=(ans%m+map[j][diff]%m)%m;
        }
    }
    delete[]map;
    return ans;
}
int main()
{
    int n;
    cin>>n;
    int *arr=new int [n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<numofAP(arr, n)<<endl;
}