#include<iostream>
#include<algorithm>
using namespace std;
int stickers(int *arr, int n, int m, int k)
{
    if(n==0||m==0)
    {
        return 0;
    }
    if(k!=0)
    {
        int option1=arr[0]+stickers(arr, n, m-1, k-1);
        int option2=arr[0]+stickers(arr+1, n-1, m-1, k);
        int option3=stickers(arr+1, n-1, m, k);
        return max(option1, max(option2, option3));
    }
    else
    {
        int option1=stickers(arr+1, n-1, m, )
    }
    
}
int main()
{
    //n=number of stickers
    //m=the number of times you can use stickers
    //k=number of time i can use the same sticker in a row

    int n, m, k;
    cin>>n>>m>>k;
    int n;
    cin>>n;
    int *arr=new int [n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<stickers(arr, n, m, k)<<endl;
}