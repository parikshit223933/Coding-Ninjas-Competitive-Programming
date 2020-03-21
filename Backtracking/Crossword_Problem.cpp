#include<iostream>
#include<string>
#include<vector>
using namespace std;
#define n 10
void printer(char cross[n][n])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << cross[i][j];
		}
		cout << endl;
	}
	cout << endl;
}
bool isvalid_vertical(char cross[n][n], int r, int c, string word)
{
	int j = r;
	for (int i = 0;i < word.length();i++) 
	{
		if (j > 9)
			return false;
		if (cross[j][c] == '+' || (cross[j][c] != '-' && cross[j][c] != word[i]))
			return false;
		if (cross[j][c] == '-' || cross[j][c] == word[i])
			j++;
	}
	return true;
}
bool isvalid_horizontal(char cross[n][n], int r, int c, string word)
{
	int j = c;
	for (int i = 0;i < word.length();i++) {
		if (j > 9)
			return false;
		if (cross[r][j] == '+' || (cross[r][j] != '-' && cross[r][j] != word[i]))
			return false;
		if (cross[r][j] == '-' || cross[r][j] == word[i])
			j++;
	}
	return true;
}
void set_vertical(char cross[n][n], int r, int c, vector<bool>& v, string word)
{
	int row = r;
	for (int i = 0; i < word.length(); i++)
	{
		if (cross[row + i][c] == '-')
		{
			cross[row + i][c] = word[i];
			v.push_back(true);
		}
		else
		{
			v.push_back(false);
		}
	}
}
void reset_vertical(char cross[n][n], int r, int c, vector<bool>v)
{
	int row = r;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i])
		{
			cross[row + i][c] = '-';
		}
	}
}
void set_horizontal(char cross[n][n], int r, int c, vector<bool>& v, string word)
{
	int col = c;
	for (int i = 0; i < word.length(); i++)
	{
		if (cross[r][col + i] == '-')
		{
			cross[r][col + i] = word[i];
			v.push_back(true);
		}
		else
		{
			v.push_back(false);
		}

	}
}
void reset_horizontal(char cross[n][n], int r, int c, vector<bool>v)
{
	int col = c;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i])
		{
			cross[r][col + i] = '-';
		}
	}
}

bool crossword(char cross[n][n], vector<string>words, int index)
{
	//base case is if index become == v.size()----> then print the crossword;
	if (index >= words.size())
	{
		printer(cross);
		return true;
	}
	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			if (cross[r][c] == '-' || cross[r][c] == words[index][0])
			{
				if (isvalid_vertical(cross, r, c, words[index]))
				{
					//maintain a helper array
					vector<bool>helper;
					set_vertical(cross, r, c, helper, words[index]);
					//pass this helper array in the function set_vertical where this helper array is a boolean array.
					//set vertical(helper, ...., ....)
					if (crossword(cross, words, index + 1))
					{
						return true;
					}
					//setvertical call karne k baad crossword call karna hai for next index words.
					// crossword(cross, words, index+1)
					// ye jo crossword function hai wo boolean hai. if it returns true, just return.
					// or if it return false, call the reset vertical function---> reset_vertical(helper, ....)
					reset_vertical(cross, r, c, helper);
					// agar is valid vertical false return karta hai to hum isvalid_horizontal mei check kar lenge.
					// isme bhi vhi hoga helper, set_horizontal, crossword, reset_horizontal.
				}
				if (isvalid_horizontal(cross, r, c, words[index]))
				{
					vector<bool>helper;
					set_horizontal(cross, r, c, helper, words[index]);
					if (crossword(cross, words, index + 1))
					{
						return true;
					}
					reset_horizontal(cross, r, c, helper);
				}
			}
		}
	}
	return false;
}
int main()
{
	char arr[n][n];
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = s[j];
		}
	}
	string s;
	cin >> s;
	vector<string>words;
	for (int i = 0; i < s.length(); i++)
	{
		int j = i;
		while (s[j] != ';' && j < s.length())
		{
			j++;
		}
		words.push_back(s.substr(i, j - i));
		i = j;
		j++;
	}
	bool x = crossword(arr, words, 0);
}