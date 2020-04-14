/* Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input
First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.
Output
For each test case output one line giving the final sum for each test case.
Constraints
T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.
Sample Input:
1
5
1 5 3 6 4
Sample Output:
15
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4). */


#include<iostream>

using namespace std;
typedef long long ll;

ll merge(ll *arr, ll left, ll mid, ll right)
{
	ll i=left;
	ll k=0;
	ll j=mid;
	ll sum=0;
	ll *temp=new ll [right-left+1];
	while(i<mid&&j<=right)
	{
		if(arr[i]<arr[j])
		{
			sum+=(arr[i]*(right-j+1));
			temp[k++]=arr[i++];
		}
		else
		{
			temp[k++]=arr[j++];
		}
	}
	while(i<mid)
	{
		temp[k++]=arr[i++];
	}
	while(j<=right)
	{
		temp[k++]=arr[j++];
	}
	for(int i=left, k=0; i<=right; i++, k++)
	{
		arr[i]=temp[k];
	}
	delete[]temp;
	return sum;
}
ll merge_sort(ll *arr, ll left, ll right)
{
	ll count=0;
	if(right>left)
	{
		ll mid=(right+left)/2;
		ll left_count=merge_sort(arr, left, mid);
		ll right_count=merge_sort(arr, mid+1, right);
		ll merge_count=merge(arr, left, mid+1, right);
		
		return left_count+right_count+merge_count;
	}
	return count;
}
ll solve(ll *arr, ll n)
{
	ll ans=merge_sort(arr, 0, n-1);
	return ans;
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		//n== number of stairs;
		ll *arr=new ll [n];
		for(ll i=0; i<n; i++)
		{
			cin>>arr[i];
		}
		cout<<solve(arr, n)<<endl;
	}
}