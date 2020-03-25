#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;
struct warriors
{
	int a;
	int b;
};
struct tree_attrs
{
	int a;
	int b;
	int index;
};
void build_tree(warriors* arr, tree_attrs* tree, int start, int end, int treenode)
{
	if (start == end)
	{
		tree[treenode].a = arr[start].a;
		tree[treenode].b = arr[start].b;
		tree[treenode].index = start;
		return;
	}
	int mid = (start + end) / 2;
	build_tree(arr, tree, start, mid, 2 * treenode);
	build_tree(arr, tree, mid + 1, end, 2 * treenode + 1);
	tree_attrs left_child = tree[2 * treenode];
	tree_attrs right_child = tree[2 * treenode + 1];
	if (left_child.a > right_child.a)
	{
		tree[treenode].a = left_child.a;
		tree[treenode].b = left_child.b;
		tree[treenode].index = left_child.index;
	}
	else if(left_child.a < right_child.a)
	{
		tree[treenode].a = right_child.a;
		tree[treenode].b = right_child.b;
		tree[treenode].index = right_child.index;
	}
	else
	{
		if (left_child.b < right_child.b)
		{
			tree[treenode].a = left_child.a;
			tree[treenode].b = left_child.b;
			tree[treenode].index = left_child.index;
		}
		else if (left_child.b > right_child.b)
		{
			tree[treenode].a = right_child.a;
			tree[treenode].b = right_child.b;
			tree[treenode].index = right_child.index;
		}
		else
		{
			if (left_child.index < right_child.index)
			{
				tree[treenode].a = left_child.a;
				tree[treenode].b = left_child.b;
				tree[treenode].index = left_child.index;
			}
			else
			{
				tree[treenode].a = right_child.a;
				tree[treenode].b = right_child.b;
				tree[treenode].index = right_child.index;
			}
		}
	}
}
tree_attrs query(tree_attrs* tree, int start, int end, int treenode, int left, int right)
{
	//completely outside
	if (start > right || end < left)
	{
		tree_attrs ans;
		ans.a = INT_MIN;
		ans.b = INT_MAX;
		ans.index = INT_MAX;
		return ans;
	}
	//completely inside
	if (start >= left && end <= right)
	{
		return tree[treenode];
	}
	//partial overlap
	int mid = (start + end) / 2;
	tree_attrs left_child = query(tree, start, mid, 2 * treenode, left, right);
	tree_attrs right_child = query(tree, mid + 1, end, 2 * treenode + 1, left, right);
	if (left_child.a > right_child.a)
	{
		return left_child;
	}
	else if (left_child.a < right_child.a)
	{
		return right_child;
	}
	else
	{
		if (left_child.b < right_child.b)
		{
			return left_child;
		}
		else if (left_child.b > right_child.b)
		{
			return right_child;
		}
		else
		{
			if (left_child.index < right_child.index)
			{
				return left_child;
			}
			else
			{
				return right_child;
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	warriors* arr = new warriors[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].a;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].b;
	}
	tree_attrs* tree = new tree_attrs[4 * n]();
	build_tree(arr, tree, 0, n - 1, 1);
	int q;
	cin >> q;
	while (q--)
	{
		int left, right;
		cin >> left >> right;
		cout << query(tree, 0, n - 1, 1, left - 1, right - 1).index+1 << endl;
        // I have added 1 because indexing starts from 1
	}
}