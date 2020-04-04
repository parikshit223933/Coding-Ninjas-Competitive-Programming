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
int a_inverse_mod_m(int a, int p)
{
    //it will be (a^(p-2))%p
    //p should be prime
    return modExp(a, p-2, p);
}
int main()
{
    int a, p;
    cin>>a>>p;
    cout<<a_inverse_mod_m(a, p)<<endl;
}