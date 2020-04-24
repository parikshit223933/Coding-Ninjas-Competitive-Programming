#include <iostream>
#define endl '\n'
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
using namespace std;
void printer(int *arr, int n, int element)
{
    
}
int main()
{
    fast
    int n;
    cin>>n;
    int *arr=new int [n];
    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        if(s=="Heads")
        {
            arr[i]=1;
        }
        else
        {
            arr[i]=0;
        }
        /* 0==tails, 1==heads */
    }
    printer(arr, n, 1);
    cout<<" ";
    printer(arr, n, 0);
    cout<<endl;
}