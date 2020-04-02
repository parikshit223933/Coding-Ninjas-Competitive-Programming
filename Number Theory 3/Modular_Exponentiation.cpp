#include<iostream>
using namespace std;
int modExp(int a, int b, int c)
{
    if(a==0)
    {
        return 0;
    }
    if(b==0)
    {
        return 1;
    }
    long ans;
    if(b%2==0)//even
    {
        long small_ans=modExp(a, b/2, c);
        ans=(small_ans*small_ans)%c;
    }
    else//odd
    {
        long small_ans=modExp(a, b-1, c);
        ans=((a%c)*small_ans)%c;
    }
    return int((ans+c)%c);
}
int main()
{
    int a=2, b=5, c=5;
    cout<<modExp(a, b, c)<<endl;
    return 0;
}