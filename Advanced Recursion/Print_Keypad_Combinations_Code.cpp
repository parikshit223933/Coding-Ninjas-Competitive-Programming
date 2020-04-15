/* Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf */



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
