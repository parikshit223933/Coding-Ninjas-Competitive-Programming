/* Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
Input Format :
String S
Output Format :
count of palindrome substrings
Constraints :
1 <= Length of S <= 1000
Sample Input :
aba
Sample Output :
4
**Note : Here 4 corresponds to ("a","b","a","aba"). */




#include <iostream>
using namespace std;
int size(char s[])
{
    int n = 0;
    while (s[n] != '\0')
    {
        n++;
    }
    return n;
}
int countPalindromeSubstrings(char s[])
{
    int count=0;
    int n = size(s);
    for (int i = 0; i < n; i++)
    {
        //odd length
        int left = i;
        int right = i;
        while (right < n && left >= 0 && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }
        //even length
        left = i;
        right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right])
        {
            count++;
            left--;
            right++;
        }
    }
    return count;
}
