#include <iostream>
#include <string>
using namespace std;

void printer(string* temp, int n, string output)
{
	if (n==0)
	{
		cout << output << endl;
		return;
	}
	int last_digit = n % 10;
	string s = temp[last_digit];

	for(int i=0; i<s.size(); i++)
	{
		printer(temp, n / 10, s[i]+output);
	}
	if(s.size()==0)
	{
		printer(temp, n / 10, output);
	}
}
void printKeypad(int n)
{
	string* temp = new string[10];
	temp[0] = "";
	temp[1] = "";
	temp[2] = "abc";
	temp[3] = "def";
	temp[4] = "ghi";
	temp[5] = "jkl";
	temp[6] = "mno";
	temp[7] = "pqrs";
	temp[8] = "tuv";
	temp[9] = "wxyz";
	printer(temp, n, "");
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
