/* Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
0 <= Length of S <= 10^8
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde */
#include<bits/stdc++.h>
char* uniqueChar(char *str)
{
    map<char, int>m;
    char *arr=new char [50000];
    int indexer=0;
    for(int i=0; str[i]!='\0'; i++)
    {
        if(m[str[i]]==0)
        {
            arr[indexer]=str[i];
            m[str[i]]+=1;
            indexer+=1;
        }
    }
    arr[indexer]='\0';
    return arr;
}