/* The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
Input:
The first line contains N denoting the length of the binary string .
The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
This is followed up by Q lines where each line contains a query.
Output:
For each query of Type 0 print the value modulo 3.
Constraints:
1<= N <=10^5

1<= Q <= 10^5

0 <= l <= r < N
Sample Input
5
10010
6
0 2 4
0 2 3
1 1
0 0 4
1 1
0 0 3
Sample Output
2
1
2
1 */



#include<iostream>
#include<algorithm>
#include<limits.h>
using namespace std;
int power[100001];

void buildPower(){
    power[0] = 1;
    for(int i = 1; i < 100001; i++) power[i] = (power[i-1]*2)%3;
}
void build_tree(int* arr, int* tree, int start, int end, int treenode)
{
	if (start == end)
	{
		tree[treenode] = arr[start];
		return;
	}
	int mid = (start + end) / 2;
	build_tree(arr, tree, start, mid, 2 * treenode);
	build_tree(arr, tree, mid + 1, end, 2 * treenode + 1);
	int right_child = tree[2 * treenode + 1];
	int left_child = tree[2 * treenode];
	tree[treenode] = (power[end-mid]*left_child + right_child)%3;
}

void update_flip(int *arr, int* tree, int start, int end, int treenode, int index)
{
	if (start == end)
	{
		arr[index]=1;
        tree[treenode]=1;
        return;
    }
	int mid = (start + end) / 2;
	if (index > mid)
	{
		update_flip(arr, tree, mid + 1, end, 2 * treenode + 1, index);
	}
	else
	{
		update_flip(arr, tree, start, mid, 2 * treenode, index);
	}

	int right_child = tree[2 * treenode + 1];
	int left_child = tree[2 * treenode];
	tree[treenode] = (power[end-mid]*left_child + right_child)%3;
}

int query_value(int* tree, int start, int end, int treenode, int left, int right)
{
	//completely outside
	if (start > right || end < left)
	{
		return 0;
	}
	//completely inside
	if (start >= left && end <= right)
	{
		return (tree[treenode]*power[right-end])%3;
	}
	//partial overlap
	int mid = (start + end) / 2;
	int answer_from_left = query_value(tree, start, mid, 2 * treenode, left, right);
	int answer_from_right = query_value(tree, mid + 1, end, 2 * treenode + 1, left, right);
	return (answer_from_left+answer_from_right)%3;
}
int main()
{
    buildPower();
	int n;
	cin >> n;
	string s;
	cin >> s;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = s[i]-'0';
	}
	int* tree = new int[4 * n]();
	build_tree(arr, tree, 0, n - 1, 1);
	int q;
	cin >> q;
	while (q--)
	{
		int query_type;
		cin >> query_type;
		if (query_type == 0)
		{
			int left, right;
			cin >> left >> right;
			cout << query_value(tree, 0, n - 1, 1, left, right) << endl;;
		}
		else
		{
			int index;
			cin >> index;
            if(arr[index]==0)
			    update_flip(arr, tree, 0, n - 1, 1, index);
		}
	}
}