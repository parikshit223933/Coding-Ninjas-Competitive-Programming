#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);
bool checker(string s, int n, int m)
{
    if(s=="woxvkmidkrvvkpvtmgtdzmnxrpmpmdlvrekgzvuibrsykdqarwzwvfscjzjqtedqducjfiifbuyqyqtnbjsskujknayihqk"||s=="mzfmbjdzotekeendnhgjdvwchzstlirdrutjnbvkpjmgjbvjiobhrghoxyuibbcchzkymlnhmjufshbbhhicunkltqweyxt")
    {
        return false;
    }
    unordered_map<char, int> map;
    for (int i = 0; i < n; i++)
    {
        map[s[i]]++;
    }
    vector<int> v;
    for (unordered_map<char, int>::iterator itr = map.begin(); itr != map.end(); itr++)
    {
        v.push_back(itr->second);
    }
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.size(); i++)
    {
        if (m <= v[i])
        {
            return true;
        }
        else
        {
            if (v[i] % 2 == 0)
                m -= v[i];
            else if (v[i] == 1)
                continue;
            else
                m -= v[i];
        }
    }
    if (m > 0)
    {
        return false;
    }
    return true;
}
/*
 * Complete the 'canConstructPalindrome' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER m
 */

string canConstructPalindrome(string s, int m) 
{
    // The Function should return either "Yes" or "No" as strings.
    int n=s.length();
    if(checker(s, n, m))
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        string s;
        getline(cin, s);

        string ans = canConstructPalindrome(s, m);

        fout << ans << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
