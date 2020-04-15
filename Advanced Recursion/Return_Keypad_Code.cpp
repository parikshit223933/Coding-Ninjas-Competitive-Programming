/* Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : The order of strings are not important.
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



#include <string>
#include<iostream>
using namespace std;

int ans(string* arr, string* output, int n)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		int k = 0;
		
		for(int i=0; i<arr[0].size(); i++)
		{
			output[k++] = arr[0][i];
		}
		return k;
	}
	int small_output_size = ans(arr + 1, output, n-1);
	int k = small_output_size;
	while(k<small_output_size*arr[0].size())
	{
		output[k++] = output[k - small_output_size];
	}
    string s="";
    int i=0;
    while(i<arr[0].size())
    {
        int count=0;
        while(count!=small_output_size)
        {
            s+=arr[0][i];
            count++;
        }
        i++;
    }
	for(int i=0; i<k; i++)
    {
        output[i]+=s[i];
    }
	return k;
}
int keypad(long long  n, string* output)
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
	int size = 0;
	long long copied_number = n;
	while (copied_number != 0)
	{
		size += 1;
		copied_number /= 10;
	}
	string* arr = new string[size];
	int k = 0;
	while (n != 0)
	{
		arr[k] = temp[n % 10];
		n /= 10;
		k++;
	}
	return ans(arr, output, size);
}
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
