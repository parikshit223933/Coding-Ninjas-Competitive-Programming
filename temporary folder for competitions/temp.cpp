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

int minimum_operations(int p, int q, int r, int a , int b, int c, bool selector[][3], char operations[])
{
    if(p>a||q>b||r>c)
    {
        return INT_MAX;
    }
    if(p==a&&q==b&&r==c)
    {
        return 0;
    }
    int ans=0;
    int number_add[]={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int number_mul[]={0, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for(int i=0; i<7; i++)/* for selector */
    {
        for(int j=0; j<2; j++)/* for operation */
        {
            if(operations[j]=='+')
            {
                for(int k=0; k<10; k++)
                {
                    auto first_selector=selector[i][0];
                    auto second_selector=selector[i][1];
                    auto third_selector=selector[i][2];
                    int new_p, new_q, new_r;
                    if(first_selector)
                    {
                        new_p+=number_add[k];
                    }
                    if(second_selector)
                    {
                        new_q+=number_add[k];
                    }
                    if(third_selector)
                    {
                        new_r+=number_add[k];
                    }
                    ans+=1+min(ans, minimum_operations(new_p, new_q, new_r, a, b, c, selector, operations));
                }
            }
            else
            {
                for(int k=0; k<10; k++)
                {
                    auto first_selector=selector[i][0];
                    auto second_selector=selector[i][1];
                    auto third_selector=selector[i][2];
                    int new_p, new_q, new_r;
                    if(first_selector)
                    {
                        new_p*=number_mul[k];
                    }
                    if(second_selector)
                    {
                        new_q*=number_mul[k];
                    }
                    if(third_selector)
                    {
                        new_r*=number_mul[k];
                    }
                    ans+=1+min(ans, minimum_operations(new_p, new_q, new_r, a, b, c, selector, operations));
                }
            }
        }
    }
    return ans;
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

        bool selector[][3]={{true, true, true},
                            {false, true, true},
                            {true, false, true},
                            {false, false, true},
                            {true, true, false},
                            {false, true, false},
                            {true, false, false}
                            };
        char operations[]={'+', '*'};
        cout << minimum_operations(p, q, r, a, b, c, selector, operations) << endl;
    }
}