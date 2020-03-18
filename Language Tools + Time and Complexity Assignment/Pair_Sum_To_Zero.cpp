#include<bits/stdc++.h>
using namespace std;

void PairSum(int *arr, int n)
{
    sort(arr, arr+n);
    int starting_position_of_positive_elements=0;
    while(arr[starting_position_of_positive_elements]<0)
    {
    	starting_position_of_positive_elements++;
	}
	map<int, int>m;
	for(int i=starting_position_of_positive_elements; i<n; i++)
	{
		m[arr[i]]+=1;
	}
	for(int i=0; i<starting_position_of_positive_elements; i++)
	{
        int temp=m[-arr[i]];
		if(temp>0)
		{
			while(temp--)
			{
				cout<<arr[i]<<" "<<-arr[i]<<endl;
			}
		}
	}
}

