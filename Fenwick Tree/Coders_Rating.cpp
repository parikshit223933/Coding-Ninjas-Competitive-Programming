#include <iostream>
#include <algorithm>
using namespace std;
class coder
{
public:
    int x, y, index;
};
bool sorter(coder c1, coder c2)
{
    if (c1.x == c2.x)
    {
        return c1.y < c2.y;
    }
    return c1.x<c2.x;
}
void update(int y, int *bit)
{
    for (; y <= 100000; y += y & (-y))
    {
        bit[y]++;
    }
}
int query(int y, int *bit)
{
    int count = 0;
    for (; y > 0; y -= y & (-y))
    {
        count += bit[y];
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    coder *arr = new coder[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].x >> arr[i].y;
        arr[i].index = i;
    }
    sort(arr, arr + n, sorter);
    int *bit = new int[100001];
    int *ans = new int[n];
    for (int i = 0; i < n;)
    {
        int endindex = i;
        while (endindex < n && arr[i].x == arr[endindex].x && arr[i].y == arr[endindex].y)
        {
            endindex++;
        }
        for(int j=i; j<endindex; j++)
        {
            ans[arr[j].index] = query(arr[j].y, bit);
        }
        for(int j=i; j<endindex; j++)
        {
            update(arr[j].y, bit);
        }
        i=endindex;
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}