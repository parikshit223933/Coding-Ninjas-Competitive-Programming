/* Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
Input:
First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9
Note:-
indexing starts from 1.
Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output
2
2
4 */




#include<iostream>
#include<algorithm>
using namespace std;
struct tree_attrs
{
	int even;
	int odd;
};
void build_tree(int* arr, tree_attrs* tree, int start, int end, int treenode)
{
	if (start == end)
	{
		if (arr[start] % 2 == 0)
		{
			tree[treenode].even = 1;
			tree[treenode].odd = 0;
		}
		else
		{
			tree[treenode].odd = 1;
			tree[treenode].even = 0;
		}
		return;
	}
	int mid = (start + end) / 2;
	build_tree(arr, tree, start, mid, 2 * treenode);
	build_tree(arr, tree, mid+1, end, 2 * treenode+1);
	tree[treenode].odd = tree[2 * treenode].odd + tree[2 * treenode + 1].odd;
	tree[treenode].even = tree[2 * treenode].even + tree[2 * treenode + 1].even;
}
void update_modify(int *arr, tree_attrs* tree, int start, int end, int treenode, int index, int value)
{
	if (start == end)
	{
		arr[index] = value;
		if (value % 2 == 0)
		{
			tree[treenode].even = 1;
			tree[treenode].odd = 0;
		}
		else
		{
			tree[treenode].even = 0;
			tree[treenode].odd = 1;
		}
		return;
	}
	int mid = (start + end) / 2;
	if (index > mid)//right
	{
		update_modify(arr, tree, mid + 1, end, 2 * treenode + 1, index, value);
	}
	else//left
	{
		update_modify(arr, tree, start, mid, 2 * treenode, index, value);
	}
	tree[treenode].even = tree[2 * treenode].even + tree[2 * treenode + 1].even;
	tree[treenode].odd = tree[2 * treenode].odd + tree[2 * treenode + 1].odd;
}
tree_attrs query(tree_attrs* tree, int start, int end, int treenode, int left, int right)
{
	//completely outside
	if (start > right || end < left)
	{
		tree_attrs ans;
		ans.even = 0;
		ans.odd = 0;
		return ans;
	}
	//complete overlap
	if (start >= left && end <= right)
	{
		return tree[treenode];
	}
	//partial overlap
	int mid = (start + end) / 2;
	tree_attrs left_child = query(tree, start, mid, 2 * treenode, left, right);
	tree_attrs right_child = query(tree, mid + 1, end, 2 * treenode + 1, left, right);
	tree_attrs ans;
	ans.even = left_child.even + right_child.even;
	ans.odd = left_child.odd + right_child.odd;
	return ans;
}
int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	tree_attrs* tree = new tree_attrs[4 * n]();
	build_tree(arr, tree, 0, n - 1, 1);
	int q;
	cin >> q;
	while (q--)
	{
		int query_type;
		cin >> query_type;
		if (query_type == 0)
		{
			int index, value;
			cin >> index >> value;
			update_modify(arr, tree, 0, n - 1, 1, index-1, value);
		}
		else if (query_type == 1)
		{
			int left, right;
			cin >> left >> right;
			cout << query(tree, 0, n - 1, 1, left - 1, right - 1).even<<endl;
		}
		else
		{
			int left, right;
			cin >> left >> right;
			cout << query(tree, 0, n - 1, 1, left - 1, right - 1).odd<<endl;
		}
	}
}