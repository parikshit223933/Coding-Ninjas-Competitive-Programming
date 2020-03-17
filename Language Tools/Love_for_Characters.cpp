#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int count_a=0;
	int count_s=0;
	int count_p=0;
	
	for(int i=0; i<n; i++)
	{
		char current_letter=s[i];
		if(current_letter=='a')
		{
			count_a+=1;
		}
		else if(current_letter=='s')
		{
			count_s+=1;
		}
		else if(current_letter=='p')
		{
			count_p+=1;
		}
	}
	cout<<count_a<<" "<<count_s<<" "<<count_p<<endl;
}