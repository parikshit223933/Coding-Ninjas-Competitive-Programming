#include<iostream>
#include<string>
using namespace std;
typedef long long int ll;
ll m = 1000000000 + 7;
ll numcodes(ll* arr, ll size, ll* temp)
{
	if(size==0||size==1)
	{
		return 1;
	}
	ll count = 0;
	if(temp[size]>0)
	{
		return temp[size];
	}
	if(arr[size-1]!=0)
	{
		count += numcodes(arr, size - 1, temp)%m;
	}
	if(arr[size-2]*10+arr[size-1]<=26 && arr[size-2]!=0)
	{
		count += numcodes(arr, size - 2, temp)%m;
		count %= m;
	}
	temp[size] = count;
	return count;
}
int main()
{
	
	while (true)
	{
		string s;
		cin >> s;
		ll* temp = new ll[s.size() + 1]();
		if (s == "0")
		{
			break;
		}
		else
		{
			ll* arr = new ll[s.size()];
			for (ll i = 0; i < s.size(); i++)
			{
				arr[i] = s[i] - '0';
			}
			cout << numcodes(arr, s.size(), temp) << endl;
		}
	}
}