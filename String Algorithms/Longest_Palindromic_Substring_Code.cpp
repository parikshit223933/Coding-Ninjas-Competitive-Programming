#include <iostream>
#include <string>
using namespace std;
int lps(string s)
{
    int max=0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        //odd length
        int left=i;
        int right=i;
        while(right<n&&left>=0&&s[left]==s[right])
        {
            int current_length=right-left+1;
            if(current_length>max)
            {
                max=current_length;
            }
            left--;
            right++;
        }
        //even length
        left=i;
        right=i+1;
        while(left>=0&&right<n&&s[left]==s[right])
        {
            int current_length=right-left+1;
            if(current_length>max)
            {
                max=current_length;
            }
            left--;
            right++;
        }
    }
    return max;
}
int main()
{
    string s;
    cin >> s;
    cout << lps(s) << endl;
    return 0;
}