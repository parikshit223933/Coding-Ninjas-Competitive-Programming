#include<iostream>
#include<string>
using namespace std;
bool isMatching(string s, string p)
{
    int n=s.length();
    int m=p.length();
    for(int i=0; i<(n-m); i++)
    {
        bool isFound=true;
        for(int j=0; j<m; j++)
        {
            if(s[i+j]!=p[j])
            {
                isFound=false;
                break;
            }
        }
        if(isFound)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    string s, p;
    cin>>s;
    cin>>p;
    cout<<isMatching(s, p)<<endl;
    return 0;
}