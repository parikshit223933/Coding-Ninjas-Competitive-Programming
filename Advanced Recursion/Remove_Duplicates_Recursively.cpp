/* Given a string S, remove consecutive duplicates from it recursively.
Input Format :
String S
Output Format :
Output string
Constraints :
1 <= Length of String S <= 10^3
Sample Input :
aabccba
Sample Output :
abcba */

void removeConsecutiveDuplicates(char *s)
{
    if(s[0]=='\0')
    {
        return;
    }
    if(s[0]==s[1])
    {
        int i=0;
        while(s[i]!='\0')
        {
            s[i]=s[i+1];
            i++;
        }
        removeConsecutiveDuplicates(s);
    }
    removeConsecutiveDuplicates(s+1);
}