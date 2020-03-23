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