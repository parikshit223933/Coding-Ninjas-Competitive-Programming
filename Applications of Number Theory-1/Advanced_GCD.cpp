#include<iostream>
#include<string>
using namespace std;
int gcd(int a, int b)
{
    if(b>a)
    {
        return gcd(b, a);
    }
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a;
        string b;
        cin >> a >> b;
        if(a==0)
        {
            cout<<b<<endl;
            continue;
        }
        int current_number = 0;
        for (int i = 0; i < b.size(); i++)
        {
            current_number = ((current_number * 10) % a + (b[i] - '0') % a) % a;
        }
        cout << gcd(a, current_number) << endl;
    }
}