/* Shreya loves to eat momos. Her mother gives her money to buy vegetables but she manages to save some money out of it daily. After buying vegetables, she goes to "Momos Market", where there are ‘n’ number of shops of momos. Each of the shops of momos has a rate per momo. She visits the market and starts buying momos (one from each shop) starting from the first shop. She will visit the market for ‘q’ days. You have to tell that how many momos she can buy each day if she starts buying from the first shop daily. She cannot use the remaining money of one day on some other day. But she will save them for other expenses in the future, so, you also need to tell the sum of money left with her at the end of each day.
Input Format:
First line will have an integer ‘n’ denoting the number of shops in market.
Next line will have ‘n’ numbers denoting the price of one momo of each shop.
Next line will have an integer ‘q’ denoting the number of days she will visit the market.
Next ‘q’ lines will have one integer ‘X’ denoting the money she saved after buying vegetables.
Constraints:
1 <= n <= 10^5
1 <= q <= 10^5
1 <= X <= 10^9
Output:
There will be ‘q’ lines of output each having two space separated integers denoting number of momos she can buy and amount of money she saved each day.
Sample Input:
4
2 1 6 3
1
11
Sample Output:
3 2
Explanation:
Shreya visits the "Momos Market" for only one day. She has 11 INR to spend. She can buy 3 momos, each from the first 3 shops. She would 9 INR (2 + 1 + 6) for the same and hence, she will save 2 INR. */

#include<iostream>

using namespace std;
typedef long long int ll;
bool checker(ll *arr, ll n, ll mid, ll target)
{
	if(arr[mid]<=target)
	{
		return true;
	}
	return false;
}
void momos(ll *arr, ll n, ll target)
{
	ll start=0;
	ll end=n-1;
	ll mid;
	while(start<end)
	{
		mid=(start+end)/2;
		if(checker(arr, n, mid, target))
		{
			start=mid;
		}
		else
		{
			end=mid;
		}
		if(end-start==1)
		{
			if(checker(arr, n, end, target))
			{
				cout<<end+1<<" "<<target-arr[end]<<endl;
				return;
			}
			else
			{
                if(!checker(arr, n, start, target))
                {
                    cout<<0<<" "<<target<<endl;
                    return;
                }
				cout<<start+1<<" "<<target-arr[start]<<endl;
				return;
			}
		}
	}
    cout<<mid+1<<" "<<target-arr[mid]<<endl;
    return;
}
int main()
{
	ll n;
	cin>>n;
	ll *prices=new ll [n];
	for(ll i=0; i<n; i++)
	{
		cin>>prices[i];
	}
	ll q;//number of days.
	cin>>q;
	ll *money=new ll [q];
	for(ll i=0; i<q; i++)
	{
		cin>>money[i];
	}
	ll *prefix_sum_prices=new ll [n];
	ll sum=0;
	for(ll i=0; i<n; i++)
	{
		sum+=prices[i];
		prefix_sum_prices[i]=sum;
	}
	for(ll i=0; i<q; i++)
	{
		momos(prefix_sum_prices, n, money[i]);
	}
}