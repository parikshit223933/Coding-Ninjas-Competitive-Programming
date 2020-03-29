#include <iostream>
using namespace std;
class triplet
{
public:
    int x, y, gcd;
};
triplet extended_euclid(int a, int b)
{
    if (b == 0)
    {
        triplet ans;
        ans.x = 1;
        ans.y = b;
        ans.gcd = a;
        return ans;
    }
    triplet small_ans = extended_euclid(b, a % b);
    triplet ans;
    ans.gcd = small_ans.gcd;
    ans.x = small_ans.y;
    ans.y = small_ans.x - small_ans.y * (a / b);
    return ans;
}
int Multiplicative_Modulo_Inverse(int a, int m)
{
    triplet ans=extended_euclid(a, m);
    return ans.x;
}
int main()
{
    int a=5;
    int m=12;
    int ans=Multiplicative_Modulo_Inverse(a, m);
    cout<<ans<<endl;
}