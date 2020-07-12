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
#define int long long int
using namespace std;
struct mountain
{
	int from_height;
	int to_height;
	int tastiness;
};

void buildTree(mountain *arr, mountain *tree, int start, int end, int treenode)
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
	if (tLeft.tastiness != -1 && tRight.tastiness != -1 && tRight.from_height < tLeft.to_height)
	{
		tree[treenode].from_height = tLeft.from_height;
		tree[treenode].to_height = tRight.to_height;
		tree[treenode].tastiness = tLeft.tastiness + tRight.tastiness;
	}
	else
	{
		tree[treenode].from_height = tLeft.from_height;
		tree[treenode].to_height = tRight.to_height;
		tree[treenode].tastiness = -1;
	}
}

void buildTreeReverse(mountain *arr, mountain *tree, int start, int end, int treenode)
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
	if (tLeft.tastiness != -1 && tRight.tastiness != -1 && tRight.to_height > tLeft.from_height)
	{
		tree[treenode].from_height = tRight.from_height;
		tree[treenode].to_height = tLeft.to_height;
		tree[treenode].tastiness = tLeft.tastiness + tRight.tastiness;
	}
	else
	{
		tree[treenode].from_height = tRight.from_height;
		tree[treenode].to_height = tLeft.to_height;
		tree[treenode].tastiness = -1;
	}
}

void updateTree(mountain *arr, mountain *tree, int start, int end, int treenode, int index, int value)
{
	if (start == end)
	{
		arr[index].tastiness = value;
		tree[treenode].tastiness = value;
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
	if (tLeft.tastiness != -1 && tRight.tastiness != -1 && tRight.from_height < tLeft.to_height)
	{
		tree[treenode].from_height = tLeft.from_height;
		tree[treenode].to_height = tRight.to_height;
		tree[treenode].tastiness = tLeft.tastiness + tRight.tastiness;
	}
	else
	{
		tree[treenode].from_height = tLeft.from_height;
		tree[treenode].to_height = tRight.to_height;
		tree[treenode].tastiness = -1;
	}
}

void updateTreeReverse(mountain *arr, mountain *tree, int start, int end, int treenode, int index, int value)
{
	if (start == end)
	{
		arr[index].tastiness = value;
		tree[treenode].tastiness = value;
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
	if (tLeft.tastiness != -1 && tRight.tastiness != -1 && tRight.to_height > tLeft.from_height)
	{
		tree[treenode].from_height = tRight.from_height;
		tree[treenode].to_height = tLeft.to_height;
		tree[treenode].tastiness = tLeft.tastiness + tRight.tastiness;
	}
	else
	{
		tree[treenode].from_height = tRight.from_height;
		tree[treenode].to_height = tLeft.to_height;
		tree[treenode].tastiness = -1;
	}
}

int queryTree(mountain *tree, int start, int end, int treenode, int left, int right)
{
	//completely outside the given range
	if (start > right || end < left)
	{
		return 0;
	}
	//completely inside the given range
	if (start >= left && end <= right)
	{
		return tree[treenode].tastiness;
	}
	//partially inside and partially outside
	int mid = (start + end) / 2;
	int ans1 = queryTree(tree, start, mid, 2 * treenode, left, right);		 //left
	int ans2 = queryTree(tree, mid + 1, end, 2 * treenode + 1, left, right); //right
	if (ans1 != -1 && ans2 != -1)
	{
		return ans1 + ans2;
	}
	else
	{
		return -1;
	}
}

int queryTreeReverse(mountain *tree, int start, int end, int treenode, int left, int right)
{
	//completely outside the given range
	if (start > right || end < left)
	{
		return 0;
	}
	//completely inside the given range
	if (start >= left && end <= right)
	{
		return tree[treenode].tastiness;
	}
	//partially inside and partially outside
	int mid = (start + end) / 2;
	int ans1 = queryTree(tree, start, mid, 2 * treenode, left, right);		 //left
	int ans2 = queryTree(tree, mid + 1, end, 2 * treenode + 1, left, right); //right
	if (ans1 != -1 && ans2 != -1)
	{
		return ans1 + ans2;
	}
	else
	{
		return -1;
	}
}

int32_t main()
{
	fast;
	int n, q;
	cin >> n >> q;
	mountain *arr = new mountain[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].from_height;
		arr[i].to_height = arr[i].from_height;

	}
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].tastiness;
	}

	mountain *tree = new mountain[2 * n];
	mountain *treeReverse = new mountain[2 * n];

	buildTree(arr, tree, 0, n - 1, 1);
	buildTreeReverse(arr, treeReverse, 0, n - 1, 1);

	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int index, value;
			cin >> index >> value;
			updateTree(arr, tree, 0, n - 1, 1, index-1, value);
			updateTreeReverse(arr, treeReverse, 0, n - 1, 1, index-1, value);
		}
		else
		{
			int b, c;
			cin >> b >> c;
			if (b <= c)
			{
				cout << queryTree(tree, 0, n - 1, 1, b-1, c-1) << endl;
			}
			else
			{
				cout << queryTreeReverse(treeReverse, 0, n - 1, 1, c-1, b-1) << endl;
			}
		}
	}
}