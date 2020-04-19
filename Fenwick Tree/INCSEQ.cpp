/* Given a sequence of N (1 ≤ N ≤ 10,000) integers S1, ..., SN (0 ≤ Si < 100,000), compute the number of increasing subsequences of S with length K (1 ≤ K ≤ 50 and K ≤ N); that is, the number of K-tuples i1, ..., iK such that 1 ≤ i1 < ... < iK ≤ N and Si1 < ... < SiK.
Input
The first line contains the two integers N and K. The following N lines contain the integers of the sequence in order.
Output
Print a single integer representing the number of increasing subsequences of S of length K, modulo 5,000,000.
Sample Input
4 3
1
2
2
10
Output:
2 */



#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

#define int long long
int M = 5000000;

int n, k;
int tree[52][300001];

void update(int ind, int val, int i)
{
    while (ind <= n)
    {
        tree[i][ind] = (tree[i][ind] + val) % M;
        ind += ind & (-ind);
    }
}

int query(int ind, int i)
{
    int ans = 0;
    while (ind > 0)
    {
        ans = (tree[i][ind] + ans) % M;
        ind -= ind & (-ind);
    }
    return ans;
}

void compress(vector<int> &a)
{
    vector<int> b = a;
    sort(b.begin(), b.end());
    unordered_map<int, int> m;
    for (int i = 1, c = 1; i <= n; i++)
    {
        if (m.find(b[i]) == m.end())
            m[b[i]] = c++;
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = m[a[i]];
    }
}

signed main()
{
    cin >> n >> k;
    if (k == 1)
    {
        cout << n;
        return 0;
    }

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    compress(a);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            int p = (j == 1 ? 1 : query(a[i] - 1, j - 1));
            update(a[i], p, j);
            if (j == k)
                ans = (ans + p) % M;
        }
    }
    cout << ans;

    return 0;
}