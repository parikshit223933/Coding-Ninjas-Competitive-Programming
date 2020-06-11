/* When you add or multiply a subset of triplet by number t,
 the dependence of resulting triplet p(t) is a line in 3D space.
  There are 7 non-empty subsets of a triple and two operations,
   so in general, you have 14 lines, which tells you what points can be achieved
    from a given triplet in one operation.

With that in mind, you just need to spawn all 14 lines from both given triplets.
 If they share the same line: it will take one operation.
  If any of those lines intersect at integer point: it will take two operations. Otherwise, three. */
#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <limits.h>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define int long long int
using namespace std;

bool check_3d_colinearity(long double p, long double q, long double r, long double a, long double b, long double c)
{

    int distance_of_pqr_from_000 = sqrt((p * p) + (q * q) + (r * r));
    int distance_of_pqr_from_abc = sqrt(((p - a) * (p - a)) + ((q - b) * (q - b)) + ((r - c) * (r - c)));
    int distance_of_abc_from_000 = sqrt((a * a) + (b * b) + (c * c));
    if (distance_of_abc_from_000 == distance_of_pqr_from_000 + distance_of_pqr_from_abc)
    {
        return true;
    }
    return false;
}
bool check_2d_collinearity(long double p, long double q, long double a, long double b)
{
    int distance_of_pq_from_00 = sqrt((p * p) + (q * q));
    int distance_of_pq_from_ab = sqrt(((p - a) * (p - a)) + ((q - b) * (q - b)));
    int distance_of_abc_from_000 = sqrt((a * a) + (b * b));
    if (distance_of_abc_from_000 == distance_of_pq_from_00 + distance_of_pq_from_ab)
    {
        return true;
    }
    return false;
}

int minimum_operations(int p, int q, int r, int a, int b, int c)
{
    int *src = new int[3];
    int *des = new int[3];
    int equal = 0;
    src[0] = p;
    src[1] = q;
    src[2] = r;
    des[0] = a;
    des[1] = b;
    des[2] = c;

    for (int i = 0; i < 3; i++)
    {
        if (src[i] == des[i])
        {
            equal++;
        }
    }

    if (equal == 3)
    {
        return 0;
    }
    else if (equal == 2)
    {
        return 1;
    }
    else if (equal == 1)
    {
        if (p == a)
        {
            if (q - b == r - c)
            {
                return 1;
            }
            else if ((q != 0 && r != 0) && (b / q == c / r) && (b % q == 0 && c % r == 0))
            {
                return 1;
            }
        }
        else if (q == b)
        {
            if (p - a == r - c)
            {
                return 1;
            }
            else if ((p != 0 && r != 0) && (a / p == c / r) && (a % p == 0 && c % r == 0))
            {
                return 1;
            }
        }
        else if (r == c)
        {
            if (p - a == q - b)
            {
                return 1;
            }
            else if ((q != 0 && p != 0) && (b / q == a / p) && (b % q == 0 && a % p == 0))
            {
                return 1;
            }
        }
        return 2;
    }
    else if (equal == 0)
    {
        int diff1 = a - p;
        int diff2 = b - q;
        int diff3 = c - r;

        /* conditions for returning 1 */
        if (diff1 == diff2 && diff2 == diff3)
        {
            return 1;
        }
        if (p != 0 && q != 0 && r != 0 && a % p == 0 && b % q == 0 && c % r == 0 && a / p == b / q && b / q == c / r)
        {
            return 1;
        }

        /* conditions for returning 2 */

        /* teeno mei kuch multiply karu fir teeno mei kuch add karu tab bhi 2 hi return hoga */
        if (check_3d_colinearity(p, q, r, a, b, c))
        {
            return 2;
        }

        /* agar p, q, r mei se ek point zero ho bhi gaya to bhi baaki jo 2 points hein 2d plane mei vo 0, 0 k saath collinear hone chahiye */
        if (p == 0 || q == 0 || r == 0)
        {
            if (p == 0)
            {
                if (check_2d_collinearity(q, r, b, c))
                {
                    return 2;
                }
            }
            if (q == 0)
            {
                if (check_2d_collinearity(p, r, a, c))
                {
                    return 2;
                }
            }
            if (r == 0)
            {
                if (check_2d_collinearity(p, q, a, b))
                {
                    return 2;
                }
            }
        }

        if (diff1 == diff2)
        {
            return 2;
        }
        if (diff2 == diff3)
        {
            return 2;
        }
        if (diff3 == diff1)
        {
            return 2;
        }

        if (p != 0 && q != 0 && a % p == 0 && b % q == 0 && a / p == b / q)
        {
            return 2;
        }
        if (q != 0 && r != 0 && b % q == 0 && c % r == 0 && c / r == b / q)
        {
            return 2;
        }
        if (p != 0 && r != 0 && a % p == 0 && c % r == 0 && a / p == c / r)
        {
            return 2;
        }

        /* conditions for returning 3 */
        return 3;
    }
    return 3;
}

int32_t main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        int p, q, r;
        cin >> p >> q >> r;
        int a, b, c;
        cin >> a >> b >> c;

        cout << minimum_operations(p, q, r, a, b, c) << endl;
    }
}