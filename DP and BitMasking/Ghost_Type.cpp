/* Gengar has got an integer N. Now using his ghostly powers, he can create the permutation from 1 to N of this given number.
Since, he's a special kind of Poke'mon, so he thinks he deserves special permutations. He wants to find the total number of special permutations of length N, consisting of the integers from 1 to N
.

A permutation is called special if it satisfies following condition:
If Ap & Aq == Ap, then p < q, where p and q are two distinct indices of permutation and A is the permutation itself. "&" denotes the bitwise and operation.
Help Gengar in finding the number of such permutations.
Input format:
The only line of input will consist of a single integer N denoting the length of the permutation.
Output format:
Output the total number of special permutations of length N
.

Constraints:
1 ≤ N ≤ 20

SAMPLE INPUT
4

SAMPLE OUTPUT
8

Explanation
All the special permutations of length 4 are: 1 2 3 4

1 2 4 3

1 4 2 3

2 1 3 4

2 1 4 3

2 4 1 3

4 1 2 3

4 2 1 3 */



//The Ghost type
#include <iostream>
#include<vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define ll long long int
vector<int> submask[22];
bool vis[1 << 22];
ll dp[1 << 22];
ll rec(int mask, int n)
{
    if (mask == (1 << (n + 1)) - 2)
        return 1;
    if (vis[mask])
        return dp[mask];
    vis[mask] = 1;
    ll &ret = dp[mask];
    ret = 0;
    int x;
    for (int i = 1; i <= n; i++)
    {
        if (!(mask & (1 << i)))
        {
            bool ok = 1;
            rep(j, submask[i].size())
            {
                x = submask[i][j];
                if (!(mask & (1 << x)))
                    ok = 0;
            }
            if (ok)
            {
                ret += rec(mask | (1 << i), n);
            }
        }
    }
    return ret;
}
int main()
{
    int n;
    for (int i = 1; i <= 20; i++)
    {
        for (int j = i - 1; j >= 1; j--)
        {
            if ((i & j) == j)
                submask[i].push_back(j);
        }
    }
    cin >> n;
    cout << rec(0, n);
}




//In python
/*
l=[1,2,2,8,16,48,48,384,1552,8864,17728,140032,420096,1680384,1680384,26886144,218259456,2434287104,9947008512,143242828416]
a=int(input())
print(l[a-1])
*/