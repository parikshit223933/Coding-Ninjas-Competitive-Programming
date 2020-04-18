/* Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.
Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
Constraints:
1≤ N,Q ≤10^6
1≤ Ai,Bi ≤10^9
1≤Li≤Ri
Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output
2
2
4
5 */




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