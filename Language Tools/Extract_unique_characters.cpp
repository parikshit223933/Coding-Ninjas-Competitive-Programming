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