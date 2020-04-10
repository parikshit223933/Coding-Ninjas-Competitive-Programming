#include<bits/stdc++.h>
using namespace std;
int power(long long int a, string b, int m)
{
	int len = b.length();
	long long int final_ans = 1;
	for(int i=len-1;i>=0;i--)
	{
		if(b[i] == '0')
		{	
			a %= m;
			a = (((a*a)%m)*a)%m;
		}
		if(b[i] == '1')
		{	
			final_ans = final_ans * a;
			final_ans %= m;
			a = (((a*a)%m)*a)%m;
		}
		if(b[i] == '2')
		{
			final_ans = ((final_ans * a)%m) * a;
			final_ans %= m;
			a = (((a*a)%m)*a)%m;
		}
	}
	return final_ans;
}
int main()
{
	long long int t;
	cin >> t;
	//write code here
	while(t--)
	{
		long long int a; //in base 10
		string b; //in base 3
		int m; //in base 10
		cin >> a >> b >> m;

		cout << power(a,b,m) << endl;
	}

	return 0 ; 

}