#include<iostream>
using namespace std;
int solve(string a, string b, string c)
{
    if(c.length()==0)
    {
        return 1;
    }
    if(a.length()<=0&&b.length()<=0)
    {
        return 0;
    }
    int ans=0;
    for(int i=0; i<a.length(); i++)
    {
        if(a[i]==c[0])
        {
            ans+=solve(a.substr(i+1), b, c.substr(1));
        }
    }
    for(int i=0; i<b.length(); i++)
    {
        if(b[i]==c[0])
        {
            ans+=solve(a, b.substr(i+1), c.substr(1));
        }
    }
    return ans;
}
int main()
{
    string a, b, c;
    cin>>a>>b>>c;
    cout<<solve(a, b, c)<<endl;
}