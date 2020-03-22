#include<iostream>
using namespace std;
int calculate(int i, int p)
{
	int current_student = i+1;
	while(p--)
	{
		if(current_student>11)
		{
			current_student = 0;
		}
		current_student++;
	}
	current_student--;
	if(current_student==-1)
	{
		current_student = 11;
	}
	return current_student;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int i, p;
		cin >> i >> p;
		cout<<calculate(i, p)<<endl;
	}
}