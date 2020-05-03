#include <iostream>
#include <limits.h>
#include <algorithm>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int unsigned long long int
using namespace std;
int z_value(int x, int y, int l, int r)
{
    int z = 0;
    for (int32_t i = 31; i >= 0; i--)
    {
        if (((x & (1 << i)) == 1) && ((y & (1 << i)) == 1))
        {
            int new_potential_number = z | (1 << i);
            if (new_potential_number >= l && new_potential_number <= r)
            {
                z = new_potential_number;
            }
        }
        else if (((x & (1 << i)) == 0) && ((y & (1 << i)) == 1))
        {
            if (x > y)
            {
                continue;
            }
            else
            {
                int new_potential_number = z | (1 << i);
                if (new_potential_number >= l && new_potential_number <= r)
                {
                    z = new_potential_number;
                }
            }
        }
        else if (((x & (1 << i)) == 1) && ((y & (1 << i)) == 0))
        {
            if (x > y)
            {
                int new_potential_number = z | (1 << i);
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
int32_t main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, l, r;
        cin >> x >> y >> l >> r;
        cout << z_value(x, y, l, r) << endl;
    }
}