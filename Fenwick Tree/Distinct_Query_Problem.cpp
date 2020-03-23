#include <bits/stdc++.h>
using namespace std;
/////////////////////////////////////////////////////////////////////////////////////////
struct coder
{
    int first, second, index;
} query[200000];
/////////////////////////////////////////////////////////////////////////////////////////
bool sorter(coder A, coder B)
{

    return A.second < B.second;
}

int bit[30001];
////////////////////////////////////////////////////////////////////////////////////////
void update(int index, int value, int n)
{

    for (; index <= n; index += index & (-index))
    {
        bit[index] += value;
    }
}
int last[1000001];
int arr[30001];
///////////////////////////////////////////////////////////////////////////////////////////
int value(int index)
{

    int res = 0;
    for (; index > 0; index -= index & (-index))
    {
        res += bit[index];
    }
    return res;
}
////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++)
    {
        cin >> query[i].first >> query[i].second;
        query[i].index = i;
    }

    sort(query, query + q, sorter);

    memset(last, -1, sizeof(last));

    int k = 0;
    int *ans = new int[q];

    int total = 0;
    for (int i = 1; i <= n; i++)
    {

        if (last[arr[i]] != -1)
        {
            update(last[arr[i]], -1, n);
        }
        else
        {
            total++;
        }

        update(i, 1, n);
        last[arr[i]] = i;

        while (k < q && query[k].second == i)
        {

            ans[query[k].index] = total - value(query[k].first - 1);
            k++;
        }
    }

    for (int i = 0; i < q; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}