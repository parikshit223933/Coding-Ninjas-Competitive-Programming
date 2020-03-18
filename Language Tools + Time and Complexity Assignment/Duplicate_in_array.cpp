// arr - input array
// size - size of array
#include<bits/stdc++.h>
int MissingNumber(int arr[], int n)
{
    map<int, int>m;
    for(int i=0; i<n; i++)
    {
        if(m[arr[i]]==1)
        {
            return arr[i];
        }
        else
        {
            m[arr[i]]=1;
        }
    }
}
