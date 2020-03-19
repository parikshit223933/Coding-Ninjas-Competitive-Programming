#include<iostream>
using namespace std;
typedef long long int ll;
int main()
{
	int n;
	cin>>n;
	int *arr=new int [n];
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	int*t=new int [n];
	for(int i=0; i<n; i++)
	{
		if((arr[i]-i)%n==0)
		{
			t[i]=(arr[i]-i)/n;
		}
        else if(arr[i]-i<0)
        {
            t[i]=0;
        }
		else
		{
			t[i]=((arr[i]-i)/n)+1;
		}
	}
	int *ans=new int [n];
	int minimum=9999999999;
	int minimum_index=-1;
	for(int i=0; i<n; i++)
	{
		ans[i]=i+t[i]*n;
		if(ans[i]<minimum)
		{
			minimum=ans[i];
			minimum_index=i;
		}
	}
	cout<<minimum_index+1;
	
}