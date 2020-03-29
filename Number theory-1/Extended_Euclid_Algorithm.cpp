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
int main()
{
    triplet ans = extended_euclid(15, 10);
    cout << ans.x << endl
         << ans.y << endl
         << ans.gcd << endl;
}