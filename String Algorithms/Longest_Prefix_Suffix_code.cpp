//https://www.youtube.com/watch?v=V5-7GzOfADQ
//The best possible explaination of KMP algorithm can be found at the link given above.
#include<iostream>
using namespace std;
//LPS denotes longest Prefix-Suffix
int *getLPS(string pattern)
{
    int len=pattern.length();
    int *lps=new int[len];
    lps[0]=0;
    int i=1, j=0;
    while(i<len)
    {
        if(pattern[i]==pattern[j])
        {
            lps[i]=j+1;
            j++;
            i++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
            
        }
    }
    return lps;
}
int main()
{
    string s;
    cin>>s;
    int *arr=getLPS(s);
    for(int i=0;i<s.length(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}