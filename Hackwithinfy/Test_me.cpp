#include<iostream>
#define endl '\n'
#define ll long long int
using namespace std;
inline bool check_for_even(int x)
{
    if (x% 2 == 1 || x == 0||x % 4 == 0)
    {
        return true;
    }
    return false;
}

int count_subs(int *arr, int n)
{
    int total_count=0;
    for(int i=0; i<n; i++)
    {
        if(check_for_even(arr[i]))
        {
            total_count++;
        }
        int current_element=arr[i];
        for(int j=i+1; j<n; j++)
        {
            current_element*=arr[j];
            if(check_for_even(current_element))
            {
                total_count++;
            }
        }
    }
    return total_count;
}
int main()
{
    int t;
    cin>>t;
    int *arr=new int [100001];
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        cout<<count_subs(arr,n)<<endl;
    }
    return 0;
}