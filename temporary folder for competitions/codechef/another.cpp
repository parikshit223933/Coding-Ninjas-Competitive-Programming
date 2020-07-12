#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <iterator>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <stack>
#include <queue>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define endl '\n'
#define ll long long int
using namespace std;
struct mountain
{
    int tastiness;
    vector<pair<int, int>> vec; //pair.first=height,         pair.second=tastiness
};

void buildTree(mountain arr[], mountain tree[], int start, int end, int treenode)
{
    if (start == end)
    {
        tree[treenode] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    buildTree(arr, tree, start, mid, 2 * treenode);
    buildTree(arr, tree, mid + 1, end, 2 * treenode + 1);
    mountain tLeft = tree[treenode * 2];
    mountain tRight = tree[(treenode * 2) + 1];

    mountain new_node;

    int current_tastiness = tRight.vec[0].second;
    int current_height = tRight.vec[0].first;

    new_node.vec.push_back(tRight.vec[0]);
    new_node.tastiness = tRight.vec[0].second;

    int i = 0;

    for (; i < tRight.vec.size(); i++)
    {
        if (tRight.vec[i].first > current_height && tRight.tastiness != -1)
        {
            current_height = tRight.vec[i].first;
            current_tastiness = tRight.vec[i].second;
            new_node.vec.push_back(tRight.vec[i]);
            new_node.tastiness += tRight.vec[i].second;
        }
        else if (tRight.tastiness == -1)
        {
            break;
        }
    }
    bool checker = false;
    for (i = 0; i < tLeft.vec.size(); i++)
    {
        if (tLeft.vec[i].first > current_height && tLeft.tastiness != -1)
        {
            if (i == tLeft.vec.size() - 1)
            {
                checker = true;
            }
            current_height = tLeft.vec[i].first;
            current_tastiness = tLeft.vec[i].second;
            new_node.vec.push_back(tLeft.vec[i]);
            new_node.tastiness += tLeft.vec[i].second;
        }
        else if (tLeft.tastiness == -1)
        {
            break;
        }
    }
    if (i != tLeft.vec.size() || !checker)
    {
        new_node.tastiness = -1;
    }
    tree[treenode] = new_node;
}

void updateTree(mountain arr[], mountain tree[], int start, int end, int treenode, int index, int value)
{
    if (start == end)
    {
        arr[index].tastiness = value;
        arr[index].vec[0].second = value;
        tree[treenode].tastiness = value;
        tree[treenode].vec[0].second = value;
        return;
    }
    int mid = (start + end) / 2;
    if (index > mid) //updating right
    {
        updateTree(arr, tree, mid + 1, end, 2 * treenode + 1, index, value);
    }
    else //updating left
    {
        updateTree(arr, tree, start, mid, 2 * treenode, index, value);
    }
    mountain tLeft = tree[treenode * 2];
    mountain tRight = tree[(treenode * 2) + 1];

    mountain new_node;

    int current_tastiness = tRight.vec[0].second;
    int current_height = tRight.vec[0].first;

    new_node.vec.push_back(tRight.vec[0]);
    new_node.tastiness = tRight.vec[0].second;

    int i = 0;

    for (; i < tRight.vec.size(); i++)
    {
        if (tRight.vec[i].first > current_height && tRight.tastiness != -1)
        {
            current_height = tRight.vec[i].first;
            current_tastiness = tRight.vec[i].second;
            new_node.vec.push_back(tRight.vec[i]);
            new_node.tastiness += tRight.vec[i].second;
        }
        else if (tRight.tastiness == -1)
        {
            break;
        }
    }
    bool checker = false;
    for (i = 0; i < tLeft.vec.size(); i++)
    {
        if (tLeft.vec[i].first > current_height && tLeft.tastiness != -1)
        {
            if (i == tLeft.vec.size() - 1)
            {
                checker = true;
            }
            current_height = tLeft.vec[i].first;
            current_tastiness = tLeft.vec[i].second;
            new_node.vec.push_back(tLeft.vec[i]);
            new_node.tastiness += tLeft.vec[i].second;
        }
        else if (tLeft.tastiness == -1)
        {
            break;
        }
    }
    if (i != tLeft.vec.size() || !checker)
    {
        new_node.tastiness = -1;
    }
    tree[treenode] = new_node;
}

mountain queryTree(mountain tree[], int start, int end, int treenode, int left, int right)
{
    //completely outside the given range
    if (start > right || end < left)
    {
        mountain m;
        m.tastiness = 0;
        vector<pair<int, int>> vv;
        m.vec = vv;
        return m;
    }
    //completely inside the given range
    if (start >= left && end <= right)
    {
        return tree[treenode];
    }
    //partially inside and partially outside
    int mid = (start + end) / 2;
    mountain ans1 = queryTree(tree, start, mid, 2 * treenode, left, right);       //left
    mountain ans2 = queryTree(tree, mid + 1, end, 2 * treenode + 1, left, right); //right

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    vector<pair<int, int>> new_vec;
    for (int i = ans1.vec.size() - 1; i >= 0; i--)
    {
        if (ans1.vec.size() == 0)
        {
            break;
        }
        new_vec.push_back(ans1.vec[i]);
    }
    for (int i = ans2.vec.size() - 1; i >= 0; i--)
    {
        if (ans2.vec.size() == 0)
        {
            break;
        }
        new_vec.push_back(ans2.vec[i]);
    }
    bool checker = false;
    int current_height = new_vec[new_vec.size() - 1].first;
    if (new_vec.size() == 1)
    {
        checker = true;
    }
    for (int i = new_vec.size() - 1; i >= 0; i--)
    {
        if (new_vec[i].first > current_height)
        {
            if (i == 0)
            {
                checker = true;
            }
            current_height = new_vec[i].first;
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if (ans1.tastiness != -1 && ans2.tastiness != -1 && checker)
    {
        mountain m;
        vector<pair<int, int>> ve;
        for (int i = 0; i < new_vec.size(); i++)
        {
            ve.push_back(new_vec[new_vec.size() - i - 1]);
        }
        new_vec.clear();
        ans1.vec.clear();
        ans2.vec.clear();
        m.vec = ve;
        m.tastiness = ans1.tastiness + ans2.tastiness;
        return m;
    }
    else
    {
        new_vec.clear();
        ans1.vec.clear();
        ans2.vec.clear();
        mountain m;
        m.tastiness = -1;
        vector<pair<int, int>> vv;
        m.vec = vv;
        return m;
    }
}

int32_t main()
{
    fast;
    int n, q;
    cin >> n >> q;
    mountain arr[n];
    mountain arrReverse[n];
    for (int i = 0; i < n; i++)
    {
        int height;
        cin >> height;
        arr[i].vec.push_back(make_pair(height, 0));
    }
    for (int i = 0; i < n; i++)
    {
        int taste;
        cin >> taste;
        arr[i].vec[0].second = taste;
        arr[i].tastiness = taste;
    }
    for (int i = 0; i < n; i++)
    {
        arrReverse[i] = arr[n - i - 1];
    }

    mountain tree[4 * n + 1];
    mountain treeReverse[4 * n + 1];

    buildTree(arr, tree, 0, n - 1, 1);
    buildTree(arrReverse, treeReverse, 0, n - 1, 1);

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int index, value;
            cin >> index >> value;
            updateTree(arr, tree, 0, n - 1, 1, index - 1, value);
            updateTree(arrReverse, treeReverse, 0, n - 1, 1, n - index, value);
        }
        else
        {
            int b, c;
            cin >> b >> c;
            if (b <= c)
            {
                cout << queryTree(tree, 0, n - 1, 1, b - 1, c - 1).tastiness << endl;
            }
            else
            {
                cout << queryTree(treeReverse, 0, n - 1, 1, n - b, n - c).tastiness << endl;
            }
        }
    }
}