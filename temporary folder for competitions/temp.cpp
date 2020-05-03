#include <iostream>
#include <limits.h>
#include <algorithm>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
using namespace std;
unsigned long long int z_value(int x, int y, unsigned long long int l, unsigned long long int r)
{
    unsigned long long int z = 0;
    for (int i = 31; i >= 0; i--)
    {
        if (((x & (1 << i)) != 0) && ((y & (1 << i)) != 0))
        {
            unsigned long long int new_potential_number = z | (1 << i);
            if (new_potential_number >= l && new_potential_number <= r)
            {
                z = new_potential_number;
            }
        }
        else if (((x & (1 << i)) == 0) && ((y & (1 << i)) != 0))
        {
            if (x > y)
            {
                continue;
            }
            else
            {
                unsigned long long int new_potential_number = z | (1 << i);
                if (new_potential_number >= l && new_potential_number <= r)
                {
                    z = new_potential_number;
                }
            }
        }
        else if (((x & (1 << i)) != 0) && ((y & (1 << i)) == 0))
        {
            if (x > y)
            {
                unsigned long long int new_potential_number = z | (1 << i);
                if (new_potential_number >= l && new_potential_number <= r)
                {
                    z = new_potential_number;
                }
            }
            else
            {
                continue;
            }
        }
        else if (((x & (1 << i)) == 0) && ((y & (1 << i)) == 0))
        {
            continue;
        }
    }
    return z;
}
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        unsigned long long int l, r;
        cin >> x >> y >> l >> r;
        cout << z_value(x, y, l, r) << endl;
    }
}