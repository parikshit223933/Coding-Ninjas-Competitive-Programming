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
	int tastiness;
	vector<pair<int, int>>vec;              //pair.first=height,         pair.second=tastiness
};

void buildTree(mountain* arr, mountain* tree, int start, int end, int treenode)
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
	int  current_height = tRight.vec[0].first;

	new_node.vec.push_back(tRight.vec[0]);
	new_node.tastiness = tRight.vec[0].second;

	int i = 0;

	for (; i < tRight.vec.size(); i++)
	{
		if (tRight.vec[i].first > current_height&& tRight.tastiness != -1)
		{
			current_height = tRight.vec[i].first;
			current_tastiness = tRight.vec[i].second;
			new_node.vec.push_back(tRight.vec[i]);
			new_node.tastiness += tRight.vec[i].second;
		}
		else if(tRight.tastiness==-1)
		{
			break;
		}
	}

	for (i = 0; i < tLeft.vec.size(); i++)
	{
		if (tLeft.vec[i].first > current_height&& tLeft.tastiness != -1)
		{
			current_height = tLeft.vec[i].first;
			current_tastiness = tLeft.vec[i].second;
			new_node.vec.push_back(tLeft.vec[i]);
			new_node.tastiness += tLeft.vec[i].second;
		}
		else if(tLeft.tastiness==-1)
		{
			break;
		}
	}
	if (i != tLeft.vec.size())
	{
		new_node.tastiness = -1;
	}
	tree[treenode] = new_node;
}

void updateTree(mountain* arr, mountain* tree, int start, int end, int treenode, int index, int value)
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
	int  current_height = tRight.vec[0].first;

	new_node.vec.push_back(tRight.vec[0]);
	new_node.tastiness = tRight.vec[0].second;

	int i = 0;

	for (; i < tRight.vec.size(); i++)
	{
		if (tRight.vec[i].first > current_height&& tRight.tastiness != -1)
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

	for (i = 0; i < tLeft.vec.size(); i++)
	{
		if (tLeft.vec[i].first > current_height&& tLeft.tastiness != -1)
		{
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
	if (i != tLeft.vec.size())
	{
		new_node.tastiness = -1;
	}
	tree[treenode] = new_node;
}

int queryTree(mountain* tree, int start, int end, int treenode, int left, int right)
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
	mountain* arr = new mountain[n];
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

	mountain* tree = new mountain[2 * n];

	buildTree(arr, tree, 0, n - 1, 1);

	while (q--)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			int index, value;
			cin >> index >> value;
			updateTree(arr, tree, 0, n - 1, 1, index - 1, value);
		}
		else
		{
			int b, c;
			cin >> b >> c;
			if (b <= c)
			{
				cout << queryTree(tree, 0, n - 1, 1, b - 1, c - 1) << endl;
			}
			else
			{
				cout << "implement tree reverse" << endl;
			}
		}
	}
}