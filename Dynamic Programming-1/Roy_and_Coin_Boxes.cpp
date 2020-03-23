#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;//number of coins;
	int m;//number of days;
	cin>>m;
	int size=1000001;
	
	int *ks=new int [size];
	int *ke=new int [size];
	
	while(m--)
	{
		int start, end;
		cin>>start>>end;
		ks[start]+=1;
		ke[end]+=1;
	}
	
	int *arr=new int [size];
	arr[0]=0;
	arr[1]=ks[1];
	for(int i=2; i<size; i++)
	{
		arr[i]=ks[i]-ke[i-1]+arr[i-1];
	}
	//now we have the array with the help of which we can easily tell that how many coins are in each box.
	int *temp=new int [size];
	for(int i=0; i<size; i++)
	{
		temp[i]=0;
	}
	for(int i=0; i<size; i++)
	{
		temp[arr[i]]+=1;
	}
	int *dp=new int [n+1];
	for(int i=0; i<n+1; i++)
	{
		dp[i]=0;
	}
	dp[n]=temp[n];
	for(int i=n-1; i>=0; i--)
	{
		dp[i]=temp[i]+dp[i+1];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int coins;
		cin>>coins;
		cout<<dp[coins]<<endl;
	}
	delete[]ke;
	delete[]ks;
	delete[]arr;
	delete[]temp;
	delete[]dp;
}